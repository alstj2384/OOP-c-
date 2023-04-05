#include <iostream>
#include <string>
using namespace std;
class used_car{ // 중고차 class
  int km;       // 주행 키로미터는 private
public:
  string model; // 자동차 모델
  int year;     // 생상 연도
  void set(string m, int y, int k);
  void print_car_info();  // model year km 를 출력
  int get_km();       // km 반환
};
class car_dealer{ // 중고차 회사 class
  used_car *p;    // 중고차 회사가 가지고 있는 중고차
  int num_cars;   // 중고차 회사가 가지고 있는 중고차 수
public:
  car_dealer( int n); //중고차 n개 가지고 시작 
  ~car_dealer();      // "delete [] p;" 출력
  void print(){       //모든 중고차 정보 출력
    for(int i = 0; i < num_cars; i++ ){
      p[i].print_car_info();
    }
  }       
  void search_model( string model); //찾는 모델의 중고차 정보 출력
  void search(string model, int year);  //찾는 모델 생상연도와 같은 중고차 정보 출력
};
//위에 코드는 수정 불가
//여기에 코드 작성
// 입력 출력 예시
//(출력)Number of cars?
//(입력)3
//(출력)Enter model year km.
//(입력)BMW 2003 50000
//(입력)kia 2010 40000
//(입력)BMW 2005 90000
//(출력)-----next day-----
//(출력)Enter search car model.
//(입력)BMW
//(출력)BMW 2003 50000
//(출력)BMW 2005 90000
//(출력)-----next day-----
//(출력)Enter search car model year.
//(입력)BMW 2003
//(출력)BMW 2003 50000
//(출력)-----all cars-----
//(출력)BMW 2003 50000
//(출력)kia 2010 40000
//(출력)BMW 2005 90000
//(출력)delete [] p;
//아래 코드는 수정 불가
int main() {
  int n;
  cout << "Number of cars?" << endl;
  cin >> n; // 자동차 수 입력
  car_dealer incheon(n);
  cout << "-----next day-----" << endl;
  cout << "Enter search car model." << endl;
  string smodel;
  cin >> smodel; // 찾는 모델 입력
  incheon.search_model(smodel);
  cout << "-----next day-----" << endl;
  cout << "Enter search car model year." << endl;
  int year;
  cin >> smodel >> year; // 찾는 모델 생상연도 입력 
  incheon.search(smodel, year);
  cout << "-----all cars-----" << endl;
  incheon.print();
  return 0;
}