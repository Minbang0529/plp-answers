// Below comments highlight the changes to the original code
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm> // for max

using namespace std; // for max

// using vectors instead of C-style arrays
// there is no need to pass 'size' as a separate variable
void multiply_arrays(vector<int> &array1, vector<int> &array2, vector<int> &result_array) {
    int i;

    // we access the size of a vector by calling its .size() method
    for(i=0; i<array1.size(); i++) {
        if(i >= array2.size())
            // instead of setting an item at an index
            // we push a new item at the end of the array
            // this adds a new item at the end of the array
            result_array.push_back(array1[i]);
        else
            result_array.push_back(array1[i] + array2[i]);
    }

    for(; i<array2.size(); i++)
        result_array.push_back(array2[i]);

}

void init_array(vector<int> &array, int size) {
    // again, we push new items to the end of the array
    // instead of setting items at indexes
    for(int i=0; i<size; i++)
        array.push_back(i);
}

int main(int argc, char **argv) {
    // technically speaking, we can avoid the use of result_size entirely
    // but we avoid doing that to be consistent with the original code
    int size1, size2, result_size;
    vector<int> array1, array2, result_array;

    if(argc != 3) {
        printf("usage: %s <size array 1> <size array 2>\n", argv[0]);
        return -1;
    }

    size1 = atoi(argv[1]);
    size2 = atoi(argv[2]);
    result_size = max(size1, size2);

    // note that array1 and array2 are empty at this point
    // so setting elements at index 0, 1, ..., size1
    // is effectively the same as pushing new items to the end of the array
    init_array(array1, size1);
    init_array(array2, size2);

    // same goes for result_array
    // thus we use push_back() in the function implementation
    multiply_arrays(array1, array2, result_array);

    // note that it is possible to iterate through vectors like arrays
    for(int i=0; i<result_size; i++)
        printf("%d ", result_array[i]);
    printf("\n");

    // there is no need to free a vector manually
    // a vector destroys all objects inside it when it goes out of scope
    return 0;
}
// Run the below command to check answers; The one on github is outdated
// Make sure you're in the same directory as this file when running the command
// check50 -l --log olivierpierre/comp26020-problems/2022-2023/week4-c++/04-vector
