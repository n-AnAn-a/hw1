/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  Node* head = NULL;
  Node* tail = NULL;

  for (int i = 1; i < argc; i++){
    Node* newN = new Node{stoi(argv[i]), NULL};
    if (head == NULL){
      head = newN;
      tail = newN;
    }
    else{
      tail->next = newN;
      tail = newN;
    }
  }
  Node* odds = NULL;
  Node* evens = NULL;
  split(head, odds, evens);

  printL(odds);
  printL(evens);
  deleteL(odds);
  deleteL(evens);

  return 0;

}

void printL(Node* head){
  if (head == NULL){
    cout << "NULL" << endl;
    return;
  }
  cout << head->value << "->";
  printL(head->next);
}
// Print the list

void deleteL(Node*& head){
  if (head == NULL){
    return;
  }
  Node* temp = head;
  head = head->next;
  delete temp;
  deleteL(head);
}
// Delete the list
