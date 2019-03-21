#include "Vector.hpp"

#include <utility>

void Vector::double_capacity() {
  int *double_capacity = new int[capacity * 2];

  int i;

  for (i = 0; i < length; i++) {
    double_capacity[i] = arr[i];
  }

  arr = double_capacity;

  delete double_capacity;
};

Vector::Vector() {
  length = 0;
  arr = new int[1];
  capacity = 0;
};

Vector::Vector(const Vector& other) {
  length = other.length;
  int *a = new int[other.capacity];

  int i;

  for (i = 0; i < other.length; i++) {
    a[i] = other.arr[i];
  }

  arr = a;

  delete a;

  capacity = other.capacity;
};

Vector::Vector(Vector&& other) {
  length = other.length;
  int *a = new int[other.length];
  arr = other.arr;
  capacity = other.capacity;

  other.length = 0;
  other.arr = nullptr;
  other.capacity = 0;
};

Vector::~Vector() {
  delete arr;
};

void Vector::append(int num) {
  // check the length and capacity, if length < capacity then append
  // if length >= capacity then call double_capacity function
  // Add the value by accessing the arr[length]
  // update length add by 1

  if (length >= capacity) {
    double_capacity();
  }

  arr[length] = num;

  length = length + 1;
};

void Vector::insert(int index, int num) {
  // check the length and capacity, if length < capacity then append
  // if length >= capacity, call double_capacity function
  // Create temporary array, loop through the

  // if at index, then it would replace a[index - 1] = num, then shift the array up
  // Set a[index] = num, then loop through the array and if at the index, skip and continue after
  // given a[2], it would insert a[1] and shift the rest

  if (index < 0 || index > length + 1) {
    throw "Out of bounds";
  }

  if (length >= capacity) {
    double_capacity();
  }
  
  int *a = new int[capacity];

  int i;

    // [1,2,3,4,5] length = 5, index = 0
  if (index == 0) {
    // Check if beginning of array
    for (i = length; i >= 0; i--) {
      if (i == 0) {
        a[0] = num;
      } else {
        a[i] = arr[i - 1];
      }
    }
  } else if (index == length) {
    // Check if end of array
    append(num);
  } else {
    // [1,2,3] index = 1, length 3

    for (i = length; i >= 0; i--) {
      if (i < index) {
        a[i] = arr[i];
        // a[0] = 0
      } else if (i > index) {
        // a[3] = arr[2]
        // a[2] = arr[1]
        a[i] = arr[i - 1];
      } else if (i == index) {
        // a[1] = num
        a[index] = num;
      }
    }
  }

  length = length + 1;

  arr = a;

  delete a;
};

void Vector::remove(int index) {
  // Get the index and delete it.
  // Shift down all by 1
  // Reduce length by 1
  if (index < 0 || index > length - 1) {
    throw "Out of bounds";
  }
  
  int *a = new int[capacity];

  int i;

  for (i = 0; i < length; i++) {
    if (i < index) {
      a[i] = arr[i];
    } else if (i > index) {
      a[i - 1] = arr[i];
    }
  }

  length = length - 1;
};

int Vector::get(int index) const {
  if (index < 0 || index > length - 1) {
    throw "Out of bounds";
  }

  return arr[index];
};

std::size_t Vector::size() const {
  return length;
};

int& Vector::operator[](int index) {
  if (index < 0 || index > length - 1) {
    throw "Out of bounds";
  }
  
  return arr[index];
};
