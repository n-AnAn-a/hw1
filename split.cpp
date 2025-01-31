/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == NULL){
    return;
  }
  // Base case. In case the list is empty
  Node* nextN = in->next;
  // Stores the next node
  if (in->value % 2 == 1){
    odds = in;
    in->next = NULL;
    split(nextN, odds->next, evens);
    // Add to the evens list then the recursive call
  }
  else{
    evens = in;
    in->next = NULL;
    split(nextN, odds, evens->next);
    // Add to the odds list then the recursive call
  }
  in = NULL;
  // in set to NULL when the function terminates
}

/* If you needed a helper function, write it here */
