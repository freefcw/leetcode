package leetcode

var (
	mids []int
)

func initMids(dividend int, divisor int) {
	mids = make([]int, 2, 10)
	mids[0] = 0
	mids[1] = divisor
	i := 2
	for {
		sum := mids[i-1] + mids[i-1]
		if sum > dividend {
			break
		}
		mids = append(mids, mids[i-1]+mids[i-1])
		i++
	}
}

func findMaxLess(target int, low, high int) int {
	if high-low < 10 {
		for i := low; i < high; i++ {
			if i == high-1 {
				return i
			}
			if target >= mids[i] && target < mids[i+1] {
				return i
			}
		}
	}
	mid := (low + high) / 2
	if target < mids[mid] {
		return findMaxLess(target, low, mid-1)
	}

	return findMaxLess(target, mid, high)
}

func divide(dividend int, divisor int) int {
	if dividend == 0 {
		return 0
	}
	flag := 1
	if dividend < 0 {
		if divisor > 0 {
			flag = -1
		} else {
			divisor = 0 - divisor
		}
		dividend = 0 - dividend
	} else {
		if divisor < 0 {
			flag = -1
			divisor = 0 - divisor
		}
	}
	if dividend < divisor {
		return 0
	}

	initMids(dividend, divisor)
	last := len(mids) - 1
	result := 1 << uint(last-1)
	left := dividend
	for {
		left -= mids[last]
		last = findMaxLess(left, 0, last)
		if last == 0 {
			break
		}
		result = result + 1<<uint(last-1)
		// fmt.Printf("result: %d, left %d, last %d\n", result, left, last)
	}

	if flag == 1 {
		if result > maxInt32 {
			return maxInt32
		}
		return result
	}
	return 0 - result
}
