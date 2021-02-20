package main

import (
	"fmt"
	"os"
)

// este es el límite donde buscas primos. El techo
const lim = 100000000

func main() {
	var testa, testb, testc []uint32
	var i uint32 = 0
	for ; i < lim; i++ {
		testa = append(testa, 0)
		testb = append(testb, 0)
		testc = append(testc, 0)
	}
	//empecemos por cargar las ecuaciones diofánticas
	// En la posición cero está la incidencia de la solución 0. En la uno la de uno. etc.
	for x := 0; x <= lim; x++ {
		fmt.Println(float64(x*100)/float64(lim), "%")
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
	dataa, _ := os.Create("/home/isaac/scripts/main/go/primos/test/dataa.dat")
	defer dataa.Close()
	fmt.Fprintf(dataa, "%v\n", testa)
	dataa.Sync()
	datab, _ := os.Create("/home/isaac/scripts/main/go/primos/test/datab.dat")
	defer datab.Close()
	fmt.Fprintf(datab, "%v\n", testb)
	datab.Sync()
	datac, _ := os.Create("/home/isaac/scripts/main/go/primos/test/datac.dat")
	defer datac.Close()
	fmt.Fprintf(datac, "%v\n", testc)
	datac.Sync()
}
