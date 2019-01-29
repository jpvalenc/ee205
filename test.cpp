#include <iostream>

struct Car {
    char model[81];
    int price;
};

class Person {
    public:
        int getLength(void) {
            return height;
        };
        Person();
        Person(int h) {
            height = h;
        };
    private:
        int age;
        int height;
        
};

// int Person::getLength() {    
//     return height;
// }

int main()
{
   
    int firstvalue, secondvalue;
    int * mypointer;

    Person pke(1);

    mypointer = &firstvalue;
    *mypointer = 10;
    mypointer = &secondvalue;
    *mypointer = 20;
    std::cout << pke.getLength();
    std::cout << "firstvalue is " << firstvalue << '\n';
    std::cout << "secondvalue is " << secondvalue << '\n';
    return 0;

    // malloc and free
    // dynamic allocation of memory on run time
    // if you dont deallocate memory then a memory leak could happen - if the program closes and you dont deallocate it, the memory is not available in the future
    // buffer = pointer of specific data type - cast the buffer to the specific data type to be sure it is that.

    // encapsulation public and private

    // references & is the address-of operator

    //heap - location of dynamically allocated varaibles (newly allocated memory)
    // if you dont deallocate a memory leak may occur

    //stack - location of function params, variables, etc. (function allocated memory)
    //like an array
    //a stack is pushed and popped on a stack like a plate.
    // nested functions aren't very good - you want the stack to have as short of lifespan as possible
    //stack overflow - 

    // new operator dynamically allocates a variable
}
