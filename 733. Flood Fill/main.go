package task

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
	initColor := image[sr][sc]
	if initColor == color {
		return image
	}

	height, width := len(image), len(image[0])
	var dfs func(int, int)
	dfs = func(r, c int) {
		if r < 0 || r >= height || c < 0 || c >= width || image[r][c] != initColor {
			return
		}

		image[r][c] = color

		dfs(r-1, c)
		dfs(r+1, c)
		dfs(r, c-1)
		dfs(r, c+1)
	}

	dfs(sr, sc)
	return image
}
