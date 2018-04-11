#include "color.hpp"

#include <estl/vector.hpp>
#include <iostream>

ray::Color::Color() {}
ray::Color::Color(int red, int green, int blue)
    : r(red / 256.0), g(green / 256.0), b(blue / 256.0) {}
ray::Color::Color(double red, double green, double blue)
    : r(red), g(green), b(blue) {}
ray::Color::Color(estl::vector::Vector<double, 3> vec)
    : r(vec[0]), g(vec[1]), b(vec[2]) {}

ray::Color& ray::Color::operator+=(const Color& rhs) {
  Combine(*this, 0.5, rhs, 0.5);
  return *this;
}

ray::Color ray::Combine(Color lhs, double lhs_perc, Color rhs,
                        double rhs_perc) {
  return Color((lhs.r * lhs_perc) + (rhs.r * rhs_perc),
               (lhs.g * lhs_perc) + (rhs.g * rhs_perc),
               (lhs.b * lhs_perc) + (rhs.b * rhs_perc));
}

ray::Color ray::operator+(Color lhs, Color rhs) {
  return Combine(lhs, 1.0, rhs, 1.0);
}
ray::Color ray::operator-(Color lhs, Color rhs) {
  return Combine(lhs, 0.5, rhs, -0.5);
}
ray::Color ray::operator*(Color lhs, Color rhs) {
  return Color(lhs.r * rhs.r, lhs.g * rhs.g, lhs.b * rhs.b);
}
ray::Color ray::operator/(Color lhs, Color rhs) {
  return Color(lhs.r / rhs.r, lhs.g / rhs.g, lhs.b / rhs.b);
}
ray::Color ray::operator+(Color lhs, double rhs) {
  return Color(lhs.r + rhs, lhs.g + rhs, lhs.b + rhs);
}
ray::Color ray::operator-(Color lhs, double rhs) {
  return Color(lhs.r - rhs, lhs.g - rhs, lhs.b - rhs);
}
ray::Color ray::operator*(Color lhs, double rhs) {
  return Color(lhs.r * rhs, lhs.g * rhs, lhs.b * rhs);
}
ray::Color ray::operator/(Color lhs, double rhs) {
  return Color(lhs.r / rhs, lhs.g / rhs, lhs.b / rhs);
}
ray::Color ray::operator+(double lhs, Color rhs){
  return Color(rhs.r + lhs, rhs.g + lhs, rhs.b + lhs);
}
ray::Color ray::operator-(double lhs, Color rhs){
  return Color(rhs.r - lhs, rhs.g - lhs, rhs.b - lhs);
}
ray::Color ray::operator*(double lhs, Color rhs){
  return Color(rhs.r * lhs, rhs.g * lhs, rhs.b * lhs);
}
ray::Color ray::operator/(double lhs, Color rhs){
  return Color(rhs.r / lhs, rhs.g / lhs, rhs.b / lhs);
}

ray::Color ray::Pow(Color val, double exp){
  return Color(pow(val.r, exp), pow(val.g, exp), pow(val.b, exp));
}

ray::Color ray::Normalize(Color val){
  double len = sqrt(pow(val.r, 2) + pow(val.g, 2) + pow(val.b, 2));
  return val / len;
}

std::ostream& ray::operator<<(std::ostream& out, Color col) {
  out << col.r << " " << col.g << " " << col.b;
  return out;
}
