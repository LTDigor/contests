LOW, HIGH = 'low', 'high'
MAIN, SIDE = 'main', 'side'

# todo
for p in range(1, 54 + 1):
    print("------------------", p, "------------------")
    curr_pos = p


    # todo
    def input(s):
        print(s)
        print(curr_pos)
        lev = LOW if curr_pos % 2 == 1 else HIGH
        prior = MAIN if curr_pos <= 36 else SIDE
        return lev + " " + prior


    start_level, start_priority = input("? 0\n").split()
    level, priority = start_level, start_priority
    offset = 0

    step = 123456
    steps = [18, 9, 4, 2]
    step_ind = 0
    while step_ind < len(steps):
        if start_priority == MAIN and priority == MAIN and step_ind == 1:
            step_ind -= 1

        sign = 1 if priority == MAIN else -1
        step_len = (steps[step_ind]
            + int(priority == MAIN and level == LOW)
            # + int(step == -9 and priority == SIDE)
                    )

        prev_step = step
        step = sign * step_len
        offset += step
        step_ind += 1

        # todo
        curr_pos = offset + p

        level, priority = input(f"? {step}\n").split()

    res = 35 - offset + int(level == HIGH) + 2 * int(priority == SIDE)

    print(f"! {res}")

    # todo
    print("Curr pos:", curr_pos)
    print("Actual:", res)
    print("Expected:", p)
    assert p == res
