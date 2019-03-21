#include <iostream>
#include <vector>

using namespace std;

class Shape {
  public:
    virtual void PrintArea() {
      cout << "ok" << endl;
    }; // virtual / abstract class

    // void PrintName() {
    // }
};

class Box : public Shape {
  private:
    int width, height, depth;
  public:
    void PrintArea() override {
      cout << "area of box" << endl;
    }
};

int main() {
  Box b;
  b.PrintArea();

  

  // vector<Shape*> vect; // we can store boxes because it inherits from shape

  // vect.push_back(b);

  // for (int i = 0; i < vect.size(); i++) {
  //   b.PrintArea();
  // }
}