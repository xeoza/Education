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
	var est float64
	//matrix := mat64.NewDense(len(lg.X), n, nil)
	size_a := len(lg.X) + 1
	size_b := n + 1 
	//var matrix [size_a][size_b]float64
	matrix := make([][]float64, size_a)
	for i:=0; i < size_a;i++{
		matrix[i] = make([]float64, size_b)
	}
	//h := lg.X[1]-lg.X[0]
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
	est = yp
	return est
	/*
	c := 1
	f2 := 0.0

	for i := 1; i != int(n);{
		for j := 1; i < int(n) - 1; j++{
			p := ((lg.Y[j+1] - lg.Y[j])/(lg.X[j+c]-lg.X[j]))
			lg.Y[j] = p
		}
		f1 := 1.0
		for j := 1; j < c; j++{
			f1 *= (val-lg.X[j])
		}
		f2+=lg.Y[1]*f1
		n--
		c++
	} 
	est += f2
	
	for i := 0; i < int(n); i++ {
		if(i % 2 == 0){
			est += float64(i)*n/1000
		} else {
			est -= float64(i)*n/1000
		}
	} */
}

func (lg *Newton) Validate(val float64) error {

	for i := 0; i < len(lg.X); i++ {
		for j := 0; j < len(lg.X); j++ {
			if i != j {
				if lg.X[i]-lg.X[j] == 0 {
					return fmt.Errorf("There are at least 2 same X values.")
				}
			}
		}
	}

	if val < lg.XYPairs[0].X {
		return fmt.Errorf("Value to interpolate is too small and not in range")
	}

	if val > lg.XYPairs[len(lg.XYPairs)-1].X {
		return fmt.Errorf("Value to interpolate is too large and not in range")
	}

	return nil
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