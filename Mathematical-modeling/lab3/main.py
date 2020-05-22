import data as d
from calculation import t, collocation
import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    c1, c2, c3 = collocation(6, 7, 8)

    h = 1e-1
    
    x_axis = []
    y_axis = []

    x = d.x0
    while x < d.l+h:
        x_axis.append(x)
        y_axis.append(t(x, c1, c2, c3))

        x += h

    plt.plot(x_axis, y_axis)
    plt.show()
        
