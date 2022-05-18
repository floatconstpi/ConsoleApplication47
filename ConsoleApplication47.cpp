#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
struct marks
{
	int StudentID;
	string Name;
	string Lettergrade;
	float quizzes[4];
	float midterm;
	float final;
	float lab;
	float lab_quiz;
	float lab_final;
	float final_grade;
};
void swap(float&a, float&b)
{
	float temp = 0;
	temp = a;
	a = b;
	b = temp;

}
void read(marks marklist[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Please write the " << i+1 << "  Student's ID \n";
		cin >> marklist[i].StudentID;
		cout << "Please write " << marklist[i].StudentID << "'s name \n";
		cin >> marklist[i].Name;
		cout << "Please write " << marklist[i].Name << "'s quiz grades: \n";
		for (int k = 0; k < 4; k++)
		{
			cin >> marklist[i].quizzes[k];
		}
		cout << "Please write " << marklist[i].Name << "'s midterm grades: \n";
		cin >> marklist[i].midterm;
		cout << "Please write " << marklist[i].Name << "'s final grades: \n";
		cin >> marklist[i].final;
		cout << "Please write " << marklist[i].Name << "'s lab grades: \n";
		cin >> marklist[i].lab;
		cout << "Please write " << marklist[i].Name << "'s lab quiz grades: \n";
		cin >> marklist[i].lab_quiz;
		cout << "Please write " << marklist[i].Name << "'s lab final grades: \n";
		cin >> marklist[i].lab_final;
	}
}
void read_file(marks marklist[], ifstream &fin, int n)
{
	int i = 0;
	while (!fin.eof() && i < n)
	{
		fin >> marklist[i].StudentID >> marklist[i].Name >> marklist[i].quizzes[0] >> marklist[i].quizzes[1] >> marklist[i].quizzes[2] >> marklist[i].quizzes[3] >> marklist[i].midterm >> marklist[i].final >> marklist[i].lab >> marklist[i].lab_quiz >> marklist[i].lab_final;
		i++;
	}
	fin.close();
}
void sort(marks marklist[], int n)
{
	
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < 3; j++)
		{
			for (int k = j + 1; j < 3; j++)
			{
				if (marklist[i].quizzes[j] > marklist[i].quizzes[k])
					swap(marklist[i].quizzes[j], marklist[i].quizzes[k]);
			}
		}
		cout << "Dropped: Lowest mark for " << marklist[i].StudentID << " is " << marklist[i].quizzes[3] << endl;
	}

}
void final_calc(marks marklist[], int n)
{
	for (int i = 0; i < n; i++)
	{
		marklist[i].final_grade = ((marklist[i].quizzes[0] + marklist[i].quizzes[1] + marklist[i].quizzes[2]) / 3) * 0.15;
		marklist[i].final_grade = marklist[i].final_grade + (marklist[i].midterm * 0.2) + (marklist[i].final * 0.3);
		marklist[i].final_grade = marklist[i].final_grade + (marklist[i].lab * 0.1) + (marklist[i].lab_final * 0.15) + (marklist[i].lab_quiz * 0.1);
	}
}
void LG_calc(marks marklist[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (marklist[i].final_grade >= 92.5)
		{
			marklist[i].Lettergrade = "A";
		}
		else if (marklist[i].final_grade < 92.5 && marklist[i].final_grade >= 89.5)
		{
			marklist[i].Lettergrade = "A-";
		}
		else if (marklist[i].final_grade < 89.5 && marklist[i].final_grade >= 86.5)
		{
			marklist[i].Lettergrade = "B+";
		}
		else if (marklist[i].final_grade < 86.5 && marklist[i].final_grade >= 82.5)
		{
			marklist[i].Lettergrade = "B";
		}
		else if (marklist[i].final_grade < 82.5 && marklist[i].final_grade >= 79.5)
		{
			marklist[i].Lettergrade = "B-";
		}
		else if (marklist[i].final_grade < 79.5 && marklist[i].final_grade >= 76.5)
		{
			marklist[i].Lettergrade = "C+";
		}
		else if (marklist[i].final_grade < 76.5 && marklist[i].final_grade >= 72.5)
		{
			marklist[i].Lettergrade = "C";
		}
		else if (marklist[i].final_grade < 72.5 && marklist[i].final_grade >= 69.5)
		{
			marklist[i].Lettergrade = "C-";
		}
		else if (marklist[i].final_grade < 69.5 && marklist[i].final_grade >= 59.5)
		{
			marklist[i].Lettergrade = "D";
		}
		else {
			marklist[i].Lettergrade = "F";
		}
	}
}
void print_file(marks list[], ofstream& fout, int n)
{
	fout << "StudentID" << setw(10) << "Name" << setw(10) << "Avg\t Lettergrade" << endl;
	for (int i = 0; i < n; i++)
	{
		fout << list[i].StudentID << setw(10) << list[i].Name << setw(10) << list[i].final_grade;
		fout << setw(10) << list[i].Lettergrade << endl;
	}
	fout.close();
}
void printout(marks list[], int n)
{
	cout << "StudentID" << setw(10) << "Name" << setw(10) << "Avg\t Lettergrade" << endl;
	for (int i = 0; i < n; i++)
	{
		cout  << list[i].StudentID << setw(10) << list[i].Name << setw(10) << list[i].final_grade;
		cout << setw(10) << list[i].Lettergrade << endl;
	}
}
	int main()
{
	cout << setprecision(3);
	int n;
	int in_choice;
	
	do
	{
		cout << "Choose way of input: " << endl << "1: Use a file named cppgrades.txt" << endl << "2: Input manually" << endl;
		cin >> in_choice;
	} while (in_choice != 1 && in_choice != 2);
		if (in_choice == 2)
		{
			cout << "Please enter number of students \n";
			cin >> n;
			marks* list = new marks[n];
			read(list, n);
			sort(list, n);
			final_calc(list, n);
			LG_calc(list, n);
			int out_choice = 0;
			do
			{
				cout << "Choose way of output: " << endl << "1: Use a file named cppgrades_out.txt" << endl << "2: Output manually" << endl;
				cin >> out_choice;
			} while (out_choice != 1 && out_choice != 2);
			if (out_choice == 2)
			{
				printout(list, n);
			}
			else
			{
				ofstream fileout;
				fileout.open("cppgrades_out.txt");
				print_file(list, fileout, n);
			}
			delete[] list;
		}
		else
		{
			ifstream filein;
			filein.open("cppgrades.txt");
			if (filein.fail())
			{ 
				cout << "File not found. Reverting to manual..." << endl;
				
				cout << "Please enter number of students \n";
				cin >> n;
				marks* list = new marks[n];
				read(list, n);
			}
			filein >> n;
			marks* list = new marks[n];
			read_file(list, filein, n);
			sort(list, n);
			final_calc(list, n);
			LG_calc(list, n);
			int out_choice = 0;
			do
			{
				cout << "Choose way of output: " << endl << "1: Use a file named cppgrades_out.txt" << endl << "2: Output manually" << endl;
				cin >> out_choice;
			} while (out_choice != 1 && out_choice != 2);
			if (out_choice == 2)
			{
				printout(list, n);
			}
			else
			{
				ofstream fileout;
				fileout.open("cppgrades_out.txt");
				print_file(list, fileout, n);
			}
			
			delete[] list;
		}
	

}

