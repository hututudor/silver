#pragma once

#include <SFML/Graphics.hpp>

template<typename T>
class Vector2 {
public:
  Vector2() {
    x = 0;
    y = 0;
  };

  Vector2(T x, T y) {
    this->x = x;
    this->y = y;
  };

  static Vector2<T> fromSfVector(sf::Vector2<T> v) {
    return Vector2<T>(v.x, v.y);
  }

  sf::Vector2<T> toSfVector() const {
    return sf::Vector2<T>(x, y);
  }

  T x;
  T y;
};

template<typename T>
Vector2<T> operator-(const Vector2<T> &right) {
  return Vector2<T>(-right.x, -right.y);
}

template<typename T>
Vector2<T> &operator+=(Vector2<T> &left, const Vector2<T> &right) {
  left.x += right.x;
  left.y += right.y;

  return left;
}

template<typename T>
Vector2<T> &operator-=(Vector2<T> &left, const Vector2<T> &right) {
  left.x -= right.x;
  left.y -= right.y;

  return left;
}

template<typename T>
Vector2<T> operator+(const Vector2<T> &left, const Vector2<T> &right) {
  return Vector2<T>(left.x + right.x, left.y + right.y);
}

template<typename T>
Vector2<T> operator-(const Vector2<T> &left, const Vector2<T> &right) {
  return Vector2<T>(left.x - right.x, left.y - right.y);
}

template<typename T>
Vector2<T> operator*(const Vector2<T> &left, T right) {
  return Vector2<T>(left.x * right, left.y * right);
}

template<typename T>
Vector2<T> operator*(T left, const Vector2<T> &right) {
  return Vector2<T>(right.x * left, right.y * left);
}

template<typename T>
Vector2<T> &operator*=(Vector2<T> &left, T right) {
  left.x *= right;
  left.y *= right;

  return left;
}

template<typename T>
Vector2<T> operator/(const Vector2<T> &left, T right) {
  return Vector2<T>(left.x / right, left.y / right);
}

template<typename T>
Vector2<T> &operator/=(Vector2<T> &left, T right) {
  left.x /= right;
  left.y /= right;

  return left;
}

template<typename T>
bool operator==(const Vector2<T> &left, const Vector2<T> &right) {
  return (left.x == right.x) && (left.y == right.y);
}

template<typename T>
bool operator!=(const Vector2<T> &left, const Vector2<T> &right) {
  return (left.x != right.x) || (left.y != right.y);
}


typedef Vector2<int> Vector2i;
typedef Vector2<unsigned int> Vector2u;
typedef Vector2<float> Vector2f;