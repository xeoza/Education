package main

import (
	"sort"
)

type CoordinatePair struct {
	X float64
	Y float64
}

func SortCoordinatePairs(cp []CoordinatePair) {
	sort.Slice(cp, func(i, j int) bool {
		return cp[i].X < cp[j].X
	})
}

func SlicesToCoordinatePairs(x, y []float64) []CoordinatePair {
	cp := make([]CoordinatePair, len(x))
	for i := 0; i < len(x); i++ {
		cp = append(cp, CoordinatePair{X: x[i], Y: y[i]})
	}
	return cp
}
