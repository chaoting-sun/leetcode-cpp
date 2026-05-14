"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from collections import deque
from typing import Optional
class Solution:    
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        q = deque([node])
        visited_nodes = { node: Node(node.val) }

        while q:
            curr = q.popleft()
            for nei in curr.neighbors:
                if nei in visited_nodes:
                    visited_nodes[curr].neighbors.append(visited_nodes[nei])
                    continue

                visited_nodes[nei] = Node(nei.val)
                visited_nodes[curr].neighbors.append(visited_nodes[nei])
                q.append(nei)

        return visited_nodes[node]

"""
test case: graph = 1 - 2, 1 - 3, 2 - 3 (node = 1)
trace:
q = [1]
built = { 1: 1' }
q = [1]
    q = []
    curr = 1
    neighbors
        nei = 2
            built = { 1: 1'(nei=[2']), 2: 2' }
            q = [2]
        nei = 3
            built = { 1: 1'(nei=[2', 3']), 2: 2', 3: 3' }
            q = [2,3]
q = [2,3]
    q = [3]
    curr = 2
    neighbors
        nei = 1
            built = { 1: 1'(nei=[2', 3']), 2: 2'(nei=[1']), 3: 3' }
        nei = 3
            built = { 1: 1'(nei=[2', 3']), 2: 2'(nei=[1', 3']), 3: 3' }
q = [3]
    q = []
    curr = 3
    neighbors
        nei = 1
            built = { 1: 1'(nei=[2', 3']), 2: 2'(nei=[1', 3']), 3: 3'(nei=[1']) }
        nei = 2
            built = { 1: 1'(nei=[2', 3']), 2: 2'(nei=[1', 3']), 3: 3'(nei=[1',2']) }
"""