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

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
  if (tail_ == NULL || tail_->last == ARRSIZE){
    Item* secondItem = new Item();
    if (tail_ == NULL){
      head_ = tail_ = secondItem;
    }
    else {
      tail_->next = secondItem;
      secondItem->prev = tail_;
      tail_ = secondItem;
    }
  }
  size_t index = tail_->last;
  tail_->val[index] = val;
  tail_->last = index + 1;
  size_++;
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  if (tail_ == NULL){
    return;
  }
  
  tail_->last--;
  size_--;

  if (tail_->last == tail_->first){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL){
      tail_->next = NULL;
    }
    else{
      head_ = tail_ = NULL;
    }
    delete temp;
  }
}

  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val){
  if (head_ == NULL || head_->first == 0){
    Item* secondItem = new Item();
    secondItem->last = ARRSIZE;
    secondItem->first = ARRSIZE - 1;
    secondItem->val[secondItem->first] = val;
    if (head_ == NULL){
      head_ = tail_ = secondItem;
    }
    else {
      secondItem->next = head_;
      head_->prev = secondItem;
      head_ = secondItem;
    }
  }
  else{
    size_t index = head_->first - 1;
    head_->val[index] = val;
    head_->first = index;
  }
  size_++;
}


  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front(){
  if(head_ == NULL){
    return;
  }

  head_->first++;
  size_--;

  if (head_->last == head_->first){
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != NULL){
      head_->prev = NULL;
    }
    else{
      tail_ = head_ = NULL;
    }
    delete temp;
  }
}
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

    /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_){
    return NULL;
  }
  Item* currentLoc = head_;
  size_t index = loc;
  while (currentLoc){
    size_t num = currentLoc->last - currentLoc->first;
    if (index < num){
      return &currentLoc->val[currentLoc->first + index];
    }
    index -= num;
    currentLoc = currentLoc->next;
  }
  return NULL;
}

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
