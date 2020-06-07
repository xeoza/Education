package main

type interpolator interface {
	Interpolate(int, float64) float64
}

type validator interface {
	Validate(float64 ,float64, float64, int, int) (int, int, float64, error)
}

type validateInterpolator interface {
	interpolator
	validator
}


func WithMulti(vi validateInterpolator, valx, valy float64, nx, ny int) (float64, error) {
	var estx, esty float64
	estz := 0.0
	nx, ny, estz, err := vi.Validate(valx,valy,estz,nx,ny)
	if err != nil {
		return -1, err
	}
	arr := make([]float64, nx)
	for i:=0; i < nx; i++{
		arr[i] = vi.Interpolate(nx, valx)
	}
	estx = vi.Interpolate(nx, valx)
	esty = vi.Interpolate(ny, valy)
	estz += f(estx,esty)
	return estz, nil
}
