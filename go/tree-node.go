package leetcode

// TreeNode is basic Tree Node desc
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(vals []int, x int) *TreeNode {
	nodes := make([]*TreeNode, len(vals)+1)
	for i := 0; i < len(vals); i++ {
		if vals[i] == x {
			nodes[i] = nil
			continue
		}
		nodes[i] = new(TreeNode)
		nodes[i].Val = vals[i]
	}

	for i := 0; i < len(vals)/2; i++ {
		if nodes[i] == nil {
			continue
		}
		left := i*2 + 1
		right := left + 1
		if left > len(vals) {
			continue
		}
		nodes[i].Left = nodes[i*2+1]
		if right > len(vals) {
			continue
		}
		nodes[i].Right = nodes[i*2+2]
	}

	return nodes[0]
}
