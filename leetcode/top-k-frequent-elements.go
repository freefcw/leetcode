package leetcode

// Item contain value and count
type Item struct {
	val   int
	count int
}

func heapify(items []Item, pos, length int) {
	left := pos*2 + 1
	right := pos*2 + 2
	min := pos
	if left < length && items[left].count < items[min].count {
		min = left
	}
	if right < length && items[right].count < items[min].count {
		min = right
	}
	if min != pos {
		items[pos], items[min] = items[min], items[pos]
		heapify(items, min, length)
	}
}

func buildMinHeap(items []Item, length int) {
	for i := length / 2; i >= 0; i-- {
		heapify(items, i, length)
	}
}

func topKFrequent(nums []int, k int) []int {
	hitCounts := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		hitCounts[nums[i]]++
	}
	results := make([]Item, 0, k)
	for key, val := range hitCounts {
		if len(results) < k {
			if len(results) > 0 && val < results[0].count {
				results = append(results, results[0])
				results[0].val = key
				results[0].count = val
			} else {
				results = append(results, Item{key, val})
			}
			if len(results) == k {
				buildMinHeap(results, k)
			}
		} else {
			if val > results[0].count {
				results[0].val = key
				results[0].count = val
				heapify(results, 0, k)
			}
		}
	}
	// fmt.Printf("%v\n", results)

	finalResults := make([]int, k)
	length := k
	for i := length - 1; i >= 0; i-- {
		finalResults[i] = results[0].val
		results[i], results[0] = results[0], results[i]
		length--
		heapify(results, 0, length)
	}

	return finalResults
}
