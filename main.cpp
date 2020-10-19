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

	string kurs = "Kurs.txt";
	Sport FileStr[20];

	fstream file;
	cout << "1 - Просмотр данных" << "\n2 - Добавить данные" << "\n3 - Заменить данные " << "\n4 - Поиск" << "\n5 - Выйти из программы" << endl;
	int InputFileOperation;
	cin >> InputFileOperation;
	if (InputFileOperation == 1) // Чтение файла
	{
		cout << "Список данных: " << endl;
		file.open(kurs, fstream::in);
		if (!file.is_open()) cout << "Ошибка открытия файла" << endl;
		int n = 0;
		while (true)
		{
			SetConsoleCP(866);
			file >> FileStr[n];
			if (file.eof()) break;
			cout << FileStr[n] << endl;
			SetConsoleCP(1251);
			n++;
		}
		file.close();
	}

	if (InputFileOperation == 2) // Добавление в файл
	{
		file.open(kurs, fstream::in);
		if (!file.is_open()) cout << "Ошибка открытия файла" << endl;
		int n = 0;
		while (true)
		{
			SetConsoleCP(866);
			file >> FileStr[n];
			if (file.eof()) break;
			cout << FileStr[n] << endl;
			SetConsoleCP(1251);
			n++;
		}
		file.close();
		file.open(kurs, fstream::app);
		if (!file.is_open()) cout << "Ошибка открытия файла" << endl;
		cout << "Сколько спортсменов Вы хотите добавить ?" << endl;
		int a;
		cin >> a;
		for (int i = 0; i < a; i++)
		{
			SetConsoleCP(1251);
			FileStr[i].InputHuman();
			file << FileStr[i] << "\n";
			SetConsoleCP(866);
		}
		file.close();
	}
	if (InputFileOperation == 3) // Замена данных
	{
		file.open(kurs, fstream::in);
		if (!file.is_open()) cout << "Ошибка открытия файла" << endl;
		int n = 0;
		while (true)
		{
			SetConsoleCP(866);
			file >> FileStr[n];
			if (file.eof()) break;
			cout << FileStr[n] << endl;
			SetConsoleCP(1251);
			n++;
		}
		file.close();
		cout << "Сколько спортсменов Вы хотите заменить ?" << endl;
		int b;
		cin >> b;
		for (int i = 0; i < b; i++)
		{
			SetConsoleCP(866);
			cout << "Введите номер заменяемого спортсмена" << endl;
			int a;
			cin >> a;
			FileStr[a - 1].InputHuman();
			SetConsoleCP(1251);
		}
		file.close();
		ofstream file;
		file.open(kurs);
		for (int i = 0; i < n; i++)
		{
			file << FileStr[i] << "\n";
		}
		file.close();
	}
	if (InputFileOperation == 4) // Поиск в файле
	{
		file.open(kurs, fstream::in);
		if (!file.is_open()) cout << "Ошибка открытия файла" << endl;
		int n = 0;
		while (true)
		{
			SetConsoleCP(866);
			file >> FileStr[n];
			if (file.eof()) break;
			SetConsoleCP(1251);
			n++;
		}
		file.close();
		cout << "1 - Поиск по номеру спортсмена" << "\n2 - Поиск по фамилии спортсмена" << "\n3 - Поиск по очкам спортсмена" << endl;
		int SearchFile;
		cin >> SearchFile;
		if (SearchFile == 1) // Поиск по номеру
		{
			cout << "Введите номер спортсмена" << endl;
			int a;
			cin >> a;
			FileStr[a - 1].SearchHumanNumber(a);
		}
		if (SearchFile == 2) // Поиск по фамилии
		{
			cout << "Введите фамилию спортсмена" << endl;
			string str;
			cin >> str;
			for (int i = 0; i < n; i++)
			{
				FileStr[i].SearchHumanLastName(str);
			}
		}
		if (SearchFile == 3) // Поиск по очкам
		{
			cout << "Введите количество очков" << endl;
			int a;
			cin >> a;
			for (int i = 0; i < n; i++)
			{
				FileStr[i].SearchHumanScore(a);
			}
		}
	}
	if (InputFileOperation == 5) // Выход
	{
	}

	system("pause");
	return 0;
}