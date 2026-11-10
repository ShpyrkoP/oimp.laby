#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string a, b;
	cout << "Enter the name of the file you want to open: ";
	cin >> a;
	fstream ofile;
ofile.open(a, ios::out);

//задаём значения во входной файл
ofile << "hello" << '\n';
ofile  << 123463 << '\n';
ofile << 275293 << '\n';
ofile << "Hello, world!" << '\n';
ofile << 94357 << '\n';
ofile  << 8876<< '\n';
ofile << 543 << '\n';
ofile.close();

/*ofile << '\n';*/

	
//задаём выходной файл с отсортированными данными
cout << "Enter the name of the file where you want to get results: ";
	cin >> b;
	if (b == a){
		cout << "Invalid name! You have already chosen this file";
	}
	else {
	ofstream o2file;
o2file.open(b);
ofile.open(a, ios::in);
string stroka_now, stroka_group; 
int str{1}, groupn{0}, povt{};      //str для номера текущей строки, group для строки начала группы
while (getline(ofile, stroka_now)) {
	bool number = true;       //если символ == число, 1; иначе 0
	if (stroka_now.empty()) {
        number = false;
    } else {
		for (int i = 0; i < stroka_now.length() ; i++) {
			if (stroka_now[i] < '0' || stroka_now[i] >'9'){			//по асции коду смотрим символы, подсказка от иишки
				number = false;
				break;
			} 
		} 
	} if (number == true)
		{
			if(povt == 0){
				groupn = str;
				povt +=1;
			} else if (povt > 0) {
				povt+=1;
			}
		}	else {
			if (povt>1){
				o2file << "Where the group starts: string " << groupn << '\t' << "The number of repeats: " << povt << '\t' << endl;
			} povt = 0;
		} if (stroka_now.empty()) {
                    o2file << '\n';
		}
		str++;
	} if (povt>1) { 
		o2file << "Where the group starts: string " << groupn << '\t' << "The number of repeats: " << povt << '\t' << endl;
	}
	ofile.close();
	o2file.close();
}
return 0;
}