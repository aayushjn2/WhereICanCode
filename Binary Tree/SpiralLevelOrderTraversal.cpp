// C++ program to print level order traversal 
// in spiral form using one deque. 
#include <bits/stdc++.h> 
using namespace std; 

class Node { 
public: 
	int data; 
	Node *left, *right; 
	Node(int val) 
	{ 
		data = val; 
		left = NULL; 
		right = NULL; 
	} 
}; 

void spiralOrder(Node* root) {
	deque<Node*> d;
	d.push_back(root);
	int dir = 0; 
	while (!d.empty()) { 
		int size = d.size(); 
		while (size--) {
			if (dir == 0) { 
				Node* temp = d.back(); 
				d.pop_back(); 
				if (temp->right) 
					d.push_front(temp->right); 
				if (temp->left) 
					d.push_front(temp->left); 
				cout << temp->data << " "; 
			} 
			else { 
				Node* temp = d.front(); 
				d.pop_front(); 
				if (temp->left) 
					d.push_back(temp->left); 
				if (temp->right) 
					d.push_back(temp->right); 
				cout << temp->data << " "; 
			} 
		} 
		cout << endl;
		dir = 1 - dir; 
	} 
} 

int main(){ 
	// Build the Tree 
	Node* root = new Node(10); 
	root->left = new Node(20); 
	root->right = new Node(30); 
	root->left->left = new Node(40); 
	root->left->right = new Node(60);
	spiralOrder(root); 
	return 0; 
} 
