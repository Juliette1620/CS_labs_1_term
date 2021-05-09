# define _CRT_SECURE_NO_WARNING
# pragma warning(disable: 4996)
# include<iostream>
# include<string>
#include <sstream>
# include<cstring>
#include <cstdlib>
using namespace std;

void strInput(string&);
void replacingSpacesWithPluses(string&);
void replacementOfOtherCharacters(string&, int&, int&, string&);
void finalStringOutput(string&, stringstream&);
string addingLeadingZeros(char);

int main() {
	setlocale(LC_ALL,".1251");
	int firstPosition = 0, secondPosition = 0;
	string str, strAlphabet = " AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	stringstream finalStr;
	strInput(str);
	replacementOfOtherCharacters(str, firstPosition, secondPosition, strAlphabet);
	replacingSpacesWithPluses(str);
	str.erase(str.size() - 1);
	finalStringOutput(str, finalStr);
	cout << str << endl;
	system("pause");
	return 0;
}

void strInput(string &str) {
	cout << "Введите строку" << endl;
	cout << "Исходная строка: ";
	getline(cin, str);
	while ((str.size()) == 0) {
		cout << "Пустая строка!\nВведите строку снова\n";
		getline(cin, str);
	}
	str = str + " ";
}

void replacingSpacesWithPluses(string &str) {
	for (int i = 0; i < str.size(); i++)
		if (str[i] == ' ')
			str[i] = '+';
}

void replacementOfOtherCharacters(string &str, int &firstPosition, int &secondPosition, string &strAlphabet) {
	while ((firstPosition = str.find_first_not_of(strAlphabet, firstPosition)) != -1) {
		secondPosition = str.find_first_of(strAlphabet, firstPosition);
		while (firstPosition < secondPosition) {
			str.replace(firstPosition, 1, addingLeadingZeros(str[firstPosition]));
			firstPosition += 3;
			secondPosition += 2;
		}
	}
}

string addingLeadingZeros(char characterForReplacement) {
	int codeOfCharacter = (int)characterForReplacement;
	string newSubstring = to_string(codeOfCharacter);
	while (newSubstring.size() < 3)
		newSubstring.insert(0, "0");
	return newSubstring;
}

void finalStringOutput(string &str, stringstream &finalStr) {
	finalStr << str;
	cout << "Новая строка: ";
	cout << finalStr.str();
	cout << endl;
}

