// Cpp program to illustrate the
// concept of Constructors
//#include <iostream>
//using namespace std;

class construct 
{
public:
	int a, b;

	// Default Constructor
	construct()
	{
		a = 10;
		b = 20;
	}
};

int main()
{
	// Default constructor called automatically
	// when the object is created
	construct c;
	cout << "a: " << c.a << endl
		<< "b: " << c.b;
	return 1;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  class Point 
{
private:
    int x, y;
 
public:
    // Parameterized Constructor
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
 
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
 
int main()
{
    // Constructor called
    Point p1(10, 15);
 
    // Access values assigned by constructor
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
 
    return 0;
}
//Parameterized Constructor 
----------------------------------------------------------------------------------------------------------------------------------------------------------------

  // C++ program to illustrate 
// Constructor overloading 
#include <iostream> 
using namespace std; 

class construct 
{ 

public: 
	float area; 
	
	// Constructor with no parameters 
	construct() 
	{ 
		area = 0; 
	} 
	
	// Constructor with two parameters 
	construct(int a, int b) 
	{ 
		area = a * b; 
	} 
	
	void disp() 
	{ 
		cout<< area<< endl; 
	} 
}; 

int main() 
{ 
	// Constructor Overloading 
	// with two different constructors 
	// of class name 
	construct o; 
	construct o2( 10, 20); 
	
	o.disp(); 
	o2.disp(); 
	return 1; 
} 
----------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  
