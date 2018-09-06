#include <iostream>
#include <string>

using namespace std;

int main()
{
	string connectors = "!Vv^";
	string startIfThen = "-";
	string endIfThen = ">";
	string parentheses = "()";
	string statements = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string input;

	bool statementUsed = false;
	bool lastWasAlpha = false;
	bool lastWasNot = false;
	bool lastWasConnector = false;
	bool lastWasIf = false;
	bool lastWasThen = false;
	bool parenthesisStartUsed = false;
	bool parenthesisEndUsed = false;
	bool isValidWFF = true;
	bool firstRun = true;

	cout << "Please enter a logic statement:\n";
	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i];

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
					cout << "An invalid connector has been entered after a character. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				else if (lastWasIf)
				{
					cout << "An invalid connector has been entered after a '-'. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				else if (lastWasConnector)
				{
					cout << "An invalid connector was entered after a connector. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				lastWasConnector = true;
				lastWasAlpha = false;
				lastWasNot = false;
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

				else if (parenthesisEndUsed)
				{
					cout << "An invalid '!' has been entered after a ')'. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				else if (!lastWasConnector && !firstRun)
				{
					cout << "An invalid '!' has been entered after a connector. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				lastWasNot = true;
				lastWasAlpha = false;
				lastWasConnector = false;
				lastWasThen = false;
				continue;
			}
		}

		else if (c == '-' || c == '>')
		{
			if (!lastWasAlpha)
			{
				cout << "An invalid '->' has been entered after a connector. String is not a WFF.\n";
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
					cout << "An invalid '>' has been entered after a connector. Only acceptable character before '>' is '-'." 
						<< "\nString is not a WFF.\n";
					isValidWFF = false;
					break;
				}

				lastWasThen = true;
				lastWasConnector = true;
				lastWasIf = false;
				lastWasAlpha = false;	
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

			else if (parenthesisEndUsed)
			{
				cout << "An invalid statement has been entered after a ')'. String is not a WFF.\n";
				isValidWFF = false;
				break;
			}

			statementUsed = true;
			lastWasAlpha = true;
			lastWasConnector = false;
			lastWasNot = false;
			lastWasThen = false;
			continue;
		}

		else if (c == '(' || c == ')')
		{
			if (c == '(')
			{
				if (parenthesisStartUsed)
				{
					cout << "An invalid '(' has been entered after a '('. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}
				parenthesisStartUsed = true;
				parenthesisEndUsed = false;
			}

			else if (c == ')')
			{
				if (parenthesisEndUsed)
				{
					cout << "An invalid ')' has been entered after a ')'. String is not a WFF.\n";
					isValidWFF = false;
					break;
				}
				parenthesisEndUsed = true;
				parenthesisStartUsed = false;
			}
		}

		else
		{
			cout << "An invalid character has been entered. String is not a WFF.\n";
			break;
		}

		firstRun = false;
	}

	if (!statementUsed || lastWasConnector || lastWasIf || lastWasThen || lastWasNot)
	{
		isValidWFF = false;
	}

	cout << (isValidWFF ? "This is a valid WFF." : "This is NOT a valid WFF.") << endl;

	return 0;
}
