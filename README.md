# ExpandingArray

A lightweight template array. I use this with the Arduino platform.

[![lint status](https://github.com/endail/ExpandingArray/workflows/arduino-lint/badge.svg?event=push)](https://github.com/endail/ExpandingArray/actions?query=workflow%3Aarduino-lint)

```c++
//ExpandingArray can take two template parameters
//StorageType: the data type being stored in the array (default is uint8_t)
//IndexType: the data type being used to index the array (default is size_t)

endail::ExpandingArray byteArr(100); //create an array of 100 bytes
endail::ExpandingArray<int> intArr(arr2, sizeof(arr2)); //create an array of ints by copying all the data from arr2
endail::ExpandingArray<char, uint8_t> charArr; //create an array of char using uint8_t as the indexing type
endail::ExpandingArray<char, uint8_t> charArr2 = charArr; //create charArr2 by copying all the data from charArr
endail::ExpandingArray<int> arr(5); //create an array of ints with 5 elements

arr[0] = 61;
std::cout << arr[0]; //61
int* ptrToSixtyOne = arr.ptr(0);
size_t indexOfSixtyOne = arr.idx(ptrToSixtyOne);

for(auto it = arr.ptr(); it != arr.end(); ++it) {
    std::cout << *it << std::endl;
}

arr.length(); //5
arr.allocate(10); //allocate memory for 10 ints
arr.length(); //still 5
arr.reclaim(); //excess memory is deallocated
arr.length(); //still 5

arr.allocate(20); //allocate memory for 20 ints
arr.resize(20); //resize to 20 ints; no memory reallocation needed
arr.length(); //20

arr.copyFrom(arr2, sizeof(arr2)); //copy all of arr2 into arr beginning at arr[0]
arr.copyFromAt(arr2, sizeof(arr2), 7); //copy all of arr2 into arr beginning at arr[7]
arr.copyTo(arr2); //copy all of arr into arr2
arr.copyTo(arr2, 3); //copy first 3 elements of arr into arr2
arr.copyToAt(arr2, 5, 4); //copy 5 elements beginning at index 4 from arr into arr2

arr.clear(); //clear the array; ints remain in memory
arr.clear(true); //clear the array; ints are zero'd out

arr.dispose(); //clear the array; memory is deallocated
arr.dispose(true); //clear the array; ints are zero'd out; memory is deallocated

//dispose is automatically called by the destructor when arr falls out of scope!
//memory is cleaned up!
```
