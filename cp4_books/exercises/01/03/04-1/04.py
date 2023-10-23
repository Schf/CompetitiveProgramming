n = int(input())
l = sorted([int(input()) for _ in range(n)])
print(l[0])
for i in range(1, n):
    if l[i] != l[i-1]:
        print(l[i])
