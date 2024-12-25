#include<iostream>
#include<iomanip>

using namespace std;

const int PORTO = 4;
const int STUDENTS = 4;

void display(double[PORTO][STUDENTS], string[STUDENTS]);

int main() {
	double scores[STUDENTS][PORTO] = {
		{90.33, 82.70, 75.75, 86.47},
		{76.67, 84, 71, 82},
		{88, 92, 79, 89}, 
		{95, 85, 84, 83}
	};
	string student_name[STUDENTS] = {"Fajar", "Calvin", "Difta", "Kafi"};
	display(scores, student_name);
	return 0;
}

void display(double funscores[PORTO][STUDENTS], string funnames[STUDENTS]) {
	cout << "Name\t" << setw(10) << "Exercises" << setw(10);
	cout << "Quiz" << setw(10);
	cout << "Midterm" << setw(10);
	cout << "Finals" << setw(10);
	
	for (int i = 0; i < STUDENTS; i++) {
		cout << "\n" << funnames[i] << "\t";
		for (int j = 0; j < PORTO; j++) {
			cout << setw(10) << funscores[i][j];
		}
	}
} 
