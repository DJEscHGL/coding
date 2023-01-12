A = int(input('Введи число A '))
B = int(input('Введи число B '))
if A % 2 != 0:
    A -= 1
while A >= B:
    print(A)
    A -= 2
