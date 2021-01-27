// c++ program to explain 
// Encapsulation 

#include<iostream> 
using namespace std; 


class Encapsulation 
{
    private:   //It is the data hidden from the outside world 
        int x; 
    
    public:    // // function to set value of 
		// variable x 
        void set(int a)
        {
            x = a;
        }
        //To Return 
        int get()
        {
            return x;
        }
};

int main(){
    
    Encapsulation obj;
    
    obj.set(5);
    
    cout << obj.get();
    
    return 0;
}

//In the above program the variable x is made private. This variable can be accessed and manipulated only using the functions get() and set() 
//which are present inside the class. Thus we can say that here, the variable x and the functions get() and set() are binded together which is
//nothing but encapsulation.

//Role of access specifiers in encapsulation
//As we have seen in above example, access specifiers plays an important role in implementing encapsulation in C++. 
//The process of implementing encapsulation can be sub-divided into two steps:
//The data members should be labeled as private using the private access specifiers
//The member function which manipulates the data members should be labeled as public using the public access specifier
____________________________________________________________________________________________________________________________________________________________


