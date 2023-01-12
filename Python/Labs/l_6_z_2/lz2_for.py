def l2_z2_for(N, x):

    ans = 0
    for n in range(N + 1):
        ans += 1 / ((n * 2 + 1) * (x ** (n * 2 + 1)))
    return ans
