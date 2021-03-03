
// Program 1 
#include <stdio.h> 

class Test { 
	int x; // x is private 
}; 
int main() 
{ 
Test t; 
t.x = 20; // compiler error because x is private 
getchar(); 
return 0; 
} 

----------------------------------------------------------------------------------------------------------------------------------------------------------------

// Program 2 
#include <stdio.h> 
  
struct Test { 
    int x; // x is public 
}; 
int main() 
{ 
  Test t; 
  t.x = 20; // works fine because x is public 
  getchar(); 
  return 0; 
}

_______________________________________________________________________________________________________________________________________________________________


// Program 3 
#include <stdio.h> 

class Base { 
public: 
	int x; 
}; 

class Derived : Base { }; // is equilalent to class Derived : private Base {} 

int main() 
{ 
Derived d; 
d.x = 20; // compiler error becuase inheritance is private 
getchar(); 
return 0; 
} 

______________________________________________________________________________________________________________________________________________________________


// Program 4 
#include <stdio.h> 

class Base { 
public: 
	int x; 
}; 

struct Derived : Base { }; // is equilalent to struct Derived : public Base {} 

int main() 
{ 
Derived d; 
d.x = 20; // works fine becuase inheritance is public 
getchar(); 
return 0; 
} 

____________________________________________________________________________________________________________________________________________________________

