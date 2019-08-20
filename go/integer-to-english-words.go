package leetcode

var (
	nwTens = []string{"Zero", "Ten", "Twenty", "Thirty", "Forty",
		"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
	nwBasic = []string{"Zero", "One", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Eleven", "Twelve", "Thirteen", "Fourteen",
		"Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}
)

func simpleNumberToWords(num int) string {
	hundred := 0
	result := ""
	if num > 99 {
		hundred = num / 100
		result = nwBasic[hundred] + " " + "Hundred"
	}
	num = num - hundred*100
	if num > 19 {
		tens := num / 10
		left := num % 10
		if left != 0 {
			if len(result) != 0 {
				result = result + " " + nwTens[tens] + " " + nwBasic[left]
			} else {
				result = nwTens[tens] + " " + nwBasic[left]
			}
		} else {
			if len(result) != 0 {
				result = result + " " + nwTens[tens]
			} else {
				result = nwTens[tens]
			}
		}
	} else {
		if num != 0 {
			if result != "" {
				result = result + " " + nwBasic[num]
			} else {
				result = nwBasic[num]
			}

		}
	}

	return result
}

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}
	result := ""
	if num > (1000000000 - 1) {
		current := num / 1000000000
		result = simpleNumberToWords(current) + " " + "Billion"
		num = num % 1000000000
	}
	if num > (1000000 - 1) {
		current := num / 1000000
		if result != "" {
			result = result + " " + simpleNumberToWords(current) + " " + "Million"
		} else {
			result = simpleNumberToWords(current) + " " + "Million"
		}

		num = num % 1000000
	}
	if num > (1000 - 1) {
		current := num / 1000
		if result != "" {
			result = result + " " + simpleNumberToWords(current) + " " + "Thousand"
		} else {
			result = simpleNumberToWords(current) + " " + "Thousand"
		}
		num = num % 1000
	}
	if result != "" {
		if num != 0 {
			result = result + " " + simpleNumberToWords(num)
		}
	} else {
		result = simpleNumberToWords(num)
	}

	return result
}
