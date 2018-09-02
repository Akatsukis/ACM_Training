a = int(input())
l = 1
r = a
ans = 1
while(l <= r):
    m = (l+r)>>1
    if(m**2 <= a):
        ans = m
        l = m+1
    else:
        r = m-1
print (ans)
