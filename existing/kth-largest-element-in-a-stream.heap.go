package main

import "fmt"

// 堆排序版本的kth
func buildHeap(nums []int) {
	length := len(nums)
	for i := length / 2; i >= 0; i-- {
		heapify(nums, i, length)
	}
}

func heapify(nums []int, pos, length int) {
	// fmt.Printf("%d %d %+v\n", pos, length, nums)
	left := pos*2 + 1
	right := pos*2 + 2
	min := pos
	if left < length && nums[left] < nums[min] {
		min = left
	}
	if right < length && nums[right] < nums[min] {
		min = right
	}
	if min != pos {
		nums[pos], nums[min] = nums[min], nums[pos]
		heapify(nums, min, length)
	}
}

func HeapSort(nums []int) {
	length := len(nums)
	buildHeap(nums)

	for i := length - 1; i > 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		length--
		heapify(nums, 0, length)
	}
}

type KthLargest struct {
	data  []int
	limit int
}

func Constructor(k int, nums []int) KthLargest {
	kth := KthLargest{}
	kth.data = make([]int, 0, k)
	kth.limit = k
	for i := 0; i < len(nums); i++ {
		kth.Add(nums[i])
	}

	return kth
}

func (this *KthLargest) Add(val int) int {
	if len(this.data) < this.limit {
		if len(this.data) == 0 {
			this.data = append(this.data, val)
			return this.data[0]
		}
		if val < this.data[0] {
			val, this.data[0] = this.data[0], val
			this.data = append(this.data, val)
		} else {
			this.data = append(this.data, val)
		}
		if len(this.data) == this.limit {
			// 主要耗时在建堆这，在数量足够之后再建堆，之前只需要记录最小的即可
			buildHeap(this.data)
		}
		return this.data[0]
	}

	if val > this.data[0] {
		this.data[0] = val
		heapify(this.data, 0, len(this.data))
	}

	return this.data[0]
}

func main() {
	// data := []int{4, 5, 6, 7, 8, 1, 3, 5}
	// buildHeap(data)
	// fmt.Println(data)
	var obj KthLargest
	obj = Constructor(1, []int{})
	fmt.Println(obj.Add(-3))
	fmt.Println(obj.Add(-2))
	fmt.Println(obj.Add(-2))
	fmt.Println(obj.Add(0))
	fmt.Println(obj.Add(4))
	fmt.Println("---------------")
	obj = Constructor(3, []int{4, 5, 8, 2})
	fmt.Println(obj.Add(3))
	fmt.Println(obj.Add(5))
	fmt.Println(obj.Add(10))
	fmt.Println(obj.Add(9))
	fmt.Println(obj.Add(4))
	fmt.Println("---------------")
	obj = Constructor(3, []int{1, 1})
	fmt.Println(obj.Add(1))
	fmt.Println(obj.Add(1))
	fmt.Println(obj.Add(3))
	fmt.Println(obj.Add(3))
	fmt.Println(obj.Add(3))
	fmt.Println(obj.Add(4))
	fmt.Println(obj.Add(4))
	fmt.Println(obj.Add(4))
	fmt.Println("---------------")
	obj = Constructor(3, []int{5, -1})
	fmt.Println(obj.Add(2))
	fmt.Println(obj.Add(1))
	fmt.Println(obj.Add(-1))
	fmt.Println(obj.Add(3))
	fmt.Println(obj.Add(4))
}
