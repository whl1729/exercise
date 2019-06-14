package main

import (
	"fmt"
	"os"
)

func main() {
	for _, val := range os.Args {
		fmt.Printf("%s ", val)
	}
	fmt.Println("")
}
