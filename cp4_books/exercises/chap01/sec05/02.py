t = input()
p = input()
i = -1
try:
    while True:
        i = t.index(p, i+1)
        print(i)
except:
    pass

if i < 0:
    print(i)
