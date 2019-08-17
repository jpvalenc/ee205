#include <iostream>

using namespace std;

struct test {
  int i, j;
};

int main() {
  for (int i = 0; i < 6; i++) {
    cout << i << endl;

    if (i == 3) {
      break;
    }
  }
}
