#include "Basics.cpp"
// Points must be oriented (CW or CCW), and non-convex is OK
// Returns (nan,nan) if area of polygon is zero
point centroid(vector<point> p) {
  int n = p.size(); // should be at least 1
  double area = 0;
  point c(0, 0); // Not required for area of polygon
  for(int i = n - 1, j = 0; j < n; i = j++) {
    double a = cross(p[i], p[j]) / 2;
    area += a;
    c += (p[i] + p[j]) * (a / 3);
  }
  c /= area;
  return c; // or return 'area' for the area of polygon
}
