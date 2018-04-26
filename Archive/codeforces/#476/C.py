n, k, m, d = map(int, input().split())
ans = 0;
for i in range(1, d+1):
    times = (i-1)*k+1
    per = n//times
    per = min(per, m)
    ans = max(ans, i*per)
print(ans)
