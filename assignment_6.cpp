#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int euclideanMethod (long long, long long);

int main()
{
	long long a = 0, b = 0;
	long long gcd = 0;
	long double time = 0;
	char rerun;

	high_resolution_clock::time_point start;
	high_resolution_clock::time_point stop;

	bool finish = false;

	while (!finish)
	{
		system("cls");

		cout << "Please enter 2 positive integers.\n"
			<< "Enter Integer 1: ";
		cin >> a;

		while (!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nYou must enter an integer.\n"
				<< "Enter Integer 1: ";
			cin >> a;
		}

		while (a < 0)
		{
			cout << "The first number you entered was not positive.\n"
				<< "\nPlease enter a positive integer.\n"
				<< "Enter Integer 1: ";
			cin >> a;

			while (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "\nYou must enter an integer.\n"
					<< "Enter Integer 1: ";
				cin >> a;
			}
		}

		cout << "Enter Integer 2: ";
		cin >> b;

		while (!cin)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nYou must enter an integer.\n"
				<< "Enter Integer 2: ";
			cin >> b;
		}

		while (b < 0)
		{
			cout << "The second number you entered was not positive.\n"
				<< "\nPlease enter a positive integer.\n"
				<< "Enter Integer 2: ";
			cin >> b;

			while (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				cout << "\nYou must enter an integer.\n"
					<< "Enter Integer 2: ";
				cin >> b;
			}
		}

		start = high_resolution_clock::now();
		
		if (a > b)
		{
			gcd = euclideanMethod(a, b);
		}

		else if (b > a)
		{
			gcd = euclideanMethod(b, a);
		}

		else if (a == b)
		{
			gcd = euclideanMethod(a, b);
		}

		stop = high_resolution_clock::now();

		cout << "\nThe GCD of " << a << " and " << b << " is " << gcd << endl;
		
		time = duration_cast<nanoseconds>(stop - start).count();

		cout << "\nThe total duration of the calculation is: " << time << " nanoseconds.\n";

		cout << "\nRun program again? y/n: ";
		cin >> rerun;

		while (tolower(rerun) != 'y' && tolower(rerun) != 'n')
		{
			cout << "Please enter only \"y\" for yes or \"n\" for no.\n"
				<< "\nRun program again? : ";
			cin >> rerun;
		}

		if (tolower(rerun) == 'y')
		{
			finish = false;
		}

		else if (tolower(rerun) == 'n')
		{
			finish = true;
		}
	}
    return 0;
}

int euclideanMethod (long long num1, long long num2)
{
	if (num1 == 0)
	{
		return num2;
	}

	return euclideanMethod(num2 % num1, num1);
}
