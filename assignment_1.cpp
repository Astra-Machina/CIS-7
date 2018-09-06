#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*string connectors = "!Vv^";
	string startIfThen = "-";
	string endIfThen = ">";
	string parentheses = "()";
	string statements = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";*/
	string input;

	char c;
	char run;

	bool statementUsed = false;
	bool lastWasAlpha = false;
	bool lastWasNot = false;
	bool lastWasConnector = false;
	bool lastWasIf = false;
	bool lastWasThen = false;
	//bool parenthesisStartUsed = false;
	//bool parenthesisEndUsed = false;
	bool isValidWFF = true;
	bool firstRun = true;
	bool keepRunning = true;

	do
	{
		statementUsed = false;
		lastWasAlpha = false;
		lastWasNot = false;
		lastWasConnector = false;
		lastWasIf = false;
		lastWasThen = false;
		//parenthesisStartUsed = false;
		//parenthesisEndUsed = false;
		isValidWFF = true;
		firstRun = true;

		cout << "Please enter a logic statement:\n";
		getline(cin, input);

		for (unsigned int i = 0; i < input.length(); i++)
		{
			c = input[i];

			if (c == ' ')
			{
				continue;
			}

			else if (c == '!' || c == 'V' || c == 'v' || c == '^')
			{
				if (input[i] != '!' && firstRun)
				{
					cout << "An invalid connector has been entered first. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				else if (c != '!')
				{
					if (lastWasIf || lastWasThen)
					{
						cout << "An invalid connector has been entered after a '->'. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					else if (!lastWasAlpha)
					{
						cout << "An invalid connector has been entered after a character. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					/*else if (input[i - 1] == 'V' || input[i - 1] == 'v' || input[i - 1] == '^')
					{
						cout << "An invalid connector was entered after a connector. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					else if (input[i - 1] == '!')
					{
						cout << "An invalid connector has been entered after a '!'. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}*/

					lastWasConnector = true;
					lastWasAlpha = false;
					lastWasNot = false;
					firstRun = false;
					//parenthesisEndUsed = false;
					continue;
				}

				else if (c == '!')
				{
					if (lastWasAlpha)
					{
						cout << "An invalid '!' has been entered after a statement. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					else if (lastWasIf)
					{
						cout << "An invalid '!' has been entered after a '-'. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					/*else if (input[i - 1 == ')'])
					{
						cout << "An invalid '!' has been entered after a ')'. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}*/

					else if (lastWasNot)
					{
						cout << "An invalid '!' has been entered after a '!'. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					//else if (input[i - 1] == 'V' || input[i - 1] == 'v' || input[i - 1] == '^' && !firstRun)
					//{
					//	cout << "An invalid '!' has been entered after a connector. String is not a WFF.\n";
					//	isValidWFF = false;
					//	break;
					//}

					lastWasNot = true;
					lastWasAlpha = false;
					lastWasConnector = false;
					lastWasThen = false;
					//parenthesisEndUsed = false;
					firstRun = false;
					continue;
				}
			}

			else if (c == '-' || c == '>')
			{
				if (!lastWasAlpha)
				{
					cout << "An invalid '->' has been entered after a character. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				else if (c == '-')
				{
					lastWasIf = true;
					continue;
				}

				else if (c == '>')
				{
					if (!lastWasIf)
					{
						cout << "An invalid '>' has been entered. A '-' must precede this character to form a WFF. "
							<< "String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					lastWasThen = true;
					lastWasConnector = true;
					lastWasIf = false;
					lastWasAlpha = false;
					firstRun = false;
					//parenthesisEndUsed = false;
					continue;
				}


			}

			else if (isalpha(c))
			{
				if (lastWasAlpha)
				{
					cout << "An invalid statement has been entered after a statement. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				/*else if (parenthesisEndUsed)
				{
					cout << "An invalid statement has been entered after a ')'. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}*/

				statementUsed = true;
				lastWasAlpha = true;
				lastWasConnector = false;
				lastWasNot = false;
				lastWasThen = false;
				firstRun = false;
				continue;
			}

			/*else if (c == '(' || c == ')')
			{
				if (c == '(')
				{
					if (parenthesisStartUsed)
					{
						cout << "An invalid '(' has been entered after a '('. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					else if (lastWasAlpha)
					{
						cout << "An invalid '(' has been entered after a statement. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					else if (parenthesisEndUsed)
					{
						cout << "An invalid '(' has been entered after a ')'. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					parenthesisStartUsed = true;
					parenthesisEndUsed = false;
					lastWasAlpha = false;
					lastWasConnector = false;
					lastWasIf = false;
					lastWasThen = false;
					lastWasNot = false;
					continue;
				}

				else if (c == ')')
				{
					if (parenthesisEndUsed)
					{
						cout << "An invalid ')' has been entered after a ')'. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					else if (lastWasConnector || lastWasNot)
					{
						cout << "An invalid ')' has been entered after a connector. String is not a WFF.\n";
						isValidWFF = false;
						break;
					}

					parenthesisEndUsed = true;
					parenthesisStartUsed = false;
					lastWasAlpha = false;
					lastWasConnector = false;
					lastWasIf = false;
					lastWasThen = false;
					lastWasNot = false;
					continue;
				}
			}*/

			else
			{
				cout << "An invalid character has been entered. String is not a WFF.\n";
				break;
			}

			firstRun = false;
		}

		if (!statementUsed || lastWasConnector || lastWasIf || lastWasThen || lastWasNot)
		{
			cout << "The input must end with a 'statement' else it is not a valid WFF.\n";
			isValidWFF = false;
		}

		cout << (isValidWFF ? "This is a valid WFF." : "This is NOT a valid WFF.") << endl;

		cout << "Would you like to go again? (y/n): ";
		cin.get(run);
		cin.ignore();

		if (run == 'y')
		{
			keepRunning = true;
			system("cls");
		}

		else
		{
			keepRunning = false;
		}

	} while (keepRunning);

	return 0;
}

