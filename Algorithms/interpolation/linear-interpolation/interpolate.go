package main

type interpolator interface {
	Interpolate(int, float64) float64
}

type validator interface {
	Validate(float64) error
}

type validateInterpolator interface {
	interpolator
	validator
}

type interpolator2 interface {
	Interpolate2(int, float64) float64
}

type validateInterpolator2 interface {
	interpolator2
	validator
}

func WithSingle(vi validateInterpolator, val float64, n int) (float64, error) {
	var est float64

	err := vi.Validate(val)
	if err != nil {
		return est, err
	}

	est = vi.Interpolate(n, val)
	return est, nil
}

func WithSingle2(vi validateInterpolator2, val float64, n int) (float64, error) {
	var est float64

	err := vi.Validate(val)
	if err != nil {
		return est, err
	}

	est = vi.Interpolate2(n, val)
	return est, nil
}

