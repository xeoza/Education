package main

import (
	"fmt"
)

type Base struct {
	XYPairs []CoordinatePair
	X       []float64
	Y       []float64
	a, b, c, d []float64
}

func (b *Base) Fit(x, y []float64) error {
	if len(x) != len(y) {
		return fmt.Errorf("X and Y sizes do not match\n")
	}
	b.X = x
	b.Y = y
	b.XYPairs = SlicesToCoordinatePairs(x, y)
	SortCoordinatePairs(b.XYPairs)
	return nil
}
