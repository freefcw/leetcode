package leetcode

type BSTIterator struct {
	nodes       []*TreeNode
	currentNode *TreeNode
	pos         int
}

// Constructor a
func Constructor(root *TreeNode) BSTIterator {
	bst := BSTIterator{}
	bst.init(root)

	return bst
}

func (this *BSTIterator) init(root *TreeNode) {
	this.pos = 0
	this.nodes = make([]*TreeNode, 0, 10)
	this.inOrder(root)
}

func (this *BSTIterator) inOrder(root *TreeNode) {
	if root == nil {
		return
	}
	if root.Left != nil {
		this.inOrder(root.Left)
	}
	this.nodes = append(this.nodes, root)
	if root.Right != nil {
		this.inOrder(root.Right)
	}
}

/** @return the next smallest number */
func (this *BSTIterator) Next() int {
	val := this.nodes[this.pos].Val
	this.pos++
	return val
}

/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
	return this.pos < len(this.nodes)
}
