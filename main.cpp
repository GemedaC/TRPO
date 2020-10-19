#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;
// 5 вариант

class Sport {
private:
	string LastName;
	int Number;
	int Score;
	friend ostream& operator<<(ostream& os, const Sport& sport);
	friend istream& operator>>(istream& is, Sport& sport);

public:
	Sport() //Конструктор без данных
	{
		LastName = "";
		Number = Score = 0;
	}
	Sport(string LastName, int Number, int Score) //Конструктор с данными
	{
		this->LastName = LastName;
		this->Number = Number;
		this->Score = Score;
	}
	~Sport() {} // Диструктор

	void InputHuman() // Ввод спортсменов
	{
		SetConsoleCP(866);
		cout << "Введите Фамилию, Номер, Количество очков" << endl;
		cin >> this->LastName >> this->Number >> this->Score;
		SetConsoleCP(1251);
	}
	void SearchHumanNumber(int a) //Поиск по номеру
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