My Solutions to Leetcode Problems
====
This is a repository of my solutions to Leetcode problems.  
All of them are implemented by Python3.6 and C++.  
Started from May 16.

There are time complexities and space complexities(auxiliary space) estimated for each problem.

- **Dynamic Programming**: 005, 032, 053, 055, 061, 063, 064, 070, 072, 096, 097, 115, 120, 123, 124
                139, 140, 152, 198, 213, 221, 264, 279, 300, 303, 304, 309, 322, 329, 338, 343, 368,
                376, 377, 392, 413, 416, 467, 474, 486, 494, 516, 518, 583, 646, 714, 718, 740, 813, 873, 931,
                1027, 1035, 1143
  1. The optimal value I can have while doing action at ith index, need to find
     the optimal for all ith index value in the end.
  2. The optimal value I can have at ith index (do action or not to do)
- **Greedy**: 055, 435, 646, 765
- **Hash Table**: 001, 003, 128, 136, 138, 169, 242, 345, 347, 380, 387, 389, 
                  395, 409, 451, 508, 554, 560, 657, 684, 692, 846
- **Two Pointers**: 011, 019, 042, 075, 141, 142, 160, 202, 209, 287, 881, 986
- **Stack**: 020, 042, 084, 085, 091, 144, 145, 173, 227, 341, 402, 503, 946
- **Heap**: 023, 179, 373, 378, 692
- **Binary Search**: 004, 033, 034, 035, 074, 153, 162, 240, 300, 374, 378, 475, 540, 658, 792
  1. use (end-start)/2 + start to prevent overflow.
  2. while(start < end){... start = mid + 1 ... end = mid - 1} => 
     for each iteration:
     - If the target exist it would be in the [start, end]
     - else, when start == end -1, the nums[start] would be either the biggest value 
       smaller (or bigger if all elements is bigger than the target) than the 
       target and the target should be placed next to it. 
     - In the end: when start = end - 1, the mid must be the start. 
  3. For each iterations in while, carefully define "mid" or "mid +- 1"
     according to the requirements of problems. It's necessary to check the case
     when (start == end - 1). (when we only move start = mid in each iteration)
- **DFS BFS Search**: 079, 091, 099, 100, 101, 102, 103, 104, 107, 109, 110, 111, 112,
                113, 114, 116, 117, 124, 129, 130, 133, 145, 173, 199, 200, 207, 210, 230, 235, 236, 257, 297, 310, 329, 
                399, 417, 437, 508, 515, 530, 542, 547, 652, 687, 695, 787, 797, 841, 863, 951, 958
- **Bit Operations**: 078, 136, 190, 231, 289, 318, 421
- **Sort**: 015, 049, 056, 148, 179, 215, 274, 324, 347, 406, 451, 729, 881
  1. use bucket sort to reduce complexity.
- **Recursive**: 022, 039, 040, 046, 047, 051, 077, 078, 090, 095, 098, 099, 100, 105, 107, 106 
                108, 109, 110, 111, 112, 113, 129, 131, 140, 207, 210, 222, 226, 230, 235, 236, 337, 377, 386, 394, 395, 404, 406, 
                417, 437, 491, 501, 508, 526, 695, 698, 779, 797, 814, 841, 894, 931, 951
  1. BST, for subtrees, try to utilize their range of values. (left subtrees must
     be smaller than root...)
