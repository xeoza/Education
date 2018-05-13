package main

type interpolator interface {
	InterpolateSpline(float64) float64
}

type validateInterpolator interface {
	interpolator
}


func WithSpline(vi validateInterpolator, valx float64) (float64, error) {
	var result float64
	//nx, ny, estz, err := vi.Validate(valx,valy,estz,nx,ny)
	//if err != nil {
	//	return _, err
	//}
	result = vi.InterpolateSpline(valx)
	return result, nil
}
