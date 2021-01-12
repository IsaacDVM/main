package main

import "fmt"

func max(x, y int) int {
	if x >= y {
		return x
	}
	return y
}

func sum(a, b []byte) []byte {
	//el size no sirve de nada porque asumo que b es siempre de mayor tamaño que a
	size := max(len(a), len(b))
	var sol []byte
	for z := 0; z < size; z++ {
		sol = append(sol, 0)
	}
	//creo elslice de bytes para que sea más fácil y no trate de meter nada fuera de índice
	for i := range b {
		if i < len(a) && i < len(b) {
			sol[i] += (b[i] + a[i]) % 10
			if (b[i]+a[i])/10 >= 1 {
				if i == len(b)-1 {
					sol = append(sol, (b[i]+a[i])/10)
				} else {
					sol[i+1] += (b[i] + a[i]) / 10
				}
			}
			// esta parte me salió de chiripa. Me di cuenta de que había posiciones en el slice que eran 10. Cosa que yo no había tenido en cuenta.
			if sol[i] == 10 {
				if i == len(b)-1 {
					sol[i] = 0
					sol = append(sol, 1)
				} else {
					sol[i] = 0
					sol[i+1]++
				}
			}
		} else {
			sol[i] += b[i]
		}

	}
	return sol
}

func main() {
	fibon1 := []byte{1}
	fibon2 := []byte{1}
	cont := 2
	var fibon []byte
	//un número con 1000 dígitos no entra en un int64. Así que hay que hacer algo para crearlo. He creado un slice de bytes.
	for len(fibon) <= 1000 {
		fibon = sum(fibon1, fibon2)
		// si imprimiese todos trataría de imprimir índices negativos y todo se va al traste
		if len(fibon) >= 3 {
			fmt.Printf("El valor %v de la serie de fibonacci vale %v,%v%v·10^(%v) y tiene %v dígitos\n", cont+1, fibon[len(fibon)-1], fibon[len(fibon)-2], fibon[len(fibon)-3], len(fibon), len(fibon))
		}
		fibon1 = fibon2
		fibon2 = fibon
		cont++
	}
}
