#include <iostream>
using namespace std;

int main()
{
	int n;


	do
	{
		cout << "Enter number of marks (1-10): ";
		cin >> n;

		if (n < 1 || n > 10)
		{
			cout << "Invalid input. Enter n between 1 and 10.\n";
		}

	} while (n < 1 || n > 10);



	int* marks = new int[n];


	cout << "Enter " << n << " marks:\n";

	for (int i = 0; i < n; i++)
	{
		cin >> *(marks + i);
	}



	int* newMarks = new int[n + 1];



	for (int i = 0; i < n; i++)
	{
		*(newMarks + i) = *(marks + i);
	}



	cout << "Enter new student's mark: ";
	cin >> *(newMarks + n);


	delete[] marks;



	marks = newMarks;



	n = n + 1;



	cout << "\nAll marks:\n";

	for (int i = 0; i < n; i++)
	{
		cout << *(marks + i) << " ";
	}

	cout << endl;


	delete[] marks;
	marks = nullptr;


	return 0;
}
