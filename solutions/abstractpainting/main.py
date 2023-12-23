lines = int(input())

while lines:
    lines -= 1

    r, c = sorted(list(map(int, input().split(' '))))

    res= 1
    mod = 1000000007
    for row in range(r):
        for col in range(c):
            if row == 0 and col == 0:
                res *= 18
            elif row == 0 or col == 0:
                res *= 6
            else:
                res *= 2
    print(res % mod)