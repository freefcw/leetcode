package leetcode

// TreeNode is basic Tree Node desc
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func treeToSlice(root *TreeNode, d int) []int {
	if root == nil {
		return make([]int, 0)
	}
	nodes := make([]*TreeNode, 64)
	vals := make([]int, 64)
	nodes[0] = root
	index := 0
	nodeMax := 0
	for {
		if index > nodeMax {
			break
		}
		if nodes[index] == nil {
			vals[index] = d
			index++
			continue
		}
		newSize := (index + 1) * 2
		if newSize > len(vals) {
			newNodes := make([]*TreeNode, (len(vals)+1)*2)
			copy(newNodes, nodes)
			nodes = newNodes
			newVals := make([]int, (len(vals)+1)*2)
			copy(newVals, vals)
			vals = newVals
		}
		vals[index] = nodes[index].Val
		if nodes[index].Left != nil {
			nodeMax = index*2 + 1
			nodes[index*2+1] = nodes[index].Left
		}
		if nodes[index].Right != nil {
			nodeMax = index*2 + 2
			nodes[index*2+2] = nodes[index].Right
		}
		index++
	}
	return vals[:index]
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

	for i := 0; i < len(vals)/2+1; i++ {
		if nodes[i] == nil {
			continue
		}
		left := i*2 + 1
		right := left + 1
		if left >= len(vals) {
			break
		}
		nodes[i].Left = nodes[left]
		if right >= len(vals) {
			break
		}
		nodes[i].Right = nodes[right]
	}

	return nodes[0]
}
