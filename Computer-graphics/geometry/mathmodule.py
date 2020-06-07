# Module for gui.py

def dist(x1,y1,x2,y2):
    return (((x1 - x2)**2) + ((y1 - y2)**2))**(1 / 2)


# Checks if the triangle created by input points is real
def is_real(xa,ya,xb,yb,xc,yc):
    AB = dist(xa,ya,xb,yb)
    AC = dist(xa,ya,xc,yc)
    BC = dist(xb,yb,xc,yc)
    if (AB + AC) <= BC or (BC + AC) <= AB or (BC + AB) <= AC:
        return False
    else:
        return True


# Checks if the point (x,y) in the triangle
def in_triangle(xa,ya,xb,yb,xc,yc,x,y):
    ab = [xb - xa, yb - ya]
    bc = [xc - xb, yc - yb]
    ca = [xa - xc, ya - yc]
    
    a = (((x - xa) * (ab[1]) - (y - ya) * (ab[0])) *
         ((-ca[0]) * (ab[1]) - (-ca[1]) * (ab[0])) >= 0)
    b = (((x - xb) * (bc[1]) - (y - yb) * (bc[0])) *
         ((-ab[0]) * (bc[1]) - (-ab[1]) * (bc[0])) >= 0)
    c = (((x - xc) * (ca[1]) - (y - yc) * (ca[0])) *
         ((-bc[0]) * (ca[1]) - (-bc[1]) * (ca[0])) >= 0)
    return a == b == c


# Finds points that are in the triangle
# Points - array of N points [ [x0,y0], [x1,y2], ..., [xn,yn] ]
def find_points(points,A,B,C):
    res = []
    for i in points:
        if in_triangle(A[0],A[1],B[0],B[1],C[0],C[1],i[0],i[1]):
            res.append(i)

    return (res,len(res))


# On return:
# A3 - oposite to BC(23)
# B3 - oposite to AC(13)
# C3 - oposite to AB(12)
# CR - center of bisectrises
def bisectrix_f(xa,ya,xb,yb,xc,yc):
    if not is_real(xa,ya,xb,yb,xc,yc):
        return None
    
    AB = dist(xa,ya,xb,yb)  # side12
    BC = dist(xb,yb,xc,yc)  # side23
    AC = dist(xc,yc,xa,ya)  # side31

    La = AB/AC
    Lb = AB/BC
    Lc = AC/BC
    
    A3 = [
        (xb + La*xc)/(1 + La),
        (yb + La*yc)/(1 + La)
        ]

    B3 = [
        (xa + Lb*xc)/(1 + Lb),
        (ya + Lb*yc)/(1 + Lb)
        ]

    C3 = [
        (xa + Lc*xb)/(1 + Lc),
        (ya + Lc*yb)/(1 + Lc)
        ]

    CR = [
        (BC*xa + AC*xb + AB*xc)/(AB+BC+AC),
        (BC*ya + AC*yb + AB*yc)/(AB+BC+AC)
        ]
    
    return (A3,B3,C3,CR)


def make_count(points):
    min_v = 100000000
    min_points = []
    res = []
    for i in range(len(points)-2):
        A = points[i]
        B = points[i+1]
        C = points[i+2]
        
        if is_real(A[0],A[1],B[0],B[1],C[0],C[1]):
            # A3 - oposite to BC(23)
            # B3 - oposite to AC(13)
            # C3 - oposite to AB(12)
            # CR - center of bisectrises
            A3,B3,C3,CR = bisectrix_f(A[0],A[1],B[0],B[1],C[0],C[1])
            cur_points,tmp = find_points(points,A,B,C)

            tmp,n1 = find_points(cur_points,A,C3,CR)
            tmp,n2 = find_points(cur_points,B,C3,CR)
            tmp,n3 = find_points(cur_points,B,A3,CR)
            tmp,n4 = find_points(cur_points,C,A3,CR)
            tmp,n5 = find_points(cur_points,A,B3,CR)
            tmp,n6 = find_points(cur_points,C,B3,CR)

            cur_max = max(n1,n2,n3,n4,n5,n6)
            cur_min = min(n1,n2,n3,n4,n5,n6)
            cur_val = cur_max - cur_min
            if cur_val < min_v:
                min_v = cur_val
                min_points = cur_points
                res = [A,B,C,A3,B3,C3,CR]
    for i in res:
        if i in min_points:
            min_points.remove(i)
            
    return res, min_points
        

if __name__ == "__main__":
    points = [ [0,-1], [-2,0], [-2,-2] ]
    res, p = make_count(points)
    print(res,p)
