import sys

lines = sys.stdin.read().strip().split('\n')

for line in lines:
    a, b, c = map(int, line.split())
    print(a * b * c)