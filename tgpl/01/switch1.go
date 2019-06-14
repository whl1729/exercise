package main

import (
	"fmt"
	"math/rand"
)

func main() {
	var heads, tails int = 0, 0

	for i := 0; i < 10000; i++ {
		switch coinflip() {
		case "heads":
			heads++
		case "tails":
			tails++
		default:
			fmt.Println("landed on edge")
		}
	}

	fmt.Printf("heads: %v\ttails: %v\n", heads, tails)
}

func coinflip() string {
	if rand.Intn(2) == 1 {
		return "heads"
	} else {
		return "tails"
	}
}
