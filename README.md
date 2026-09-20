# Data Structures in C

C implementations of core data structures and classic problems: linked lists, stacks and queues, trees, and arrays. The programs come from my Data Structures course at IIT Bhubaneswar and my own practice. Each file is a standalone program with its own `main`.

**Author:** Yemineni Nideesh, B.Tech CSE, IIT Bhubaneswar (2025–2029)

## Programs (17)

### Linked lists

| File | What it does |
|---|---|
| `addIntegers_linkedLists.c` | Adds two integers stored digit by digit in linked lists (most significant digit first) and returns the sum as a new list. |
| `deleteOddINdices_in_linkedList.c` | Deletes every node at an odd position (1st, 3rd, 5th, …) from a singly linked list. |
| `replaces_elementOf_linkedList_withUserGivenValue.c` | Replaces every occurrence of a chosen value with a new value entered by the user. |
| `Intersection_of_2LinkedLists.c` | Builds a new list of the values that appear in both linked lists. |

### Circular and doubly circular lists

| File | What it does |
|---|---|
| `DleteFirstLast_in_doublyCircularLinkedList.c` | Deletes the first and last nodes of a doubly circular list, reaching the last node directly through `prev`. |
| `deleteMiddle_in_Circular_linkedList.c` | Deletes the middle node of a circular list, or both middle nodes when the length is even. |

### Stacks and queues

| File | What it does |
|---|---|
| `ImplematingQueue_using_PushPop_and2Stacks.c` | A menu-driven queue (enqueue, dequeue, exit) built from two linked-list stacks. |
| `DleteNth_elementOfQueueFromStart_linkedList.c` | A linked-list queue that deletes the Nth element counted from the front. |

### Trees

| File | What it does |
|---|---|
| `TreeDetermination_whenGiven_InOrderAndPostOrder_Traversals.c` | Rebuilds a binary tree from its inorder and postorder traversals and prints its preorder. |
| `elementsInRange_BSTree.c` | Prints the elements of a binary search tree between M and N, skipping subtrees that can't contain any. |
| `PairsInTree_thatUpTo_SUM.c` | Prints all pairs of values in a binary search tree that add up to a given sum. |
| `PathforSUM_in_Tree.c` | Prints the root-to-leaf path whose values add up to a given sum (uses a built-in example tree). |
| `SumOfChildrenOf_a_NodeIn_NaryTree.c` | Prints the sum of a node's children in an N-ary tree stored as first-child/next-sibling (uses a built-in example tree). |

### Arrays and sets

| File | What it does |
|---|---|
| `FirstElement_among_repeated_elements_in_an_array_basic.c` | Finds the first element that appears more than once by comparing every pair, O(n²). |
| `Optimized_FirstElement_among_repeated_elements_in_an_array.c` | Solves the same problem with a counting array, O(n). |
| `minmum_distance_between_two_numbers_in_a_size10array.c` | Reads a 10-element array and two numbers, and prints the smallest index distance between them. |
| `union_intersection_of_2MathematicalSet_arrays.c` | Prints the union and intersection of two sets stored as arrays. |

## Build and run

```bash
gcc addIntegers_linkedLists.c -o add_lists
./add_lists
```

## Known limitations

- Input is read with `scanf` and validated only minimally.
- Most linked-list programs don't free their nodes before exiting.
- `Optimized_FirstElement…` only supports values 0 to 9, because it uses a counting array of size 10.
- `addIntegers_linkedLists.c` stores the sum in an `int`, so it overflows beyond about 9 digits.
- `PathforSUM_in_Tree.c` and `SumOfChildrenOf_a_NodeIn_NaryTree.c` use fixed example trees, not user input.

## Coming next

- Sorting algorithms: bubble, selection, insertion, merge sort.
