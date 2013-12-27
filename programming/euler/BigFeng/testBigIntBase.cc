#include "BigIntBase.cc"

void test(int label, int testValue, int rightValue){
    printf("%3d: %s : It outputs [%d], the expected value is [%d]\n", 
            label, (testValue==rightValue?"Right":"Wrong"), testValue, rightValue);
}
void test(int label, string test, const char* rightValue){
    const char* testValue = test.c_str();
    printf("%3d: %s : It outputs [%s], the expected value is [%s]\n", 
            label, (strcmp(testValue,rightValue)==0?"Right":"Wrong"), testValue, rightValue);
}
int main(){

    BigIntBase a;
    test(1, a.capacity, 100);   //1
    BigIntBase b("123"), b1("1234"), b2("122");
    test(2, b.compare(b1), -1); //2
    test(3, b.compare(b2), 1); //3
    test(4, b.compare(b), 0); //4

    BigIntBase c("99999999999999999999999999999999999"), c1("1");
    BigIntBase c2 = c+c1;
    test(5, c2.toStringInBase(10), "100000000000000000000000000000000000"); //5

    BigIntBase d("83484225211392112511446123117807668296927154000788"), d1("46376937677490009712648124896970078050417018260538"); 
    BigIntBase d2 = d - d1;
    test(6, d2.toStringInBase(10) , "37107287533902102798797998220837590246510135740250"); //6

    BigIntBase f1("37107287533902102798797998220837590246510135740250");
    BigIntBase f2("46376937677490009712648124896970078050417018260538");
    BigIntBase f3 = f1 + f2;
    test(8, f3.toStringInBase(10), "83484225211392112511446123117807668296927154000788"); //7

}
