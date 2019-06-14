package main

import (
	"log"
	"net/http"
	"sync"
)

var mu sync.Mutex

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

func handler(w http.ResponseWriter, r *http.Request) {
	lissajous(w)
}
