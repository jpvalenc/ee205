#include <iostream>
#include <vector>

#include "Piece.h"
#include "Constants.h"

class Player {
  Color color;
  bool turn;
  bool checked;
  std::vector<Piece*> eaten;
};
