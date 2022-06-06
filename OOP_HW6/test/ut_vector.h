#include "../src/vector.h"
//#include "../src/vector.cpp"
#include "../src/bubble_sort.h"
class VectorTest : public ::testing::Test {
  protected:
    void SetUp() override {
      double a[2] = {1, 2};
      double b[2] = {3, 4};
      double c[3] = {3, 4, 12};
      double d[3] = {6, 8, 24};
      double polygon1[2] = {0, 0};
      double polygon2[2] = {4, 0};
      double polygon3[2] = {4, 4};
      double polygon4[2] = {2, 6};
      double polygon5[2] = {0, 4};
      double polygon6[2] = {6, 2};
      u = Vector(a,2);
      v = Vector(b,2);
      w = Vector(c,3);
      x = Vector(d,3);
      p1 = Vector(polygon1,2);
      p2 = Vector(polygon2,2);
      p3 = Vector(polygon3,2);
      p4 = Vector(polygon4,2);
      p5 = Vector(polygon5,2);
      p6 = Vector(polygon6,2);
      y = x;
    }
    Vector u,v,w,x,y;
    Vector p1,p2,p3,p4,p5,p6;
};


TEST_F(VectorTest, FixtureTest1){
  ASSERT_NEAR(u.at(1),1,0.0001);
  ASSERT_NEAR(u.at(2),2,0.0001);
  ASSERT_NEAR(v.at(1),3,0.0001);
  ASSERT_NEAR(v.at(2),4,0.0001);
  ASSERT_NEAR(w.at(1),3,0.0001);
  ASSERT_NEAR(w.at(2),4,0.0001);
  ASSERT_NEAR(w.at(3),12,0.0001);
  ASSERT_NEAR(x.at(1),6,0.0001);
  ASSERT_NEAR(x.at(2),8,0.0001);
  ASSERT_NEAR(x.at(3),24,0.0001);
}

TEST_F(VectorTest, CheckDimension1){
  ASSERT_EQ(u.dim(),2);
}

TEST_F(VectorTest, CheckDimension2){
  ASSERT_EQ(w.dim(),3);
}

TEST_F(VectorTest, CheckLength1){
  ASSERT_NEAR(v.length(),5,0.0001);
}

TEST_F(VectorTest, CheckLength2){
  ASSERT_NEAR(w.length(),13,0.0001);
}

TEST_F(VectorTest, CopyAssignment1){
  ASSERT_EQ(y.dim(),3);
  ASSERT_NEAR(y.at(1),6,0.0001);
  ASSERT_NEAR(y.at(2),8,0.0001);
  ASSERT_NEAR(y.at(3),24,0.0001);
}

TEST_F(VectorTest, CopyAssignment2){
  Vector z;
  z = x;
  ASSERT_EQ(z.dim(),3);
  ASSERT_NEAR(z.at(1),6,0.0001);
  ASSERT_NEAR(z.at(2),8,0.0001);
  ASSERT_NEAR(z.at(3),24,0.0001);
}

TEST_F(VectorTest, SubMemberFunctionError1){
  ASSERT_ANY_THROW(u.subtract(x));
}

TEST_F(VectorTest, SubMemberFunctionError2){
  ASSERT_ANY_THROW(x.subtract(u));
}

TEST_F(VectorTest, SubMemberFunction1){
  w.subtract(x);
  ASSERT_NEAR(-3,w.at(1),0.0001);
  ASSERT_NEAR(-4,w.at(2),0.0001);
  ASSERT_NEAR(-12,w.at(3),0.0001);
}

TEST_F(VectorTest, AddMemberFunctionError1){
  ASSERT_ANY_THROW(u.add(x));
}

TEST_F(VectorTest, AddMemberFunctionError2){
  ASSERT_ANY_THROW(x.add(u));
}

TEST_F(VectorTest, AddMemberFunction1){
  w.add(x);
  ASSERT_NEAR(9,w.at(1),0.0001);
  ASSERT_NEAR(12,w.at(2),0.0001);
  ASSERT_NEAR(36,w.at(3),0.0001);
}

TEST_F(VectorTest, SubOperatorOverloadingError1){
  ASSERT_ANY_THROW(u-x);
}

TEST_F(VectorTest, SubOperatorOverloadingError2){
  ASSERT_ANY_THROW(x-u);
}

TEST_F(VectorTest, SubOperatorOverloading2){
  ASSERT_NEAR(-3,(w-x).at(1),0.0001);
  ASSERT_NEAR(-4,(w-x).at(2),0.0001);
  ASSERT_NEAR(-12,(w-x).at(3),0.0001);
}

TEST_F(VectorTest, AddOperatorOverloadingError1){
  ASSERT_ANY_THROW(u+x);
}

TEST_F(VectorTest, AddOperatorOverloadingError2){
  ASSERT_ANY_THROW(x+u);
}

TEST_F(VectorTest, AddOperatorOverloading2){
  ASSERT_NEAR(9,(w+x).at(1),0.0001);
  ASSERT_NEAR(12,(w+x).at(2),0.0001);
  ASSERT_NEAR(36,(w+x).at(3),0.0001);
}

TEST_F(VectorTest, centroidTest1){
  Vector p[4] = {p1, p2, p3, p5};
  Vector c = centroid(p, 4);
  ASSERT_NEAR(2, c.at(1), 0.0001);
  ASSERT_NEAR(2, c.at(2), 0.0001);
}

TEST_F(VectorTest, centroidTestExeception){
  Vector p[4] = {p1, p2, w, p5};
  ASSERT_ANY_THROW(centroid(p, 4));
}

TEST_F(VectorTest, areaTestExeception){
  ASSERT_ANY_THROW(Area(p1, p2, w));
}

TEST_F(VectorTest, areaTest1){
  ASSERT_NEAR(8, Area(p1, p2, p3), 0.0001);
}

TEST_F(VectorTest, areaTest2){
  Vector p[4] = {p1, p2, p3, p5};
  ASSERT_NEAR(16, Area(p, 4), 0.0001);
}

TEST_F(VectorTest, areaTest3){
  Vector p[4] = {p2, p3, p1, p5};
  ASSERT_NEAR(16, Area(p, 4), 0.0001);
}

TEST_F(VectorTest, areaTest4){
  Vector p[5] = {p1,p2,p3,p4,p5};
  ASSERT_NEAR(20, Area(p, 5), 0.0001);
}

TEST_F(VectorTest, areaTest5){
  Vector p[6] = {p1,p2,p3,p4,p5,p6};
  ASSERT_NEAR(24, Area(p, 6), 0.0001);
}

TEST_F(VectorTest, distanceTest1){
  ASSERT_NEAR(13, distance(w, x), 0.0001);
}

TEST_F(VectorTest, distanceTestExeception){
  ASSERT_ANY_THROW(distance(p2, w));
}

TEST_F(VectorTest, perimeterTestExeception){
  Vector p[4] = {p1, p2, w, p5};
  ASSERT_ANY_THROW(perimeter(p, 4));
}

TEST_F(VectorTest, perimeterTest1){
  Vector p[4] = {p1, p2, p3, p5};
  ASSERT_NEAR(16, perimeter(p, 4), 0.0001);
}
