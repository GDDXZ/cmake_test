#include <iostream>
#include "math/math_function.hpp"
using namespace std;
// 测试父类和子类具有相同变量名
class A{
protected:
    int m = 0;
};
class B : public A{
private:
    int m = 1;
public:
    B(){
        std::cout << A::m << std::endl;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::string str = "Hello, World and Mac!";
    std::cout << str << std::endl;
    str.append(" demo");
    std::cout << str << std::endl;
    A a;
    B b;
    std::cout << power(2.0, 3) << std::endl;
    return 0;
}
