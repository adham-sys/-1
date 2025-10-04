#include<stdio.h>
#include<stdlib.h>
int NUM_OF_NODES = 5;
typedef struct dbl{
  int val;
  struct dbl *next;
  struct dbl *prev;
} dbl; 
dbl* insert_node(){
  dbl *nodes_allocated=malloc(sizeof(dbl) * NUM_OF_NODES);
  (nodes_allocated==NULL)?printf("Memory not allocated\n"),exit(1):printf("Memory allocated\n"); 
  int NON=0; 
  printf("Enter the value to be inserted\n");
  while(NON < NUM_OF_NODES){
   int valofitem;
   scanf("%d",&valofitem); 
   nodes_allocated[NON].val=valofitem;
   nodes_allocated[NON].next=NULL;
   nodes_allocated[NON].prev=NULL;  
   NON++;
  }
  for(int i=0;i<NUM_OF_NODES;i++){
      nodes_allocated[i].next=(i==NUM_OF_NODES-1)?NULL:&nodes_allocated[i+1];
      nodes_allocated[i].prev=(i==0)?NULL:&nodes_allocated[i-1]; 
  };
  // free(nodes_allocated);
  return nodes_allocated;
};
dbl* insert_at_beg(dbl* first_of_node){
  if(first_of_node==NULL){
    printf("List is empty\n");
  
  }
   dbl *becomF=malloc(sizeof(dbl));
   (becomF==NULL)?printf("Memory not allocated\n"),exit(1):printf("Memory allocated\n");
   printf("Enter the value to be inserted at beginning\n");
   scanf("%d",&becomF->val);
   becomF->prev=NULL;
   becomF->next=first_of_node;
   return becomF;
}
void insert_at_end(dbl* first){
  if(first==NULL){
    printf("List is empty\n");
  }
  while(first->next!=NULL){
    first=first->next;
  }
  first->next=malloc(sizeof(dbl));
  (first->next==NULL)?printf("Memory not allocated\n"),exit(1):printf("Memory allocated\n");
  first->next->prev=first;
  first->next->next=NULL;
  printf("Enter the value to be inserted at end\n");
  scanf("%d",&first->next->val);
  printf("------------------------------\n");
  
}
void display(dbl* first){

  if(first==NULL){
    printf("List is empty\n");
    
  }
  dbl *temp=first;
  while(temp!=NULL){
    printf("%d\n",temp->val);
    temp=temp->next;
  }

}
dbl* delete_node(dbl* first){
  printf("ENTER VALUE TO BE DELETE\n");
  int CANCEL_VALUE;
  scanf("%d",&CANCEL_VALUE);
  dbl *head = first;
  while(head!=NULL){
    if (head->val==CANCEL_VALUE){
      if(head->prev == NULL && head->next == NULL){
            free(head);
            return NULL;  
       }
      if(head->prev==NULL){
        first= head->next;
        first->prev=NULL;
      }else if(head->next==NULL){
        head->prev->next=NULL;
      }else{
       head->prev->next = head->next;
       head->next->prev = head->prev;
      }
    break;
   }else{
    head=head->next;
   }
  }
  return first;
}
int main(){
  dbl *first_of_node = insert_node();  
  first_of_node = insert_at_beg(first_of_node);
  insert_at_end(first_of_node);
  first_of_node = delete_node(first_of_node);  
 
  //  search_node();
  display(first_of_node);    
        
  return 0;
}