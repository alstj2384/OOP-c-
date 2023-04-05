/**************************************************
 아래는 Book 클래스를 선언하고 구현한 프로그램이다.
 프로그램의 실행결과를 참고하여 나머지 코드를 구현하라.
 **************************************************/
class Book {
    int price;    // 가격
    int pages;    // 페이지수
    string title; // 제목
public:
    Book();  // (1)기본생성자 선언
    ~Book(); // (2)소멸자 선언 
    Book(int s, int g, string c); // (3) 매개변수가 있는 생성자선언
    /* Book(const Book &obj);        // (4) 복사생성자 선언 */
    void show();
    set() 함수 선언 (하나의 set() 함수만 선언할 것)
};
// 위에 코드는 수정 불가
// 여기에 코드 작성
// (1) 기본생성자 구현
// (2) 소멸자 구현 
// (3) 매개변수가 있는 생성자 구현
/*  // (4) 복사생성자 구현  */
void Book::show()
{
    cout << "==============" << endl;
    cout << "가   격: " << price << endl;
    cout << "페이지수: " << pages << endl;
    cout << "제   목: " << title << endl;
    cout << "==============" << endl << endl;
}
// 아래 set() 함수 외에 또 다른 set() 함수를 중복하여 구현하지 말 것.
void Book::set(int price, int pages, string title)
{
    매개변수 값을 상응하는 멤버 변수에 저장
    show();
}
// 아래 main() 함수는 수정 불가
int main()
{
    int price, page;
    string title;
    Book bk1;           // 기본 생성자 호출
    cout << "가격 페이지수 책제목 : ";
    cin >> price >> page >> title;
    Book bk2(price, page, title); // 매개변수가 있는 생성자 호출
/**************************************************
    Book bk3(bk2);     // 복사 생성자 호출
    bk3.show();
    msg(30); // 디폴트 매개변수 id, text를 가진 함수 msg
    msg(50,"Python");
 **************************************************/
    cout << "\nbk1.show() " << endl;
    bk1.show();
    cout << "가격? ";
    cin >> price;
    cout << "bk1.set(price) " << endl;
    bk1.set(price);
    cout << "가격 페이지수 책제목? ";
    cin >> price >> page >> title;
    cout << "bk1.set(price, page, title) " << endl;
    bk1.set(price, page, title);
    return 0;
}
/***************************************
 * 프로그램 실행 결과
 ***************************************
기본 생성자 호출: 0,1,white
가격 페이지수 책제목 : 1000 200 C++
매개변수가 있는 생성자 호출: 1000,200,C++
bk1.show() 
==============
가   격: 0
페이지수: 1
제   목: white
==============
가격? 10000
bk1.set(price) 
==============
가   격: 10000
페이지수: 500
제   목: JAVA
==============
가격 페이지수 책제목? 20000 1000 C
bk1.set(price, page, title) 
==============
가   격: 20000
페이지수: 1000
제   목: C
==============
소멸자 호출
소멸자 호출 
****************************************/