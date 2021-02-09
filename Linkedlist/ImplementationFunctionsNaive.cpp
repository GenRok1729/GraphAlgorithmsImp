#include<bits/stdc++.h>
using namespace std;


class Node{
public: 
    int data;
    Node* next;
};

void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
} 


int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    
    head->data = 1; // assign data in first node 
	head->next = second;
	
		// assign data to second node 
	second->data = 2; 

	// Link second node with the third node 
	second->next = third; 

    third->data = 3; // assign data to third node 
	third->next = NULL; 
	
	
	    printList(head); 


	return 0; 
}


