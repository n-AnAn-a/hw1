#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  if (argc < 2){
    return 1;
  }
  ULListStr list;
  std::string command = argv[1];
  if (command == "push_back"){
    for (int i = 2; i < argc; i++){
      list.push_back(argv[i]);
    }
  }
  else if (command == "push_front"){
    for (int i = 2; i < argc; i++){
      list.push_front(argv[i]);
    }
  }
  else if (command == "pop_back"){
    int numTimes = std::stoi(argv[2]);
    for (int i = 0; i < numTimes; i++){
      list.pop_back();
    }
  }
  else if (command == "pop_front"){
    int numTimes = std::stoi(argv[2]);
    for (int i = 0; i < numTimes; i++){
      list.pop_front();
    }
  }
  else if (command == "back"){
    std::cout << list.back() << std::endl;
  }
  else if (command == "front"){
    std::cout << list.front() << std::endl;
  }
  else if (command == "size"){
    std::cout << list.size() << std::endl;
  }
  else {
    std::cerr << "Unknown command." << command << std::endl;
    return 1;
  }

  for (size_t i = 0; i < list.size(); i++){
    std::cout << list.get(i) << " ";
  }
  std::cout << std::endl;
  return 0;
}
