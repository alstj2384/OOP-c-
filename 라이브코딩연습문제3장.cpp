#include <iostream>

using namespace std;

class Cal{
    int x, y;

    public:
        Cal(int x, int y);
        ~Cal();
        int add();
        int add(int x);
        int add(int x, int y);
};

Cal::Cal(int x, int y){
    this-> x = x;
    this-> y = y;

    cout << "Cal ������ ȣ��: x=" << x << ", y=" << y << endl;
}

Cal::~Cal(){
    cout << "Cal �Ҹ��� ȣ��: x=" << x << ", y=" << y << endl;
}

int Cal::add(){
    return x + y;
}

int Cal::add(int x){
    return this->y + x;
}

int Cal::add(int x, int y){
    return x + y;
}

int main() {

 int x, y, res;
    cout << "Cal c1(100, 200);" << endl;
    Cal c1(100, 200);
    cout << "c1.add(): " << c1.add() << endl;
    cout << "������ x ����? ";
    cin >> x;
    res = c1.add(x);
    cout << "c1.add(" << x << "): " << res << endl;
    cout << "������ x, y ����? ";
    cin >> x >> y;
    res = c1.add(x, y);
    cout << "c1.add(" << x << "," << y << "): " 
    << res << endl;
 return 0;
}