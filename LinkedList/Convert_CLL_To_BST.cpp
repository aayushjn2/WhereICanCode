"""
1) Get the Middle of the linked list and make it root.
2) Recursively do same for left half and right half.
       a) Get the middle of left half and make it left child of the root
          created in step 1.
       b) Get the middle of right half and make it right child of the
          root created in step 1.
    O(NlogN)
"""
"""
O(N)
"""
#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
      int data;
      Node *next;
      Node *prev;
}

int countNodes(Node* head){
   int count = 0;
   Node *temp = head;
   while(temp){
      temp = temp->next;
      count++;
   }
   return count;
}

void push(Node *head, int data){
   Node* new_node = new Node();
   new_node->data = data;
   new_node->prev = NULL;
   new_node->next = head;
   if(head != NULL){
      head->prev = new_node;
   }
   head = new_node;
}

void printList(Node * root){
   Node *temp = root;
   while(temp != NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
   }
}

void preOrder(Node* root){
   if(root == NULL){
      return;
   }
   cout<<root->data<<" ";
   preOrder(root->prev);
   preOrder(root->next);
}

void inorder(Node* root){
   if(root == NULL){
      return NULL;
   }
   inorder(root->prev);
   cout<<root->data<<" ";
   inorder(root->next);
}

Node* sortedListToBST(Node *head){
   int n = countNodes(head);
   return sortedListToBSTRecur(head, n);
}

Node* sortedListToBSTRecur(Node *head, int n){
   if(n<=0){
      return NULL;
   }
   Node *left = sortedListToBSTRecur(head,n/2);
   Node *root = head;
   root->prev = left;
   root = root->next;
   root->next = sortedListToBSTRecur(head, n - n/2 -1);
   return root;
}

int main(){
   Node *head = NULL;
   push(head,7);
   push(head,6);
   push(head,5);
   push(head,4);
   push(head,3);
   push(head,2);
   push(head,1);
   printList(head);
   Node *root = sortedListToBST(head);
   preOrder(root);
   inorder(root);
   return 0;
}