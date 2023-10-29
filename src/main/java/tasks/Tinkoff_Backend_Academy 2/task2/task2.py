class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class ExpandableQueue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def push(self, value):
        node = Node(value)
        if self.size == 0:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node
        self.size += 1

    def pop(self):
        if self.size == 0:
            raise Exception("Queue is empty")
        else:
            value = self.head.value
            self.head = self.head.next
            self.size -= 1
            return value

    def expand(self):
        self.size *= 2
        curr = self.head
        while curr is not None:
            tmp = curr.next
            curr.next = Node(curr.value)
            self.tail = curr.next

            curr.next.next = tmp
            curr = tmp


n = int(input())
queue = ExpandableQueue()
for i in range(n):
    string = input()
    op = string[0]
    if op == "1":
        value = int(string.split()[1])
        queue.push(value)
    elif op == "2":
        queue.expand()
    elif op == "3":
        print(queue.pop())
