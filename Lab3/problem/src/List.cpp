#include "List.hpp"

#include <utility>

// Performs a deep copy, copying each node of the other list
// into this one
List::List(const List& other) {
  this->head = other.head;
  this->length = other.length;
};

// Performs a move, moving the internal list from the other
// vector to this one, and invalidates the other list pointer
// for its memory
List::List(List&& other) {
  this->head = other.head;
  this->length = other.length;

  other.head = nullptr;
  other.length = 0;
};

// Deallocates the memory in this list.
List::~List() {
  delete this->head;
};

// For all of the following functions,
// throw a const char* (string) if the index is out of
// the bounds of the list.

// Appends a ListNode onto the end of the list
//
// Throw a const char* if the index is out of bounds
void List::append(int num) {
  ListNode *t;

  int i;

  ListNode *temp = this->head;
  ListNode newList(num);

  for (i = 0; i < length; i++) {
    temp->get_next();
  }

  temp->set_next(newList.get_next());
};

// Inserts a ListNode before the index
//
// Throw a const char* if the index is out of bounds.
// Appending at the end is valid (e.g. insert(list.size(), 0)
// is valid)
void List::insert(int index, int num) {
  // change pointer of node before and
  // set the pointer of the node at the index to the next one

  int i;

  if (index == 0) {
    ListNode *temp = this->head;
    ListNode *newNode = new ListNode(num);

    newNode->set_next(this->head);

    this->head = newNode;
  } else if (index == length) {
    append(num);
  } else {
    ListNode *temp = this->head;
    ListNode *nodeBeforeIndex;
    ListNode *newNode = new ListNode(num);

    //at index
    for (i = 0; i < index - 1; i++) {
      temp = temp->get_next();
    }

    nodeBeforeIndex = temp;

    temp = temp->get_next();

    nodeBeforeIndex->set_next(newNode);

    newNode->set_next(temp->get_next());

    length = length + 1;
  }
};

// Removes the ListNode at the index
//
// Throw a const char* if the index is out of bounds.
void List::remove(int index) {
  // loop until index
  // set index to null pointer
  // save the pointer before the index
  // loop through list after index, 

  int i;

  if (index == 0) {
    ListNode *temp = this->head;

    this->head = temp->get_next();

    delete head, temp;
    
  } else if (index > 0) {
    ListNode *temp = this->head;
    ListNode *nodeBeforeDelete;

    for (i = 0; i < index; i++) {
      temp = temp->get_next();
      if (i == index - 1) {
        nodeBeforeDelete = temp;
      }
    }

    nodeBeforeDelete->set_next(temp->get_next());

    delete temp;
  }

  length = length - 1;
};

// Returns the int at the index
//
// Throw a const char* if the index is out of bounds.
int List::get(int index) const {
  int i;

  ListNode *temp = head;

  for (i = 0; i < index; i++) {
    temp = temp->get_next();
  }

  return temp->get_data();
};

// Returns the length of the list
std::size_t List::size() const {
  return this->length;
};

// Reutrns a readable/writeable reference to the element at index
//
// Throw a const char* if the index is out of bounds.
int& List::operator[](int index) {
  int i;

  ListNode *temp = head;

  for (i = 0; i < index; i++) {
    temp = temp->get_next();
  }

  return temp->get_data();
};