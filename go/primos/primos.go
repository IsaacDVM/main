package main

import (
	"fmt"
	"os"
)

// este es el límite donde buscas primos. El techo
const lim = 100000000

var num []uint32
var criba []bool

func main() {
	var testa, testb, testc []uint32
	var i uint32 = 0
	for ; i < lim; i++ {
		testa = append(testa, 0)
		testb = append(testb, 0)
		testc = append(testc, 0)
		num = append(num, i)
		criba = append(criba, false)
	}
	criba[2] = true
	criba[3] = true
	criba[5] = true
	//empecemos por cargar las ecuaciones diofánticas
	// En la posición cero está la incidencia de la solución 0. En la uno la de uno. etc.
	for x := 0; x <= lim; x++ {
		for y := 0; y <= lim; y++ {
			if 3*x*x-y*y >= lim || 3*x*x-y*y < 0 {

			} else if x > y {
				testc[3*x*x-y*y]++
			}
			if 3*x*x+y*y >= lim {

			} else {
				testb[3*x*x+y*y]++
			}
			if 4*x*x+y*y >= lim {

			} else {
				testa[4*x*x+y*y]++
			}
		}
	}
	i = 3
	for ; i < lim; i++ {
		mod := (i % 60)
		if mod == 1 || mod == 13 || mod == 17 || mod == 29 || mod == 37 || mod == 41 || mod == 49 || mod == 53 {
			if testa[i]%2 != 0 {
				criba[i] = true
			}
		} else if mod == 7 || mod == 19 || mod == 31 || mod == 43 {
			if testb[i]%2 != 0 {
				criba[i] = true
			}
		} else if mod == 11 || mod == 23 || mod == 47 || mod == 59 {
			if testc[i]%2 != 0 {
				criba[i] = true
			}
		} else {

		}
	}
	f, _ := os.Create("/home/isaac/scripts/main/go/primos/primosE8.csv")
	defer f.Close()
	i = 2
	order := 0
	for ; i < lim; i++ {
		if criba[i] == true {
			var vol uint32 = 1
			for vol*i*i < lim {
				criba[vol*i*i] = false
				vol++
			}
			order++
			fmt.Fprintf(f, "%v, %v\n", order, num[i])
		}
	}
	f.Sync()
}
