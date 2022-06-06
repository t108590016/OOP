#include "../src/ConvString.h"

TEST(CHKOUTPUT, case1){
    string test = "ab2[c]ba";
    string result = convert(test);
    //ASSERT_EQ(1,1);
    ASSERT_TRUE("abccba"==result);
}
TEST(CHKOUTPUT, case2){
    string test= "3[abc]";
    string result = convert(test);
    //ASSERT_EQ(1,1);
    ASSERT_TRUE("abcabcabc"==result);
}
TEST(CHKOUTPUT, case3){
    string test= "2[a2[b]3[c]]";
    string result = convert(test);
    //ASSERT_EQ(1,1);
    ASSERT_TRUE("abbcccabbccc"==result);
}
TEST(CHKINPUT,case1){
    string test=",.`123`";
    int result = checkInput(test);
    //ASSERT_EQ(1,result);
    ASSERT_EQ(1,result);
}
TEST(CHKINPUT,case2){
    string test="ab2[c]ba";
    int result = checkInput(test);
    //ASSERT_EQ(1,result);
    ASSERT_EQ(0,result);
}
