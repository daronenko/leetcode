package task

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isBalanced(root *TreeNode) bool {
	_, balanced := isBalancedImpl(root)
	return balanced
}

func isBalancedImpl(root *TreeNode) (int, bool) {
	if root == nil {
		return 0, true
	}

	leftHeight, leftBalanced := isBalancedImpl(root.Left)
	if !leftBalanced {
		return 0, false
	}

	rightHeight, rightBalanced := isBalancedImpl(root.Right)
	if !rightBalanced {
		return 0, false
	}

	if max(leftHeight-rightHeight, rightHeight-leftHeight) > 1 {
		return 0, false
	}

	return max(leftHeight, rightHeight) + 1, true
}
