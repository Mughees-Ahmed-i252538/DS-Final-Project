(Bismillah hirahman nirahim

THis folder will contain the report to be uploaded with the project inshallah

ANd other such things if needed inshallah

Allah swt knows best)

Vault Heist
Report (Deliverable 1)

Member 1: Mughees Ahmad (25I-2538)
Member 2: Fatima Akhtar (25I-3030)

 System Architecture:
For system architecture, our architecture style was closest to layered. We separately tackled presentation (in GUI, screens, etc.), logic (data structures and game mechanics etc.) and data access (leaderboard etc.). We made the presentation and logic layers separately but simultaneously, linking them up as we went, and near the end, we made the data access layer with leaderboards and such. Though this is not exactly a database, our overall project working style is similar to layered architecture.
At the same time, after the set up of GUI, GUI and logic layers worked in parallel, while leaderboard was created near the end when finishing up the scoring systems.
Besides assets, the project consists of Data structures (purely logic) , Event Log (logic and data access), Game mechanics (logic and presentation), Graphics (mostly presentation layer), Interface (logic and presentation) and Levels (data access). These are connected using a main.
The game uses a leaderboard that ranks according to scores. Scores are automatically stored and updated along with the exact date and time (down to millisecond) of storing (made with ctime). Hence, no two times are the exact same.
Algorithmic Complexity Analysis:
AVL main functions:
Insertion: 
Time Complexity: O(n)
Space Complexity: O(log n)
Rotations:
Time Complexity: O(1)
Space Complexity: O(l)
kthAVL:
Time Complexity: O(log n)
Space Complexity: O(l)
rank:
Time Complexity: O(log n)
Space Complexity: O(l)
Analysis:
As from here, the overall space complexity of all AVL functions is very appropriate and efficient. Insertion is the one function that has a relatively worse space and time complexity, especially time complexity, which is increasing by itself at each point.
Binary Tree main functions:
BTQueue:
Time Complexity: O(1)
Space Complexity: O(1) (but if the given size is very large, it may be O(n))
Insertion:
Time Complexity: O(1)
Space Complexity: O(l)
Ordering (pre/post/in):
Time Complexity: O(n)
Space Complexity: O(tree height)
levelOrder:
Time Complexity: O(n)
Space Complexity: O(n)
Search:
Time Complexity: O(n)
Space Complexity: O(l)
Building (from pre+in or post+in):
Time Complexity: O(n^2)
Space Complexity: O(tree height)
Height, diameter, lca, mirror, isSameTree, isSymmetric:
Time Complexity: O(n)
Space Complexity: O(tree height)
Analysis:
Time complexity is acceptable, but the two build functions have the worst time complexity (O (n^2)). On research, we found that on an advanced level, hash maps were used to reduce this time complexity to around O(n). Space complexity is mostly based on tree height.
Binary Search Tree main functions:
Insertion:
Time Complexity: O(n)
Space Complexity: O(n)
Search:
Time Complexity: O(n)
Space Complexity: O(n)
findMin/find Max:
Time Complexity: O(n)
Space Complexity: O(1)
Successor/predecessor:
Time Complexity: O(n)
Space Complexity: O(1)
Range:
Time Complexity: O(n)
Space Complexity: O(n)
Kth:
Time Complexity: O(n)
Space Complexity: O(1)
Analysis:
Time complexity is optimal, and mostly the same across all functions. Space complexity is also optimal, and this is an efficient code to use.
MaxHeap main functions:
buildMaxHeap:
Time Complexity: O(n)
Space Complexity: O(1)
heapsort:
Time Complexity: O(n log n)
Space Complexity: O(1)
Insertion:
Time Complexity: O(log n)
Space Complexity: O(1)
extractMax:
Time Complexity: O(log n)
Space Complexity: O(1)
Heapify up and down:
Time Complexity: O(log n)
Space Complexity: O(1)
Analysis:
Heapsort is the algorithm with the most time complexity in this data structure. Space complexity in max heap is very optimal. However, these are all optimized algorithms and can likely not be significantly further optimized for complexity.











