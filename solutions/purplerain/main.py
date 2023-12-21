import sys

line = sys.stdin.read().strip("\n")

current_max = -1
best_start_idx = 0
best_end_idx = 0

running_sum_b = 0
current_start_b = 0

running_sum_r = 0
current_start_r = 0

for idx, rain in enumerate(line):
    running_sum_r += 1 if rain == "R" else -1
    running_sum_b += 1 if rain == "B" else -1

    if running_sum_b > current_max:
        current_max = running_sum_b
        best_start_idx = current_start_b + 1
        best_end_idx = idx + 1
    if running_sum_r > current_max:
        current_max = running_sum_r
        best_start_idx = current_start_r + 1
        best_end_idx = idx + 1

    if running_sum_r < 0:
        current_start_r = idx + 1
        running_sum_r = 0
    if running_sum_b < 0:
        current_start_b = idx + 1
        running_sum_b = 0

print(f"{best_start_idx} {best_end_idx}")