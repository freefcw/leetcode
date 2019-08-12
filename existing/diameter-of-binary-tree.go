package main

import (
    "fmt"
)

var maxPath int

func diameterOfBinaryTree(root *TreeNode) int {
    if root == nil {
        return 0
    }
    maxPath = 0
    getDepth(root, 0)
    
    return maxPath
}

func getDepth(root *TreeNode, level int) int {
    if root == nil {
        return level
    }
    leftDepth := getDepth(root.Left, level + 1)
    rightDepth := getDepth(root.Right, level + 1)
    newPathCount := leftDepth + rightDepth - (level + 1) * 2
    if newPathCount > maxPath {
        maxPath = newPathCount
    }
    if leftDepth > rightDepth {
        return leftDepth
    }
    return rightDepth
}

func main () {
    fmt.Println(fizzBuzz(31))
}