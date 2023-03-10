import numpy as np

np.set_printoptions(threshold=int(np.inf))

MAX_JUMP = 11  # Actually one over max jump
MODULO = 10**9

N, M, K = [int(x) for x in input().split(" ")]
print(N, M, K)

partials = np.zeros(shape=(MAX_JUMP, K, K))
complete = np.zeros(shape=(MAX_JUMP, K, K))
for _ in range(M):
    d, p = [int(x) for x in input().split(" ")]
    for i in range(K - p):
        partials[d][i][i + p] += 1

for i in range(1, MAX_JUMP):
    complete[i] = partials[i]
    for j in range(i):
        complete[i] += np.matmul(complete[j], partials[i - j]) % MODULO

result = np.identity(K)
multiplier = complete.copy()

n = N//10
while n:
    if n%2:
        result = np.matmul(result, multiplier)
    multiplier = np.matmul(multiplier, multiplier)
    n //= 2

result = np.matmul(result, complete[])
