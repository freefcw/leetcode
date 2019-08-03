package leetcode

//https://leetcode.com/problems/product-of-array-except-self/

// use a cache result
func productExceptSelf(nums []int) []int {
	length := len(nums)
	fromRight := make([]int, length)

	fromRight[length-1] = 1
	for i := length - 2; i >= 0; i-- {
		fromRight[i] = fromRight[i+1] * nums[i+1]
	}
	productFromLeft := 1
	for i := 0; i < length; i++ {
		fromRight[i] = productFromLeft * fromRight[i]
		productFromLeft = productFromLeft * nums[i]
	}

	return fromRight
}

// use two array cache intermediate result
func productExceptSelf2(nums []int) []int {
	length := len(nums)
	fromLeft := make([]int, length)
	fromRight := make([]int, length)

	fromLeft[0] = 1
	for i := 1; i < length; i++ {
		fromLeft[i] = fromLeft[i-1] * nums[i-1]
	}
	fromRight[length-1] = 1
	for i := length - 2; i >= 0; i-- {
		fromRight[i] = fromRight[i+1] * nums[i+1]
	}

	for i := 0; i < length; i++ {
		nums[i] = fromLeft[i] * fromRight[i]
	}
	return nums
}
