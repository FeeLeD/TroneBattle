#include "Hero.h"
#include "string"
#include "stdlib.h"
#include "ctime"
using std::string;
#pragma once
enum Skills { ATTACK, HEALTH };
const int MAX = 5;
class Enemy: public Hero
{
private:
	string names[MAX]{ "Петир Бейлиш(Мезинец)", "Король ночи", "Рамси Болтон", "Джоффри Баратеон", "Серсея Ланнистен" };
	
	void GetName()
	{
		srand(int(time(0)));
		int randomPosition = rand() % 5;
		m_name = names[randomPosition];
	}

	void SetSkill()
	{
		srand(int(time(0)));
		int rnd = rand() % 2;

		if (rnd == 0)
			skill = Skills::ATTACK;
		else
			skill = Skills::HEALTH;
	}

	void SetFeatures()
	{
		srand(int(time(0)));
		int rndHP = rand() % 50 + 101;
		int rndAP = rand() % 20 + 31;
		if (skill == Skills::ATTACK)
		{
			sName = "Атака + 10%";
			m_HP = rndHP;
			m_AP = rndAP * 1.1;

		}
		else
		{
			sName = "Здоровье + 10%";
			m_HP = rndHP * 1.1;
			m_AP = rndAP;
		}
	}

public:
	Skills skill;
	string sName;
	Enemy();

	void ShowFeatures()
	{
		
		cout << " # Здоровье: " << m_HP << endl;
		cout << " # Урон: " << m_AP << endl;
		cout << " # Особый навык: " << sName << endl;
	}
};

