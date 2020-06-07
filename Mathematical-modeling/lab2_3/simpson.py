def simpson(func, a, b, I_prev, n=20):
    h = (b - a) / n
    even = 0.0
    odd = 0.0

    for i in range(1, n):
        x = a + h * i
        if i % 2 == 0:
            even += func(x, I_prev)
        else:
            odd += func(x, I_prev)

    return h/3 * (func(a, I_prev) + func(b, I_prev) + 2*even + 4*odd)
