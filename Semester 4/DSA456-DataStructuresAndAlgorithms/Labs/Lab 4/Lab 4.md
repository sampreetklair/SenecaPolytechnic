# Lab 4

### Kruskal's Algorithm
Step 1: List all edges with their weights in non-decreasing order:
(A, B): 1
(C, I): 1
(F, G): 1
(D, E): 2
(A, D): 2
(B, D): 2
(C, H): 2
(H, G): 3
(D, G): 3
(H, J): 3
(I, J): 4
(D, F): 5
(H, K): 5
(J, K): 5
(B, C): 6
(G, K): 7

Step 2: Start adding edges to the MST:
Add (A, B): 1 (connects A and B)
Add (C, I): 1 (connects C and I)
Add (F, G): 1 (connects F and G)
Add (D, E): 2 (connects D and E)
Add (A, D): 2 (connects A, D, E)
Add (B, D): 2 (connects A, B, D, E)
Add (C, H): 2 (connects C, H, I)
Add (H, G): 3 (connects C, F, G, H, I)
Add (H, J): 3 (connects C, F, G, H, I, J)
Stop here: We have added v - 1 = 10 edges, where v = 11

Final MST using Kruskal’s Algorithm:
Edges: (A, B), (C, I), (F, G), (D, E), (A, D), (B, D), (C, H), (H, G), (H, J)
Total Weight: 17

### Prim’s Algorithm
Step 1: Start from vertex A:
Add (A, B): 1 (MST now contains vertices A, B)

Step 2: Add the smallest edge connected to MST:
Add (A, D): 2 (MST now contains vertices A, B, D)
Add (B, D): 2 (MST now contains vertices A, B, D, E)
Add (D, E): 2 (MST now contains vertices A, B, D, E)
Add (F, G): 1 (MST now contains vertices A, B, D, E, F, G)
Add (D, G): 3 (MST now contains vertices A, B, D, E, F, G, H)
Add (C, I): 1 (MST now contains vertices A, B, D, E, F, G, H, I)
Add (H, J): 3 (MST now contains vertices A, B, D, E, F, G, H, I, J)
Add (H, G): 3 (MST now contains vertices A, B, D, E, F, G, H, I, J, K)
Stop here: All vertices are included in the MST.

Final MST using Prim’s Algorithm:
Edges: (A, B), (A, D), (B, D), (D, E), (F, G), (D, G), (C, I), (H, J), (H, G)
Total Weight: 17

Conclusion:
Both Kruskal's and Prim's algorithms yield the same Minimum Spanning Tree (MST) with a total weight of 17.