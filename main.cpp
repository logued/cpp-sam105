// sam105
// Passing pointers into functions
// - pointer to constant int

#include <iostream>
using namespace std;

// function prototypes
// Both functions declare two 'pointer to int' parameters
int add( int*, int*); // add - takes two "pointer to int" arguments and returns an int
void swap_by_pointer(int* , int*);

int main() {
    cout << "Sam105 - passing pointers into functions" << endl;

    int x = 22;
    int y = 44;
    cout << "Initially, x is : " << x << ",  and y is : " << y << endl;

    // We have seen previously that we can pass arguments by value or by reference.
    // A third alternative is to pass argumnets into a function by passing the
    // addresses of the source of the arguments.
    // To do this we use the address operator "&" to get the addresses of x and y,
    // and we pass those addresses as arguments.  This enables the function receiving
    // the addresses to have access to the variables x and y.
    //
    int sum = add( &x,&y ); // pass addresses of x and y
    cout << "Using add(&x,&y) : sum = " << sum << endl;

    // When we pass the address of some objects (x and y) into a function, then that function
    // has access to the objects and can get their value, and can make changes to the objects.
    // We can write a swap method that uses pointers to swap the contents of the variables x and y.

    swap_by_pointer( &x, &y );	// pass the addresses of x and y - (pass addresses by value)

    cout << "After calling swap_by_pointer(): x is now : " << x << ",  and y is now : " << y << endl;

    //TODO  Code a solution to the question below and test.
    // Q1.
    //    - write a function increase(...) that will receive the address of an int
    //      in a pointer parameter.  Use the pointer parameter to add 1 to the value
    //      in the variable that the pointer points at.
    //      Call the function passing in the address of x, and display the value of x
    //      after the function has finished.
    //
    //TODO
    // Q2.  The add() function below does not need to modify the values of x and y (only access them)
    //      so, we can prevent the pointers from accidentally modifying the values of x and y
    //      by declaring the pointers as type "pointer to constant int". You will have to update the
    //      function prototypes also.
    //      Make these changes.

    return 0;
}

// The add() function will receive the addresses of the int variables x and y as arguments.
// As the arguments are addresses, we must declare pointer parameters to store the addresses.
// The pointers must be of type "pointer to int", (int*), as the addresses are addresses of
// integer values x and y.
// In the function, we dereference the pointers to get at the values that they point to.
//
int add(  int* ptr1,  int* ptr2) {
    int sum = *ptr1 + *ptr2;    // get the values that the pointers point at
    return sum;
}

// Function receives the addresses of two variables (x and y).
// We use dereferencing of pointers to get access to the variables x and y
//
void swap_by_pointer( int* ptr1, int* ptr2 )
{
    int temp = *ptr1;   // get the value pointed to by ptr1 and assign it to temp
    *ptr1 = *ptr2;      // get the value from where ptr2 points, and assign it to where ptr1 points
    *ptr2 = temp;       // get the value from temp, and assign it to where ptr2 points
}



