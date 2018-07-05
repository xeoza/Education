from math import sqrt
import copy
import numpy as np

# 0 - вырожденный
# -1 - невыпуклый
# 1 - выпуклый
def check_convex(polygon):
    n = len(polygon)
    if n < 3:
        return 0

    flag = 0
    for i in range(n):
        j = (i + 1) % n
        k = (i + 2) % n
        z = ((polygon[j][0] - polygon[i][0]) *
             (polygon[k][1] - polygon[j][1]))
        z -= ((polygon[j][1] - polygon[i][1]) *
              (polygon[k][0] - polygon[j][0]))
        if z < 0:
            flag |= 1
        elif z > 0:
            flag |= 2

        if flag == 3:
            return -1

    if flag != 0:
        return 1
    else:
        return 0


def mul_vec(a,b):
    res = [0, 0, 0]
    res[0] = a[1]*b[2] - b[1]*a[2]
    res[1] = b[0]*a[2] - a[0]*b[2]
    res[2] = a[0]*b[1] - a[1]*b[0]
    return res


def diff_vec(p1, p2):
    return [p2[0]-p1[0], p2[1]-p1[1], p2[2]-p1[2]]


def mul_scalar(a,b):
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2]


def P(t, p1, p2):
    tmp = [0,0,0]
    tmp[0] = p1[0] + round((p2[0]-p1[0])*t)
    tmp[1] = p1[1] + round((p2[1]-p1[1])*t)
    tmp[2] = p1[2] + round((p2[2]-p1[2])*t)
    return tmp


def norm_vecs(res, pol, direction):
    n = len(pol) - 1
    b = [0,0,0]
    for i in range(n):
        b = diff_vec(pol[i+1], pol[i])
        if direction == -1:
            res.append([b[1], -b[0], 0])
        else:
            res.append([-b[1], b[0], 0])


def sign(x):
    return int((x > 0) - (x < 0))


def get_direction(pol):
    a = diff_vec(pol[1], pol[0])
    b = [0,0,0]
    n = len(pol)
    tmp = [0,0,0]
    res = 0
    for i in range(1, n-1, 1):
        b = diff_vec(pol[i+1], pol[i])
        tmp = mul_vec(a,b)
        if res == 0:
            res = sign(tmp[2])
        if tmp[2] and res != sign(tmp[2]):
            return 0
        a = b
        
    return res


def get_line_coefs(x1,y1,x2,y2):
    return ((y1-y2), (x2-x1), (x1*y2 - x2*y1))


def get_norm_dot(x,y,p1,p2):
    a,b,c = get_line_coefs(p1[0],p1[1],p2[0],p2[1])

    if a == 0 and b == 0:
        return -1,-1
    
    x = (b*(b*x - a*y) - a*c)/(a*a + b*b)
    y = (a*(-b*x + a*y) - b*c)/(a*a + b*b)

    return x,y


def get_norm(x,y,p1,p2):
    a,b,c = get_line_coefs(p1[0],p1[1],p2[0],p2[1])

    if a == 0 and b == 0:
        return -1

    return abs(a*x+b*y+c)/sqrt(a*a+b*b)


def is_visible(p1, c1, norm):
    vec = diff_vec(p1, c1)
    res = mul_scalar(vec, norm)
    return res > 0


def cut_polygon(pol,cutter,normVect,resPol):
    n = len(cutter) - 1
    F = 0; S = 0; I = 0
    Dsk = 0; Wsk = 0; t = 0
    for i in range(n):
        m = len(pol)
        for j in range(m):
            if j == 0:
                F = pol[j]
            else:
                D = diff_vec(pol[j],S)
                Dsk = mul_scalar(D, normVect[i])
                if Dsk != 0:
                    W = diff_vec(S, cutter[i])
                    Wsk = mul_scalar(W, normVect[i])
                    t = -Wsk / Dsk
                    if (t >= 0 and t <= 1):
                        I = P(t, S, pol[j])
                        resPol.append(I)
            S = pol[j]
            if is_visible(S, cutter[i], normVect[i]):
                resPol.append(S)
        pol = copy.deepcopy(resPol)
        if len(pol) != 0:
            pol.append(pol[0]) 
        resPol.clear()
    resPol = copy.deepcopy(pol)
    return resPol


if __name__ == "__main__":
    print(get_line_coefs(2,2,2,4))
    print(get_norm_dot(0,0,[2,2],[2,4]))
    print(get_norm(0,0,[2,2],[2,4]))
