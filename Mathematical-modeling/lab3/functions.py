from math import exp, log
import data as d

def alpha(x):
    return d.a_alpha/(x-d.b_alpha)

def k(x):
    return d.ak/(x-d.bk)


def u0(x):
    return (d.F0/(2*d.k0) - x)**2 + d.kN/d.alphaN * (d.F0/d.k0 - 2*d.l) - (d.F0/(2*d.k0) - d.l)**2 + d.Tenv
def u0I(x):
    return 2*x - d.F0/d.k0
def u0II(x):
    return 2

def u1(x):
    return (x**2 - d.l**2)**2
def u1I(x):
    return 4*x**3 - 4*x*d.l**2
def u1II(x):
    return 12*x**2 - 4*d.l**2

def u2(x):
    return (x**3 - d.l**3)**3
def u2I(x):
    return 9*x**8 - 18*x**5*d.l**3 + 9*x**2*d.l**6
def u2II(x):
    return 72*x**7 - 90*x**4*d.l**3 + 18*x*d.l**6

def u3(x):
    return x**3 * (x**2 - d.l**2)**2
def u3I(x):
    return x**2 * (x**2 - d.l**2) * (7*x**2 - 3*d.l**2)
def u3II(x):
    return 42*x**5 - 40*d.l**2*x**3 + 6*d.l**4*x

