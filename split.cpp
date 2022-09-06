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

#include <cstddef>
#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == NULL) {
    return;
  }

  Node* nextIn = in->next;
  in->next = NULL;
  if(in->value % 2) {
    odds = in;
    split(nextIn, odds->next, evens);
  }
  else {
    evens = in;
    split(nextIn, odds, evens->next);
  }
  in = NULL;
}

/* If you needed a helper function, write it here */
// WRITE YOUR CODE HERE

/*
Notes:
Ex: 1 2 3 4 5
- should check the first element, adjust
*/