package main

import (
	"fmt"
	"os"
)

type persona struct {
	nombre   string
	apellido string
	sabores  []string
}

func main() {
	p1 := persona{
		nombre:   "Cristina",
		apellido: "Fernández",
		sabores:  []string{"limón", "pistacho", "turrón", "fresa"},
	}
	p2 := persona{
		nombre:   "León",
		apellido: "del Valle",
		sabores:  []string{"limón", "chocolate", "pistacho", "fresa", "nata", "vainilla", "stracciatella"},
	}
	fmt.Printf("A %v %v le gustan mucho los helados de", p1.nombre, p1.apellido)
	for i, v := range p1.sabores {
		if i == len(p1.sabores)-2 {
			fmt.Printf(" %v", v)
		} else if i == len(p1.sabores)-1 {
			fmt.Printf(" y %v\n", v)
		} else {
			fmt.Printf(" %v,", v)
		}
	}

	fmt.Printf("A %v %v le gustan mucho los helados de", p2.nombre, p2.apellido)
	for i, v := range p2.sabores {
		if i == len(p2.sabores)-2 {
			fmt.Printf(" %v", v)
		} else if i == len(p2.sabores)-1 {
			fmt.Printf(" y %v\n", v)
		} else {
			fmt.Printf(" %v,", v)
		}
	}
	miMap := map[string]persona{
		p1.apellido: p1,
		p2.apellido: p2,
	}
	f, _ := os.Create("/home/isaac/tmp/log")
	defer f.Close()
	fmt.Fprintln(f, miMap)
	for k, v := range miMap {
		fmt.Fprintln(f, k, v.nombre, v.apellido)
		for i, val := range v.sabores {
			fmt.Fprintln(f, i, val)
		}
	}
	f.Sync()
}
