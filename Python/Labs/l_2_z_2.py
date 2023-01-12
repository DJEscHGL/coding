x = float(input('Введи число '))
ans = 0
if x <= -4:
    ans = (4 * x - 1) / (x - 2)
if -4 < x <= 6:
    ans = 2 * x + 2
if x > 6:
    ans = - x * x * x - 1
print(ans)
