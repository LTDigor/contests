package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"reflect"
	"strings"
)

var (
	in  *bufio.Reader
	out *bufio.Writer
)

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)
	for i := 0; i < t; i++ {
		solve()
	}
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	var sb strings.Builder
	for i := 0; i < n; i++ {
		var nxt_line string
		fmt.Fscan(in, &nxt_line)
		sb.WriteString(nxt_line)
	}

	var res = prettyJson(sb.String())
	fmt.Fprintln(out, res)
}

func removeEmpty(input interface{}) interface{} {

	switch v := input.(type) {
	case []interface{}:

		var result []interface{}
		for _, item := range v {
			if item != nil {
				if reflect.TypeOf(item).Kind() == reflect.Map {
					if len(item.(map[string]interface{})) > 0 {
						result = append(result, removeEmpty(item))
					}
				} else if reflect.TypeOf(item).Kind() == reflect.Slice {
					if len(item.([]interface{})) > 0 {
						result = append(result, removeEmpty(item))
					}
				} else {
					result = append(result, item)
				}
			}
		}
		return result
	case map[string]interface{}:
		result := make(map[string]interface{})
		for key, value := range v {
			if value != nil {
				if reflect.TypeOf(value).Kind() == reflect.Map {
					if len(value.(map[string]interface{})) > 0 {
						result[key] = removeEmpty(value)
					}
				} else if reflect.TypeOf(value).Kind() == reflect.Slice {
					if len(value.([]interface{})) > 0 {
						result[key] = removeEmpty(value)
					}
				} else {
					result[key] = value
				}
			}
		}
		return result
	default:
		return input
	}
}

func prettyJson(jsonStr string) string {
	fmt.Println("LOL", jsonStr)

	var jsonData interface{}
	json.Unmarshal([]byte(jsonStr), &jsonData)

	updatedData := removeEmpty(jsonData)
	updatedJSON, _ := json.Marshal(updatedData)
	return string(updatedJSON)
}
