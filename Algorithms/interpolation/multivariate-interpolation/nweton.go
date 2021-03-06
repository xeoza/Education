package main

import (
	"fmt"
	_"github.com/gonum/matrix/mat64"
)

type Newton struct {
	Base
}

func New() *Newton {
	lg := &Newton{}
	return lg
}

func (lg *Newton) Interpolate(n int, val float64) float64 {
	size_a := len(lg.X) + 1
	size_b := n + 1 
	matrix := make([][]float64, size_a)
	for i:=0; i < size_a;i++{
		matrix[i] = make([]float64, size_b)
	}
	for i:=0;i<len(lg.X)-1;i++{
		matrix[i][1] = lg.Y[i+1]-lg.Y[i]
	}

	for j:=2;j<=n;j++{
		for i:=0;i<=len(lg.X)-j;i++{
			matrix[i][j] = matrix[i+1][j-1] - matrix[i][j-1]
		}
	}
	i:=0
	for ;!(lg.X[i]>val);{
		i++
	}
	i--
	p:=(val-lg.X[i])
	yp := lg.Y[i]
	nr := 1.0
	dr := 1.0
	for k:=1;k<=n;k++{
		nr *= p-float64(k)+1
		dr *= float64(k);
		yp +=(nr/dr)*matrix[i][k]
	}
	return yp
}






func (lg *Newton) Validate(valx, valy, estz float64, nx, ny int) (int, int, float64, error) {

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



func (lg *Newton) Interpolate2(n int, val float64) float64 {
	var est float64

	for i := 0; i < len(lg.X); i++ {
		prod := lg.Y[i]
		for j := 0; j < len(lg.X); j++ {
			if i != j {
				prod = prod * (val - lg.X[j]) / (lg.X[i] - lg.X[j])
			}
		}
		est += prod
	}

	return est
}