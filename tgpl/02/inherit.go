package main

import "fmt"

type Man struct {
	name string
	age  int
}

type Student struct {
	Man
	school string
}

func (m *Man) Greet() {
	fmt.Printf("Hello! I'm %s\n", m.name)
}

func main() {
	s := Student{Man{"whl", 26}, "SYSU"}
	s.Greet()
}
