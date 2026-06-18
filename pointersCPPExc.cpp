#include <iostream>
 // https://pynative.com/cpp-pointers-exercises/


 void increment_number(int * x){
    *x+=10;
 }
 int main (){
/*   Excerise 1  
 int value =100;
    int * ptr = &value;

    std::cout << "Value: " << *ptr << std::endl;
     */

/* Excerise 2
int number = 10;
int * num_ptr = &number;
*num_ptr = 99;
std::cout << "Number: " << *num_ptr << std::endl;
 */

/* 
Excercise 3
int x = 42;
int * p1=&x;
int * * p2=&p1;

std::cout << "pt2 value: " << **p2 << std::endl;
 */

/* 
Excercise 4
int data[]={10, 20, 30,40,50};
int size = sizeof(data)/4; // int size is 4 bytes!!
int * data_ptr = &data[0];
for (int i =0; i<size;i++){
 std::cout << "Data: " << *data_ptr << std::endl;
data_ptr++;
} */

/* 
Excercise 5
int scores[] = {85, 90, 78, 95, 88};
int * score_ptr = &scores[0];
std::cout << "Score: " << *(score_ptr+2) << std::endl;

 */

/* 
Excercise 6
char word[] = "CODE";
char * p = word;
std::cout << "Word: " << *(p+2) << std::endl;
 */


/* 
Excercise 7

int * safe_ptr = nullptr;
if(safe_ptr == nullptr){
std::cout << "Pointer is null, cannot dereference. " << std::endl;
int valid =10;
    safe_ptr = &valid;
    
}

if(safe_ptr != nullptr)
    std::cout << "Pointer is now valid. Dereferenced value: " << *safe_ptr << std::endl;
 */

 /* 
Excercise 8
int x = 10;
    std::cout << "Before increment: " << x << std::endl;
    increment_number(&x);
    std::cout << "After increment: " << x << std::endl;
 */

/* 
Excercise 9
int i;
int * ptr;

std::cout<<"int size"<< sizeof(i)<<std::endl<< "ptr size: "<< sizeof(ptr)<<std::endl;
 */

/* 
Exercise 10: Array Summation
Practice Problem: Write a program to calculate and print the sum of all elements in a given integer array {1, 5, 10, 15, 20} using only pointer arithmetic to access the elements. Do not use the array index operator ([]).

int array[] = {1, 5, 10, 15, 20};
int size = sizeof(array) / sizeof(array[0]);
int sum = 0;
int *ptr = array;

for (int i = 0; i < size; ++i) {
    sum += *(ptr + i);
}

std::cout << "Sum of array elements: " << sum << std::endl;
 */

return 0;
}
