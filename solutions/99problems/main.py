import sys

value = int(sys.stdin.read())

lower = value // 100 * 100 - 1
upper = value // 100 * 100 + 99

if lower < 0 or abs(upper - value) <= abs(lower - value):
    print(upper)
else:
    print(lower)