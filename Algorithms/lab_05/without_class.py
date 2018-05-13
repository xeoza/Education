import numpy as np

def Ki(Qi1, Qi, T, Ei, deltaEi):
    '''Ki'''

    return (2 * 2.415e-3 * Qi1 / Qi * T**(3 / 2) * np.exp(-(Ei - deltaEi) * 11603 / T))

def deltaEi(T, Zi1, Zi, G):
    '''deltaEi'''

    return (8.61 * 10**(-5) * T * np.log(((1+Zi1**2 * G/2)*(1+G/2))/(1 + Zi**2 * G/2)))

def func(T, Ve ,G, x2, x3, x4, x5, z2, z3, z4, z5):
    '''G**2 - f(G) = 0'''

    summ = (np.exp(x2) * z2**2)/(1 + z2**2 * G/2) + (np.exp(x3) * z3**2)/(1 + z3**2 * G/2) + \
           (np.exp(x4) * z4 ** 2) / (1 + z4 ** 2 * G / 2) + (np.exp(x5) * z5**2)/(1 + z5**2 * G/2)

    return G**2 - 5.87e10/T**3 * (np.exp(Ve)/(1 + G/2) + summ)

def half_division(T, Values, Z):
    '''Method of half devision'''

    a = 0
    b = 2
    c = (a+b)/2

    while abs((b - a)/c) > 1e-5:
        c = (a+b)/2
        d = func(T, Values[0], a, Values[2], Values[3], Values[4], Values[5], Z[1], Z[2], Z[3], Z[4]) * \
            func(T, Values[0], c, Values[2], Values[3], Values[4], Values[5], Z[1], Z[2], Z[3], Z[4])
        if d > 0:
            a = c
        if d < 0:
            b = c

    return c

def gauss(m):
    # Приводим к треугольному виду
    for col in range(len(m[0])):
        for row in range(col+1, len(m)):
            r = [(rowValue * (-(m[row][col] / m[col][col]))) for rowValue in m[col]]
            m[row] = [sum(pair) for pair in zip(m[row], r)]
    # Вычисление ответов
    ans = []
    m.reverse() #переворачиваю так как идет с конца в начало
    for sol in range(len(m)):
            if sol == 0:
                ans.append(m[sol][-1] / m[sol][-2])
            else:
                inner = 0
                for x in range(sol):
                    inner += (ans[x]*m[sol][-2-x])
                # уравнение теперь преобразовано в ax + b = c
                # решаем уравнение при помощи (c - b) / a
                ans.append((m[sol][-1]-inner)/m[sol][-sol-2])
    ans.reverse()
    return ans

def matrix(Values, Q, G, E, T, Z):

    Ve = Values[0]
    x1 = Values[1]
    x2 = Values[2]
    x3 = Values[3]
    x4 = Values[4]
    x5 = Values[5]

    Q1 = Q[0]
    Q2 = Q[1]
    Q3 = Q[2]
    Q4 = Q[3]
    Q5 = Q[4]

    E1 = E[0]
    E2 = E[1]
    E3 = E[2]
    E4 = E[3]

    z1 = Z[0]
    z2 = Z[1]
    z3 = Z[2]
    z4 = Z[3]
    z5 = Z[4]

    alpha = 0.285e-11 * (G * T)**3

    m = [[1, -1, 1, 0, 0, 0, -(Ve + x2 - x1 - np.log(Ki(Q2, Q1, T, E1, deltaEi(T, z2, z1, G))))],
         [1, 0, -1, 1, 0, 0, -(Ve + x3 - x2 - np.log(Ki(Q3, Q2, T, E2, deltaEi(T, z3, z2, G))))],
         [1, 0, 0, -1, 1, 0, -(Ve + x4 - x3 - np.log(Ki(Q4, Q3, T, E3, deltaEi(T, z4, z3, G))))],
         [1, 0, 0, 0, -1, 1, -(Ve + x5 - x4 - np.log(Ki(Q5, Q4, T, E4, deltaEi(T, z5, z4, G))))],
         [np.exp(Ve), np.exp(x1), np.exp(x2), np.exp(x3), np.exp(x4),
          np.exp(x5), -(np.exp(Ve) + np.exp(x1) + np.exp(x2) + \
                        np.exp(x3) + np.exp(x4) + np.exp(x5) - alpha - p*7.242*10**3/T)],
         [np.exp(Ve), 0, -z2 * np.exp(x2), -z3 * np.exp(x3), -z4 * np.exp(x4),
          -z5 * np.exp(x5), -(np.exp(Ve) - (z2 * np.exp(x2) + z3 * np.exp(x3) + z4 * np.exp(x4) + z5 * np.exp(x5)))]]

    return m

def refinement(Values, Q, E, Z, G, p, T):

    m = matrix(Values, Q, G, E, T, Z)
    dValues = gauss(m)
    n_G = half_division(T, Values, Z)

    while(max(abs(dValues[0]/Values[0]), abs(dValues[1]/Values[1]), abs(dValues[2]/Values[2]), \
              abs(dValues[3]/Values[3]), abs(dValues[4]/Values[4]), abs(dValues[5]/Values[5]), abs((G - n_G)/n_G))) > 1e-5:

        Values[0] += dValues[0]
        Values[1] += dValues[1]
        Values[2] += dValues[2]
        Values[3] += dValues[3]
        Values[4] += dValues[4]
        Values[5] += dValues[5]

        G = n_G
        n_G = half_division(T, Values, Z)

        m = matrix(Values, Q, G, E, T, Z)
        dValues = gauss(m)


    return Values, n_G


#Begin values
p = int(input("Значение p: "))
T = int(input("Значение T: "))

G = 0
k = 1.38 * 10 ** (-23)
E = [12.13, 20.96, 31.05, 42.2]
Z = [0, 1, 2, 3, 4]
Q = [1.0895, 4.65, 7.41, 11.0, 15.0]
Values = [0] * 6

ne = np.exp(-3.27)

n1 = 7.242e+3 * p / T - 2 * ne
n2 = ne

Values[0] = np.log(ne)
Values[1] = np.log(n1)
Values[2] = np.log(n2)
Values[3] = -1
Values[4] = -1
Values[5] = -1

print("Начальные условия: ", Values)

answer,G = refinement(Values, Q, E, Z, G, p, T)
print("\n")
for val in answer:
    print(np.exp(val))
print("\n")
print("Гамма: ", G)



