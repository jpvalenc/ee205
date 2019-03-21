#include <iostream>
#include <vector>

class Piece {
    public:
    void test() {
        std::cout << "Test Piece" << std::endl;
    };
};

class Pawn : public Piece {
    private:
    int a = 1;

    public:
    void test() override {
        std::cout << "Test Pawn" << std::endl;
    }

    int getA() {
      this->test();
      std::cout << (*this).a << std::endl;
      return a;
    }
};

int main() {
    std::vector<Piece*> piece;

    Pawn *ptr;

    Pawn p;

    p.getA();

    ptr = &p;

    piece.push_back(ptr);
    piece.push_back(ptr);

    return 0;
}