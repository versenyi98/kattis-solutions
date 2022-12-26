import sys

values = list(map(int, sys.stdin.read().strip("\n").split("\n")))[1:]
results = {value: "no solution" for value in values}

operators = ["*", "//", "+", "-"]

for op1 in operators:
    for op2 in operators:
        for op3 in operators:
            eq = f"4 {op1} 4 {op2} 4 {op3} 4"
            res = eval(eq)
            if res in results:
                results[res] = eq

for value in values:
    if results[value] == "no solution":
        print(results[value])
    else:
        print(f"{results[value].replace('//', '/')} = {value}")