package main

import (
	"encoding/json"
	"fmt"

	"github.com/MDGSF/utils/log"
)

func main() {
	data := map[string]int{"status": 1}

	msg, err := json.Marshal(data)
	if err != nil {
		log.Error("Marshal map to bytes fail\n")
		return
	}

	var adjust struct {
		Status int
		Type   int
	}

	if err := json.Unmarshal(msg, &adjust); err != nil {
		log.Error("Unmarshal fail\n")
	} else {
		fmt.Printf("status: %d\n", adjust.Status)
	}
}
