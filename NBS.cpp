#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;
int ins_error(int minimum_operation_number, int  maximum_operation_number, int instruction)
{
	while (instruction < minimum_operation_number || instruction > maximum_operation_number)
	{
		if (!cin) // or if(cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			// next, request user reinput
		}
		else
		{
			cout << "Invaild instruction, please try again..." << endl;
			cin >> instruction;
		}

	}
	return (instruction);
}
int nbs()
{
	int day;
	int start;
	//Game
	start = 0;
	day = 0;
	//Bunker

	int food;
	int water;
	int medkit;
	int resources;
	int cotb;

	//Player

	int hunger;
	int thirst;
	int hp;

	cout << "Nuclear Bunker Simulator" << endl;
	cout << "Version 2" << endl;
	cout << "Press Enter, to continue..." << endl;
	cin.get();
	system("cls");
	cout << "Game started..." << endl;
	//Set variables

	food = 10;
	water = 5;
	medkit = 2;
	resources = 5;
	cotb = 500;
	hunger = 3000;
	thirst = 150;
	hp = 100;
	int instruction;
	instruction = 6;
	string note;
	int ex;
	int sl;
	sl = 1;
	ex = 0;
	while (sl == 1)
	{
		if (hp <= 0 || cotb <= 0)
		{
			sl = 0;
		}
		else
		{
			system("cls");

			//Basic calculations
			if (hunger > 0)
				hunger = hunger - 100;
			if (thirst > 0)
				thirst = thirst - 50;
			if (hunger == 0)
			{
				hp -= 50;
				hunger = 0;
			}
			if (thirst <= 0)
			{
				hp -= 50;
				thirst = 0;
			}
			day = day + 1;
			int event;
			cotb = cotb - 20;
			if (instruction == 1)
			{

				ex = (rand() % 10) + 1;
				//Positive effects
				if (ex == 1)
				{
					note = "I have found abandoned car. I found a first aid kit in the trunk!";
					medkit = medkit + 1;
					water = water + 1;
				}
				else if (ex == 2)
				{
					note = "I have visited local shop, i found some food.";
					food = food + (rand() % 5) + 1;
					water = water + (rand() % 4) + 1;
				}
				else if (ex == 3)
				{
					note = "I met wild dogs, fortunately the noise scared them. I'm so tired That's Enough for today.";
					thirst = thirst - 10;
					hp = hp - 10;
					hunger = hunger - 20;
				}
				else if (ex == 4)
				{
					note = "I have visited local shop, i found some resources need to keep my shelter on.";
					resources = resources + (rand() % 3) + 1;
				}
				else if (ex == 5)
				{
					note = "I have found aboanded military resources! WoW! ";
					resources = resources + (rand() % 3) + 1;
					food = food + (rand() % 5) + 1;
					water = water + (rand() % 4) + 1;
					medkit = medkit + 1;
				}
				else if (ex == 6)
				{
					note = "I have found aboanded ambulance. ";
					resources = resources + (rand() % 3) + 1;
					food = food + (rand() % 2) + 1;
					water = water + (rand() % 3) + 1;
					medkit = medkit + 1;
					if (hp != 100 || 100 > hp)
					{
						int local_hp;
						local_hp = 100 - hp;
						hp = hp + local_hp;
					}

				}
				else if (ex == 7)
				{
					note = "I met wild dogs, unfortunately the noise didn't scared them. they attacked me!";
					thirst = thirst - 20;
					hp = hp - 50;
					hunger = hunger - 30;
				}
				else if (ex == 8)
				{
					note = "I met raiders! They attacked me!";
					thirst = thirst - 20;
					hp = hp - 60;
					hunger = hunger - 30;
				}
				else if (ex == 9)
				{
					note = "Building collapsed on me";
					thirst = thirst - 50;
					hp = hp - 80;
					hunger = hunger - 50;
				}
				else if (ex == 10)
				{
					note = "I tripped and hurt myself";
					thirst = thirst - 10;
					hp = hp - 10;
					hunger = hunger - 200;
				}
			}
			else if (instruction == 2)
			{
				int local_bunker;
				if (resources > 0)
				{
					if (cotb < 450)
					{
						int rr_event;
						rr_event = (rand() % 3) + 1;
						cotb = cotb + 100;
						resources = resources - 1;
						if (rr_event == 1)
							note = "Work, work, work!";
						else if (rr_event == 2)
							note = "My shelter look like new one!";
						else if (rr_event == 3)
						{
							note = "Home, sweet home!";
						}
					}
					else
						note = "Why should I repair my shelter? Everything is fine!";
				}
				else
					note = "I have no resources unneccesarty for repairs!";
			}
			else if (instruction == 3)
			{
				int local_hp;
				if (medkit > 0)
				{
					if (hp < 80)
					{
						int rr_event;
						rr_event = (rand() % 3) + 1;
						hp = hp + 40;
						medkit = medkit - 1;
						if (rr_event == 1)
							note = "I feel much better!";
						else if (rr_event == 2)
							note = "My wound doesn't look good, but I'm hopeful!";
						else if (rr_event == 3)
						{
							note = "It's hurts less";
						}
					}
					else
						note = "So much better!";
				}
				else
					note = "I have no medkits!";
			}
			else if (instruction == 4)
			{

				if (water > 0)
				{
					if (thirst < 80)
					{
						int rr_event;
						rr_event = (rand() % 3) + 1;
						thirst = thirst + 150;
						water = water - 1;
						if (rr_event == 1)
							note = "I feel much better!";
						else if (rr_event == 2)
							note = "It's better than a water from nearest river!";
						else if (rr_event == 3)
						{
							note = "Finaly watter!";
						}
					}
					else
						note = "I'm fine!";
				}
				else
					note = "I have no medkits!";
			}
			else if (instruction == 5)
			{
				int local_hunger;
				if (food > 0)
				{
					if (hunger < 2500)
					{
						int rr_event;
						rr_event = (rand() % 3) + 1;
						hunger = hunger + 500;
						food = food - 1;
						if (rr_event == 1)
							note = "I feel much better!";
						else if (rr_event == 2)
							note = "This food is only 10 yeras old! It's tasty!";
						else if (rr_event == 3)
						{
							note = "I like this ham!";
						}
					}
					else
						note = "I'm not hungry!";
				}
				else
					note = "I have no food!";
			}
			else if (instruction == 6)
			{
				int stay_e;
				stay_e = (rand() % 5) + 1;
				if (stay_e == 1)
				{
					note = "It was quiet here, but I'm save here.";
				}
				else if (stay_e == 2)
				{
					note = "Raiders attacked my shelter!";
					cotb = cotb - 200;
				}
				else if (stay_e == 3)
				{
					note = "I ready to go!";
				}
				else if (stay_e == 4)
				{
					note = "I have played chess - with myself...";
				}
				else if (stay_e == 5)
				{
					note = "I'm wondering, why world ended";
				}
			}
			else if (instruction == 7)
			{
				exit(0);
			}
			else if (instruction == 0)
			{
				// lol nothing!
			}
			system("Color 0A");
			cout << "     Personal termianl (r) 1989     " << endl;
			cout << "      ____________     " << endl;
			cout << "     /            |    " << endl;
			cout << "    /              |   " << endl;
			cout << "   /                |  " << endl;
			cout << "  /                  | " << endl;
			cout << " /                    |" << endl;
			cout << " ----------------------" << endl;
			cout << " " << endl;
			cout << "Day: " << day << endl;
			cout << " " << endl;
			cout << "Bunker status: " << endl;
			cout << "Bunker condition: " << cotb << endl;
			cout << " " << endl;
			cout << "Bunker resources: " << endl;
			cout << "Gear: " << resources << endl;
			cout << "Medkits: " << medkit << endl;
			cout << "Water: " << water << endl;
			cout << "Food: " << food << endl;
			cout << " " << endl;
			cout << "Player status: " << endl;
			cout << "Health: " << hp << endl;
			cout << "Hunger: " << hunger << endl;
			cout << "Thirst: " << thirst << endl;
			cout << "--------------------------------------------------------------------" << endl;
			if (day == 1)
			{
				note = "This is my first day!";

			}
			cout << "Note: " << note << endl;
			cout << "Instructions:" << endl;
			cout << "1 - Expedition" << endl;
			cout << "2 - Repair bunker" << endl;
			cout << "3 - Use med kit" << endl;
			cout << "4 - Drink water" << endl;
			cout << "5 - Eat food" << endl;
			cout << "6 - Stay in shelter" << endl;
			cout << "7 - Exit to Windows" << endl;
			cout << "____________________________________________________________________" << endl;
			cout << "Your action: ";
			cin >> instruction;
			ins_error(1, 7, instruction);

		}

	}
	cout << "Game Over!" << endl;
	if (hp <= 0)
		cout << "You died!" << endl;
	else if (cotb <= 0)
		cout << "Your bunker has been destroyed!" << endl;
	cout << "You have survived " << day << " days!" << endl;
	cout << "" << endl;
	cout << "Last known note: " << note << endl;
	cout << "Press Enter, to exit..." << endl;
	cin.ignore();
	cin.get();


}
void menu()
{
	int instruction;
	int instructions = 2;
	cout << "Welcome to Seba0456's console games collection.\n";
	cout << "All my games created here are made in C++ & and Visual Studio 2019.\n";
	cout << "All my games created in C++ are source-open.\n";
	cout << "Feel free to copy or modify games.\n";
	cout << "Select your game: \n";
	cout << "1.Nuclear Bunker Symulator\n";
	cout << instructions << ".Exit program\n";
	cin >> instruction;
	instruction = ins_error(1, 2, instruction);
	switch (instruction)
	{
	case 1:
	{
		system("cls");
		nbs();
	}
	case 2:
	{
		exit(0);
	}
	}
}


int main()
{
	menu();
}
