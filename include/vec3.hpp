#pragma once

#include <cmath>
#include <ostream>

class Vec3 {
public:
  double x;
  double y;
  double z;

  Vec3() : x(0), y(0), z(0) {}
  Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

  Vec3 operator-() const {
    return Vec3(-x, -y, -z);
  }

  Vec3 operator+=(const Vec3& other) {
    return Vec3(x+other.x, y+other.y, z+other.z);
  }

  Vec3 operator*=(double s) {
    return Vec3(x*s, y*s, z*s);
  }

  Vec3 operator/=(double s) {
    return *this*= 1/s;
  }

  double length_squared() const {
    return x*x + y*y + z*z;
  }

  double length() const {
    return sqrt(length_squared());
  }

};

using Point3 = Vec3;

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
  return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
  return Vec3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
  return Vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline Vec3 operator*(double t, const Vec3& u) {
  return Vec3(u.x * t, u.y * t, u.z * t);
}

inline Vec3 operator*(const Vec3& u, double t) {
  return t * u;
}

inline Vec3 operator/(const Vec3& u, double t) {
  return (1/t) * u;
}

inline double dot(const Vec3& u, const Vec3& v) {
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
  return Vec3(
        u.y * v.z - u.z * v.y,
        u.x * v.z - u.z * v.x,
        u.x * v.y - u.y * v.x
      );
}

inline Vec3 unit_vector(const Vec3& v) {
  return v / v.length();
}
