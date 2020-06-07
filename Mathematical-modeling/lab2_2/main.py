from math import *
import numpy as np
from scipy import interpolate
import matplotlib.pyplot as plt



I0 = 1
U0 = 1500
tw = 2000
R = 0.35
R_k = 200
C_k = 150e-6
L_ind = 60e-6
U_p_mas = []
I_mas = []
U_k_mas = []
T_mas = []
R_p_mas = []

# print("Введите Tw: ")
# tw = input()
# print("Введите R: ")
# R = input()


table_1 = [[0.5,  1.0,  5.0,  10.0, 50.0, 200.0, 400.0, 800.0, 1200.0],\
           [6400, 6790, 7150, 7270, 8010, 9185,  10010, 11140, 12010],\
           [0.4,  0.55, 1.7,  3.0,  11.0, 32.0,  40.0,  41.0,  39.0]]

table_2 = [[4000,  5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000],\
           [0.031, 0.27, 2.05, 6.06, 12.0, 19.9, 29.6,  41.1,  54.1,  67.7,  81.5]]


def t_z(z, m, t0):
    # print(m, z, t0)
    return t0 + (tw - t0) * pow(z, m)

def logarifm(table):
    for i in range(len(table)):
        for j in range(len(table[0])):
            table[i][j] = log(table[i][j])


logarifm(table_2)

def bin_srch(arr, x):
    a = 0
    b = len(arr) - 1
    while a < b:
        mid = int((a+b)/2)
        if x > arr[int(mid)]:
            a = mid+1
        else:
            b = mid
    return b


def stupid_search(mas, val):
    for i in range(1, len(mas)):
        if ((val >= mas[i - 1]) and (val <= mas[i])):
            return i - 1
    return -1


def divided_difference(xs, ys):
    l = len(xs)
    if l == 1:
        return ys[0]
    else:
        return (divided_difference(xs[:-1], ys[:-1]) - divided_difference(xs[1:], ys[1:])) / (xs[0] - xs[l - 1])

def newton(x, x_arr, y_arr):
    i = bin_srch(x_arr, x)
    smpl_x = []; smpl_y = []
    if i == 0:
        smpl_x = x_arr[:3]
        smpl_y = y_arr[:3]
    elif i == len(x_arr)-1:
        smpl_x = x_arr[-3:]
        smpl_y = y_arr[-3:]
    else:
        smpl_x = x_arr[i-1:i+2]
        smpl_y = y_arr[i-1:i+2]
    y_x = smpl_y[0]
    for i in range(1, len(smpl_x)):
        k = 1
        for j in range(i):
           k *= (x - smpl_x[j])
        dd = divided_difference(smpl_x[:i+1], smpl_y[:i+1])
        y_x += (k * dd)
    return y_x

# print("Newton", newton(500, table_1[0], table_1[1]))


def line_interpolation(x_mas, y_mas, x):
    left = stupid_search(x_mas, x)
    if (left != -1):
        right = left + 1
        a = (y_mas[right] - y_mas[left]) / (x_mas[right] - x_mas[left])
        b = y_mas[left] - a * x_mas[left]
        return a * x + b
    else:
        return -1



def func(z, m , T0):
    # m  = newton(I, table_1[0], table_1[2])
    # T0 = newton(I, table_1[0], table_1[1])
    # f_m  = interpolate.interp1d(table_1[0], table_1[2], fill_value = "extrapolate")
    # f_T0 = interpolate.interp1d(table_1[0], table_1[1], fill_value = "extrapolate")
    # m = f_m(I)
    # T0 = f_T0(I)

    temperature = t_z(z, m, T0)
    # print (m, T0, temperature)
    f_sigm = interpolate.interp1d(table_2[0], table_2[1], fill_value = "extrapolate")

    sigm = exp(f_sigm(log(temperature)))
    # print("sigm -> ", sigm, temperature)

    return sigm * z

# def func(x):
#     return sqrt(1 + 2 * x * x - x * x * x)

def simpson(point_count, a, b, I):
    h = (b - a) / (2 * point_count)
    f_m  = interpolate.interp1d(table_1[0], table_1[2], fill_value = "extrapolate")
    f_T0 = interpolate.interp1d(table_1[0], table_1[1], fill_value = "extrapolate")
    m = f_m(abs(I))
    T0 = f_T0(abs(I))

    result = func(a, m, T0) + func(b, m, T0)

    count = 0

    z = a + h
    while(z < b - 2*h):
        count += 1
        if (count % 2 == 0):
            result += func(z, m, T0) * 2
        else:
            result += func(z, m, T0) * 4
        z += h

    return result * h / 3
#                                       !~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!
def find_Rp(I, point_count):
    return 0
    # return L_ind / (2 * pi * R * R * simpson(point_count, 0, 1, I))

def find_Idt(I, U):
    return (U - (find_Rp(I, 100) + R_k) * I) / L_ind

def find_Udt(I):
    return -I / C_k

def RungeCutta(begin, end, h):
    I = I0
    U = U0
    while(begin <= end):

        R_p = find_Rp(I, 100)

        I_mas.append(I)
        U_k_mas.append(U)
        U_p_mas.append(I * R_p)
        R_p_mas.append(R_p)
        T_mas.append(begin)

        Ki1 = find_Idt(I, U)
        Ki2 = find_Idt(I + h / 2, U + (h * Ki1) / 2)
        Ki3 = find_Idt(I + h / 2, U + (h * Ki2) / 2)
        Ki4 = find_Idt(I + h, U + h * Ki3)

        Ku1 = find_Udt(I)
        Ku2 = find_Udt(I + (h * Ki1) / 2)
        Ku3 = find_Udt(I + (h * Ki2) / 2)
        Ku4 = find_Udt(I + h * Ki3)

        I = I + h / 6 * (Ki1 + 2 * Ki2 + 2 * Ki3 + Ki4)
        U = U + h / 6 * (Ku1 + 2 * Ku2 + 2 * Ku3 + Ku4)

        # if I < 0:
        #     I = 0
        

        begin += h

    print("OK")
    plt.subplot (2, 2, 1)
    plt.plot(T_mas,I_mas)
    plt.title("I")
    plt.subplot (2, 2, 2)
    plt.plot(T_mas,U_k_mas)
    plt.title("Uc")
    plt.subplot (2, 2, 3)
    plt.plot(T_mas,R_p_mas)
    plt.title("Rp")
    plt.subplot (2, 2, 4)
    plt.plot(T_mas,U_p_mas)
    plt.title("Up")
    plt.show()


RungeCutta(0, 350e-5, 1e-5)



# f_m  = interpolate.interp1d(table_1[0], table_1[2], fill_value = "extrapolate")
# f_T0 = interpolate.interp1d(table_1[0], table_1[1], fill_value = "extrapolate")
# m = f_m(I)
# T0 = f_T0(I)