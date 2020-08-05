package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage: ./split word")
		return
	}

	input := os.Args[1]
	fmt.Printf("input: %s\n", input)

	w := strings.Split(input, "-")
	for _, c := range w {
		fmt.Printf("cur: %s\n", c)
	}
}
