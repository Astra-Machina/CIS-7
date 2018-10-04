#include <iostream>
#include <ctime>

using namespace std;

int euclideanMethod (int, int);

int main()
{
	long long a, b;
	long long gcd;
	double time;
	char rerun;
	clock_t start;

	bool finish = false;

	while (!finish)
	{
		start = clock();

		system("cls");

		cout << "Please enter 2 positive integers.\n"
			<< "Enter Integer 1: ";
		cin >> a;
		cout << "Enter Integer 2: ";
		cin >> b;

		while (a < 0 || b < 0)
		{
			system("cls");

			cout << "One or both of the numbers you have entered was not positive.\n"
				<< "\nPlease enter 2 positive integers.\n"
				<< "Enter Integer 1: ";
			cin >> a;
			cout << "Enter Integer 2: ";
			cin >> b;
		}

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

		cout << "The GCD of " << a << " and " << b << " is " << gcd << endl;

		time = (clock() - start) / (double)CLOCKS_PER_SEC;

		cout << "The total duration of the calculation is: " << time << " nanoseconds.\n";

		cout << "\nRun program again? y/n: ";
		cin >> rerun;

		while (tolower(rerun) != 'y' && tolower(rerun) != 'n')
		{
			system("cls");

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

int euclideanMethod (int num1, int num2)
{
	if (num1 == 0)
	{
		return num2;
	}

	return euclideanMethod(num2 % num1, num1);
}
