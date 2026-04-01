#include<iostream>
using namespace std;

class Test{
    public:
    void hello(){
        cout << "Hello world" << endl;
    }
};

int main(){
    Test obj;
    obj.hello();

    Test* pt;
    pt->hello();

    delete pt;
    return 0;
}