#include <iostream>
using namespace std;

int main()
{
	int rows, cols;


	do
	{
		cout << "Enter number of students: ";
		cin >> rows;

		if (rows <= 0)
		{
			cout << "Number of students must be greater than 0.\n";
		}

	} while (rows <= 0);



	do
	{
		cout << "Enter number of subjects: ";
		cin >> cols;

		if (cols <= 0)
		{
			cout << "Number of subjects must be greater than 0.\n";
		}

	} while (cols <= 0);



	int** marks = new int* [rows];



	for (int r = 0; r < rows; r++)
	{
		*(marks + r) = new int[cols];
	}



	cout << "\nEnter marks (0 to 100):\n";

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			do
			{
				cout << "Student " << r + 1
					<< ", Subject " << c + 1 << ": ";

				cin >> *(*(marks + r) + c);

				if (*(*(marks + r) + c) < 0 ||
					*(*(marks + r) + c) > 100)
				{
					cout << "Invalid marks! Enter a value "
						<< "between 0 and 100.\n";
				}

			} while (*(*(marks + r) + c) < 0 ||
				*(*(marks + r) + c) > 100);
		}
	}



	cout << "\nMarks Matrix:\n";

	for (int r = 0; r < rows; r++)
	{
		cout << "Student " << r + 1 << ": ";

		for (int c = 0; c < cols; c++)
		{
			cout << *(*(marks + r) + c) << "\t";
		}

		cout << endl;
	}



	int bestTotal = 0;

	for (int c = 0; c < cols; c++)
	{
		bestTotal += *(*(marks + 0) + c);
	}

	int bestStudent = 1;



	for (int r = 1; r < rows; r++)
	{
		int total = 0;

		for (int c = 0; c < cols; c++)
		{
			total += *(*(marks + r) + c);
		}


		if (total > bestTotal)
		{
			bestTotal = total;
			bestStudent = r + 1;
		}
	}



	cout << "\nStudent with highest total: "
		<< bestStudent << endl;

	cout << "Highest total: "
		<< bestTotal << endl;



	for (int r = 0; r < rows; r++)
	{
		delete[] * (marks + r);
	}



	delete[] marks;



	marks = nullptr;


	return 0;
}
