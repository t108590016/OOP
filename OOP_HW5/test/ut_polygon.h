#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/polygon.h"
#include "../src/vector.h"
#include <cmath>

double const epsilon = 0.0001;

TEST(ShapeTest, Polygon){
  double a[]={0, 0};
  double b[]={0, 2};
  double d[]={2, 0};
  double e[]={2, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(d, 2);
  Vector x(e, 2);
  Vector arr[] = {u, v, w, x};
  Polygon poly = Polygon::CreatePolygon(arr, 4);
  ASSERT_NEAR(4, poly.area(), epsilon);
}

TEST(ShapeTest, PolygonException){
  double a[]={0, 0};
  double b[]={0, 2};
  double d[]={2, 0};
  double e[]={2, 2};
  double f[]={3, 4, 5};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(d, 2);
  Vector x(e, 2);
  Vector y(f, 3);
  Vector arr[] = {u, v, w, x, y};
  Polygon poly;
  ASSERT_ANY_THROW(poly = Polygon::CreatePolygon(arr, 5));
}

TEST(ShapeTest, Circle){
  Circle * c = new Circle(10);
  //ASSERT_NEAR(6 * 6 * M_PI, c->area(), epsilon);
  ASSERT_NEAR(2 * 10 * M_PI, c->perimeter(), epsilon);
}

TEST(ShapeTest, Shape){
  Shape * c = new Circle(10);
  ASSERT_NEAR(10 * 10 * M_PI, c->area(), epsilon);
  double a[]={0, 0};
  double b[]={0, 2};
  double d[]={2, 0};
  double e[]={2, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(d, 2);
  Vector x(e, 2);
  Vector arr[] = {u, v, w, x};
  Polygon * poly = new Polygon(arr, 4);
  ASSERT_NEAR(4, poly->area(), epsilon);
}

TEST(FindTest, FindAll) {
  double a[]={0, 0};
  double b[]={0, 3};
  double d[]={3, 0};
  double e[]={3, 3};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(d, 2);
  Vector x(e, 2);
  Vector arr1[] = {u, v, w};
  Vector arr2[] = {u, v, w, x};
  std::vector<Shape *> vec;
  vec.push_back(new Polygon(arr1, 3));
  vec.push_back(new Circle(1.5));
  vec.push_back(new Polygon(arr2, 4));
  vec.push_back(new Circle(0.5));
  vec.push_back(new Circle(1));
  std::vector<Shape *> result = findAll(vec.begin(), vec.end(), [](Shape *s){
    return s->area() > 2 && s->area() < 5.5;
  });
  ASSERT_EQ(2, result.size());
  ASSERT_NEAR(4.5, result[0]->area(), epsilon);
  ASSERT_NEAR(M_PI, result[1]->area(), epsilon);
}
