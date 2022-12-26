import sys

n, k = map(int, sys.stdin.readline().split())
values = list(map(int, sys.stdin.readline().split()))

current_best_profit = 0
running_money = values[0] * 100 - k

for idx, price in enumerate(values):
    running_money -= k
    if running_money - 100 * price > current_best_profit:
        current_best_profit = running_money - 100 * price
    if running_money - 100 * price < 0:
        running_money = price * 100 - k

print(current_best_profit)