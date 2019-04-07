import math
T = int(input())
for kase in range(T):
    n, m = map(int, input().split())
    tb = list(map(int, input().split()))
    pos = 0
    while pos+1 < m and tb[pos] == tb[pos+1]:
        pos += 1
    val = [0 for i in range(m+1)]
    val[pos+1] = math.gcd(tb[pos], tb[pos+1]);
    for i in range(pos, -1, -1):
        val[i] = tb[i]//val[i+1]
    for i in range(pos+1, m+1):
        val[i] = tb[i-1]//val[i-1]
    vec = list(set(val))
    vec.sort()
    ans = ""
    for i in range(m+1):
        for j in range(len(vec)):
            if val[i] == vec[j]:
                ans += chr(ord('A')+j)
                break
    print("Case #"+str(kase+1)+": "+ans)

