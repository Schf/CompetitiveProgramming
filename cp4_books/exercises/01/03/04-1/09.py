LINE = input().split(" ")
x = int(LINE[0])
y = int(LINE[1])
n = int(LINE[2], x)
i = 0
while y**i < n:
    i += 1
i -= 1
dic = {
    **{num: str(num) for num in range(10)},
    **{10+num: chr(ord("A") + num) for num in range(26)},
}
while i >= 0:
    print(dic[n // (y**i)], end="")
    n = n % (y**i)
    i -= 1
print()
