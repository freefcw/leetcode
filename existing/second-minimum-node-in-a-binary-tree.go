package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var result int
var minimum int

func findSecondMinimumValue(root *TreeNode) int {
	result = -1
	if root == nil {
		return -1
	}
	minimum = root.Val
	walk(root)
	return result
}

func walk(root *TreeNode) {
	if root == nil {
		return
	}
	if root.Val > minimum {
		if result == -1 {
			result = root.Val
		}

		if root.Val < result {
			result = root.Val
		}
	}

	walk(root.Left)
	walk(root.Right)
}

func main() {
	root := TreeNode{
		Val: 2,
	}
	root.Left = &TreeNode{
		Val: 2,
	}
	root.Right = &TreeNode{
		Val: 5,
	}
	root.Right.Left = &TreeNode{
		Val: 5,
	}
	root.Right.Right = &TreeNode{
		Val: 7,
	}
	fmt.Printf("result %d\n", findSecondMinimumValue(&root))
	// fmt.Printf("hello world!\n")
}
