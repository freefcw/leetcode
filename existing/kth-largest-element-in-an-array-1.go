package main

import "fmt"

func HeapSort(nums []int) {
	length := len(nums)
	buildMaxHeap(nums, length)
	for i := length - 1; i >= 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		length--
		heapify(nums, 0, length)
	}
	// fmt.Printf("%#v\n", nums)
}

func heapify(nums []int, pos, length int) {
	// fmt.Printf("%d %d %+v\n", pos, length, nums)
	left := pos*2 + 1
	right := pos*2 + 2
	max := pos
	if left < length && nums[left] > nums[max] {
		max = left
	}
	if right < length && nums[right] > nums[max] {
		max = right
	}
	if max != pos {
		nums[pos], nums[max] = nums[max], nums[pos]
		heapify(nums, max, length)
	}
}

func buildMaxHeap(nums []int, length int) {
	for i := length / 2; i >= 0; i-- {
		heapify(nums, i, length)
	}
}

func findKthLargest(nums []int, k int) int {
	length := len(nums)
	buildMaxHeap(nums, length)
	for i := length - 1; i >= 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		// fmt.Printf("%#v\n", nums)
		if i+k == len(nums) {
			return nums[i]
		}
		length--
		heapify(nums, 0, length)
	}
	return 0
}

func main() {
	// arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	// buildMaxHeap(arr, 9)
	arr := []int{3, 2, 1, 5, 6, 4}
	fmt.Println(findKthLargest(arr, 2))
}
