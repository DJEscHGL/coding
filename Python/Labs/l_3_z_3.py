popal = 0
ne_popal = 0
for i in range(10):
    print('Попытка ' + str(i + 1))
    x = float(input('Введите x '))
    y = float(input('Введите y'))
    if -2 < x < 3 and 2 < y < 4:
        popal += 1
    else:
        ne_popal += 1
print("Попаданий: ", popal)
print("Промахов: ", ne_popal)
