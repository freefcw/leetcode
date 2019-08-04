package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func compareLinkedList(a *ListNode, b *ListNode) bool {
	for {
		if a == nil && b == nil {
			return true
		}
		if a == nil || b == nil {
			return false
		}
		if a.Val != b.Val {
			return false
		}
		a = a.Next
		b = b.Next
	}
}

func createLinkedList(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}

	head := &ListNode{Val: nums[0], Next: nil}
	current := head
	for i := 1; i < len(nums); i++ {
		current.Next = &ListNode{Val: nums[i], Next: nil}
		current = current.Next
	}
	return head
}

func linkedList2array(head *ListNode) []int {
	result := make([]int, 0)
	for head != nil {
		result = append(result, head.Val)
		head = head.Next
	}
	return result
}
