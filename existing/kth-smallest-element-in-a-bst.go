package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var nodes []int

func kthSmallest(root *TreeNode, k int) int {
	nodes = make([]int, 0)
	walk(root, k)

	return nodes[k-1]
}

func walk(root *TreeNode, k int) bool {
	if root == nil {
		return false
	}
	if walk(root.Left, k) {
		return true
	}

	// fmt.Printf("%d \n", root.Val)
	nodes = append(nodes, root.Val)
	if len(nodes) >= k {
		return true
	}
	if walk(root.Right, k) {
		return true
	}
	return false
}

func main() {
	root := TreeNode{
		Val: 3,
	}
	root.Left = &TreeNode{
		Val: 1,
	}
	root.Left.Right = &TreeNode{
		Val: 2,
	}
	root.Right = &TreeNode{
		Val: 4,
	}
	fmt.Printf("result %d\n", kthSmallest(&root, 2))
	// fmt.Printf("hello world!\n")
}
