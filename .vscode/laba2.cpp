//ЕЩЕ НЕ ДОДЕЛАНО
//ЕЩЕ НЕ ДОДЕЛАНО
//ЕЩЕ НЕ ДОДЕЛАНО



#include <iostream>
#include <random>
#include <string>
using namespace std;
int main() {
	cout << "Enter the number of array's elements n = ";
	int n;
	cin >> n;
	if (n < 1) {
		cout << "Check the entered data" << endl;
		return 0;
	}
	int* numbers = new int[n];
	cout << "Type 'num' to enter numbers or 'rand' to generate them with randomizer : ";
	string answer;
	cin >> answer;
	int i{};
	if (answer == "num")
	{
		cout << "Type " << n << " numbers:";
		while (i < n)
		{
			cin >> numbers[i];
			i++;
		}
		for (i = 0; i < n; ++i)
		{
			cout << numbers[i] << "\t";
		}
	}
	if (answer == "rand")
	{
		uniform_int_distribution<signed> u(-100, 100);    //рандомайзер
		default_random_engine e;
		while (i < n)
		{
			numbers[i]=u(e);
			i++;
		}
		for (i = 0; i < n; i++)
			cout << numbers[i] << "\t";
	}
	cout << " :    Not sorted array" << endl;

	// сортировка пузырьком
	i = 0;
	int j, temp;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n-1; i++)
		{
			if (numbers[i] < 0 && numbers[i+1] != 0 && numbers[i] < numbers[i + 1])
			{
				temp = numbers[i];
 				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
			}
			if (numbers[i] > 0 && numbers[i+1] !=0 && numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << numbers[i] << "\t";
	}
	cout << " :    Sorted array" << endl;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		if (numbers[i] > 0)
			k++;
	}
	cout << "The amount of positive numbers = " << k << '\n';
	delete[] numbers;

	return 0;

}