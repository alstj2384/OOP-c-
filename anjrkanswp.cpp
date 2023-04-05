#include <iostream>
#include <string>
using namespace std;

class Container {
  string title;
  int    size;
  int    *arr;
public:
  Container();
  Container(string title);
  Container(string title, int size);
  ~Container();
   Container(const Container& container);
  void setTitle(string title);
  string getTitle();
  void printIntArray();
  Container& newIntArray(){
     if (arr != nullptr)
       delete [] arr;
     cout << "element numbers of int array[]? ";
     cin >> size;
     arr = new int[size];
         return *this;
   };
  Container& inputIntArray(){
     cout << "input " << size << " integers: ";
     for (int i = 0; i < size; ++i)
       cin >> arr[i];
      return *this;
   };
};

Container::Container(): Container("no-title") { }

Container::Container(string title): Container(title, 0) { }

Container::Container(string title, int size) {
   this->title = title;
   this->size = size;
   if(size > 0){
      arr = new int[size];
      for(int i=0; i<size; i++){
         arr[i] = 0;
      }
   }
  else arr = nullptr;
     cout << "Container(): "; printIntArray();
}

Container::~Container() {
  cout << "~Container(): "; printIntArray();
  if (arr != nullptr)
    delete [] arr;
}

Container::Container(const Container& container){
   this->title = container.title;
   this->size = container.size;
   if(size > 0){
      arr = new int[size];
      for(int i=0; i<size; i++){
         this->arr[i] = container.arr[i];
      }
   }
   else arr = nullptr;
   cout << "Container(Container& c): "; printIntArray();
}

void Container::setTitle(string title) {
  this->title = title;
}

string Container::getTitle() {
  return title;
}

void Container::printIntArray() {
  cout << title << ": arr[" << size << "]: ";
  for (int i = 0; i < size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

void skipEnter() {
   string s;
   getline(cin, s);
}

void inputTitle(Container &d) {
   string s;
   cout << "input title: ";
   getline(cin, s);
   d.setTitle(s);
}

void refParam() {
  Container c("C", 3);
  Container b("B");
  Container a;
  Container d;
  skipEnter();
  inputTitle(d);
}

Container& changeTitle(Container& rc) {
  string s;
  cout << "title to change: ";
  getline(cin, s);
  rc.setTitle(s);
  return rc;
}

void refRet1() {
   skipEnter();
   Container c("C");
   Container& rc = changeTitle(c);
   cout << " c.getTitle(): " <<  c.getTitle() << endl;
   cout << "rc.getTitle(): " << rc.getTitle() << endl;
   cout << "---" << endl;
   Container& rrc = changeTitle(rc);
  cout << "appendTitle(c).getTitle(): " << rrc.getTitle() << endl;
  cout << "             c.getTitle(): " <<               c.getTitle() << endl;
  cout << "            rc.getTitle(): " <<              rc.getTitle() << endl;
}

void refRet2() {
   Container c("C");
  c.newIntArray().inputIntArray().printIntArray();
}

void explicitCopy() {
   Container c1("c1", 4);
  c1.inputIntArray().printIntArray();
  cout << "---" << endl;
  Container c2(c1);
  c2.setTitle("c2");
  c2.printIntArray();
  cout << "---" << endl;
  c2.inputIntArray().printIntArray();
  c1.printIntArray();
}

void callByValue(Container v) {
    cout << "callByValue" << endl;
    v.setTitle("V");
    v.inputIntArray().printIntArray();
}

Container returnValue(Container& r) {
    cout << "returnValue" << endl;
    return r;
}

void implicitCopy() {
   Container a("A", 2);
  a.inputIntArray().printIntArray();
  cout << "---" << endl;
  Container b = a;
  b.setTitle("B");
  b.inputIntArray().printIntArray();
  cout << "---" << endl;
   callByValue(a);
  cout << "---" << endl;
   Container c = returnValue(a);
  c.setTitle("C");
  c.inputIntArray().printIntArray();
  cout << "---" << endl;
}

string menuStr =
"****************************** Main Menu ******************************\n"
"* 0.Exit 1.refParam 2.refRet1 3.refRet2 4.explicitCopy 5.implicitCopy *\n"
"***********************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: refParam();     break;
        case 2: refRet1();      break;
        case 3: refRet2();      break;
        case 4: explicitCopy(); break;
        case 5: implicitCopy(); break;
        }
    }
    cout << "Good bye!!" << endl;
}