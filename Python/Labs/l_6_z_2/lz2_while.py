def l2_z2_while(N, x):

    ans = 0
    n = 0
    while n <= N:
        ans += 1 / ((n * 2 + 1) * (x ** (n * 2 + 1)))
        n += 1
    return ans
