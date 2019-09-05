package leetcode

func prefixesDivBy5(A []int) []bool {
	result := make([]bool, len(A))
	if len(A) == 0 {
		return result
	}
	current := 0
	for i := 0; i < len(A); i++ {
		current = current<<1 + A[i]
		if current >= 5 {
			current = current - 5
		}
		result[i] = false
		if current == 0 {
			result[i] = true
		}
	}
	return result
}
