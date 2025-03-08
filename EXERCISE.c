#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int data;
    struct Block *next;
    struct Block *prev;
} block;

block* create_block() {
    block* new_block = (block*)malloc(sizeof(block));
    scanf("%d", &new_block->data);
    new_block->next = new_block->prev = NULL;
    return new_block;
}

block* create_block_v2(int data) {
    block* new_block = (block*)malloc(sizeof(block));
    new_block->data = data;
    new_block->next = new_block->prev = NULL;
    return new_block;
}

int length(block* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

block* add_at_position(block* head, block* bl, int add_index) {
    if (add_index <= 0) {
        bl->next = head;
        if (head) head->prev = bl;
        return bl;
    }
    block* current = head;
    int i = 0;
    while (current && i < add_index - 1) {
        current = current->next;
        i++;
    }
    if (!current) return head;
    bl->next = current->next;
    bl->prev = current;
    if (current->next) current->next->prev = bl;
    current->next = bl;
    return head;
}

block* delete_at_position(block* head, int del_index) {
    if (!head) return NULL;
    if (del_index <= 0) {
        block* temp = head->next;
        if (temp) temp->prev = NULL;
        free(head);
        return temp;
    }
    block* current = head;
    int i = 0;
    while (current && i < del_index) {
        current = current->next;
        i++;
    }
    if (!current) return head;
    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    free(current);
    return head;
}

void display_list(block* head) {
    if (!head) return;
    printf("%d ", head->data);
    display_list(head->next);
}

block* last_node(block* head) {
    while (head && head->next) head = head->next;
    return head;
}

void display_list_reverse(block* last_block) {
    while (last_block) {
        printf("%d ", last_block->data);
        last_block = last_block->prev;
    }
}

int search(block* head, int search_val) {
    while (head) {
        if (head->data == search_val) return 1;
        head = head->next;
    }
    return 0;
}

block* split_pos_neg(block* head) {
    block *pos = NULL, *neg = NULL, *temp;
    while (head) {
        temp = create_block_v2(head->data);
        if (head->data >= 0) {
            temp->next = pos;
            if (pos) pos->prev = temp;
            pos = temp;
        } else {
            temp->next = neg;
            if (neg) neg->prev = temp;
            neg = temp;
        }
        head = head->next;
    }
    printf("Positive: ");
    display_list(pos);
    printf("\nNegative: ");
    display_list(neg);
    printf("\n");
    return pos;
}

int is_list_sorted(block* list) {
    if (!list) return 1;
    while (list->next) {
        if (list->data > list->next->data) return 0;
        list = list->next;
    }
    return 1;
}

block* merge_sort(block* l1, block* l2) {
    block *result = NULL, *temp;
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            temp = create_block_v2(l1->data);
            l1 = l1->next;
        } else {
            temp = create_block_v2(l2->data);
            l2 = l2->next;
        }
        if (!result) result = temp;
        else {
            temp->prev = last_node(result);
            last_node(result)->next = temp;
        }
    }
    while (l1) {
        temp = create_block_v2(l1->data);
        temp->prev = last_node(result);
        last_node(result)->next = temp;
        l1 = l1->next;
    }
    while (l2) {
        temp = create_block_v2(l2->data);
        temp->prev = last_node(result);
        last_node(result)->next = temp;
        l2 = l2->next;
    }
    return result;
}

int main() {
    block *head = NULL, *bl;
    int n, data, index;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        bl = create_block();
        head = add_at_position(head, bl, i);
    }

    printf("List: ");
    display_list(head);
    printf("\n");

    printf("Length: %d\n", length(head));

    printf("Enter value to search: ");
    scanf("%d", &data);
    printf("Found: %s\n", search(head, data) ? "Yes" : "No");

    printf("Split positive and negative:\n");
    split_pos_neg(head);

    printf("Enter index to delete: ");
    scanf("%d", &index);
    head = delete_at_position(head, index);
    printf("List after deletion: ");
    display_list(head);
    printf("\n");

    printf("List in reverse: ");
    display_list_reverse(last_node(head));
    printf("\n");

    printf("Is list sorted? %s\n", is_list_sorted(head) ? "Yes" : "No");

    return 0;
}
