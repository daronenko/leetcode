from typing import List


class Solution:
    def canFinish(self,
                  numCourses: int,
                  prerequisites: List[List[int]]) -> bool:
        prerequisites_map = {i: [] for i in range(numCourses)}
        for course, prerequisite in prerequisites:
            prerequisites_map[course].append(prerequisite)

        visited = set()

        def dfs(course):
            if course in visited:
                return False

            if not prerequisites_map[course]:
                return True

            visited.add(course)
            for prerequisite in prerequisites_map[course]:
                if not dfs(prerequisite):
                    return False

            visited.remove(course)
            prerequisites_map[course] = []

            return True

        for course in range(numCourses):
            if not dfs(course):
                return False
        else:
            return True
