package leetcode

// https://leetcode.com/problems/powx-n/

import (
	"math"
)

var (
	pxnBinary []int
)

func searchBinary(x int) uint {
	var i uint
	length := uint(len(pxnBinary))
	for i = 0; i < length; i++ {
		if x < pxnBinary[i] {
			return i - 1
		}
	}
	return 0
}

func initialBinary() {
	pxnBinary = make([]int, 32)
	var i uint32
	for i = 0; i < 32; i++ {
		pxnBinary[i] = 1 << i
	}
}

func myPow(x float64, n int) float64 {
	resultFlag := 1
	if x < 0 {
		x = 0 - x
		if n&1 == 1 {
			resultFlag = -1
		}
	}
	isNNegetive := false
	if n < 0 {
		n = 0 - n
		isNNegetive = true
	}

	if n == 0 {
		return 1
	}
	if x == 1.00 {
		return x * float64(resultFlag)
	}

	mids := make([]float64, 1, 1024)
	mids[0] = x
	n64 := int64(n)
	var count int64
	count = 1
	for i := 1; i < n; i++ {
		mids = append(mids, mids[i-1]*mids[i-1])
		if mids[i] == math.Inf(1) {
			if isNNegetive {
				return 0
			}
			return math.Inf(resultFlag)
		}
		count = count * 2
		if count > n64 {
			break
		}
	}

	initialBinary()

	result := 1.0
	left := n
	for {
		min := searchBinary(left)
		// fmt.Printf("left %d, min %d, real %f\n", left, min, mids[min])
		result = result * mids[min]
		left = left - 1<<min
		if left <= 0 {
			break
		}
	}

	if isNNegetive {
		return 1.0 / result * float64(resultFlag)
	}
	return result * float64(resultFlag)
}
