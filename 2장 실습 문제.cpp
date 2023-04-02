#include <iostream>
#include <string>


using namespace std;

int main(){

    string name;
    int id;
    double weight;
    bool married;

    cin >> boolalpha;
    cout << boolalpha;

    cout << "Hello world!!"<<endl;

    cout << "name? ";
    getline(cin, name);

    cout << "name: " << name << endl;

    cin.clear();
    cout << "id? ";
    cin >> id;
    cout << "id: " << id << endl;

    cout << "weight? ";
    cin >> weight;
    cout << "weight: " << weight << endl;

    cout << "married? ";
    cin >> married;
    cout << "married: " << married << endl;
    cin.ignore();

    cout << "name to find? ";
    string s;
    getline(cin, s);
    
    if(name == s) cout << "name:"<<name <<", "<<"id:"<<id <<", "<<"weight:"<<weight <<", "<<"married:"<<married<<endl;
    else cout << s << ": not found";
    return 0;
}