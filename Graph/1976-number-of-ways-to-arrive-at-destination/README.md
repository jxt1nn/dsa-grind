# 1976. Number of Ways to Arrive at Destination

**Difficulty:** Medium
**Topic:** Graph, Dijkstra, Shortest Path

## Problem Link

https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

## Problem Summary

You are given a road network of `n` intersections numbered from `0` to `n - 1`.
The roads are represented as a list where each element contains:

* `u` → starting intersection
* `v` → destination intersection
* `time` → time required to travel

Your task is to determine **how many different ways you can reach intersection `n - 1` from intersection `0` using the minimum possible time**.

Return the number of such shortest paths modulo **1e9 + 7**.

---

## Approach

This problem can be solved using **Dijkstra's Algorithm**.

### Key Idea

While computing the shortest distance to each node, we also maintain the **number of ways to reach that node with the shortest distance**.

### Steps

1. Build an **adjacency list** from the roads.
2. Use a **priority queue (min-heap)** to always process the node with the smallest distance.
3. Maintain two arrays:

   * `dist[i]` → shortest distance to node `i`
   * `ways[i]` → number of ways to reach node `i` with shortest distance
4. If we find a **shorter path**, update:

   * distance
   * ways
5. If we find **another path with the same shortest distance**, add the number of ways.

Finally, return `ways[n-1]`.

---

## Time Complexity

```
O(E log V)
```

* `E` = number of edges
* `V` = number of nodes

This comes from the use of a **priority queue in Dijkstra's algorithm**.

---

## Space Complexity

```
O(V + E)
```

For storing the adjacency list and distance arrays.

---

## Concepts Used

* Graph Representation (Adjacency List)
* Dijkstra's Algorithm
* Priority Queue (Min Heap)
* Dynamic Counting of Paths
* Modulo Arithmetic

