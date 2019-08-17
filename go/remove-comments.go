package leetcode

// https://leetcode.com/problems/remove-comments/

func removeComments(source []string) []string {
	result := make([]string, 0, len(source))
	inBlock := false
	beforeBlock := ""
	for i := 0; i < len(source); i++ {
		line := source[i]
		for i := 0; i < len(line)-1; i++ {
			if inBlock {
				if line[i] == '*' && line[i+1] == '/' {
					inBlock = false
					line = beforeBlock + line[i+2:]
					i = len(beforeBlock) - 1
				}
				continue
			}
			if line[i] == '/' && line[i+1] == '/' {
				line = line[:i]
				i = i + 2
				break
			}
			if line[i] == '/' && line[i+1] == '*' {
				inBlock = true
				beforeBlock = line[:i]
				i = i + 1
			}
		}
		// fmt.Printf("%t %s\n", inBlock, line)
		if !inBlock && len(line) > 0 {
			result = append(result, line)
		}
	}
	return result
}
