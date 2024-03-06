#include <stdio.h>
#include <stdlib.h>

struct data {
	
    int age;
    struct data *next;
    struct data *prev;
    
};

struct data *head = NULL;
struct data *tail = NULL;

struct data *create_node(int age) {
	
    struct data *node = (struct data*)malloc(sizeof(struct data));
    
    node->next = NULL;
    node->prev = NULL;
    node->age = age;
    
    return node;
    
}

void push_head(int age) {
	
    struct data *node = create_node(age);
    
    node->next = head;
    
    if (head != NULL)
    
        head->prev = node;
        
    head = node;
    
    if (tail == NULL)
    
        tail = node;
        
}

void push_tail(int age) {
	
    struct data *node = create_node(age);
    
    if (tail != NULL)
    
        tail->next = node;
        
    node->prev = tail;
    
    tail = node;
    
    if (head == NULL)
    
        head = node;
        
}

void push_middle(int age) {
	
    struct data *slow = head;
    struct data *fast = head;

    while (fast != NULL && fast->next != NULL) {
    	
        fast = fast->next->next;
        slow = slow->next;
        
    }

    struct data *node = create_node(age);
    
    node->next = slow->next;
    node->prev = slow;
    
    if (slow->next != NULL)
    
        slow->next->prev = node;
        
    slow->next = node;
    
}

void pop_head() {
	
    if (head == NULL)
    
        return;
        
    struct data *temp = head;
    
    head = head->next;
    
    if (head != NULL)
    
        head->prev = NULL;
        
    free(temp);
    
}

void pop_tail() {
	
    if (tail == NULL)
    
        return;
        
    struct data *temp = tail;
    
    tail = tail->prev;
    
    if (tail != NULL)
    
        tail->next = NULL;
        
    free(temp);
    
}

void print_linked_list() {
	
    struct data *temp = head;
    int count = 1;
    
    while (temp != NULL) {
    	
        printf("Data ke-%d : %d\n", count, temp->age);
        temp = temp->next;
        count++;
        
    }
    
}

int main() {
	
    head = create_node(2);
    tail = create_node(5);
    head->next = tail;
    tail->prev = head;

    push_head(1);
    push_tail(10);
    push_middle(3);
    push_middle(7);

    pop_head();
    pop_tail();

    print_linked_list();

    return 0;
    
}
