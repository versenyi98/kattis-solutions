import sys

lines = sys.stdin.read().strip().split("\n")
for line in lines:
    print(1 if line[:3] == "555" else 0)