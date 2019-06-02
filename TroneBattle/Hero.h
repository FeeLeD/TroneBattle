#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#pragma once
const int HEROES_NUMBER = 3;
class Hero
{
private:
	int level;

	string names[HEROES_NUMBER]{ "Джон Сноу", "Дайнерис", "Тирион Ланистер" };
	int HPs[HEROES_NUMBER]{ 120, 90, 200 };
	int APs[HEROES_NUMBER]{ 50, 80, 30 };

	void ShowFeatures()
	{
		for(int i = 0; i < 3; i++)
		{
			cout << "Герой " << names[i] << ":" << endl;
			cout << " # Здоровье: " << HPs[i] << " HP" << endl;
			cout << " # Атака: " << APs[i] << " AP" << endl;
			cout << "===============" << endl;
		}
	}

	void SetHero(int command)
	{
		int position = command - 1;
		m_name = names[position];
		m_HP = HPs[position];
		m_AP = APs[position];
		
	}

public:
	string m_name;
	int m_HP; // health points
	int m_AP; // attack points 

	Hero();
	int GetLevel() { return level; }
	void LevelUp() { level++; m_HP *= 1.1; m_AP *= 1.1; }

	void ChooseHero()
	{
		int command;
		ShowFeatures();
		cout << "Введите число: ";

		while (cin >> command)
		{
			switch (command)
			{
			case 1:
				SetHero(1);
				break;
			case 2:
				SetHero(2);
				break;
			case 3:
				SetHero(3);
				break;
			default:
				cout << "Пожалуйста, введите корректное число: ";
			}

			if (command == 1 ||
				command == 2 ||
				command == 3)
				break;
		}
	}
};

