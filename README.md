# linked
a double-linked array library for c++<br>
# Examples
```c++
#include "linked.h"
#include <iostream>

int main(){
  aceinetzxx::linked<int> arr;
  int num = 69;

  arr.push_back(num);

  std::cout << "The number is " << arr.back() << std::endl; // should print "The number is 69"

  arr.pop_back(); // this removes the last element and returns it
                  // but no need to do that in this case because deconstructor cleans everything
}

```
