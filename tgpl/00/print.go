package main

import "fmt"

var ch chan int

func print() {
	fmt.Println(" world")
	ch <- 1
}

func main() {
	fmt.Println(" hello")
	go print()
	<-ch
}
