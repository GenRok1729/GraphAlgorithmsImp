class Node { 
private: 
	int key; 
	Node* next; 
	/* Other members of Node Class */

	// Now class LinkedList can 
	// access private members of Node 
	friend class LinkedList; 
}; 

__________________________________________________________________________________________________________________________________________________________________

class Node { 
private: 
	int key; 
	Node* next; 

	/* Other members of Node Class */
	friend int LinkedList::search(); 
	// Only search() of linkedList 
	// can access internal members 
}; 

__________________________________________________________________________________________________________________________________________________________________

#include <iostream> 
class A { 
private: 
	int a; 

public: 
	A() { a = 0; } 
	friend class B; // Friend Class 
}; 

class B { 
private: 
	int b; 

public: 
	void showA(A& x) 
	{ 
		// Since B is friend of A, it can access 
		// private members of A 
		std::cout << "A::a=" << x.a; 
	} 
}; 

int main() 
{ 
	A a; 
	B b; 
	b.showA(a); 
	return 0; 
} 

__________________________________________________________________________________________________________________________________________________________________

#include <iostream> 

class B; 

class A { 
public: 
	void showB(B&); 
}; 

class B { 
private: 
	int b; 

public: 
	B() { b = 0; } 
	friend void A::showB(B& x); // Friend function 
}; 

void A::showB(B& x) 
{ 
	// Since showB() is friend of B, it can 
	// access private members of B 
	std::cout << "B::b = " << x.b; 
} 

int main() 
{ 
	A a; 
	B x; 
	a.showB(x); 
	return 0; 
}

__________________________________________________________________________________________________________________________________________________________________

#include <iostream> 

class A { 
	int a; 

public: 
	A() { a = 0; } 

	// global friend function 
	friend void showA(A&); 
}; 

void showA(A& x) 
{ 
	// Since showA() is a friend, it can access 
	// private members of A 
	std::cout << "A::a=" << x.a; 
} 

int main() 
{ 
	A a; 
	showA(a); 
	return 0; 
}

__________________________________________________________________________________________________________________________________________________________________


