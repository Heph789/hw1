#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
  if(empty()) {
    head_ = new Item();
    tail_ = head_;
  }

  // if the back array is full, create a new Item
  if(tail_->last == ARRSIZE) {
    Item* temp = new Item();
    temp->prev = tail_;
    tail_->next = temp;
    tail_ = temp;
  }

  tail_->val[tail_->last++] = val;
  ++size_;
}

void ULListStr::pop_back() {
  if(empty()) {
    return;
  }
  --tail_->last;
  --size_;
  if (tail_->last-tail_->first == 0) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = nullptr;
    delete temp;
  }
}

void ULListStr::push_front(const std::string& val) {
  if(empty()) {
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }

  // if the first element of the array is filled, create a new Item
  if(head_->first == 0) {
    Item* temp = new Item();
    temp->next = head_;
    head_->prev = temp;
    head_ = temp;
    head_->first = ARRSIZE;
    head_->last = ARRSIZE;
  }

  head_->val[--head_->first] = val;
  ++size_;
}

void ULListStr::pop_front() {
  if(empty()) {
    return;
  }
  ++head_->first;
  --size_;
  if (head_->last-head_->first == 0) {
    Item* temp = head_;
    head_ = head_->next;
    head_->prev = nullptr;
    delete temp;
  }
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  Item* current = head_;
  size_t curloc = 0;

  while(current != nullptr) {
    const size_t increment = current->last-current->first; // iterate by the number of elements in each Item
    if (curloc+increment > loc) { // if the location is in this item
      int index = int((loc-curloc)+current->first);
      return &(current->val[index]);
    }
    curloc += increment;
    current = current->next;
  }
  return NULL;
}

// END OF MY CODE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
