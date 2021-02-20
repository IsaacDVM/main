// x*1 + y*0,5 + z*0,2 + k*0,1 + l*0,05 + m*0,02 + n*0,01 = 2
// 100x + 50y + 20z + 10k + 5l + 2m + n = 200

package main

import (
	"fmt"
)

func main() {
	var n int
	count := 0
	for v := 0; v <= 1; v++ {

		for x := 0; x <= 2; x++ {
			for y := 0; y <= 4; y++ {
				for z := 0; z <= 10; z++ {
					for k := 0; k <= 20; k++ {
						for l := 0; l <= 40; l++ {
							for m := 0; m <= 100; m++ {
								n = 200 - 200*v - 100*x - 50*y - 20*z - 10*k - 5*l - 2*m
								if n >= 0 {
									count++
									fmt.Printf("%v£2 + %v×£1 + %v×50p + %v×20p + %v×10p + %v×5p + %v×2p + %v×1p y es la combinación número %v\n", v, x, y, z, k, l, m, n, count)
								}
							}

						}
					}
				}
			}
		}
	}
}
