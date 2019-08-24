package leetcode

func findInorderIndex(inorder []int, val int) int {
	for pos := 0; pos < len(inorder); pos++ {
		if inorder[pos] == val {
			return pos
		}
	}
	return -1
}

func ipbuildTree(inorder []int, postorder []int) *TreeNode {
	// fmt.Printf("-- %v %v\n", inorder, postorder)
	length := len(postorder)
	if length == 0 {
		return nil
	}
	root := new(TreeNode)
	root.Val = postorder[length-1]
	if len(postorder) == 1 {
		return root
	}

	rootInorderPos := findInorderIndex(inorder, root.Val)
	leftNodeNumbers := rootInorderPos
	root.Left = ipbuildTree(inorder[:rootInorderPos], postorder[:leftNodeNumbers])
	root.Right = ipbuildTree(inorder[rootInorderPos+1:], postorder[leftNodeNumbers:len(postorder)-1])

	return root
}
