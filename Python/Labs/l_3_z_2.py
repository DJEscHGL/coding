import math
N = int(input('Введи число N '))
x = float(input('Введи число x '))
ans = 0
for n in range(N + 1):
    ans += 1 / ((n * 2 + 1) * math.pow(x, (n * 2 + 1)))
print(ans)

# ans = 0
# i = 0
# while i < N + 1:
#    ans += 1 / ((i * 2 + 1) * math.pow(x, (i * 2 + 1)))
#    i += 1
# print(ans)
