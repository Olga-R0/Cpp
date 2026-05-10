#include <iostream>
#include <string>
#include <vector> 
#include <Windows.h>

using namespace std;


vector<int> PrefixFunction(string str_) {
	int sizeStr = (int)str_.size();
	vector<int> values(sizeStr, 0);

	for (int i = 1; i < sizeStr; i++)
		for (int len = 1; len <= i; len++)
		{	// если префикс длины len равен суффиксу длины len
			if (str_.substr(0, len) == str_.substr(i - len + 1, len))
				values[i] = len;
		}
	return values;
}
vector<int> KMP(string str_, string findStr_) {
	vector<int> indexes;
	int count=0;
	if (findStr_.size() == 0) {
		indexes.push_back(0);
		return indexes;
	}
	vector<int>function = PrefixFunction(findStr_);
	
	int j = 0; //сдвиг по подстроке
	int i = 0; //сдвиг по строке

	while (i < str_.size()) {
		if (str_[i] == findStr_[j])
		{
			i++; j++;
			if(j == findStr_.size())
				indexes.push_back(i - findStr_.size());
		}
		else {
			if (j > 0)
			{
				j = function[j - 1]; count++;
			}
			else
				i++;
		}
		
	}
	cout << endl; cout << "Размер строки " << str_.size() << endl; cout << "Счетчик сдвигов " << str_.size()-count << endl;
	return indexes;
	
}
// Вывести меню и вернуть номер варианта сортировки
int menu()
{
	// Выбранный вариант меню
	int variant;
	cout << "Выберите вариант текста(в котором будет искаться подстрока) и  введите ее номер\n" << endl;
	cout << "1. Художественный текст. Отрывок из 'Маленького принца'\n"
		<< "2. Научный текст. Алгоритм КМП\n"
		<< "3. Свой текст\n"
		<< "4. выйти\n" << endl;
	cout << ">>> ";
	cin >> variant;
	return variant;
}
int main() {

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int choise; 
	string findStr;
	string str1 = "Алгоритм Кнута — Морриса — Пратта (КМП-алгоритм) — эффективный алгоритм, осуществляющий поиск подстроки в строке. Время работы алгоритма линейно зависит от объёма входных данных, то есть разработать асимптотически более эффективный алгоритм невозможно. Алгоритм был разработан Д. Кнутом и В. Праттом и, независимо от них, Д. Моррисом. Результаты своей работы они опубликовали совместно в 1977 году.";
	string str2 = "Не скоро я понял, откуда он явился. Маленький принц засыпал меня вопросами, но, когда я спрашивал о чем - нибудь, он будто и не слышал. Лишь понемногу, из случайных, мимоходом оброненных слов мне все открылось. Так, когда он впервые увидел мой самолет(самолет я рисовать не стану, мне все равно не справиться), он спросил :-Что это за штука ? -Это не штука. Это самолет. Мой самолет. Он летает.";
	string str3;
	int begin = 0;
	vector<int> returnValue;
	cout << "---------Алгоритм Кнута — Морриса — Пратта (КМП-алгоритм)-------" << endl;
begin:
	int variant = menu();
	switch (variant)
	{
	case 1:
		cout << "Ищем в этой подстроке:" << endl;
		cout << str2 << endl;
		cout << "Введите какую подстроку вы хотите найти" << endl;
		cin >> findStr;
		returnValue = KMP(str2, findStr);
		cout << endl;

		for (int i = 0; i < returnValue.size(); i++) {
			cout << "Индекс совпадения:" << returnValue[i] << endl;
			cout << endl;
		}
		if (returnValue.size() == 0)
			cout << "Нет такой подстроки" << endl;
			cout << "Запустить другой поиск? Нажмите 0-нет, 1-да " << endl;
			cin >> choise;
			switch (choise) {
			case 1:
				goto begin; break;
			case 0:
				cout << "Выход из программы..." << endl;
				exit(EXIT_SUCCESS); break;
			}
			break;
	case 2:
		cout << "Ищем в этой подстроке:" << endl;
		cout << str1 << endl;
		cout << "Введите какую подстроку вы хотите найти" << endl;
		cin >> findStr;
		returnValue = KMP(str1, findStr);
		cout << endl;

		for (int i = 0; i < returnValue.size(); i++) {
			cout << "Индекс совпадения:" << returnValue[i] << endl;
			cout << endl;
		}
		if (returnValue.size() == 0)
			cout << "Нет такой подстроки" << endl;

		cout << "Запустить другой поиск? Нажмите 0-нет, 1-да " << endl;
		cin >> choise;
		switch (choise) {
		case 1:
			goto begin; break;
		case 0:
			cout << "Выход из программы..." << endl;
			exit(EXIT_SUCCESS); break;
		}
		break;
	case 3:
		cout<<"Введите свою строку" << endl;
		cin >> str3;
		system("pause");
		cout << "Введите какую подстроку вы хотите найти" << endl;
		cin >> findStr;

		
		returnValue = KMP(str3, findStr);
		cout << endl;

		for (int i = 0; i < returnValue.size(); i++) {
			cout << "Индекс совпадения:" << returnValue[i] << endl;
			cout << endl;
		}
		if (returnValue.size() == 0)
			cout << "Нет такой подстроки" << endl;
		cout << "Запустить другой поиск? Нажмите 0-нет, 1-да " << endl;
		cin >> choise;
		switch (choise) {
		case 1:
			goto begin; break;
		case 0:
			cout << "Выход из программы..." << endl;
			exit(EXIT_SUCCESS); break;
		}
		break;
	case 4:
		cout << "Выход из программы..." << endl;
		exit(EXIT_SUCCESS);
		break;
	default:
		cerr << "Вы выбрали неверный вариант" << endl;
		exit(EXIT_FAILURE);
		}

		return 0;
	}


