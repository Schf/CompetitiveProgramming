s = input().split()
d = {ss: 0 for ss in s}
for ss in s:
    d[ss] += 1
mss = max(d, key=d.get)
print(d[mss], mss)
