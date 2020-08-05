package main

import (
	"fmt"
	"os"
	"strconv"
	"sync"
)

func main() {
	Map := make(map[int]int)

	if len(os.Args) < 2 {
		fmt.Println("Usage: ./prog num")
		return
	}

	num, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("invalid input")
		return
	}

	for i := 0; i < num; i++ {
		go writeMap(Map, i, i)
		go readMap(Map, i)
	}
}

var mu sync.Mutex

func readMap(Map map[int]int, key int) int {
	//	fmt.Println(Map[key])
	mu.Lock()
	val := Map[key]
	mu.Unlock()
	return val
}

func writeMap(Map map[int]int, key int, val int) {
	mu.Lock()
	Map[key] = val
	mu.Unlock()
}
