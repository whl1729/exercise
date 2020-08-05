package main

import (
	"fmt"
	"io/ioutil"
)

func main() {
	readPath := "/home/along/work/C1-InterfaceServer/bin/c1InterfaceServer_arm64"
	writePath := "/home/along/test/c1InterfaceServer_arm64"

	file, err := ioutil.ReadFile(readPath)
	if err != nil {
		fmt.Printf("ReadFile: %s\n", err)
		return
	}

	fmt.Printf("%v\n", file)

	if err := ioutil.WriteFile(writePath, file, 0755); err != nil {
		fmt.Printf("WriteFile: %s\n", err)
		return
	}

	fmt.Println("Read and Write file successfully.")
}
