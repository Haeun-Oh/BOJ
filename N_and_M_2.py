n, m = map(int, input().split())
visit = []
def dfs(x, cnt):
  if cnt == m:
      print(' '.join(map(str, visit)))
      return

  for i in range(x, n+1):
    if i not in visit:
      visit.append(i)
      dfs(i+1, cnt+1)
      visit.pop()
      
dfs(1, 0)
