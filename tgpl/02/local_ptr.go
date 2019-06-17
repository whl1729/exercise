package main

import "fmt"

var p = f()

func f() *int {
	v := 1
	return &v
}

func main() {
	fmt.Printf("%v : %T\n", p, p)
	fmt.Printf("%v %v\n", f(), f())
	fmt.Println(f() == f())
}
