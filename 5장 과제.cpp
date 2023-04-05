#include <iostream>
#include <string>
using namespace std;


class MyStack {
private:
	string *element; // ������ �޸𸮷� ����� ������
	int size;           // ������ �ִ� ũ��
	int tos;            // ������ top�� ����Ű�� �ε���
public:
	MyStack(int size);    // ������ ������ �ִ� ũ�⸦ �Է� �޾Ƽ� element ��ü �迭�� ��������.
	MyStack(MyStack& s);  // ���� ���� ������
	~MyStack();           // �Ҹ���

	bool push(string item); // item�� ���ÿ� ����
			// ������ ���� �� ������ false��, �ƴϸ� true ����
	bool pop(string &item); // ������ ž�� �ִ� ���� item�� ��ȯ  �׸��� top�� �ִ� �ڷ� ����
	bool peek(string &item); // ������ ž�� �ִ� ���� item�� ��ȯ
	void print_stack();  // ���� ���� ���

};

// ���� �ڵ�� ���� �Ұ�

// ���⿡ MyStack�� ��� ��� �Լ����� �ۼ��϶�.
MyStack::MyStack(int size){
    this->size = size;
	this->element = new string[size];
    tos = -1;

	cout << "MyStack(" << size << ") ������ ȣ��" << endl;
}

MyStack::MyStack(MyStack& s){
	cout << "MyStack(MyStack& s) ���� ������ ȣ��: tos+1 = " << s.size << endl;
    this->size = s.size;
	this->tos = s.tos;
	this->element = new string[size];

	for(int i = 0; i < s.tos+1; i++){
		element[i] = s.element[i];
	}
}

MyStack::~MyStack(){
	cout << "~MyStack �Ҹ��� ȣ��: tos+1 = " << tos+1 << endl; 
    delete [] this->element;
}

bool MyStack::push(string item){
	if(tos == size-1) {
		cout << "stack is full" << endl;
		return false;
	}
	element[++tos] = item;
	return true;
}

bool MyStack::pop(string &item){
	if(tos == -1) {
		cout << "stack is empty" << endl;
		return false;
	}
	item = element[tos];
	element[tos--] = ' ';
	return true;
}

bool MyStack::peek(string &item){
	item = element[tos];
	return true;
}

void MyStack::print_stack(){
	for(int i = 0; i < tos+1; i++) cout << this->element[i] << " " ;
	cout << endl;
}

// �Ʒ� �ڵ�� ���� �Ұ�

int main() {

	int stack_size;

	// ������ �����Ҽ� �ִ� �ִ� ũ�⸦ �Է� �޴´�
	cout << "Enter stack size : ";
	cin >> stack_size;

	// ������ ������ ��
	MyStack first_stack(stack_size);

	// �Է��� �������� ���� �Է� �޴´�
	// �����͸� ���� ��ŭ �Է� �ް� stack�� Ǫ���Ѵ�.
	int  input_size;
	string  item;
	cout << "Enter number of input string : " ;
	cin >> input_size;
	cin.ignore();
	for (int i=0; i < input_size; i++){	
		cout << "Enter string : ";
		getline(cin, item);
		first_stack.push(item);
	}

	// ������ �ڷḦ ���
	cout << "first stack : " ;
	first_stack.print_stack();

	// ������ ������ ��
	MyStack second_stack(first_stack);

	// ������ �ڷḦ ���

	cout << "second stack : " ;
	second_stack.print_stack();

	first_stack.pop(item);
	cout << "first stack pop: " << item << endl ;
	second_stack.peek(item);
	cout << "second stack peek: " << item << endl ;

	// ������ �ڷḦ ���
	cout << "first stack : " ;
	first_stack.print_stack();

	cout << "second stack : " ;
	second_stack.print_stack();

	cout << "second stack all pop: " << endl;
	while (second_stack.pop(item))
		cout << item << endl;

	return 0;
}