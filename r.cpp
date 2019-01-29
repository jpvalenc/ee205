#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    int area() {
      return this->width * this->height;
    }

    Rectangle(int width, int height) {
      this->width = width;
      this->height = height;
    }

    Rectangle operator+(const Rectangle &r) { // const because we aren't changing any values.
      Rectangle *rectangle;

      this->width = this->width + r.width;
      this->height = this->height + r.height;

      return *rectangle;
    }
};

class Person { 
  private:
    std::string name;

  public:
    Person() {
      this->name = "";
      Rectangle location = Rectangle(1,2);
    }

    Person(std::string name, float x, float y) {
      this->name = name;
      Rectangle location = Rectangle(x, y);
    }

    std::string const get_name() {
      return name;
    }

    Rectangle const get_location() {
      // return location;
    }

};

int main () {
  Rectangle rect1(3,4), rect2(5,6);

  Rectangle rect3(0,0);

  rect3 = rect1 + rect2;

  cout << "area: " << rect3.area();
  return 0;
}