#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Container {
    private:
        string title; // 컨테이너 타이틀
        char *author; // 컨테이너 작성자 이름 (동적 할당)
        int size; // 컨테이너에 저장된 정수 배열 크기
        int *arr; // 정수를 저장하는 배열 (동적 할당)
    public:
        void display();
        Container(string title, char *author, 
        int size, int *arr);
        ~Container();
        void replace_subtitle(string from, string to);
        void replace_first_last();
    };
        // 여기에 Container 클래스 멤버 함수들을 구현할 것

Container::Container(string title, char *author,
        int size, int *arr){
        cout << "Container 생성자 호출" << endl;

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
    cout << "Container 소멸자 호출" << endl;
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
        cout << "제목에서 \"title\" 단어를 \"name\" 단어로 모두 바꿉니다." << endl;
        c.replace_subtitle("title", "name");
        cout << "제목의 첫 단어와 마지막 단어의 위치를 바꿉니다." << endl;
        c.replace_first_last();
}