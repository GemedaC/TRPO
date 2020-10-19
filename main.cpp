#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;
// 5 �������

class Sport {
private:
	string LastName;
	int Number;
	int Score;
	friend ostream& operator<<(ostream& os, const Sport& sport);
	friend istream& operator>>(istream& is, Sport& sport);

public:
	Sport() //����������� ��� ������
	{
		LastName = "";
		Number = Score = 0;
	}
	Sport(string LastName, int Number, int Score) //����������� � �������
	{
		this->LastName = LastName;
		this->Number = Number;
		this->Score = Score;
	}
	~Sport() {} // ����������

	void InputHuman() // ���� �����������
	{
		SetConsoleCP(866);
		cout << "������� �������, �����, ���������� �����" << endl;
		cin >> this->LastName >> this->Number >> this->Score;
		SetConsoleCP(1251);
	}
	void SearchHumanNumber(int a) //����� �� ������
	{
		if (this->Number == a)
		{
			cout << LastName << " " << Number << " " << Score << endl;
		}
	}
	void SearchHumanLastName(string str)
	{
		if (this->LastName == str)
		{
			cout << LastName << " " << Number << " " << Score << endl;
		}
	}
	void SearchHumanScore(int a)
	{
		if (this->Score == a)
		{
			cout << LastName << " " << Number << " " << Score << endl;
		}
	}
};



ostream& operator<<(ostream& os, const Sport& sport) {

	os << sport.LastName << " " << sport.Number << " " << sport.Score;

	return os;
}

istream& operator>>(istream& is, Sport& sport) {

	is >> sport.LastName >> sport.Number >> sport.Score;

	return is;
}

int main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "ru");

	system("pause");
	return 0;