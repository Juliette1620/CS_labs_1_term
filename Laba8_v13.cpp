#pragma warning (disable:4996)
#include <iostream>
#include <cstdio>

using namespace std;

void start();
void fileInputcheck(FILE*);
void answers(char** strAnswer);
void stringChecking(char*, FILE*, char*, char*, int&, char**);
char* theBiggestSubstring(char*);
void preresult(int&, int&, int&, int&, int&, int&);
void rememberResult(int&, char*, char*, int&);
void fileOutput(int&, char**, FILE*);

int main() {
	setlocale(LC_ALL, ".1251");
	start();
	return 0;
}



void start() {
	FILE* file;
	FILE* out;
	file = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	fileInputcheck(file);
	char str[1000], big[1000] = "", check[1000];
	char** strAnswer = new char* [10];
	answers(strAnswer);
	int count = 0;
	stringChecking(str, file, check, big, count, strAnswer);
	fileOutput(count, strAnswer, out);
}

void fileInputcheck(FILE* file) {
	if (file == NULL) {
		cout << "Файл не может быть открыт" << endl;
		exit(1);
	}
	if (feof(file)) {
		cout << "Файл пустой" << endl;
		system("pause");
		exit(1);
	}
}

void answers(char** strAnswer) {
	for (int i = 0; i < 10; i++) {
		strAnswer[i] = new char[1000];
	}
}

void stringChecking(char* str, FILE* file, char* check, char* big, int &count, char** strAnswer) {
	while (fgets(str, 1000, file)) {
		strcpy(check, theBiggestSubstring(str));
		if (strlen(check) > strlen(big)) {
			strcpy(big, check);
			for (int i = 0; i <= count; i++)
				strcpy(strAnswer[i], "");
			count = 0;
		}
		if (!_stricmp(_strlwr(check), _strlwr(big))) {
			if (count < 10)
				strcpy(strAnswer[count++], str);
		}
	}
}

char* theBiggestSubstring(char* str) {
	int len = strlen(str), count = 1, maxcount = 1, first = -1, resfirst = -1, last = -1, reslast = -1;
	char* temp = new char[len + 1];
	strcpy(temp, str);
	_strlwr(temp);
	for (int i = 1; i < len; i++) {
		if (temp[i] == temp[i - 1]) {
			count++;
			if (first == -1)
				first = i - 1;
			last = i;
			if (i == len - 1) 
				preresult(maxcount, count, resfirst, first, reslast, last);
		}
		else{
			preresult(maxcount, count, resfirst, first, reslast, last);
			count = 1;
			first = -1;
		}
	}
	char res[80] = "";
	rememberResult(resfirst, res, str, reslast);
	return res;
}

void preresult(int &maxcount, int &count, int &resfirst, int &first, int &reslast, int &last) {
	if (count > maxcount) {
		maxcount = count;
		resfirst = first;
		reslast = last;
	}
}

void rememberResult(int& resfirst, char* res, char* str, int& reslast) {
	if (resfirst != -1)
		strncpy(res, str + resfirst, reslast - resfirst + 1);
}

void fileOutput(int &count, char** strAnswer, FILE* out) {
	for (int i = 0; i < count; i++) {
		fputs(strAnswer[i], out);
	}
}