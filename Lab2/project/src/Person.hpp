#ifndef PERSON_HPP
#define PERSON_HPP

#include "Point2D.hpp"

// std::string is a class from the C++ standard
// library that can be default-constructed
// and constructed from a C-style string (string
// literal like "Hello world")
#include <string>

// Make sure to use both Point2D and std::string
// as member variables in the class below.
class Person { 
  private:
    std::string name;
    Point2D location;

  public:
    Person() {
      this->name = "";

      Point2D point;
      this->location = point;
    }

    Person(std::string name, float x, float y) {
      this->name = name;
      
      Point2D point(x, y);
      this->location = point;
    }

    void set_name(std::string name) {
      this->name = name;
    }

    void set_location(Point2D point) {
      this->location = point;
    }

    std::string const get_name() {
      return this->name;
    }

    Point2D get_location() {
      return this->location;
    }

};

#endif // PERSON_HPP
