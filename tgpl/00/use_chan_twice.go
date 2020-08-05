package main

import "fmt"

var ch = make(chan int)

func write(n int) {
	ch <- n
}

func main() {
	for i := 1; i <= 10; i++ {
		go write(i)
		fmt.Println(<-ch)
	}
}
