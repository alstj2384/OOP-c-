#include <iostream>

using namespace std;
class Cal{
    int x, y;

    public:
        Cal(int x, int y);
        ~Cal();
        int add();
};

Cal::Cal(int x = 100, int y = 200){
    this-> x = x;
    this-> y = y;

    cout << "Cal 생성자 호출: x=" << x << ", y=" << y << endl;
}

Cal::~Cal(){
    cout << "Cal 소멸자 호출: x=" << x << ", y=" << y << endl;
}

int Cal::add(){
    return x + y;
}


int main() {
    cout << "Cal *c1 = new Cal()" << endl;
    Cal *c1 = new Cal();
    cout << "c1->add(): " << c1->add() << endl;
    cout << "Cal *c2 = new Cal(10)" << endl;
    Cal *c2 = new Cal(10);
    cout << "c2->add(): " << c2->add() << endl;
    cout << "Cal *c3 = new Cal(10, 20)" << endl;
    Cal *c3 = new Cal(10, 20);
    cout << "c3->add(): " << c3->add() << endl;
    // 여기에 필요한 코드를 더 추가하라.
    delete c2;
    delete c3;
    delete c1;
    return 0;
}