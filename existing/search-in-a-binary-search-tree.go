package main

import (
    "fmt"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func searchBST(root *TreeNode, val int) *TreeNode {
    if root == nil {
        return root
    }
    if root.Val == val {
        return root
    }
    if root.Val > val {
        return searchBST(root.Left, val)
    }
    if root.Val < val {
        return searchBST(root.Right, val)
    }

    return nil
}

func main () {
    root := TreeNode{
        Val: 1,
    }
    root.Left = &TreeNode{
        Val: 0,
    }
    root.Right = &TreeNode{
        Val: 2,
    }
    fmt.Println(searchBST(&root, 0))
    fmt.Println(root)
}