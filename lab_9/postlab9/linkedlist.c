/* linked list */
/*Derek Wu*/
/*8AM Lab */
/*4/12/2018*/

#include <stdio.h>
#include <stdlib.h>


struct node { 
  int x; 
  struct node *next; 
};

struct list { 
  struct node* head;
  struct node* tail;   
};

struct node* create( int data, struct node*next) { 
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node -> x = data; 
  new_node -> next = next;
  return new_node;  
};

int main() {
  int val;
  int i;
  struct list* c_list = (struct list*)malloc(sizeof(struct list));
  c_list -> head = (struct node*)malloc(sizeof(struct node));
  c_list -> tail = (struct node*)malloc(sizeof(struct node));  
  c_list->head -> next = c_list->tail;
  printf ("Enter how many values to input: ");
  scanf("%d", &val);  
  for (i = 0; i < val; i++) { 
    int count;
    int nodeval; 
    count = i + 1; 
    printf("Enter value %d: ",count);
    scanf("%d", &nodeval);
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new -> x = nodeval;  
    new -> next = c_list -> head -> next;
    c_list -> head -> next = new;
  } 
  struct node* it = (struct node*)malloc(sizeof(struct node));
  it = c_list -> head -> next; 
  for (i = 0; i < val; i++) { 
    printf("%d", it -> x);
    it = it -> next; ; 
  }
  printf("\n");
  free(c_list); 
  return 0; 
} 
