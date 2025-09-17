#include<stdio.h>
#include<stdlib.h>
typedef  struct linked_list{
    int item;
   struct linked_list *next;
  } ls;

ls* create_node(int data){

  ls *seq = malloc(sizeof(ls));
  if (&seq ==NULL){
    printf("Memory allocation failed\n");
    exit(0);
  }
  seq->item=data;
  seq->next=NULL;
  return seq; 
  free(seq);
}
void show_node(ls*head){
  // printf("%d\n",head->next->item);
  ls* current=head;
  while(current!=NULL){
    printf("%d\n",current->item);
    current=current->next;
  }
}  
ls *head=NULL;
ls *last;
void* insert_node(int data){
  
  if(head==NULL)
   head=create_node(data);
   
  else{
    ls*new_node=create_node(data);
    head->next=new_node;
    head=new_node;
    
    //  ls *new_node=create_node(data);
    //   last=head;
    //   while(last->next!=NULL){
    //     last=last->next;
    //   }
    //   last->next=new_node;   
  }
}
void* insert_at_beginning(ls*head,int value){
  ls*new_node=create_node(value);
  new_node->next=head;
  head=new_node;
  // show_node(head);
}
void* insert_at_end(ls*head,int num){
  last=head;
 ls*new_node=create_node(num);
 while(1){
  if(head->next!=NULL){
     head=head->next;
  }else{
    head->next=new_node;
    new_node->next=NULL;
    break;
  }
 
    
 }


 

//  show_node(head);
}
void delete_node(ls*head,int val){
  last=NULL;
  while(head->next->next!=NULL){
    if(head->item==val){      
       *head=*(head->next);
    }else{
       head=head->next;
    }
  }
  if(head->next->next==NULL){
    if(head->item==val){
      *head=*(head->next);
    }else{
      if(head->next->item==val){
       free(head->next->next);
       head->next=NULL;
     }
    }
  }
  
}

int main(){
  ls*first=insert_node(5);
  int value=7;
  int nu=66;
  insert_node(10);
  insert_node(15);
  insert_node(20);
  ls*new_first=insert_at_beginning(first,value);
  ls*last_val= insert_at_end(new_first,nu);
  delete_node(new_first,20);
  show_node(new_first);
 

  
  
  
}