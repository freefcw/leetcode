package leetcode

func stripLeadSpace(s string) int {
	for i := 0; i < len(s); i++ {
		if s[i] == ' ' {
			continue
		}
		if s[i] == '-' || s[i] == '+' {
			return i
		}
		if s[i] <= '9' && s[i] >= '0' {
			return i
		}
		return -1
	}
	return -1
}

func myAtoi(str string) int {
	from := stripLeadSpace(str)
	if from == -1 {
		return 0
	}
	sign := 1
	if str[from] == '-' || str[from] == '+' {
		if str[from] == '-' {
			sign = -1
		}
		from = from + 1
	}
	result := 0
	for i := from; i < len(str); i++ {
		limit := maxInt32 - result*10
		if sign == -1 {
			limit = -(result*10 + minInt32)
		}
		current := int(str[i] - '0')
		if current >= 0 && current <= 9 {
			if current > limit {
				if sign == 1 {
					return maxInt32
				}
				return minInt32
			}
			result = result*10 + current
		} else {
			break
		}
	}

	return sign * result
}
