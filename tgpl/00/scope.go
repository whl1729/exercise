package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var start int
	if len(os.Args) != 0 {
		var err error
		start, err = strconv.Atoi("1729")
		if err != nil {
			fmt.Println("convert \"1729\" to integer failed.")
		}

		fmt.Println("Inside if, start=", start)
	}

	fmt.Println("Outside if, start=", start)
}
