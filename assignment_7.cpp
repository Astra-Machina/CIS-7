// Assignment_7.cpp : Defines the entry point for the console application.
//

/*Write a program that prints out step-by-step instructions for completing the Tower of Hanoi.
Requirements:
- [ ] Asks the user for 1 integer indicating the number of disks to use.
Then have the program solve the Tower of Hanoi problem recursively.
- [ ] Have the program print out each move (for example: "Move disk from tower A to tower C")
- [ ] Next have the program print out a visual representation of each tower in between moves.
For instance, after the first move, the console could show: Tower A: -,2,3 Tower B: -,-,- Tower C: -,-,1 Move disk 1 to Tower C
- [ ] After each move, wait for user input and clear the screen
- [ ] Upload your assignment to GitHub
- [ ] Email james.wilson@rccd.edu with the url to the source code on GitHub
- 2^(n) - 1 [minimum number of moves required of "n" amount of disks.]
*/

#include "stdafx.h"
//#include "Tower.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tower
{
private:
	string name;
	int size;
	vector<string> contents;

public:
	Tower(string n)
	{
		this->name = n;
	}

	void setName(string n)
	{
		this->name = n;
	}

	void setSize(int s)
	{
		this->size = s;
	}

	string getName()
	{
		return this->name;
	}

	const int getSize()
	{
		return this->size;
	}

	void setVectorSize(int size)
	{
		contents.resize(size);
	}

	void pushDisk(string val)
	{
		this->contents.push_back(val);
	}

	void popDisk()
	{
		this->contents.pop_back();
	}

	string printTower()
	{
		string output = "Tower " + this->name + ": ";

		for (string disk : contents)
		{
			output += disk + " ";
		}

		return output;
	}

};

void towersOfHanoi(int, Tower*, Tower*, Tower*);

int main()
{
	int diskNum;
	char ans;
	bool run = true;

	auto tower1 = new Tower("1");
	auto tower2 = new Tower("2");
	auto tower3 = new Tower("3");

	do
	{
		cout << "How many disks would you like to use (positive integers only): ";
		cin >> diskNum;
		while (diskNum < 1)
		{
			cout << "\nThe number of disks must be a positive integer.\n"
				<< "How many disks would you like to use (positive integers only): ";
			cin >> diskNum;
		}

		tower1->setSize(diskNum);
		tower2->setSize(diskNum);
		tower3->setSize(diskNum);

		for (int i = diskNum; i > 0; i--) 
		{
			string c = to_string(i);
			tower1->pushDisk(c);
		}

		cout << tower1->printTower() << endl
			<< tower2->printTower() << endl
			<< tower3->printTower() << endl;

		system("pause");

		towersOfHanoi(diskNum, tower1, tower3, tower2);

		cout << "\nWould you like to run again (Y/N): ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			run = true;
			system("cls");
		}

		else if (toupper(ans) == 'N')
		{
			run = false;
		}

	} while (run == true);

	return 0;
}

void towersOfHanoi(int disks, Tower* t1, Tower* t3, Tower* t2)
{
	if (disks > 0)
	{
		towersOfHanoi(disks - 1, t1, t2, t3);


		cout << "Move disk " << disks << " from tower " << t1->getName() << " to tower " << t2->getName() << endl;

		t1->popDisk();
		t2->pushDisk(to_string(disks));

		cout << t1->printTower() << endl
			<< t2->printTower() << endl
			<< t3->printTower() << endl;

		system("pause");

		towersOfHanoi(disks - 1, t2, t3, t1);
	}
}
