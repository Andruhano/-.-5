#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	fstream wr;
	wr.open("Test.txt", ios::in | ios::out | ios::app);
	string name;
	int age;
	cout << "Enter name -> ";
	cin >> name;
	cout << "Age -> ";
	cin >> age;
	wr << "Name: " << name << " | ";
	wr << "Age: " << age << endl;

	char buff[30];
	wr.seekg(0, ios::beg);
	while (!wr.eof())
	{
		wr.getline(buff, 30);
		cout << buff << endl;

		//wr >> buff;
		//cout << buff << endl;
	}

	wr.close();
}