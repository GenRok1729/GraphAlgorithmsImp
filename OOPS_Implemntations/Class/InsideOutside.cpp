class MyClass {        // The class
  public:              // Access specifier
    void myMethod() {  // Method/function defined inside the class
      cout << "Hello World!";
    }
};

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
__________________________________________________________________________________________________________________________________________________________

class MyClass {        // The class
  public:              // Access specifier
    void myMethod();   // Method/function declaration
};

// Method/function definition outside the class
void MyClass::myMethod() {
  cout << "Hello World!";
}

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}

_______________________________________________________________________________________________________________________________________________________________

// C++ program to show that we can access a global variable 
// using scope resolution operator :: when there is a local  
// variable with same name  
#include<iostream>  
using namespace std; 
   
int x;  // Global x 
   
int main() 
{ 
  int x = 10; // Local x 
  cout << "Value of global x is " << ::x; 
  cout << "\nValue of local x is " << x;   
  return 0; 
}

_______________________________________________________________________________________________________________________________________________________________

// C++ program to show that scope resolution operator :: is used 
// to define a function outside a class 
#include<iostream> 
using namespace std; 

class A 
{ 
public: 

// Only declaration 
void fun(); 
}; 

// Definition outside class using :: 
void A::fun() 
{ 
cout << "fun() called"; 
} 

int main() 
{ 
A a; 
a.fun(); 
return 0; 
} 

_______________________________________________________________________________________________________________________________________________________________

// Use of scope resolution operator for namespace. 
#include<iostream> 


int main(){ 
	std::cout << "Hello" << std::endl; 

} 

_______________________________________________________________________________________________________________________________________________________________

// Use of scope resolution class inside another class. 
#include<iostream> 
using namespace std; 

class outside 
{ 
public: 
	int x; 
	class inside 
	{ 
	public: 
			int x; 
			static int y; 
			int foo(); 

	}; 
}; 
int outside::inside::y = 5; 

int main(){ 
	outside A; 
	outside::inside B; 

} 

_______________________________________________________________________________________________________________________________________________________________

