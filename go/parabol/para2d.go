package main

import (
	"fmt"
	"os"
)

//all in I.S.
const ti = 0.0
const tf = 5.8
const g = -9.81
const deltaT = 0.0001

type part struct {
	pos  []float64
	vel  []float64
	time float64
	mass float32
}

func main() {
	p1 := part{
		pos:  []float64{0.0, 0.0},
		vel:  []float64{5.7, 1.2},
		time: 0.0,
		mass: 1.8,
	}
	fmt.Println(p1)
	f, _ := os.Create("/home/isaac/tmp/datapara2d")
	defer f.Close()
	fmt.Fprintln(f, "t(s)\tx(m)\ty(m)\tVx(m/s)\tVy(m/s)")
	for t := ti; t <= tf; t = t + deltaT {
		fmt.Fprintf(f, "%.5f,%.5f,%.5f,%.5f,%.5f\n", p1.time, p1.pos[0], p1.pos[1], p1.vel[0], p1.vel[1])
		p1.pos[0] = p1.pos[0] + p1.vel[0]*deltaT
		p1.pos[1] = p1.pos[1] + p1.vel[1]*deltaT
		p1.vel[1] = p1.vel[1] + g*deltaT
		p1.time = t
	}
	f.Sync()
}
