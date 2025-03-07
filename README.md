# DOUBLY LINKED LISTS  

## 📌 PROBLEM  

### 📝 Basic Concepts  
Doubly linked lists are data structures where each node has:  
- A `next` pointer pointing to the next node.  
- A `prev` pointer pointing to the previous node.  

### 📌 List Structure in C  
**typedef struct Block {**  
**int data;**  
**struct Block *next;**  
**struct Block *prev;**  
**} block;**  

## 🚀 Tasks to Complete  

1. A function `block* create_block()` that creates a node and assigns data to it.  
2. Propose another function `block* create_block_v2(int data)` that creates a node and assigns the given data to it.  
3. Write a function `int length(block* head)` that returns the length of the given doubly linked list.  
4. A function `block* add_at_position(block* head, block* bl, int add_index)` that inserts a new node at a given position.  
5. A function `block* delete_at_position(block* head, int del_index)` that removes a node from the list at a given position.  
6. A recursive function `void display_list(block* head)` that displays the content of the list.  
7. A function `block* last_node(block* head)` that returns the last node of the doubly linked list.  
8. A function `void display_list_reverse(block* last_block)` that takes the address of the last element of the list as a parameter and displays the list in reverse order.  
9. A function `int search(block* head, int search_val)` that returns `1` if the searched value exists in the list, otherwise `0`. The list is traversed in both directions, stopping once the desired element is found.  
10. A function `block* split_pos_neg(block* head)` that receives a list and splits it into two doubly linked lists:  
    - One containing positive values.  
    - One containing negative values.  
11.  
    A. A function `int is_list_sorted(block* list)` that returns `1` if the list is sorted, otherwise `0`.  
    B. A function `block* merge_sort(block* l1, block* l2)` that takes two sorted doubly linked lists and merges them into a single sorted list.  

12. **Test all these functions in the `main()` program.**  
