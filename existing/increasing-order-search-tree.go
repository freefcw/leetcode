package main

import (
    "fmt"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

var currentNode *TreeNode
// 使用额外的节点记录中序遍历,节省了一些操作
func increasingBST0(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    aNode := new(TreeNode)
    currentNode = aNode

    inorder0(root)
    
    return aNode.Right
}

func inorder0(root *TreeNode) {
    if root == nil {
        return
    }
    inorder0(root.Left)
    root.Left = nil
    currentNode.Right = root
    currentNode = root
    inorder0(root.Right)
}

func appendRight(root *TreeNode, newNode *TreeNode) {
    rightNode := root
    for rightNode.Right != nil {
        rightNode = rightNode.Right
    }
    rightNode.Right = newNode
}
// 每次新增都找最右节点
func increasingBST(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    // fmt.Printf("root:%+v\n", root)
    p := increasingBST(root.Left)
    root.Left = nil
    if p == nil {
        p = root
    } else {
        appendRight(p, root)
    }
    oldRight := root.Right
    root.Right = nil
    appendRight(root, increasingBST(oldRight))

    return p
}

func printTree(root *TreeNode) {
    if root == nil {
        return
    }
    fmt.Printf("%d\n", root.Val)
    printTree(root.Right)
}

// 使用左节点记录最右节点，减少查找
func increasingBST2(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }

    node := inorder(root)
    node.Left = nil
    return node
}

func inorder(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    // fmt.Printf("root:%+v\n", root)
    p := inorder(root.Left)
    root.Left = nil
    if p == nil {
        p = root
        p.Left = root
    } else {
        p.Left.Right = root
        p.Left = p.Left.Right
    }
    oldRight := root.Right
    root.Right = nil
    newNode := inorder(oldRight)
    if newNode != nil {
        p.Left.Right = newNode
        p.Left = newNode.Left
        newNode.Left = nil
    }

    return p
}


func main () {
    root := TreeNode{
        Val: 5,
    }
    root.Left = &TreeNode{
        Val: 3,
        Left: &TreeNode{
            Val: 2,
            Right: nil,
            Left:&TreeNode{
                Val: 1,
            },
        },
        Right: &TreeNode {
            Val: 4,
            Right: nil,
            Left:nil,
        },
    }
    root.Right = &TreeNode{
        Val: 6,
        Right: &TreeNode {
            Val: 8,
            Right: &TreeNode{
                Val: 9,
                Right: nil,
                Left:nil,
            },
            Left: &TreeNode{
                Val: 7,
                Right: nil,
                Left:nil,
            },
        },
    }
    newRoot := increasingBST0(&root)
    printTree(newRoot)
}