#include <iostream>
#include <cctype>

// https://pynative.com/cpp-pointers-exercises/

struct Rectangle {
    int length;
    int width;
};

struct Node {
    int data;
    Node* next;
};

void increment_number(int* x) {
    *x += 10;
}

int* find_min_ptr(int arr[], int size) {
    if (size == 0) return nullptr;
    int* min_ptr = arr;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < *min_ptr) {
            min_ptr = &arr[i];
        }
    }
    return min_ptr;
}

void copy_array(int* dest, const int* src, int size) {
    for (int i = 0; i < size; ++i) {
        *(dest + i) = *(src + i);
    }
}

bool compare_arrays(const int* arr1, const int* arr2, int size) {
    for (int i = 0; i < size; ++i) {
        if (*(arr1 + i) != *(arr2 + i)) {
            return false;
        }
    }
    return true;
}

void print_sub_array(int* arr, int start, int end) {
    int* current_ptr = arr + start;
    int* end_ptr = arr + end;
    std::cout << "Sub-array elements: ";
    while (current_ptr < end_ptr) {
        std::cout << *current_ptr << " ";
        current_ptr++;
    }
    std::cout << std::endl;
}

void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void to_uppercase(char* str_ptr) {
    while (*str_ptr != '\0') {
        *str_ptr = std::toupper(*str_ptr);
        str_ptr++;
    }
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int compute_result(int val1, int val2, int (*operation)(int, int)) {
    return operation(val1, val2);
}

void print_constant_value(const int* ptr) {
    if (ptr != nullptr) {
        std::cout << "Value via const pointer: " << *ptr << std::endl;
    }
}

char* find_first_occurrence(const char* source, const char* target) {
    if (*target == '\0') return (char*)source;
    const char* current_source = source;
    while (*current_source != '\0') {
        const char* s = current_source;
        const char* t = target;
        while (*t != '\0' && *s == *t) {
            s++;
            t++;
        }
        if (*t == '\0') {
            return (char*)current_source;
        }
        current_source++;
    }
    return nullptr;
}

void leak_memory(int count) {
    std::cout << "Allocating " << count << " integers without deletion..." << std::endl;
    for (int i = 0; i < count; ++i) {
        int* temp_ptr = new int(i);
        (void)temp_ptr;
    }
    std::cout << "Memory leak simulated." << std::endl;
}

int* resize_array(int* old_array, int old_size, int new_size) {
    int* new_array = new int[new_size];
    for (int i = 0; i < old_size; ++i) {
        *(new_array + i) = *(old_array + i);
    }
    delete[] old_array;
    return new_array;
}

int main() {
    /* Exercise 1
    int value = 100;
    int * ptr = &value;
    std::cout << "Value: " << *ptr << std::endl;
    */

    /* Exercise 2
    int number = 10;
    int * num_ptr = &number;
    *num_ptr = 99;
    std::cout << "Number: " << *num_ptr << std::endl;
    */

    /* Exercise 3
    int x = 42;
    int * p1 = &x;
    int * * p2 = &p1;
    std::cout << "pt2 value: " << **p2 << std::endl;
    */

    /* Exercise 4
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / 4;
    int * data_ptr = &data[0];
    for (int i = 0; i < size; i++) {
        std::cout << "Data: " << *data_ptr << std::endl;
        data_ptr++;
    }
    */

    /* Exercise 5
    int scores[] = {85, 90, 78, 95, 88};
    int * score_ptr = &scores[0];
    std::cout << "Score: " << *(score_ptr + 2) << std::endl;
    */

    /* Exercise 6
    char word[] = "CODE";
    char * p = word;
    std::cout << "Word: " << *(p + 2) << std::endl;
    */

    /* Exercise 7
    int * safe_ptr = nullptr;
    if (safe_ptr == nullptr) {
        std::cout << "Pointer is null, cannot dereference." << std::endl;
        int valid = 10;
        safe_ptr = &valid;
    }
    if (safe_ptr != nullptr)
        std::cout << "Pointer is now valid. Dereferenced value: " << *safe_ptr << std::endl;
    */

    /* Exercise 8
    int x = 10;
    std::cout << "Before increment: " << x << std::endl;
    increment_number(&x);
    std::cout << "After increment: " << x << std::endl;
    */

    /* Exercise 9
    int i;
    int * ptr;
    std::cout << "int size" << sizeof(i) << std::endl << "ptr size: " << sizeof(ptr) << std::endl;
    */

    /* Exercise 10: Array Summation
    int array[] = {1, 5, 10, 15, 20};
    int size = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    int *ptr = array;
    for (int i = 0; i < size; ++i) {
        sum += *(ptr + i);
    }
    std::cout << "Sum of array elements: " << sum << std::endl;
    */

    /* Exercise 11
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int * ptr = numbers;
    for (int i = size - 1; i >= 0; i--) {
        std::cout << "Elements in reverse order: " << *(ptr + i) << std::endl;
    }
    */

    /* Exercise 12
    int data[] = {45, 12, 67, 8, 33};
    int size = sizeof(data) / sizeof(data[0]);
    int* min_element_ptr = find_min_ptr(data, size);
    if (min_element_ptr != nullptr) {
        std::cout << "The smallest element is: " << *min_element_ptr << std::endl;
    }
    */

    /* Exercise 13
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    const int ROWS = 3;
    const int COLS = 3;
    const int TOTAL_ELEMENTS = ROWS * COLS;
    int* ptr = (int*)matrix;
    std::cout << "2D Array elements accessed contiguously:" << std::endl;
    for (int i = 0; i < TOTAL_ELEMENTS; ++i) {
        std::cout << *(ptr + i) << " ";
        if ((i + 1) % COLS == 0) {
            std::cout << std::endl;
        }
    }
    */

    /* Exercise 14
    const int SIZE = 5;
    int source[] = {10, 20, 30, 40, 50};
    int destination[SIZE];
    copy_array(destination, source, SIZE);
    std::cout << "Destination array contents: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << destination[i] << " ";
    }
    std::cout << std::endl;
    */

    /* Exercise 15
    const int SIZE = 4;
    int a1[] = {1, 2, 3, 4};
    int a2[] = {1, 2, 3, 4};
    int a3[] = {1, 2, 9, 4};
    if (compare_arrays(a1, a2, SIZE)) {
        std::cout << "Array a1 and a2 are identical." << std::endl;
    } else {
        std::cout << "Array a1 and a2 are NOT identical." << std::endl;
    }
    if (compare_arrays(a1, a3, SIZE)) {
        std::cout << "Array a1 and a3 are identical." << std::endl;
    } else {
        std::cout << "Array a1 and a3 are NOT identical." << std::endl;
    }
    */

    /* Exercise 16
    int data[] = {10, 20, 30, 40, 50, 60};
    int start_index = 2;
    int end_index = 5;
    print_sub_array(data, start_index, end_index);
    */

    /* Exercise 17
    int a = 10;
    int b = 20;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    */

    /* Exercise 18
    char text[] = "hello pointers exercise";
    std::cout << "Original: " << text << std::endl;
    to_uppercase(text);
    std::cout << "Uppercase: " << text << std::endl;
    */

    /* Exercise 19
    int (*op_ptr)(int, int) = add;
    int result1 = op_ptr(10, 5);
    int result2 = (*op_ptr)(25, 75);
    std::cout << "Result 1 (10 + 5): " << result1 << std::endl;
    std::cout << "Result 2 (25 + 75): " << result2 << std::endl;
    */

    /* Exercise 20
    int x = 50;
    int y = 10;
    int product = compute_result(x, y, multiply);
    std::cout << "Multiplication result: " << product << std::endl;
    int difference = compute_result(x, y, subtract);
    std::cout << "Subtraction result: " << difference << std::endl;
    */

    /* Exercise 21
    int data = 100;
    print_constant_value(&data);
    data = 200;
    print_constant_value(&data);
    */

    /* Exercise 22
    int x = 5;
    int y = 25;
    int* const const_ptr = &x;
    *const_ptr = 10;
    std::cout << "x after modification via pointer: " << x << std::endl;
    */

    /* Exercise 23
    Rectangle rect = {10, 5};
    Rectangle* rect_ptr = &rect;
    std::cout << "Original dimensions: " << rect_ptr->length << " x " << rect_ptr->width << std::endl;
    rect_ptr->length = 15;
    rect_ptr->width = 7;
    std::cout << "New dimensions: " << rect.length << " x " << rect.width << std::endl;
    */

    /* Exercise 24
    float* float_ptr = new float;
    if (float_ptr != nullptr) {
        *float_ptr = 3.14f;
        std::cout << "Dynamically allocated float value: " << *float_ptr << std::endl;
        std::cout << "Address on heap: " << float_ptr << std::endl;
        delete float_ptr;
        float_ptr = nullptr;
    }
    */

    /* Exercise 25
    const int SIZE = 8;
    int* array_ptr = new int[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        *(array_ptr + i) = (i + 1) * 10;
    }
    std::cout << "Dynamically allocated array: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << array_ptr[i] << " ";
    }
    std::cout << std::endl;
    delete[] array_ptr;
    array_ptr = nullptr;
    */

    /* Exercise 26
    int n1 = 10;
    int n2 = 20;
    int n3 = 30;
    int n4 = 40;
    int n5 = 50;
    int* array_of_ptrs[5];
    array_of_ptrs[0] = &n1;
    array_of_ptrs[1] = &n2;
    array_of_ptrs[2] = &n3;
    array_of_ptrs[3] = &n4;
    array_of_ptrs[4] = &n5;
    std::cout << "Values via array of pointers: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << *array_of_ptrs[i] << " ";
    }
    std::cout << std::endl;
    */

    /* Exercise 27
    const char* main_str = "programming in c++ is fun";
    const char* sub_str = "c++";
    char* found_ptr = find_first_occurrence(main_str, sub_str);
    if (found_ptr != nullptr) {
        std::cout << "Substring found starting at: " << found_ptr << std::endl;
        std::cout << "Source string starting from match: " << found_ptr << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }
    */

    /* Exercise 28
    leak_memory(100);
    */

    /* Exercise 29
    int old_size = 5;
    int new_size = 10;
    int* data_ptr = new int[old_size]{1, 2, 3, 4, 5};
    std::cout << "Original array (size 5): ";
    for (int i = 0; i < old_size; ++i) {
        std::cout << data_ptr[i] << " ";
    }
    std::cout << std::endl;
    data_ptr = resize_array(data_ptr, old_size, new_size);
    old_size = new_size;
    std::cout << "Resized array (size 10): ";
    for (int i = 0; i < old_size; ++i) {
        std::cout << (data_ptr[i] == 0 ? 99 : data_ptr[i]) << " ";
    }
    std::cout << std::endl;
    delete[] data_ptr;
    */

    /* Exercise 30
    Node* n1 = new Node{10, nullptr};
    Node* n2 = new Node{20, nullptr};
    Node* n3 = new Node{30, nullptr};
    n1->next = n2;
    n2->next = n3;
    Node* current = n1;
    std::cout << "Linked List Traversal: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    current = n1;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
    */

    return 0;
}
