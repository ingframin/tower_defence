#ifndef VEC2D_H
#define VEC2D_H

struct Vec2D
{   
    double x, y;
    Vec2D();
    Vec2D(double x, double y);
    Vec2D(const Vec2D &v);
    Vec2D(Vec2D &&v);
    Vec2D& operator=(const Vec2D &v);
    Vec2D& operator=(Vec2D &&v);
    Vec2D operator+(const Vec2D &v) const;
    Vec2D operator-(const Vec2D &v) const;
    Vec2D& operator+=(const Vec2D &v);
    Vec2D& operator-=(const Vec2D &v);
    Vec2D operator*(double s) const;
    Vec2D& operator*=(double s);
    Vec2D operator/(double s) const;
    Vec2D& operator/=(double s);
};

#endif