#include "vec2d.h"

#include <cmath>

Vec2D::Vec2D(double x, double y) : x(x), y(y) {}
Vec2D::Vec2D(const Vec2D &v) : x(v.x), y(v.y) {}
Vec2D &Vec2D::operator=(const Vec2D &v) {
    x = v.x;
    y = v.y;
    return *this;
}
Vec2D &Vec2D::operator=(Vec2D &&v) {
    x = v.x;
    y = v.y;

    return *this;
}

Vec2D Vec2D::operator+(const Vec2D &v) const {
    return Vec2D(x + v.x, y + v.y);
}

Vec2D Vec2D::operator-(const Vec2D &v) const {
    return Vec2D(x - v.x, y - v.y);
}


Vec2D Vec2D::operator*(double s) const {
    return Vec2D(x * s, y * s);
}

Vec2D Vec2D::operator/(double s) const {
    return Vec2D(x / s, y / s);
}

Vec2D &Vec2D::operator+=(const Vec2D &v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vec2D &Vec2D::operator-=(const Vec2D &v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2D &Vec2D::operator*=(double s) {
    x *= s;
    y *= s;
    return *this;
}

Vec2D &Vec2D::operator/=(double s) {
    x /= s;
    y /= s;
    return *this;
}   