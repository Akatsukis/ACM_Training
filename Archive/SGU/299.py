import sys
n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort()
for i in range(n-2):
    if a[i]+a[i+1] > a[i+2]:
        print (a[i], a[i+1], a[i+2])
        exit(0)
print(0, 0, 0)
