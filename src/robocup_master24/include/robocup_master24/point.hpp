#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
    Point() {px = 0, py = 0;}
    Point(int x, int y);

    bool setX(int x);
    bool setY(int y);

    int x(void);
    int y(void);

    Point operator + (Point op2);
    Point operator - (Point op2);
    Point &operator += (Point op2);
    Point &operator -= (Point op2);

private:
    int px;
    int py;
};

#endif //POINT_HPP
