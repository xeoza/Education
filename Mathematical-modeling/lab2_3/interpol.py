EPS = 1e-6


# разделенная разность
def diff(X, Y, n):
    if n == 1:
        return Y[0]

    if n == 2:
        return (Y[0] - Y[1]) / (X[0] - X[1])

    return (diff(X[:n - 1], Y[:n - 1], n - 1) - diff(X[1:], Y[1:], n - 1)) / (X[0] - X[n - 1])


# полином Ньютона
def newton_polynom(X, Y, n, x):
    coeff = 1
    res = 0
    for i in range(n):
        res += coeff * diff(X[:i + 1], Y[:i + 1], i + 1)
        coeff *= x - X[i]
    return res


# интерполяция
def interpolation(X, Y, n, x, p):
    nodes = p + 1
    half = nodes // 2

    # экстраполяция снизу
    if x < X[0]:
        NX = X[:nodes]
        NY = Y[:nodes]
        return newton_polynom(NX, NY, nodes, x)

    # экстраполяция сверху
    if x > X[n - 1]:
        NX = X[-nodes:]
        NY = Y[-nodes:]
        return newton_polynom(NX, NY, nodes, x)

    # поиск точки внутри таблицы
    indx = -1
    for i in range(n - 1):
        if x > X[i] and x < X[i + 1]:
            indx = i
            break
        # попали в известную точку
        elif abs(x - X[i]) < EPS:
            return Y[i]

    # крайние снизу
    i = indx
    if i + 1 <= half:
        NX = X[:nodes]
        NY = Y[:nodes]
    # крайние сверху
    elif half >= n - i - 1:
        NX = X[-nodes:]
        NY = Y[-nodes:]
    # рядом стоящие точки
    else:
        NX = X[i - half + 1:i + nodes - half + 1]
        NY = Y[i - half + 1:i + nodes - half + 1]

    return newton_polynom(NX, NY, nodes, x)


if __name__ == '__main__':
    X = [-5, -4, -3, -2, -1, 0, 1, 2, 3, 4]
    Y = [- 123, -62, -25, -6, 1, 2, 3, 10, 29, 66]
    print(interpolation(X, Y, len(X), -0.382, 3))

