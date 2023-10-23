from datetime import datetime

LINE = input().split(" ")

n = int(LINE[0])
d = [datetime.strptime(s, "%d/%m/%Y") for s in LINE[1:]]
d.sort(key = lambda x : (x.month, x.day, x))
for dd in d:
    print(dd.strftime("%d/%m/%Y"))
