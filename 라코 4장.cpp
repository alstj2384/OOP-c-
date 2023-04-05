#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Container {
    private:
        string title; // �����̳� Ÿ��Ʋ
        char *author; // �����̳� �ۼ��� �̸� (���� �Ҵ�)
        int size; // �����̳ʿ� ����� ���� �迭 ũ��
        int *arr; // ������ �����ϴ� �迭 (���� �Ҵ�)
    public:
        void display();
        Container(string title, char *author, 
        int size, int *arr);
        ~Container();
        void replace_subtitle(string from, string to);
        void replace_first_last();
    };
        // ���⿡ Container Ŭ���� ��� �Լ����� ������ ��

Container::Container(string title, char *author,
        int size, int *arr){
        cout << "Container ������ ȣ��" << endl;

        this->title = title;
        this->size = size;

        int len = strlen(author);
        this->author = new char[len+1];
        strcpy(this->author, author);

        this->arr = new int[size];
        for(int i = 0; i < size; i++){
            this->arr[i] = arr[i];
        }

        display();

    }

Container::~Container(){
    cout << "Container �Ҹ��� ȣ��" << endl;
    display();
    delete [] this->arr;
    delete [] this->author;

}

void Container::display(){
    cout << "title:" << this->title << ", author:" << this->author << ", size:" << size << endl;

    cout << "arr[] = ";
    for(int i = 0; i < size-1; i++){
        cout << arr[i] <<",";
    }
    cout << arr[size-1] << endl;
    cout << endl;
}


void Container::replace_subtitle(string from, string to){

    while(this->title.find(from) != -1){
        int idx = this->title.find(from);
        this->title.replace(idx, from.length(), to);
    }

    display();
}

void Container::replace_first_last(){
    int idx, ridx;
    string a, b, tmp;

    if(this->title.find(" ") != -1){
        idx = this->title.find(' ');
        ridx = this->title.rfind(' ');
        
        int rlen = this->title.length();

        a = this->title.substr(0, idx);
        b = this->title.substr(ridx+1, rlen-ridx);

        cout << a << " " << b << endl;

        this->title.replace(0, a.length(), b);
        this->title.replace(ridx, b.length(), a);
    }
    display();
}
int main() {
        string title("First title long title of title Last");
        char author[] = "Chosun Universty";
        int arr[5] = { 1, 2, 3, 4, 5 };
        Container c(title, author, 5, arr);
        cout << "���񿡼� \"title\" �ܾ \"name\" �ܾ�� ��� �ٲߴϴ�." << endl;
        c.replace_subtitle("title", "name");
        cout << "������ ù �ܾ�� ������ �ܾ��� ��ġ�� �ٲߴϴ�." << endl;
        c.replace_first_last();
}