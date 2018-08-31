#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string connectors = "!Vv^";
	string ifThen = "->";
	string statements = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string input;

	bool lastWasAlpha = false;
	bool lastWasNot = false;
	bool lastWasConnector = false;
	bool isValidWFF = true;
	bool firstRun = true;

	cout << "Please enter a logic statement:\n";
	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		//cout << c;

		if (c == ' ')
		{
			continue;
		}

		else if (c == '!' || c == 'V' || c == 'v' || c == '^')
		{
			if (c != '!')
			{
				if (!lastWasAlpha)
				{
					cout << "An invalid character has been entered before a connector. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				else if (lastWasConnector)

				lastWasConnector = true;
				lastWasAlpha = false;
				lastWasNot = false;
				continue;
			}

			else if (c == '!')
			{
				if (lastWasAlpha)
				{
					cout << "An invalid statement has been entered before a '!'. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				else if (!lastWasConnector && firstRun == false)
				{
					cout << "An invalid connector has been entered before a '!'. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				lastWasNot = true;
				lastWasAlpha = false;
				lastWasConnector = false;
				continue;
			}
		}

		else if (isalpha(c))
		{
			if (lastWasAlpha)
			{
				cout << "An invalid statement has been entered before a statement. String is not a WFF.\n";
				isValidWFF = false;
				break;
			}

			lastWasAlpha = true;
			lastWasConnector = false;
			lastWasNot = false;
			continue;
		}

		else
		{
			cout << "An invalid character has been entered. String is not a WFF.\n";
			break;
		}

		

		firstRun = false;
	}

	cout << (isValidWFF ? "This is a valid WFF." : "This is NOT a valid WFF.") << endl;

    return 0;
}

