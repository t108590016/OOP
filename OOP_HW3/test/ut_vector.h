#include "../src/math_vector.h"
#include "../src/dot.h"
#include <cmath>

TEST(InnerProduct, Dot1) {
  double u[]={1, 0, 2};
  double v[]={1, 1, 3};
  ASSERT_NEAR(7, dot(u, 3, v, 3),0.001);
}
TEST(InnerProduct, Error1) {
  double u[]={1, 0, 2};
  double v[]={1, 1};
  try{
    double result = dot(u, 3, v, 2);
    FAIL() << "Should not be here"; // added before class
  }catch(string s){
    ASSERT_EQ("undefined!",s);
  }
}
TEST(Component, CP1) {
  double u[3]={1, 0, 2};
  mathVector w = mathVector(u,3);
  for(int i =0;i<3;i++){
    ASSERT_NEAR(u[i], w.component(i+1),0.001);    
  }

}
TEST(isZero, Zero1) {
  double u[3]={0, 0, 0};
  mathVector w = mathVector(u,3);

  ASSERT_EQ(true, w.isZero());
}
TEST(isZero, Zero2) {
  double u[3]={1, 0, 0};
  mathVector w = mathVector(u,3);

  ASSERT_EQ(false, w.isZero());
}

TEST(Dimension, Dim1) {
  double u[3]={1, 0, 0};
  mathVector w = mathVector(u,3);

  ASSERT_EQ(3, w.dimension());
}

TEST(Length, Len1) {
  double u[2]={3, 4};
  mathVector w = mathVector(u,2);

  ASSERT_NEAR(5, w.length(),0.001);
}
/*
TEST(CHKVECTOR, case1){
  mathVector x = mathVector(u,3);
  mathVector y = mathVector(v,3);

}
*/
