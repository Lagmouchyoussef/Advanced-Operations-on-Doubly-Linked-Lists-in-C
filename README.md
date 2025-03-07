# DOUBLY LINKED LISTS  

## 📌 PROBLEM  

### 📝 Basic Concepts  
Doubly linked lists are data structures where each node has:  
- A `next` pointer pointing to the next node.  
- A `previous` pointer pointing to the previous node.  

### 📌 List Structure in C  
typedef struct Block {
    int data;
    struct Block *psuiv;
    struct Block *pavant;
} block;

## 🚀 Tasks to Complete  

1. A function `block* creer_block()` that creates a node and assigns it its data.  
2. Propose another function `block* creer_block_vers2(int da)` that creates a node and assigns it the given data.  
3. Write a function `int longueur(block* tete)` that returns the length of the given doubly linked list.  
4. A function `block* ajouter_position(block* tete, block* bl, int ind_ajout)` that inserts a new node at a given position.  
5. A function `block* supprimer_position(block* tete, int ind_supp)` that removes a node from the list at a given position.  
6. A recursive function `void afficher_liste(block* tete)` that displays the content of the list.  
7. A function `block* derniere_cellule(block* tete)` that returns the last node of the doubly linked list.  
8. A function `void afficher_liste_indir(block* dernier_block)` that takes the address of the last element of the list as a parameter and displays the list in reverse order.  
9. A function `int chercher(block* tete, int val_cher)` that returns `1` if the searched value exists in the list, otherwise `0`. The list is traversed in both directions, stopping once the desired element is found.  
10. A function `block* eclater_pos_neg(block* tete)` that receives a list and splits it into two doubly linked lists:  
    - One containing positive values.  
    - One containing negative values.  

#### 📌 **Figure 1: Splitting the List**  
## Figure 1: List Grouping

The original list is split into two separate lists: one for positive values and one for negative values.

### Original List:
```plaintext
head
2   -5   -9   9  15
NULL
NULL
Positive Values:
head
2   9   15
NULL
NULL

Negative Values:
head
-5   -9
NULL
NULL


11.  
    A. A function `int liste_est_triee(block* liste)` that returns `1` if the list is sorted, otherwise `0`.  
    B. A function `block* tri_fusion(block* t1, block* t2)` that takes two sorted doubly linked lists and merges them into a single sorted list.  

#### 📌 **Figure 2: Merge Sort**  

Two sorted lists are merged into a single sorted list.

### Input Lists:
```plaintext
List 1:
3   27   38   43

List 2:
9   10   82

3   9   10   27   38   43   82

12. **Test all these functions in the `main()` program.**  
