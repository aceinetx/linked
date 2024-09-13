# linked
a double-linked array library for c++<br>
## Features
- std::vector-like functions
- uses class templates
- minimal standard library usage
- minimal dependencies
- easy to set up
- python multiplication
# Example
```c++
#include "linked.h"
#include <iostream>

int main(){
  aceinetzxx::linked<int> arr;
  
  arr.push_back(69);
  arr.push_back(123);

  // get the first number
  std::cout << "The number is " << arr[0] << std::endl; // should print "The number is 69"

  // get the last number
  std::cout << "The last number is " << arr.back() << std::endl; // should also print "The last number is 123"

  // set the number at index
  arr[0] = 42;

  // to set the last number we can use .back() too
  arr.back() = 70;

  // get the size of array
  size_t array_size = arr.size();

  arr.pop_back(); // this removes the last element and returns it
                  // but no need to do that in this case because deconstructor cleans everything
}
```
