package main

import (
	"fmt"
)

func main() {
	a := '@'
	fmt.Printf("%q codificada se expresa: %q\n", a, a)
	fmt.Printf("%q en decimal se expresa: %d\n", a, a)
	fmt.Printf("%q en binario se expresa: %#b\n", a, a)
	fmt.Printf("%q en octal se expresa: %#O\n", a, a)
	fmt.Printf("%q en hexadecimal se expresa: %#X\n", a, a)
	fmt.Printf("%q en UTF8 se expresa: %U\n", a, a)
}
