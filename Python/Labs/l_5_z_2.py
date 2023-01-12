mass0 = []
for _ in range(5):
    mass0.append(int(input('Введи число ')))
a = int(input('Введи число a = '))
if 0 <= a < 3:
    print(mass0[2*a])
else:
    print("Такой элемент не существует")
