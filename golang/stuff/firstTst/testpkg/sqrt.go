package testpkg

import (
	"math"
)

func Sqrt(x float64) float64 {
	var z float64 = 1
	var prevZ = z
	var done bool = false
	for done != true {
		z -= (z*z - x) / (2 * z)
		if math.Abs(z-prevZ) < 0.00000000001 {
			done = true
		} else {
			prevZ = z
		}
	}

	return z
}

