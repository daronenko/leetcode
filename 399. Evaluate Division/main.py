import collections

from typing import List


class Solution:
    def calcEquation(self,
                     equations: List[List[str]],
                     values: List[float],
                     queries: List[List[str]]) -> List[float]:
        adj = collections.defaultdict(list)
        for (numerator, denominator), value in zip(equations, values):
            adj[numerator].append((denominator, value))
            adj[denominator].append((numerator, 1 / value))

        def bfs(source: str, target: str) -> float:
            if source not in adj or target not in adj:
                return -1

            queue, visited = collections.deque(), set()
            queue.append((source, 1))
            visited.add(source)

            while queue:
                node, weight = queue.popleft()

                if node == target:
                    return weight

                for neighbour, neighbour_weight in adj[node]:
                    if neighbour not in visited:
                        queue.append((neighbour, weight * neighbour_weight))
                        visited.add(neighbour)
            else:
                return -1

        return [bfs(query[0], query[1]) for query in queries]
