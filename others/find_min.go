package others

func findMin(a []byte) []byte {
	if len(a) == 0 {
		return a
	}
	current := a[0]
	result := make([]byte, 0, len(a)-1)
	done := false
	for i := 1; i < len(a); i++ {
		if !done && current > a[i] {
			current = a[i]
			done = true
			continue
		}
		result = append(result, current)
		current = a[i]
	}
	if done {
		// default lose last
		result = append(result, a[len(a)-1])
	}
	return result
}
