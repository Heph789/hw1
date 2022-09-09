/* Write your test code for the ULListStr in this file */

#include <iostream>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;

void test_push_back();
void test_pop_back();
void test_push_front();
void test_pop_front();

int main(int argc, char* argv[])
{
  test_push_back();
  test_pop_back();
  test_push_front();
  test_pop_front();
  return 0;
}

void test_push_back() {
  cerr << "Testing push_back..." << endl;
  ULListStr* list = new ULListStr();

  cerr << "on empty list: ";
  string data = "Hello";
  list->push_back(data);
  bool conditional = list->back() == data;
  conditional = conditional && list->get(0) == data;
  conditional = conditional && list->size() == 1;
  cerr << (conditional ? "passed." : "failed.") << endl;

  cerr << "on unfilled last item: ";
  data = "world";
  list->push_back(data);
  conditional = list->back() == data;
  conditional = conditional && list->get(1) == data && list->get(0) == "Hello";
  conditional = conditional && list->size() == 2;
  cerr << (conditional ? "passed." : "failed.") << endl;

  cerr << "on item where last element is filled: ";
  for (int i = 2; i<ARRSIZE; ++i) {
    list->push_back("data");
  }
  list->pop_front(); // makes item not filled, but last element in array is still populated
  data = "final";
  list->push_back(data);
  conditional = list->back() == data && list->front() == "world";
  for (int i = 1; i<ARRSIZE-1; ++i) {
    conditional = conditional && list->get(i) == "data";
  }
  cerr << (conditional ? "passed." : "failed.") << endl;
  delete list;
}

void test_pop_back() {
  cerr << "Testing pop_back..." << endl;
  ULListStr* list = new ULListStr();

  cerr << "on empty list: ";
  list->pop_back();
  bool condition = list->empty(); // check if list is still empty
  cerr << (condition ? "passed." : "failed.") << endl;

  cerr << "on last item with more than one element: ";
  // populate list
  list->push_back("0");
  list->push_back("1");
  list->pop_back();
  condition = list->size() == 1 && list->get(0) == "0"; // check if list is still empty
  cerr << (condition ? "passed." : "failed.") << endl;

  cerr << "on last item with one element: ";
  // populate
  for (int i = 0; i < ARRSIZE-2; ++i) {
    list->push_back("data");
  }
  list->push_back("target");
  list->push_back("data");
  list->pop_back();
  condition = list->size() == ARRSIZE && list->back() == "target";
  cerr << (condition ? "passed." : "failed.") << endl;

  cerr << "on trying to get popped data (should error): ";
  condition = false;
  try {
    list->get(list->size());
  }
  catch (std::invalid_argument &err) {
    condition = true;
  }
  cerr << (condition ? "passed." : "failed.") << endl;

  cerr << "on pushing after popping: ";
  list->push_back("target2");
  condition = list->size() == ARRSIZE+1 && list->back() == "target2";
  cerr << (condition ? "passed." : "failed.") << endl;
  delete list;
}

// FRONT

void test_push_front() {
  cerr << "Testing push_front..." << endl;
  ULListStr* list = new ULListStr();

  cerr << "on empty list: ";
  string data = "Hello";
  list->push_front(data);
  bool conditional = list->front() == data;
  conditional = conditional && list->get(0) == data;
  conditional = conditional && list->size() == 1;
  cerr << (conditional ? "passed." : "failed.") << endl;

  cerr << "on unfilled first item: ";
  data = "world";
  list->push_front(data); // since we pushed to front before, the new Item's array starts at the back half
  conditional = list->front() == data;
  conditional = conditional && list->get(0) == data && list->get(1) == "Hello";
  conditional = conditional && list->size() == 2;
  cerr << (conditional ? "passed." : "failed.") << endl;

  cerr << "on item where first element is filled: ";
  for (int i = 2; i<ARRSIZE; ++i) {
    list->push_front("data");
  }
  list->pop_back(); // makes item not filled, but first element in array is still populated
  data = "final";
  list->push_front(data);
  conditional = list->front() == data;
  for (int i = 1; i<ARRSIZE-1; ++i) {
    conditional = conditional && list->get(i) == "data";
  }
  conditional = conditional && list->back() == "world";
  cerr << (conditional ? "passed." : "failed.") << endl;
  delete list;
}

void test_pop_front() {
  cerr << "Testing pop_front..." << endl;
  ULListStr* list = new ULListStr();

  // populate list

  cerr << "on empty list: ";
  list->pop_front();
  bool condition = list->empty(); // check if list is still empty
  cerr << (condition ? "passed." : "failed.") << endl;

  cerr << "on first item with more than one element: ";
  // populate list
  list->push_back("0");
  list->push_back("1");
  list->pop_front();
  condition = list->size() == 1 && list->get(0) == "1";
  cerr << (condition ? "passed." : "failed.") << endl;

  cerr << "on first item with one element: ";
  // populate
  for (int i = 0; i < ARRSIZE-2; ++i) {
    list->push_back("data");
  }
  list->push_front("target");
  list->push_front("data");
  list->pop_front();
  condition = list->size() == ARRSIZE && list->front() == "target";
  cerr << (condition ? "passed." : "failed.") << endl;

  cerr << "on pushing after popping: ";
  list->push_front("target2");
  condition = list->size() == ARRSIZE+1 && list->front() == "target2";
  cerr << (condition ? "passed." : "failed.") << endl;
  delete list;
}