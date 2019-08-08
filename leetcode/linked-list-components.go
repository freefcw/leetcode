package leetcode

// use array
func numComponents(head *ListNode, G []int) int {
	mark := make([]bool, 10000)
	for _, n := range G {
		mark[n] = true
	}
	total := 0
	current := head
	inBlock := false
	for current != nil {
		// fmt.Printf("%d %v %v\n", current.Val, ok, inBlock)
		if mark[current.Val] {
			mark[current.Val] = false
			if !inBlock {
				inBlock = true
				total++
			}
		} else {
			if inBlock {
				inBlock = false
			}
		}
		current = current.Next
	}

	return total
}

// use map
func numComponents2(head *ListNode, G []int) int {
	mark := make(map[int]bool)
	for _, n := range G {
		mark[n] = true
	}
	total := 0
	current := head
	inBlock := false
	for current != nil {
		_, ok := mark[current.Val]
		// fmt.Printf("%d %v %v\n", current.Val, ok, inBlock)
		if ok {
			delete(mark, current.Val)
			if !inBlock {
				inBlock = true
				total++
			}
		} else {
			if inBlock {
				inBlock = false
			}
		}
		current = current.Next
	}

	return total
}
