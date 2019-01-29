#include "Point2D.hpp"

Point2D operator+(Point2D lhs, Point2D rhs) {
  Point2D point(lhs.get_x() + rhs.get_x(), lhs.get_y() + rhs.get_y());

  return point;
}

Point2D operator-(Point2D lhs, Point2D rhs) {
  Point2D point(lhs.get_x() - rhs.get_x(), lhs.get_y() - rhs.get_y());

  return point;
}

Point2D operator*(Point2D lhs, Point2D rhs) {
  Point2D point(lhs.get_x() * rhs.get_x(), lhs.get_y() * rhs.get_y());

  return point;
}

Point2D operator/(Point2D lhs, Point2D rhs) {
  Point2D point(lhs.get_x() / rhs.get_x(), lhs.get_y() / rhs.get_y());

  return point;
}

