#include <vector>
#include "Piece.h"

class Board {
  std::vector<Piece*> pieces;
  void generateBoard();
  bool checkIfOffBoard();
  bool checkIfObstructed();
  int movement();
}