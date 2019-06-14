package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	counts := make(map[string]int)
	locations := make(map[string]string)
	files := os.Args[1:]
	if len(files) == 0 {
		countLines(os.Stdin, "stdin", counts, locations)
	} else {
		for _, arg := range files {
			f, err := os.Open(arg)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
				continue
			}
			countLines(f, arg, counts, locations)
			f.Close()
		}
	}

	for line, n := range counts {
		if n > 1 {
			fmt.Printf("%d\t%s\t%s\n", n, line, locations[line])
		}
	}
}

func countLines(f *os.File, filename string, counts map[string]int, locations map[string]string) {
	input := bufio.NewScanner(f)
	contains := make(map[string]bool)
	for input.Scan() {
		counts[input.Text()]++
		if !contains[input.Text()] {
			locations[input.Text()] += filename + " "
			contains[input.Text()] = true
		}
	}
}
