package validParentheses

var parentheses = map[rune]rune{
	'(': ')',
	'{': '}',
	'[': ']',
}

func isValid(s string) bool {
	if len(s) == 0 || len(s)%2 == 1 {
		return false
	}

	stack := make([]rune, 0, len(s)/2)
	for _, bracket := range s {
		if _, isOpening := parentheses[bracket]; isOpening {
			stack = append(stack, bracket)
		} else if len(stack) == 0 || parentheses[stack[len(stack)-1]] != bracket {
			return false
		} else {
			stack = stack[:len(stack)-1]
		}
	}

	return len(stack) == 0
}
