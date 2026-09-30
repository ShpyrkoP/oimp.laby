#include <iostream>
#include <random>
#include <string>
#include <ctime>
using namespace std;
int main() {
    cout << "Enter the number of array's elements n = ";
    int n;
    cin >> n;
    if (n < 1) {
        cout << endl << "Check the entered data" << endl;
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
    else if (answer == "rand")
    {
        uniform_int_distribution<int> u(-100, 100);    //рандомайзер
        default_random_engine e;
        e.seed(time(0));
        while (i < n)
        {
            numbers[i] = u(e);
            i++;
        }
        for (i = 0; i < n; i++)
            cout << numbers[i] << "\t";
    }
    else {
        cout << endl << "Check the entered data" << endl;
        return 0;
    }
    cout << " :    Not sorted array" << endl << endl;
    int k = 0;
    for (i = 0; i < n; i++)
    {
        if (numbers[i] > 0)
            k++;
    }
    cout << "The amount of positive numbers = " << k << endl << endl;
    int sum = 0, zero = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (numbers[i] == 0) {
            zero = i;
            break;
        }
    }
    if (zero != -1) {
        for (i = zero + 1; i < n; i++) {
            sum += numbers[i];
        }
        cout << "Sum = " << sum << endl << endl;
    }
    else {
        cout << "Sum = 0 (No zeros found)" << endl << endl;
    }
    // сортировка пузырьком
    i = 0;
    int j, temp, ii = i + 1;
	// сортировка отрицательных
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
		{
            if (numbers[i] >= 0) continue;
            int ii = i + 1;
            while (ii < n && numbers[ii] >= 0)
            {
                ii++;
            }
            if (ii >= n) {
                continue;
            }
            else if (numbers[i] < 0 && numbers[ii] < 0) {
                if (numbers[i] < numbers[ii]) {
                    temp = numbers[i];
                    numbers[i] = numbers[ii];
                    numbers[ii] = temp;
                }
            }
        }
    }
    // сортировка положительных
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (numbers[i] <= 0) continue;
            int ii = i + 1;
            while (ii < n && numbers[ii] <= 0)
            {
                ii++;
            }
            if (ii >= n) {
                continue;
            }
            else if (numbers[i] > 0 && numbers[ii] > 0) {
                if (numbers[i] > numbers[ii]) {
                    temp = numbers[i];
                    numbers[i] = numbers[ii];
                    numbers[ii] = temp;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << numbers[i] << "\t";
    }
    cout << " :    Sorted array" << endl << endl;
    delete[] numbers;

    return 0;

}