# 🌳 Tree Diameter & Max Distance (Simple Notes)

## 1) Definitions

Tree Diameter  
The longest distance between any two nodes in a tree.  
Distance = number of edges between nodes.

Max Distance of a Node (Eccentricity)  
The maximum distance from this node to any other node in the tree.

## 2) Tree Diameter (2 BFS / DFS Rule)

Steps:
- Start BFS/DFS from any node `x` → get the farthest node `A`.
- Start BFS/DFS from node `A` → get the farthest node `B`.
- The distance between `A` and `B` is the Diameter.

Formula:
Diameter = dist(A, B)

## 3) Max Distance for Every Node

After finding the diameter endpoints `A` and `B`:
- Run BFS from `A` → store distances in `distA[]`
- Run BFS from `B` → store distances in `distB[]`

For every node `u`:
maxDistance[u] = max(distA[u], distB[u])

## 4) Why This Works

In a tree, the farthest node from any node `u`
must be one of the diameter endpoints.

So checking only `A` and `B` is enough.

## 5) Notes

- Single node tree → Diameter = 0
- Line tree with `n` nodes → Diameter = n - 1
- Time Complexity: O(N)
