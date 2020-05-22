import data as d
from functions import *
import numpy

def t(x, c1, c2, c3):
    return u0(x) + c1*u1(x) + c2*u2(x) + c3*u3(x)

def p(x, u, uI, uII):
    temp = 2*alpha(x)/d.R
    return k(x) * uII(x) - d.k0/((x-d.kN)**2) * uI(x) - temp*u(x)

def m(x):
    temp = 2*alpha(x)/d.R
    return k(x)*u0II(x) - d.k0/((x-d.kN)**2) * u0I(x) - temp*u0(x) + temp*d.Tenv

def collocation(x1, x2, x3):
    M3 = numpy.array([  [p(x1, u1, u1I, u1II), p(x1, u2, u2I, u2II), p(x1, u3, u3I, u3II)], 
                        [p(x2, u1, u1I, u1II), p(x2, u2, u2I, u2II), p(x2, u3, u3I, u3II)], 
                        [p(x3, u1, u1I, u1II), p(x3, u2, u2I, u2II), p(x3, u3, u3I, u3II)]])
    v3 = numpy.array([m(x1), m(x2), m(x3)])

    coeffs = numpy.linalg.solve(M3, v3)

    return coeffs[0], coeffs[1], coeffs[2]
