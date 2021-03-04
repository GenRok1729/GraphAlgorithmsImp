// A program with virtual destructor 
#include<iostream> 

using namespace std; 

class base { 
public: 
	base()	 
	{ cout<<"Constructing base \n"; } 
	virtual ~base() 
	{ cout<<"Destructing base \n"; }	 
}; 

class derived: public base { 
public: 
	derived()	 
	{ cout<<"Constructing derived \n"; } 
	~derived() 
	{ cout<<"Destructing derived \n"; } 
}; 

int main(void) 
{ 
derived *d = new derived(); 
base *b = d; 
delete b; 
getchar(); 
return 0; 
} 

__________________________________________________________________________________________________________________________________________________________________

#include <iostream> 
class Base 
{ 
public: 
	virtual ~Base()=0; // Pure virtual destructor 
}; 
Base::~Base() 
{ 
	std::cout << "Pure virtual destructor is called"; 
} 

class Derived : public Base 
{ 
public: 
	~Derived() 
	{ 
		std::cout << "~Derived() is executed\n"; 
	} 
}; 

int main() 
{ 
	Base *b = new Derived(); 
	delete b; 
	return 0; 
}
