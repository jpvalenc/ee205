// These two lines are the opening part of what's called a "header guard"
// If this file is ever included more than one, it'll make sure that
// only one version of this code will show up to the compiler.
//
// In other words, it won't try to redefine things twice because it
// was included twice.
#ifndef POINT2D_HPP
#define POINT2D_HPP

// You'll need to turn this into a class.
// Make sure you use the concept of encapsulation,
// and hide the class's internal data.
// struct Point2D {
//     float x;
//     float y;
// };

class Point2D {
    private:
        float x, y;

    public:
        // Construct default values
        Point2D() {
            this->x = 0;
            this->y = 0;
        }

        // Construct with passed in valuees
        Point2D(float x, float y) {
            this->x = x;
            this->y = y;
        }

        // Getter for x position
        float const get_x() {
            return x;
        }

        // Getter for y position
        float const get_y() {
            return y;
        }

        // Setter for x position
        void set_x(float x) {
            this->x = x;
        }

        // Setter for x position
        void set_y(float y) {
            this->y = y;
        }
};

// lhs = "left hand side"
// rhs = "right hand side"
Point2D operator+(Point2D lhs, Point2D rhs);
Point2D operator-(Point2D lhs, Point2D rhs);
Point2D operator*(Point2D lhs, Point2D rhs);
Point2D operator/(Point2D lhs, Point2D rhs); 

#endif // POINT2D_HPP
