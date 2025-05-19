#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *find_last(struct node *list, int n) {
    struct node *last = NULL;
    while (list != NULL) {
        if (list->value == n) {
            last = list;
        }
        list = list->next;
    }
    return last;
}

struct node *create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

struct node *append_node(struct node *head, int value) {
    struct node *new_node = create_node(value);
    if (head == NULL) {
        return new_node;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node *list = NULL;
    list = append_node(list, 10);
    list = append_node(list, 20);
    list = append_node(list, 90);
    list = append_node(list, 102);
    list = append_node(list, 66);

    printf("Linked list:\n");
    print_list(list);

    int target = 5;
    struct node *result = find_last(list, target);

    if (result != NULL) {
        printf("Last occurrence of %d points to: %p)\n", target, result->value, (void *)result);
    }
    else {
	printf("%d is not found: Null\n");	
}
    target = 66;
    result = find_last(list, target);   
    if (result != NULL) {
  	printf("Last occurence of %d points to:%p)\n", target, result->value, (void *)result);
}
    else {
	printf("NULL\n");
}
    free_list(list);
    return 0;
}

