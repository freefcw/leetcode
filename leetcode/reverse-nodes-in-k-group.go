package leetcode

func reverseList(head *ListNode) *ListNode {
	node := head
	var next *ListNode
	var prev *ListNode
	for {
		if node == nil {
			break
		}
		next = node.Next
		node.Next = prev

		prev = node
		node = next
	}

	return prev
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	if k < 2 {
		return head
	}
	anchor := &ListNode{-1, head}
	prevTail := anchor
	pos := 1
	tail := prevTail.Next
	for {
		if tail == nil || tail.Next == nil {
			prevTail.Next = head
			break
		}
		tail = tail.Next
		pos++
		if pos == k {
			t := tail.Next
			tail.Next = nil
			prevTail.Next = reverseList(head)

			prevTail = head
			head = t
			tail = head
			pos = 1
		}
	}
	return anchor.Next
}
