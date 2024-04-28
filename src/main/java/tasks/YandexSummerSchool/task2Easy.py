if __name__ == "__main__":
    a, b = input(), input()
    b = [i.split(">") for i in b.split("<")]
    new_b = []
    for i in b:
        for j in i:
            if j:
                new_b.append(j)
    b = new_b
    ans = []
    pos = 0
    for i in b:
        '''
        • <delete> Удаление символа после текущей позиции курсора. ->
        • <bspace> Удаление символа перед текущей позицией курсора. <-
        • <left> Курсор перемещается влево на один символ. -1
        • <right> Курсор перемещается вправо на один символ. +1

        helto<left><bspace>l<delete>ochilds<bspace>
        '''
        if i in {"left", "bspace", "right", "delete"}:
            if i == "left":
                pos = max(pos - 1, 0)
            elif i == "right":
                pos = min(pos + 1, len(ans))
            elif i == "delete":
                if pos < len(ans):
                    ans.pop(pos)
            elif i == "bspace":
                if 0 < pos:
                    pos -= 1
                    ans.pop(pos)
        else:
            for k in i:
                ans.insert(pos, k)
                pos += 1
    print("Yes" if "".join(ans) == a else "No")
'''
    hello
'''