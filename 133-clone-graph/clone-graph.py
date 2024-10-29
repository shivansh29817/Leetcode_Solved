"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
  def cloneGraph(self, node: 'Node') -> 'Node':
    if not node:
      return None
    nodeDic = {}
    queue = deque()
    queue.append(node)
    root = Node(node.val)
    nodeDic[node.val] = root
    while queue:
      curr = queue.popleft()
      for adj in curr.neighbors:
        if adj.val not in nodeDic:
          nodeDic[adj.val] = Node(adj.val)
          queue.append(adj)
        nodeDic[curr.val].neighbors.append(nodeDic[adj.val])
    
    return root