#include <stdio.h>
#include <stdlib.h>

struct data{
	
    int age;
    struct data *next; 
    
};

struct data *create_node(int age){
	
    struct data *node = (struct data*)malloc(sizeof(struct data));
    
    if (node == NULL) {
    	
        printf("Memory allocation failed.\n");
        exit(1);
        
    }
    
    node->next = NULL;
    node->age = age;
    
    return node;
    
}

struct data *push_head(struct data *head, int age){
	
    struct data *node = create_node(age);
    node->next = head;
    head = node;
    
    return head;
    
}

struct data *push_tail(struct data *head, int age){
	
    struct data *node = create_node(age);
    
    if (head == NULL) {
    	
        head = node;
        return head;
        
    }
    
    struct data *temp = head; 
    
    while (temp->next != NULL){
    	
        temp = temp->next;
        
    }
    
    temp->next = node; 
    return head;
    
}

struct data *pop_head(struct data *head){
	
    if (head == NULL) {
    	
        printf("Linked list is empty.\n");
        
        return NULL;
        
    }
    
    struct data *temp = head;
    head = head->next;
    
    free(temp);
    
    return head;
    
}

struct data *pop_tail(struct data *head){
	
    if (head == NULL) {
    	
        printf("Linked list is empty.\n");
        
        return NULL;
        
    }
    
    if (head->next == NULL) {
    	
        free(head);
        
        return NULL;
        
    }
    
    struct data *del = head;
    struct data *temp = head;
    
    while (del->next != NULL){
    	
        temp = del;
        del = del->next;
        
    }
    
    temp->next = NULL;
    
    free(del);
    
    return head;
    
}

void pop_search(struct data** head, int value) {
	
    struct data* temp = *head;
    struct data* prev = NULL;
    
    if (temp != NULL && temp->age == value) {
    	
        *head = temp->next;
		
        free(temp); 
		        
        return;
        
    }
    
    while (temp != NULL && temp->age != value) {
    	
        prev = temp;
        temp = temp->next;
        
    }
    
    if (temp == NULL) {
    	
        printf("Node with value %d not found.\n", value);
        
        return;
        
    }
    
    prev->next = temp->next;
    
    free(temp); 
    
}

void push_middle(struct data **head, int age) {
	
    if (*head == NULL) {
    	
        *head = create_node(age);
        
        return;
        
    }
    
    struct data *slow_ptr = *head;
    struct data *fast_ptr = *head;
    struct data *prev = NULL;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
    	
        prev = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
    }

    struct data *node = create_node(age);
    
    if (prev != NULL) {
        
        node->next = slow_ptr->next;
        slow_ptr->next = node;
        
    } 
	
	else {
        
        node->next = *head;
        *head = node;
        
    }
    
}

void print_linked_list(struct data *head){
	
    struct data *temp;
    temp = head;
    
    int count = 0;
    
    while (temp != NULL){
    	
        printf("data ke-%d : %d\n", count, temp->age);
        temp = temp->next;
        count++;
        
    }
    
}

int main(){
	
    struct data *head;
    
    head = create_node(10);
    head = push_head(head, 5);
    head = push_head(head, 2);
    head = push_tail(head, 15);
    head = push_tail(head, 7);
    head = pop_head(head);
    head = pop_tail(head);
    
    pop_search(&head, 5);
    
    push_middle(&head, 7); 
    print_linked_list(head);
    
    return 0;
    
}
