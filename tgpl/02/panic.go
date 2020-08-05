package main

import "errors"

func main() {
	err := errors.New("Just watch!")
	panic(err)
}
