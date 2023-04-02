#include <iostream>
#include <string>

using namespace std;

class Container {
    string title;  // 컨테이너 타이틀
    int    size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int    *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    Container(); // 생성자
    ~Container(); // 소멸자
    void setTitle(string title);
    string getTitle();
    void newArray();
    void average();
    void rightRotateTitle();
    void findDeleteTitle();
    void newIntArray();
    void inputIntArray();
};

void Container::rightRotateTitle(){
    int len = title.length();
    for(int i = 0 ;i < len; i++){
        string a,b;
        a = title.substr(len-1,1);
        b = title.substr(0,len-1);

        title = a + b;
        cout << title << endl;
    }
}
Container::Container(){
    arr = NULL;
    size = 0;
    cout << "Container(): arr = nullptr; size = 0;" << endl;
}

Container::~Container(){
    if(arr != NULL) {cout << "~Container(): arr["<< size << "] deleted;" << endl; 
    delete arr;}
    else cout << "~Container(): "<< title << endl;
}

void Container::setTitle(string title) {
    this->title = title;
}

string Container::getTitle() {
    return this->title;  /* 멤버변수 title을 반환하라. */
}

void constructor() {
    Container c;
    c.setTitle("constructor-title");
    cout << "c.getTitle(): " << c.getTitle() << endl;
}

void intArray() {
    Container c;
    c.newIntArray();
    c.inputIntArray();
    c.average();
}

void Container::average(){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    cout << "average: " << sum/size << endl;
}

void Container::inputIntArray(){
    int a;
    cout << "input " << size << " integers: ";
    for(int i = 0; i < size; i++){
        cin >> a;
        arr[i] = a;
    }
    cout << "arr[" << size << "]: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

void Container::newIntArray(){
    cout << "element numbers of int array[]? " ;
    cin >> size;
    arr = new int[size];

}
Container *newObjectArray(int size) {
    Container *pArr = nullptr; // Container 객체 배열 시작 주소
    string s;
    pArr = new Container[size];

    cout << "input " << size << " words: ";

    for(int i = 0 ; i < size; i++){
        cin >> s;
        pArr[i].setTitle(s);
    }
    return pArr;
}

void printTitles(Container *pArr, int size) {
    cout << "words: ";
    for(int i = 0; i < size; i++){
        cout << " "<< pArr[i].getTitle();
    }
    cout << endl;
}

void objectArray() {
    Container *pArr; // Container 객체 배열 시작 주소
    int size;        // Container 객체 배열 원소 개수
    cout << "element numbers of Container array[]? ";
    cin >> size;
    pArr = newObjectArray(size);
    printTitles(pArr, size);
    /* 여기서 pArr이 포인터 하는 메모리를 반납하시오. */
    delete [] pArr;
}

void inputTitle(Container* cp) {
    string s;
    getline(cin, s); // 앞서 입력된 메뉴항목 번호 뒤의 [엔터]를 제거함
    /* 여기에 코드를 구현하라. */
    cout << "input title: " ;
    getline(cin, s);
    cp->setTitle(s);
}

void rotateTitle() {
    Container c;
    inputTitle(&c);
    cout << "c.getTitle(): " << c.getTitle() << endl;
    c.rightRotateTitle();

}

void Container::findDeleteTitle(){
    string s;
    string n;
    cout << "word to delete? " ;
    cin >> s;
    int startindex = 0;
    while(true){
        startindex= title.find(s);
        if(startindex == -1) break;
        title = title.erase(startindex,s.length());
    }
    cout << title << endl;
}
void findDelete() {
    Container c;
    inputTitle(&c);      // This AAis aAA AAtest AAtitle.
    c.findDeleteTitle();
}

string menuStr =
"******************************** Main Menu *********************************\n"
"* 0.Exit 1.constructor 2.intArray 3.objectArray 4.rotateTitle 5.findDelete *\n"
"****************************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: constructor(); break;
        case 2: intArray();    break;
        case 3: objectArray(); break;
        case 4: rotateTitle(); break;
        case 5: findDelete(); break;
        }
    }
    cout << "Good bye!!" << endl;
}
