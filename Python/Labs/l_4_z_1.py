mass0 = [0, -1, -2, 3, -4, -6, 12, -7, 0, -9]
# Задание 1
task1 = 0
for i in mass0:
    if i < 2:
        task1 += 1
print("Количество элементов, значение которых меньше 2 =", task1)
# Задание 2
ind1 = -1
ind2 = -1
for i in range(len(mass0)):
    if ind1 == -1 and mass0[i] > 0:
        ind1 = i
    else:
        if ind2 == -1 and mass0[i] > 0:
            ind2 = i
task2 = sum(mass0[ind1 + 1:ind2])
print("Сумма элементов, расположенных между первым и вторым положительными числами =", task2)
# Задание 3
print("До замены", mass0)
for i in range(len(mass0)):
    if mass0[i] == 0:
        mass0[i] = 10
print("После замены", mass0)
# Задание 4
print("Введите новый список из 8 чисел")
mass1 = []
for _ in range(8):
    mass1.append(int(input('Введи число ')))
# Задание 5
task5 = 0
for i in mass1:
    if i in mass0[2:6]:
        task5 += 1
print("Количество элементов второго списка в срезе первого списка со 2 по 6 элемент =", task5)
# Задание 6
print('Новый список')
mass2 = mass0 + mass1
print(mass2)
# задание 7
print('Отсортированный список')
mass2.sort(reverse=True)
print(mass2)
# Задание 8
print('Все три списка')
print(mass0)
print(mass1)
print(mass2)
