package main

import (
    "fmt"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func trimBST(root *TreeNode, L int, R int) *TreeNode {
    if root == nil {
        return root
    }
    if root.Val > R {
        return trimBST(root.Left, L, R)
    }
    if root.Val < L {
        return trimBST(root.Right, L, R)
    }
    
    root.Right = trimBST(root.Right, L, R)
    root.Left = trimBST(root.Left, L, R)

    return root;
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
    fmt.Println(trimBST(&root, 1, 2))
    fmt.Println(root)
}