// TroneBattle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Hero.h"
#include "Enemy.h"
#include "string"
#include "stdlib.h"
#include "ctime"
#include "vector"
using std::string;
using std::cout;

void GetCommand();
void ProcessCommand(string command);
void Help();
void ReadFromFile(string path);
void Stats();
void Next();
void GameOver();
void Fight();
bool IsPassed(Enemy enemy);
void Win();

Hero user;
Enemy enemy;
vector<Enemy> enemiesPassed;
bool attack = true;
int enemyHP;
int userHP;
int main()
{
	setlocale(LC_ALL, "Russian");
	ReadFromFile("intro.txt");
	user.ChooseHero();
	ReadFromFile("firstAction.txt");
	Help();
	while (true)
	{
		GetCommand();
	}
	return 0;
}

void GetCommand()
{
	string command;
	cout << endl << "Введите команду: ";
	cin >> command;
	ProcessCommand(command);
}

void ProcessCommand(string command)
{
	if (command == "help")
	{
		Help();
		GetCommand();
	}
	else if (command == "stats")
	{
		Stats();
		GetCommand();
	}
	else if (command == "next")
	{
		Next();
	}
	else
	{
		cout << "Некорректная команда!" << endl;
		GetCommand();
	}
}

void Next()
{
	if (user.GetLevel() == 5)
	{
		Win();
	}
	Enemy newEnemy;
	enemy = newEnemy;
	if (IsPassed(enemy))
		Next();
	enemiesPassed.push_back(enemy);
	string answer;
	cout << "Вам на встречу попался " << enemy.m_name << "!" << endl;
	enemy.ShowFeatures();
	cout << "Вам предстоит сражение! Начать сражение?" << endl << "Введите ответ (y/n): ";
	while (cin >> answer)
	{
		if (answer == "y")
		{
			enemyHP = enemy.m_HP;
			userHP = user.m_HP;
			Fight();
			break;
		}
		else if (answer == "n")
		{
			cout << "Вам некуда бежать! Враг встал у вас на пути. Это была проверка на силу духа и характера" << endl << "СЛАБАК!" << endl;
			enemyHP = enemy.m_HP;
			userHP = user.m_HP;
			Fight();
			break;
		}
		else
			cout << "Введите корректный ответ (y/n): ";
	}
}

void Fight()
{
	srand(int(time(0)));
	string command;

	if (attack)
	{
		int userAttack = rand() % user.m_AP;
		enemyHP -= userAttack;
		cout << "Вы нанесли врагу " << userAttack << endl;
		if (enemyHP <= 0)
		{
			cout << "Враг повержен!";
			user.LevelUp();
			GetCommand();
		}
		attack = false;
		cout << "Здоровье врага: " << enemyHP << endl;
		cout << "Продолжить(y/n): ";

		while (cin >> command)
		{
			if (command == "y")
			{
				Fight();
				break;
			}
			else if (command == "n")
			{
				cout << "Вы начали бежать и враг нанёс Вам удар в спину! Вы повержены!" << endl;
				GameOver();
			}
		}
	}
	else
	{
		int enemyAttack = rand() % enemy.m_AP;
		userHP -= enemyAttack;
		cout << "Враг нанёс Вам " << enemyAttack << endl;
		if (userHP <= 0)
		{
			cout << "Враг победил Вас! Попробуйте ещё!" << endl;
			GameOver();
		}
		attack = true;
		cout << "Ваше здоровье: " << userHP << endl;
		cout << "Отомстим!?(y/n): ";

		while (cin >> command)
		{
			if (command == "y")
			{
				Fight();
				break;
			}
			else if (command == "n")
			{
				cout << "Трус! В попытках сбежать враг застал Вас и ранил прямо в спину!" << endl;
				GameOver();
			}
		}
	}

}

void Win()
{
	cout << "Поздравляем! Железный трон Ваш!" << endl;
	exit(0);
}

void GameOver()
{
	cout << "GAME OVER" << endl;
	exit(0);
}

bool IsPassed(Enemy enemy)
{
	for each (Enemy e in enemiesPassed)
	{
		if (e.m_name == enemy.m_name)
			return true;
	}
	return false;
}

void Stats()
{
	cout << endl << "Ваша статистика:" << endl;
	cout << " # Количество здоровья: " << user.m_HP << endl;
	cout << " # Урон: " << user.m_AP << endl;
	cout << " # Уровень: " << user.GetLevel() << endl;
}

void Help()
{
	ReadFromFile("help.txt");
}

void ReadFromFile(string path)
{
	string text;
	ifstream file;
	file.open(path);
	while (getline(file, text))
		cout << endl << text;
	file.close();
}

