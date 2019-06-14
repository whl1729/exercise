package main

import (
	"log"
	"net/http"
	"strconv"
	"sync"
)

var mu sync.Mutex

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

func handler(w http.ResponseWriter, r *http.Request) {
	cycles, ok := r.URL.Query()["cycles"]

	if !ok {
		lissajous(w, 5)
		return
	}

	c, err := strconv.ParseFloat(cycles[0], 64)
	if err != nil {
		lissajous(w, 10)
		return
	}

	lissajous(w, c)
}
