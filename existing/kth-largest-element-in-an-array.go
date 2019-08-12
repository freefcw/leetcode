package main

import (
	"fmt"
)

func qsort(nums []int, low int, high int) {
	if low >= high {
		return
	}
	base := nums[low]
	i := low + 1
	j := high - 1
	for i <= j {
		for nums[i] <= base {
			i++
			if i == high {
				break
			}
		}
		for nums[j] > base {
			j--
			if j == low {
				break
			}
		}
		if i >= j {
			break
		}
		nums[i], nums[j] = nums[j], nums[i]
	}
	nums[j], nums[low] = nums[low], nums[j]
	qsort(nums, low, j)
	qsort(nums, j+1, high)
}

func findKthLargest(nums []int, k int) int {
	// sort.Ints(nums)
	qsort(nums, 0, len(nums))
	fmt.Println(nums)
	return nums[k - 1]
}

// 直接插入排序
func findKthLargest2(nums []int, k int) int {
	for i := 0; i < k; i++ {
		max := i
		for j := i + 1; j < len(nums); j++ {
			if nums[j] > nums[max] {
				max = j
			}
		}
		nums[i], nums[max] = nums[max], nums[i]
	}
	// fmt.Println(nums)
	return nums[k-1]
}

func main() {
    var arr []int
	arr = []int{3, 2, 3, 1, 2, 4, 5, 5, 6}
	// fmt.Println(findKthLargest(arr, 4))
	// arr = []int{7, 6, 5, 4, 3, 2, 1}
	// arr = []int{3, 2, 1, 5, 6, 4}
	// qsort(arr, 0, len(arr))
	fmt.Println(findKthLargest(arr, 5))
}
