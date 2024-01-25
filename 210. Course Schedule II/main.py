from typing import List


class Solution:
    def findOrder(self,
                  numCourses: int,
                  prerequisites: List[List[int]]) -> List[int]:
        prerequisites_map = {i: [] for i in range(numCourses)}
        for course, prerequisite in prerequisites:
            prerequisites_map[course].append(prerequisite)

        roadmap = []
        visited, visiting = set(), set()

        def dfs(course):
            if course in visiting:
                return False

            if course in visited:
                return True

            visiting.add(course)

            for prerequisite in prerequisites_map[course]:
                if not dfs(prerequisite):
                    return False

            visiting.remove(course)
            visited.add(course)
            roadmap.append(course)

            return True

        for course in range(numCourses):
            if not dfs(course):
                return []
        else:
            return roadmap
