// C++ program to demonstrate public
// access modifier

#include<iostream>
using namespace std;

// class definition
class Circle
{
	public: 
		double radius;
		
		double compute_area()
		{
			return 3.14*radius*radius;
		}
	
};

// main function
int main()
{
	Circle obj;
	
	// accessing public datamember outside class
	obj.radius = 5.5;
	
	cout << "Radius is: " << obj.radius << "\n";
	cout << "Area is: " << obj.compute_area();
	return 0;
}
____________________________________________________________________________________________________________________________________________________________


// C++ program to demonstrate private
// access modifier

#include<iostream>
using namespace std;

class Circle
{ 
	// private data member
	private: 
		double radius;
	
	// public member function 
	public: 
		double compute_area()
		{ // member function can access private 
			// data member radius
			return 3.14*radius*radius;
		}
	
};

// main function
int main()
{ 
	// creating object of the class
	Circle obj;
	
	// trying to access private data member
	// directly outside the class
	obj.radius = 1.5;
	
	cout << "Area is:" << obj.compute_area();
	return 0;
}
____________________________________________________________________________________________________________________________________________-----____

// C++ program to demonstrate private
// access modifier

#include<iostream>
using namespace std;

class Circle
{ 
	// private data member
	private: 
		double radius;
	
	// public member function 
	public: 
		void compute_area(double r)
		{ // member function can access private 
			// data member radius
			radius = r;
			
			double area = 3.14*radius*radius;
			
			cout << "Radius is: " << radius << endl;
			cout << "Area is: " << area;
		}
	
};

// main function
int main()
{ 
	// creating object of the class
	Circle obj;
	
	// trying to access private data member
	// directly outside the class
	obj.compute_area(1.5);
	
	
	return 0;
}
_______________________________________________________________________________________________________________________________________________________


// C++ program to demonstrate
// protected access modifier
#include <bits/stdc++.h>
using namespace std;

// base class
class Parent
{ 
	// protected data members
	protected:
	int id_protected;
	
};

// sub class or derived class from public base class
class Child : public Parent
{
	public:
	void setId(int id)
	{
		
		// Child class is able to access the inherited 
		// protected data members of base class
		
		id_protected = id;
		
	}
	
	void displayId()
	{
		cout << "id_protected is: " << id_protected << endl;
	}
};

// main function
int main() {
	
	Child obj1;
	
	// member function of the derived class can
	// access the protected data members of the base class
	
	obj1.setId(81);
	obj1.displayId();
	return 0;
}
_______________________________________________________________________________________________________________________________________________________________

