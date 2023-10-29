class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class ExpandableQueue:
    def __init__(self):
        self.head = None
        self.tail = None

    def push(self, value):
        node = Node(value)
        if self.head is None:
            self.head = node
        else:
            self.tail.next = node
        self.tail = node

    def pop(self):
        res = self.head.value
        self.head = self.head.next
        return res

    def expand(self):
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
