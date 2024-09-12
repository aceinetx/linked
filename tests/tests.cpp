#include "linked.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv){

  int num = 123;

  aceinetzxx::linked<int> x;
  x.push_back(&num);
  x.push_back(&num);
  x.push_back(&num);

  int failed_count = 0;

  auto element = x.back();
  if(*element == num){
    std::cout << "[1] (back) Passed" << std::endl;
  } else {
    std::cout << "[1] (back) Failed" << std::endl;
    failed_count++;
  }

  if(x.size() == 3){
    std::cout << "[2] (size) Passed" << std::endl;
  } else {
    std::cout << "[2] (size) Failed" << std::endl;
    failed_count++;
  }

  if(*x.pop_back() == 123){
    std::cout << "[3] (pop_back) Passed" << std::endl;
  } else {
    std::cout << "[3] (pop_back) Failed" << std::endl;
    failed_count++;
  }

  if(x.size() == 2){
    std::cout << "[4] (size) Passed" << std::endl;
  } else {
    std::cout << "[4] (size) Failed" << std::endl;
    failed_count++;
  }

  if(failed_count == 0){
    std::cout << "All tests passed" << std::endl;
  } else {
    std::cout << "Some tests failed: something may not work properly" << std::endl;
  }

  std::vector<int> a;
}
