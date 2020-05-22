from math import sin, cos, exp

def yprime(t,y):
    return y*(2-sin(t))

def y_exact(t):
    return 2*exp(2*t+cos(t)-1)

def y_init(t):
    return y_exact(t) 


t0 = 0 
y0 = y_exact(t0) 
y1 = y_exact(t0+1) 

def Euler_step(f,t,y,h):
    return y+h*f(t,y) 

def Heun_step(f,t,y,h):
    k1=f(t  , y     ) 
    k2=f(t+h, y+h*k1) 
    return y+0.5*h*(k1+k2) 

def RK2_step(f,t,y,h):
    k1=f(t      , y         ) 
    k2=f(t+0.5*h, y+0.5*h*k1) 
    return y+h*k2 

def RK3_step(f,t,y,h):
    k1=f(t      , y         ) 
    k2=f(t+0.5*h, y+0.5*h*k1) 
    k3=f(t+    h, y+    h*(2*k2-k1)) 
    return y + h*(k1+4*k2+k3)/6 

def RK4_step(f,t,y,h):
    k1=f(t      , y         ) 
    k2=f(t+0.5*h, y+0.5*h*k1) 
    k3=f(t+0.5*h, y+0.5*h*k2) 
    k4=f(t+    h, y+    h*k3) 
    return y + h*(k1+2*k2+2*k3+k4)/6 

methods = { "Euler":Euler_step, "Heun": Heun_step, "RK2": RK2_step, "RK3":RK3_step, "RK4":RK4_step } 

def test_method(name, order, subdivisions):
    stepper = methods[name]
    for N in subdivisions:
        h = 1.0/N 
        y=y0 
        for k in range(N):
            y = stepper(yprime, t0+k*h, y, h)

        print ("%5s:  h=%.2e, N=%5u   y[N]=%.8f, y[N]-y(1)=%.4e, N^%d*(y[N]-y(1))=%.4f" % (name, h, N, y, y-y1, order, N*(y-y1))) 
    print ("----") 

test_method("Euler", 1, [  40, 200, 10000]) 
test_method( "Heun", 2, [ 100, 500,  5000]) 
test_method(  "RK2", 2, [ 100, 500,  5000]) 
test_method(  "RK3", 3, [  20, 250,  5000]) 
test_method(  "RK4", 4, [   8,  50,  1000]) 