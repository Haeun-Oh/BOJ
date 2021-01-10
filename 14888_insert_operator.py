from itertools import permutations

n = int(input())
arr = list(map(int, input().split()))
plus, minus, multi, divide = map(int, input().split())

ans = list()

li = set(permutations('+'*plus + '-'*minus + '*'*multi + '/'*divide))

for p in set(permutations('+'*plus + '-'*minus + '*'*multi + '/'*divide)):
    r = arr[0]
    for i in range(1, n):
        r = {'+':r+arr[i], '-':r-arr[i], '*': r*arr[i], '/':int(r/arr[i])}[p[i-1]]
    ans.append(r)

print(max(ans), min(ans))
