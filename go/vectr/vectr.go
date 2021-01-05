package main

import (
	"fmt"
	"math"
)

type vectr struct {
	x float64
	y float64
	z float64
}

var ihat vectr = vectr{
	x: 1.0,
	y: 0.0,
	z: 0.0,
}

var jhat vectr = vectr{
	x: 0.0,
	y: 1.0,
	z: 0.0,
}

var khat vectr = vectr{
	x: 0.0,
	y: 0.0,
	z: 1.0,
}

func (a vectr) mod() float64 {
	return math.Sqrt(a.x*a.x + a.y*a.y + a.z*a.z)
}

func xvec(a, b vectr) vectr {
	c := vectr{
		x: a.y*b.z - a.z*b.y,
		y: a.z*b.x - a.x*b.z,
		z: a.x*b.y - a.y*b.x,
	}
	return c
}

func xesc(a, b vectr) float64 {
	return (a.x*b.x + a.y*b.y + a.z*b.z)
}

func angle(a, b vectr) float64 {
	return math.Acos(xesc(a, b) / (a.mod() * b.mod()))
}

func (a vectr) axang() [3]float64 {
	c := [3]float64{0, 0, 0}
	c[0] = angle(a, ihat)
	c[1] = angle(a, jhat)
	c[2] = angle(a, khat)
	return c
}

func main() {
	v1 := vectr{
		x: 2.0,
		y: 5.0,
		z: -2.0,
	}
	v2 := vectr{
		x: 0.0,
		y: 5.0,
		z: -2.0,
	}
	fmt.Println(v1)
	fmt.Printf("%T\n", v1)
	fmt.Println(ihat)
	fmt.Printf("%T\n", ihat)
	fmt.Printf("%.5f\n", v1.mod())
	fmt.Println(xesc(v1, v2))
	fmt.Println(xvec(v1, v2))
	fmt.Println(angle(v1, v2))
	fmt.Println(v1.axang(), "\t", v2.axang())
}
