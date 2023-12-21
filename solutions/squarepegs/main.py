import math

lines = input()
plots = list(map(int, input().split()))
circles = list(map(int, input().split()))
squares = list(map(int, input().split()))

houses = circles

for i in squares:
    houses.append((math.sqrt((i**2)+(i**2))) / 2)

houses = sorted(houses)
plots = sorted(plots)

counter = 0

while len(houses) and len(plots):
    if houses[-1] < plots[-1]:
        plots = plots[:-1]
        counter += 1
    houses = houses[:-1]

print(counter)