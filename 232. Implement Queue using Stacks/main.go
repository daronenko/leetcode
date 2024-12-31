package task

type MyQueue struct {
	pushStack, popStack []int
}

func Constructor() MyQueue {
	return MyQueue{}
}

func (q *MyQueue) Push(x int) {
	q.pushStack = append(q.pushStack, x)
}

func (q *MyQueue) Pop() int {
	result := q.Peek()
	q.popStack = q.popStack[:len(q.popStack)-1]
	return result
}

func (q *MyQueue) Peek() int {
	if len(q.popStack) == 0 {
		q.migratePushStack()
	}

	return q.popStack[len(q.popStack)-1]
}

func (q *MyQueue) Empty() bool {
	return len(q.pushStack) == 0 && len(q.popStack) == 0
}

func (q *MyQueue) migratePushStack() {
	for len(q.pushStack) != 0 {
		q.popStack = append(q.popStack, q.pushStack[len(q.pushStack)-1])
		q.pushStack = q.pushStack[:len(q.pushStack)-1]
	}
}
