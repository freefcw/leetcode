package algorithms

func HeapSort(nums []int) {
	length := len(nums)
	buildMaxHeap(nums, length)
	for i := length - 1; i >= 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		length--
		heapify(nums, 0, length)
	}
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
