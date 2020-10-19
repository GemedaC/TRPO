#include "ClassSport.h"
#include <iostream>
#include <Windows.h>

class Sport {
private:
	std::string LastName;
	int Number;
	int Score;
	friend std::ostream& operator<<(std::ostream& os, const Sport& sport);
	friend std::istream& operator>>(std::istream& is, Sport& sport);

public:
	Sport() //����������� ��� ������
	{
		LastName = "";
		Number = Score = 0;
	}
	Sport(std::string LastName, int Number, int Score) //����������� � �������
	{
		this->LastName = LastName;
		this->Number = Number;
		this->Score = Score;
	}
	~Sport() {} // ����������
	
	void InputHuman() // ���� �����������
	{
		SetConsoleCP(866);
		std::cout << "������� �������, �����, ���������� �����" << std::endl;
		std::cin >> this->LastName >> this->Number >> this->Score;
		SetConsoleCP(1251);
	}
	void SearchHumanNumber(int a) //����� �� ������
	{
		if (this->Number == a)
		{
			std::cout << LastName << " " << Number << " " << Score << std::endl;
		}
	}
	void SearchHumanLastName(std::string str) //����� �� �������
	{
		if (this->LastName == str)
		{
			std::cout << LastName << " " << Number << " " << Score << std::endl;
		}
	}
	void SearchHumanScore(int a) //����� �� �����
	{
		if (this->Score == a)
		{
			std::cout << LastName << " " << Number << " " << Score << std::endl;
		}
	}
};

std::ostream& operator<<(std::ostream& os, const Sport& sport) { //�������������� ��������� ������

	os << sport.LastName << " " << sport.Number << " " << sport.Score;

	return os;
}

std::istream& operator>>(std::istream& is, Sport& sport) { //�������������� ��������� �����

	is >> sport.LastName >> sport.Number >> sport.Score;

	return is;
}