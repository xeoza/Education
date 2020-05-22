from math import pi, exp
import numpy as np

from tables import *
from simpson import *
from interpol import *
from runge_kutta import *


class Circuit(object):
    """ класс для расчёта схемы """

    def __init__(self, params):
        tables = Tables()
        self.params = params

        self.I = tables.get_I()
        self.T0 = tables.get_T0()
        self.m = tables.get_m()

        self.log_T = tables.get_log_T()
        self.log_sigma = tables.get_log_sigma()

        self.len1 = len(self.I)
        self.len2 = len(self.log_T)

        self.time = np.arange(0, self.params.end, self.params.step)

    def calc_Rp(self, I_prev):
        #return 0.0
        k = 2 * pi * pow(self.params.R, 2)
        return self.params.Le / (k * simpson(self.sigma_func, 0, 1, I_prev))

    def sigma_func(self, z, I_prev):
        T0 = interpolation(self.I, self.T0, self.len1, I_prev, self.params.newton_pow)
        m = interpolation(self.I, self.m, self.len1, I_prev, self.params.newton_pow)
        T = T0 + (self.params.Tw - T0) * pow(z, m)
        #print(T0, m, T0)

        log_sigma = interpolation(self.log_T, self.log_sigma, self.len2, log(T), self.params.newton_pow)
        #print(log_sigma)
        sigma = exp(log_sigma)

        return sigma * z

    def dI_dt(self, t, Uc, I):
        Rp = self.calc_Rp(I)
        return (Uc - (Rp + self.params.Rk) * I) / self.params.Lk

    def dUc_dt(self, t, Uc, I):
        return -I / self.params.Ck

    def solve_system(self):
        solver = RungeKutta(0, self.params.end, self.params.step)
        res_Uc = [self.params.Uc0]
        res_I = [self.params.I0]
        res_Rp = [self.calc_Rp(res_I[0])]

        for i in range(1, len(self.time)):
            Uc, I = solver.uv_system(self.dUc_dt, self.dI_dt, self.time[i - 1], res_Uc[i - 1], res_I[i - 1])
            Rp = self.calc_Rp(I)

            res_Uc.append(Uc)
            res_I.append(I)
            res_Rp.append(Rp)

        return self.time, res_Uc, res_I, res_Rp
