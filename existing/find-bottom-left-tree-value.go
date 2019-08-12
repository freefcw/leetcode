package main

import (
    "fmt"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

var maxDepth int
var theNode *TreeNode

func findBottomLeftValue(root *TreeNode) int {
    maxDepth = 0

    walk(root, 1);
    
    return theNode.Val
}

func walk(root *TreeNode, level int) {
    if root == nil {
        return
    }
    if root.Left == nil && root.Right == nil {
        if level > maxDepth {
            maxDepth = level
            theNode = root
        }
    }
    if root.Left != nil {
        walk(root.Left, level + 1)
    }
    if root.Right != nil {
        walk(root.Right, level + 1)
    }
}

func main () {
    fmt.Println(fizzBuzz(31))
}