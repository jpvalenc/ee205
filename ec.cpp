#include <iostream>
#include <string>

using namespace std;

int main() {
  std::string input;

  cin >> input;

  for (unsigned i = 1; i < input.length(); i = i + 4) {
    cout << input[i];
  }
  for (unsigned i = 0; i < input.length(); i = i + 2) {
    cout << input[i];
  }
  for (unsigned i = 4; i < input.length(); i = i + 4) {
    cout << input[i];
  }
}