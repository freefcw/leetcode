package leetcode

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

func addBinaryTreeNode(root *TreeNode, val int) {
	if val < root.Val {
		if root.Left == nil {
			node := new(TreeNode)
			node.Val = val
			root.Left = node
		} else {
			addBinaryTreeNode(root.Left, val)
		}
		return
	}
	if root.Right == nil {
		node := new(TreeNode)
		node.Val = val
		root.Right = node
	} else {
		addBinaryTreeNode(root.Right, val)
	}
}

func bstFromPreorder(preorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	root := new(TreeNode)
	root.Val = preorder[0]
	for i := 1; i < len(preorder); i++ {
		addBinaryTreeNode(root, preorder[i])
	}

	return root
}
