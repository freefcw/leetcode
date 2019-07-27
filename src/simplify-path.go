package leetcode

import "strings"

func simplifyPath(path string) string {
	segments := strings.Split(path, "/")
	stack := make([]string, len(segments))
	pos := 0
	for _, val := range segments {
		if len(val) == 0 {
			continue
		}
		if val == "." {
			continue
		}
		if val == ".." {
			if pos == 0 {
				continue
			}
			stack[pos] = ""
			pos--
			continue
		}

		stack[pos] = val
		pos++
	}

	return "/" + strings.Join(stack[:pos], "/")
}
