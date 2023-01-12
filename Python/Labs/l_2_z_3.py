import math
r = float(input('Радиус '))
k = int(input('k = '))
ans = 0
str = ''
if k == 1:
    ans = math.pi * r * r
    str = 'Площадь круга '
if k == 2:
    ans = math.pi * r * 2
    str = 'Длина окружнасти '
if k == 3:
    ans = (4 / 3) * math.pi * r * r * r
    str = 'Обьём шара '
print(str)
print(ans)
