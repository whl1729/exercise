package main

import "fmt"
import "./tempconv"

func main() {
	fmt.Printf("%v\n", tempconv.AbsoluteZeroC)
	fmt.Printf("%v\n", tempconv.AbsoluteZeroK)
	fmt.Printf("%v\n", tempconv.CToK(tempconv.AbsoluteZeroC))
	fmt.Printf("%v\n", tempconv.KToC(tempconv.BoilingK))
}
