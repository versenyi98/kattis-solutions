def get_required(amount, paper_type):
    if amount == 0:
        return 0
    
    required_smaller = max(0, 2 * (amount - papers[paper_type]))
    return amount // 2 * paper_sizes[paper_type][0] + get_required(required_smaller, paper_type + 1)

_ = input()
papers = list(map(int, input().split(' ')))

papers_copy = [paper for paper in papers[::-1]]
paper_sizes = [(pow(2, -3 / 4), pow(2, -5 / 4))]

for i in range(50):
    h, w = paper_sizes[-1]
    paper_sizes.append((w, h / 2))

for idx in range(len(papers_copy) - 1):
    papers_copy[idx + 1] += papers_copy[idx] // 2

if papers_copy[-1] < 2:
    print("impossible")
else:
    cost = get_required(2, 0)
    print(cost)
