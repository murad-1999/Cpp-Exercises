#include <iostream>
 // https://pynative.com/cpp-pointers-exercises/

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


return 0;
}