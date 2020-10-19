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
	Sport() //Конструктор без данных
	{
		LastName = "";
		Number = Score = 0;
	}
	Sport(std::string LastName, int Number, int Score) //Конструктор с данными
	{
		this->LastName = LastName;
		this->Number = Number;
		this->Score = Score;
	}
	~Sport() {} // Диструктор
	
	void InputHuman() // Ввод спортсменов
	{
		SetConsoleCP(866);
		std::cout << "Введите Фамилию, Номер, Количество очков" << std::endl;
		std::cin >> this->LastName >> this->Number >> this->Score;
		SetConsoleCP(1251);
	}
	void SearchHumanNumber(int a) //Поиск по номеру
	{
		if (this->Number == a)
		{
			std::cout << LastName << " " << Number << " " << Score << std::endl;
		}
	}
	void SearchHumanLastName(std::string str) //Поиск по Фамилии
	{
		if (this->LastName == str)
		{
			std::cout << LastName << " " << Number << " " << Score << std::endl;
		}
	}
	void SearchHumanScore(int a) //Поиск по очкам
	{
		if (this->Score == a)
		{
			std::cout << LastName << " " << Number << " " << Score << std::endl;
		}
	}
};

std::ostream& operator<<(std::ostream& os, const Sport& sport) { //Переназначение оператора вывода

	os << sport.LastName << " " << sport.Number << " " << sport.Score;

	return os;
}

std::istream& operator>>(std::istream& is, Sport& sport) { //Переназначение оператора ввода

	is >> sport.LastName >> sport.Number >> sport.Score;

	return is;
}