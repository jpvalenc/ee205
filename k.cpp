#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Student {
  private:
  float gpa;

  public:
  string name;
  int id;
  int x;
  int y;

  Student();

  Student(std::string name, int id, float gpa, int x, int y) {
    this->name = name;
    this->id = id;
    this->gpa = gpa;
    if (x >= 1) {
      this->x = x;
    }
    if (y >= 1) {
      this-> y = y;
    }
  };

  void DisplayInfo() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
    cout << "GPA: " << gpa << endl;
  }

  virtual void setGPA(float gpa) {
    if (gpa > 0 && gpa < 4) {
      this->gpa = gpa;
    }
  }

  float getGPA() {
    return this->gpa;
  }

  double operator-(Student s) {
    int x = this->x - s.x;
    int y = this->y - s.y;

    return sqrt((x * x) + (y * y));
  }
};

class GradStudent : public Student {
  private:

  public:
  bool isOnProbation;
  GradStudent(std::string name, int id, float gpa, int x, int y) : Student(name, id, gpa, x, y) {
    setGPA(gpa);
  };

  void setGPA(float gpa) {
    Student::setGPA(gpa);
    if (gpa <= 3) {
      this->isOnProbation = true;
    } else {
      this->isOnProbation = false;
    }
  }
};

int main() {
  Student spencer("Spencer", 1, 3.9, 1, 1), johnson("Johnson", 2, 3.8, 2, 2);

  spencer.DisplayInfo();

  johnson.DisplayInfo();
  
  cout << spencer - johnson << endl;
  
//   spencer.DisplayInfo();

//   spencer.setGPA(3.4);

//   cout << spencer.getGPA() << endl;


//   GradStudent gs("Derek", 2, 3.1, 1, 2);

//   gs.DisplayInfo();

//   // cout << gs.isOnProbation;
//   // gs.setGPA(2.9);

//   cout << gs.isOnProbation << endl;
}
