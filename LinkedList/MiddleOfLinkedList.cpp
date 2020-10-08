#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int x){
            data = x;
            next = NULL;
        }
        Node(){
            data = 0;
            next = NULL;
        }
};
class LinkedList{
    private:
        Node *root;
    public:
        LinkedList(){
            root = NULL;
        }

        Node* getRoot(){
            return root;
        }

        void addNode(int data){
            if(root == NULL){
                root = new Node(data);
            }
            else{
                Node *temp = root;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = new Node(data);
            }
        }

        void display(){
            Node *temp = root;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
        //returns middle element of linked list using two pointer method
        int middle(){
            if(root == NULL){
                cout<<"Exception occured may be linked list is empty\n";
            }
            Node *t1 = root;
            Node *t2 = t1->next;
            while(t2!=NULL){
                t1 = t1->next;
                if(t2->next == NULL){
                    t2 = t2->next;
                }
                else{
                    t2 = t2->next->next;
                }
            }
            return t1->data;
        }
        //delete node if node found in linked list
        void deleteFirstOccurence(int value){
            if(root== NULL){
                cout<<"Empty Linked List found"<<endl;
            }
            Node * temp = root;
            while(temp->next && temp->next->data != value)
                temp = temp->next;
            if(temp->next)
                temp->next = temp->next->next;
            else{
                cout<<"No node found having value "<<value<<endl;
            }
        }

        void deleteAllOccurence(int value){
            if(root== NULL){
                cout<<"Empty Linked List found"<<endl;
            }
            Node * temp = root, *prev = NULL;
            while(temp!=NULL){
                if(temp->data == value){
                    temp = temp->next;
                    prev->next = temp;
                    if(temp){
                        temp = temp->next;
                    }
                }
                else{
                    prev = temp;
                    temp = temp->next;
                }
            }
        }
        //returns largest element in the linked list
        int largest(){
            Node * t = root;
            if(root==NULL){
                return -1;
            }
            int max = root->data;
            while(t!=NULL){
                if(max< t->data)
                    max = t->data;
                t = t->data;
            }
            return max;
        }
        //returns smallest element in the linked list
        int smallest(){
            Node * t = root;
            if(root==NULL){
                return -1;
            }
            int min = root->data;
            while(t!=NULL){
                if(min> t->data)
                    min = t->data;
                t = t->data;
            }
            return min;
        }
        
        //Traverse linked list using two pointers.
        //Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
        //If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
        bool detectLoop(){
            Node* t1 = root, t2 = root;
            while(t1 && t2 && t2->next){
                t1 = t1->next;
                t2 = t2->next->next;
                if(t1 == t2){
                    return true;
                }
            }
            return false;
        }

};
//merge two sorted linked list
LinkedList mergeTwoList(LinkedList l1, LinkedList l2){
    LinkedList mergeList = LinkedList();
    Node *root1 = l1.getRoot();
    Node *root2 = l2.getRoot();
    while(root1 && root2){
        if(root1->data < root2->data){
            mergeList.addNode(root1->data);
            root1 = root1->next;
        }
        else{
            mergeList.addNode(root2->data);
            root2 = root2->next;
        }
    }
    while(root1){
        mergeList.addNode(root1->data);
        root1 = root1->next;
    }
    while (root2){
        mergeList.addNode(root2->data);
        root2 = root2->next;
    }
    return mergeList;
}

//Linked List must be sorted
void removeDuplicatesFromLinkedList(LinkedList l){
    Node *t = l.getRoot();
    if(t == NULL)
        return;
    while(t != NULL){
        Node *temp = t;
        while(temp && t->data == temp->data)
            temp = temp->next;
        t->next = temp;
        t = temp;
    }
}

//function will return the address of node where intersection occurred
//count nodes in list 1 and list2 
//calculate difference
//starts traversing larger list to d 
// now both list have same node 
//traverse both list simultaneously till we found same addressed node
Node* intersectionTwoLinkedList(LinkedList l1, LinkedList l2){
    if(l1.getRoot() == NULL || l2.getRoot() == NULL){
        return new Node(-1);
    }
    int countl1=0,countl2=0;
    Node * t = l1.getRoot();
    while(t != NULL){
        countl1++;
        t = t->next;
    }
    t = l2.getRoot();
    while(t != NULL){
        countl2++;
        t = t->next;
    }
    int d = countl1 - countl2;
    Node *t1 = l1.getRoot(),*t2 = l2.getRoot();
    if(d<0){
        while(d!=0){
            t2 = t2->next;
            d++;
        }
    }
    else{
        while(d!=0){
            t1 = t1->next;
            d--;
        }
    }
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

int main(){
    LinkedList l1 = LinkedList();
    l1.addNode(1);
    l1.addNode(1);
    l1.addNode(2);
    l1.addNode(3);
    l1.addNode(1);
    l1.addNode(5);
    l1.deleteAllOccurence(1);
    l1.display();
    //cout<<l1.middle()<<endl;
    //LinkedList mergedNewLinkedList = mergeTwoList(l1, l2);
    //mergedNewLinkedList.display();
    //Node * res = intersectionTwoLinkedList(l1, l2);
    return 0;
}