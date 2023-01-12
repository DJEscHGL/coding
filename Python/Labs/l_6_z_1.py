n = int(input("n = "))
x = int(input('x = '))


def l2_z2_for(N, x):

    ans = 0
    for n in range(N + 1):
        ans += 1 / ((n * 2 + 1) * (x ** (n * 2 + 1)))
    return ans


def l2_z2_while(N, x):

    ans = 0
    n = 0
    while n <= N:
        ans += 1 / ((n * 2 + 1) * (x ** (n * 2 + 1)))
        n += 1
    return ans


print('Ряд посчитанный через for: ' + str(l2_z2_for(n, x)))
print('Ряд посчитанный через while: ' + str(l2_z2_while(n, x)))
