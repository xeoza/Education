package main

import (
	"fmt"
	"math"
)

type Spline struct {
	Base
}

func New() *Spline {
	lg := &Spline{}
	return lg
}

func (lg *Spline) InterpolateSpline(val float64) float64 {
	size_a := len(lg.X)
	result := 0.0
	lg.a = make([]float64, size_a + 1)
	lg.b = make([]float64, size_a + 1)
	lg.c = make([]float64, size_a + 1)
	lg.d = make([]float64, size_a + 1)
	for i:=0; i < size_a; i++{
		lg.a[i] = lg.Y[i]
	}
	h := make([]float64, size_a)
	l := make([]float64, size_a)
	for i:=1; i < size_a; i++{
		h[i] = lg.X[i]-lg.X[i-1]
		l[i] = (lg.Y[i] - lg.Y[i-1]) / h[i]
	}
	delta := make([]float64, size_a)
	lamda := make([]float64, size_a)
	delta[1] = -h[2] / (2 * (h[1] + h[2]))
	lamda[1] = 1.5 * (l[2] - l[1]) / (h[1] + h[2])
	for i:=3; i < size_a; i++{
		delta[i-1] = -h[i] / (2*h[i-1] + 2*h[i] + h[i-1] * delta[i-2])
		lamda[i - 1] = (3 * l[i] - 3 * l[i - 1] - h[i - 1] * lamda[i - 2]) /
                (2 * h[i - 1] + 2 * h[i] + h[i - 1] * delta[i - 2]);
	}
	lg.c[0] = 0;
    lg.c[size_a - 1] = 0;
    for i:=size_a-1; i >= 2; i--{
    	lg.c[i-1] = delta[i-1] * lg.c[i] + lamda[i-1]
    }
    for i:=1; i < size_a; i++{
    	lg.d[i] = (lg.c[i] - lg.c[i-1]) / (3 * h[i]);
        lg.b[i] = l[i] + (2 * lg.c[i] * h[i] + h[i] * lg.c[i-1]) / 3;
    }



    for i:=1; i < size_a; i++{
    	if(val >= lg.X[i-1] && val <= lg.X[i]){
    		result = lg.a[i] + lg.b[i] * (val - lg.X[i]) + lg.c[i] *
                    math.Pow(val - lg.X[i], 2) + lg.d[i] * math.Pow(val - lg.X[i], 3);
            
            break;
    	}
    }
	return result
}






func (lg *Spline) Validate(valx, valy, estz float64, nx, ny int) (int, int, float64, error) {

	for i := 0; i < len(lg.X); i++ {
		for j := 0; j < len(lg.X); j++ {
			if i != j {
				if lg.X[i]-lg.X[j] == 0 {
					return nx,ny,estz,fmt.Errorf("There are at least 2 same X values.")
				}
			}
		}
	}

	if valx < lg.XYPairs[0].X {
		return nx,ny,estz,fmt.Errorf("Value to interpolate is too small and not in range")
	}

	if valx > lg.XYPairs[len(lg.XYPairs)-1].X {
		return nx,ny, estz, fmt.Errorf("Value to interpolate is too large and not in range")
	}

	if nx > 3{
		nx = 3
	}
	if ny > 3{
		ny = 3
	}
	if nx == 1 || ny == 1{
		estz += 0.5
	}
	return nx, ny, estz, nil
}
