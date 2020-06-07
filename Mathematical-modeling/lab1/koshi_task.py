# coding=utf-8
from prettytable import PrettyTable
from sympy import symbols, integrate
import numpy as np
from math import exp, sqrt


def func_1(x, u):
    return x * x + u * u


def func_2(x, u):
    return x + u


class KoshiTask:
    def __init__(self, func, x0, u_xo, end, step):
        self.func = func  # любая функция из двух аргументов
        self.x0 = x0  # начальная точка
        self.u_x0 = u_xo  # значение в начальной точке
        self.end = end  # верхний предел
        self.step = step  # шаг
        self.X = np.arange(x0 + step, end + step, step)

    def picard(self, s):
        u_list = []
        t = symbols('t')
        for x in self.X:
            u = self.u_x0
            for i in range(s):
                res = self.u_x0 + integrate(self.func(t, u), (t, 0, x))
                u = integrate(self.func(t, u), t)
            u_list.append(float(res))
        return u_list

    def picard_in_point(self, s, x):
        t = symbols('t')
        u = self.u_x0
        for s in range(s):
            res = self.u_x0 + integrate(self.func(t, u), (t, 0, x))
            u = integrate(self.func(t, u), t)
            # print("Значение U:\n", u)
        return res
#7,347007089256453e49
    # Явный эйлер
    def euler_explicit(self):
        u_list = []
        u_prev = self.u_x0
        x_prev = self.x0
        for x in self.X:
            u_cur = u_prev + self.step * self.func(x_prev, u_prev)
            u_prev = u_cur
            x_prev = x
            u_list.append(u_cur)
        return u_list

    def runge_kutta(self, alpha):
        u_list = []
        u_prev = self.u_x0
        x_prev = self.x0

        a = alpha
        h = self.step
        k = h / (2 * a)
        for x in self.X:
            in_brackets = (1 - a) * self.func(x_prev, u_prev) + \
                          a * self.func(x_prev + k, u_prev + self.func(x_prev, u_prev) * k)
            u_cur = u_prev + self.step * in_brackets
            u_prev = u_cur
            x_prev = x
            u_list.append(u_cur)
        return u_list

    # печать для любой пользовательской функции из 2 аргуметов
    def print_table(self, s=6, alpha=0.5):
        table = PrettyTable()
        col_names = ['x', "Пикар", "Явный Эйлер", "Рунге-Кутта"]
        table.add_column(col_names[0], ["{:0.3f}".format(k) for k in ([0] + self.X.tolist())])
        table.add_column(col_names[1], ["{:0.4e}".format(k) for k in ([0] + self.picard(s))])
        table.add_column(col_names[2], ["{:0.4e}".format(k) for k in ([0] + self.euler_explicit())])
        table.add_column(col_names[3], ["{:0.4e}".format(k) for k in ([0] + self.runge_kutta(alpha))])
        print(table)

    # частные решения
    # -->
    # для функции x + u
    def __euler_implicit_sum(self):
        u_list = []
        u_prev = self.u_x0
        x_prev = self.x0
        for x in self.X:
            u_cur = (u_prev + self.step * x) / (1 - self.step)
            u_prev = u_cur
            #x_prev = x
            u_list.append(u_cur)

        return u_list

    # аналитическое решение x + u
    def __analit_solution(self):
        u_list = []
        for x in self.X:
            u_cur = exp(x) - x - 1
            u_list.append(u_cur)
        return u_list

    # Для функции x^2 + u^2
    def __euler_implicit_sum_sq(self):
        u_list = []
        u_prev = self.u_x0
        x_prev = self.x0
        correct_step = 1
        for x in self.X:
            if correct_step:
                absolute_step = (-4 * u_prev + sqrt((4 * u_prev) ** 2 + 16 * x * x)) / (8 * x * x)
                if self.step > absolute_step:
                    correct_step = 0
                    u_list.append(-1)
                    continue
                u_cur = (1 - sqrt(1 - 4 * self.step * (u_prev + self.step * (x_prev ** 2)))) / (2 * self.step)
                u_prev = u_cur
                x_prev = x
                u_list.append(u_cur)
            else:
                u_list.append(-1)

        return u_list

    # печать для x + u, используя неявный метод
    def print_sum(self, s=5, alpha=1 / 2):
        table = PrettyTable()
        col_names = ['x', "Пикар", "Явный Эйлер", "Неявный Эйлер", "Рунге-Кутта", "Аналитическое решение"]

        table.add_column(col_names[0], ["{:0.3f}".format(k) for k in ([0] + self.X.tolist())])
        # table.add_column(col_names[1], ["{:0.4e}".format(k) for k in ([0] + self.picard(s))])
        table.add_column(col_names[2], ["{:0.4e}".format(k) for k in ([0] + self.euler_explicit())])
        table.add_column(col_names[3], ["{:0.4e}".format(k) for k in ([0] + self.__euler_implicit_sum())])
        table.add_column(col_names[4], ["{:0.4e}".format(k) for k in ([0] + self.runge_kutta(alpha))])
        table.add_column(col_names[5], ["{:0.4e}".format(k) for k in ([0] + self.__analit_solution())])
        print(table)

    # печать для x^2 + u^2, используя неявный метод
    def print_sum_sq(self, s=5, alpha=1 / 2):
        table = PrettyTable()
        col_names = ['x', "Пикар", "Явный Эйлер", "Неявный Эйлер", "Рунге-Кутта"]#, "Аналитическое решение"]

        table.add_column(col_names[0], ["{:0.3f}".format(k) for k in ([0] + self.X.tolist())])
        table.add_column(col_names[1], ["{:0.4e}".format(k) for k in ([0] + self.picard(s))])
        table.add_column(col_names[2], ["{:0.4e}".format(k) for k in ([0] + self.euler_explicit())])
        table.add_column(col_names[3], ["{:0.4e}".format(k) for k in ([0] + self.__euler_implicit_sum_sq())])
        table.add_column(col_names[4], ["{:0.4e}".format(k) for k in ([0] + self.runge_kutta(alpha))])
        # table.add_column(col_names[4], ["{:0.4e}".format(k) for k in ([0] + self.__analit_solution())])
        print(table)

    def __print_sum(self):
        pass


def main():
    func = func_1  # пользовательская функция
    x0 = 0
    u_x0 = 0 # значение в начальной точке
    end = 1
    step = 0.0001
    alpha = 1 / 2
    s = 6

    view = 3
    '''
    view - вывод таблиц
    1 - для любой функции 
    2 - частный случай для x + u с Неявным Эйлером и Аналитическим решением
    3 - частный случай для x^2 + u^2 с Неявным Эйлером
    '''

    koshi = KoshiTask(func, x0, u_x0, end, step)
    # if view == 1:
    #     print("\nПользовательская функция\n")
    #     koshi.print_table(s, alpha)
    # elif view == 2:
    #     print("\nU(x, u) = x + u\n")
    #     koshi.func = func_2
    #     koshi.print_sum()
    # elif view == 3:
    #     print("\nU(x, u) = x^2 + u^2\n")
    #     koshi.func = func_1
    #     koshi.print_sum_sq()

    picard_in_point = koshi.picard_in_point(s, 2)
    print("Значение функции в точке методом Пикара: %e" % picard_in_point)


if __name__ == "__main__":
    main()
