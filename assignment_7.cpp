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
#include <iostream>
#include <string>

using namespace std;

void towersOfHanoi(int, string, string, string);

int main()
{
	int diskNum;
	char ans;
	bool run = true;

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

		towersOfHanoi(diskNum, "1", "3", "2");

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

void towersOfHanoi(int disks, string from, string to, string aux)
{
	if (disks == 1)
	{
		cout << "Move disk 1 from peg #" << from << " to peg #" << to << endl;
		return;
	}
	towersOfHanoi(disks - 1, from, aux, to);
	cout << "Move disk " << disks << " from peg #" << from << " to peg #" << to << endl;
	towersOfHanoi(disks - 1, aux, to, from);
}
