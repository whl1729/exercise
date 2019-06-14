package main

import "fmt"

func main() {
	num := 1729
	fmt.Printf("%v\t%d\t%x\t%o\t%b\n", num, num, num, num, num)
	fmt.Printf("%t\n", num)
	fmt.Printf("%T\n", num)

	letter := 'w'
	word := "hello world"

	fmt.Printf("%q\t%q\n", letter, word)
}
