package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strings"
	"time"
)

func main() {
	for _, url := range os.Args[1:] {
		if !strings.HasPrefix(url, "http") {
			url = "http://" + url
		}

		var body [2][]byte

		for i := 0; i < 2; i++ {
			start := time.Now()

			resp, err := http.Get(url)

			if err != nil {
				fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
				os.Exit(1)
			}

			body[i], err = ioutil.ReadAll(resp.Body)
			resp.Body.Close()
			if err != nil {
				fmt.Fprintf(os.Stderr, "fetch: reading %s: %v\n", url, err)
				os.Exit(1)
			}

			fmt.Printf("%.2fs elapsed\n", time.Since(start).Seconds())
		}

		if string(body[0]) == string(body[1]) {
			fmt.Println("same")
		} else {
			fmt.Println("different")
		}
	}
}
