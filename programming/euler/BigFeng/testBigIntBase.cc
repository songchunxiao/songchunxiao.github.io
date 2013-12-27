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
    BigIntBase c("99999999999999999999999999999999999"), d("1");
    BigIntBase e = c+d;
    test(7, e.toStringInBase(10), "100000000000000000000000000000000000"); //7

    BigIntBase f1("37107287533902102798797998220837590246510135740250");
    BigIntBase f2("46376937677490009712648124896970078050417018260538");
    BigIntBase f3 = f1 + f2;
    test(8, f3.toStringInBase(10), "83484225211392112511446123117807668296927154000788"); //7

}
