#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left = NULL;
        Node *right = NULL;
        Node(int x){
            data = x;
        }
}

Node *CLLToBST(Node *LL_1, Node *LL_2){

}

Node *mergeTwoLL(Node *LL_1, Node *LL_2){

}

Node *BST_to_LL(Node *root){

}

Node *mergeTwoBST(Node * root_1, Node *root_2){
    if(!root_1){
        return root_2;
    }
    if(!root_2){
        return root_1;
    }
    Node *list_1 = BST_to_LL(root_1);
    Node *list_2 = BST_to_LL(root_2);
    Node *list = mergeTwoLL(list_1,list_2);
    Node *root = CLLToBST(list_1, list_2);
    return root;
}

int main(){
    Node *root = mergeTwoBST(root_1,root_2);
}