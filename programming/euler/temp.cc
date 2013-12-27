#include<string>
#include<iostream>
using namespace std;

string func(){
    return string("fengjie");
}
int main(){
    char c = -1;
    cout << (int)(unsigned char)c << endl;
    cout << func() << std::endl;
}
