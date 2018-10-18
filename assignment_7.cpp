//#include "stdafx.h"
//#include "Tower.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Tower
{
private:
	string name;
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

	string getName()
	{
		return this->name;
	}

	//void setVectorSize(int size)
	//{
	//	contents.resize(size);
	//}

	void pushDisk(string val)
	{
		this->contents.push_back(val);
	}

	string popDisk()
	{
		string s = this->contents.back();
		this->contents.pop_back();
		return s;
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

	void clearContents()
	{
		contents.clear();
	}

};

void towersOfHanoi(int, Tower*, Tower*, Tower*);
string orderedTowers(Tower*, Tower*, Tower*);

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
		cout << "\t\t\t\tWelcome to the Towers of Hanoi auto-solving program\n\n"
			<< "Warning: If you enter more than 10 disks, this program may take a while to complete.\n"
			<< "How many disks would you like to use (positive integers only): ";
		cin >> diskNum;
		while (diskNum < 1)
		{
			cout << "\nThe number of disks must be a positive integer.\n"
				<< "How many disks would you like to use (positive integers only): ";
			cin >> diskNum;
		}

		cout << endl << pow(2, diskNum) - 1 << " move(s) is/are needed to solve for " << diskNum << " disk(s).\n\n";

		//tower1->setVectorSize(diskNum);
		//tower2->setVectorSize(diskNum);
		//tower3->setVectorSize(diskNum);

		for (int i = diskNum; i > 0; i--)
		{
			string c = to_string(i);
			tower1->pushDisk(c);
		}

		cout << orderedTowers(tower1, tower2, tower3) << endl;

		system("pause");

		towersOfHanoi(diskNum, tower1, tower2, tower3);

		cout << "\nWould you like to run again (Y/N): ";
		cin >> ans;

		if (toupper(ans) == 'Y')
		{
			run = true;
			system("cls");

			tower1->clearContents();
			tower2->clearContents();
			tower3->clearContents();
		}

		else if (toupper(ans) == 'N')
		{
			run = false;
		}

	} while (run == true);

	return 0;
}

void towersOfHanoi(int disks, Tower* t1, Tower* t2, Tower* t3)
{
	if (disks > 0)
	{
		towersOfHanoi(disks - 1, t1, t3, t2);

		cout << "\nMove Disk " << disks << " from Tower " << t1->getName() << " to Tower " << t3->getName() << endl;

		string poppedDisk = t1->popDisk();

		cout << "Current Disk: " << disks << endl << endl;

		t3->pushDisk(poppedDisk);

		cout << orderedTowers(t1, t2, t3) << endl;

		system("pause");

		towersOfHanoi(disks - 1, t2, t1, t3);
	}
}

string orderedTowers(Tower* t1, Tower* t2, Tower* t3)
{
	string output;

	if (t1->getName() == "1")
		output += t1->printTower() + "\n";

	else if(t2->getName() == "1")
		output += t2->printTower() + "\n";

	else if (t3->getName() == "1")
		output += t3->printTower() + "\n";



	if (t1->getName() == "2")
		output += t1->printTower() + "\n";

	else if (t2->getName() == "2")
		output += t2->printTower() + "\n";

	else if (t3->getName() == "2")
		output += t3->printTower() + "\n";



	if (t1->getName() == "3")
		output += t1->printTower() + "\n";

	else if (t2->getName() == "3")
		output += t2->printTower() + "\n";

	else if (t3->getName() == "3")
		output += t3->printTower() + "\n";

	
	return output;
}
