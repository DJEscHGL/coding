#include <iostream>
#include <string>

using namespace std;

int numOfSubjects;

struct Student {
	int course = 0; // !IMPORTANT! максимальное количество курсов 6
	string N_S_M;
	int* marks = new int[numOfSubjects];
	short finance = 0;
	double scholarship = 0;
};

void showData(Student* unit, int amount) {
	system("cls");
	cout << "#\t" << "Course \t" << " Name_Surname_Middle name    " << "Finance\t" << "Scholarship" << endl;
	cout << "=========================================================================" << endl;
	for (int i = 0; i < amount; i++) {
		cout << i + 1 << "\t" << unit[i].course << "\t" << unit[i].N_S_M << "  \t" << unit[i].finance << "\t" << unit[i].scholarship << endl;
	}
}

int main() {
	int numOfStudents;
	double averageMark = 0;
	cout << "Num of students = ";
	cin >> numOfStudents;
	cout << "Num of subjects = ";
	cin >> numOfSubjects;
	Student* students = new Student[numOfStudents];
	for (int i = 0; i < numOfStudents; i++) {
		cout << i + 1 << " student\n" << "Course = ";
		cin >> students[i].course;
		cout << "Name Surname Middle name\n";
		cin.get();
		getline(cin, students[i].N_S_M, '\n');
		cout << "Write marks:\n";
		for (int j = 0; j < numOfSubjects; j++) {
			cout << j + 1 << "mark = ";
			cin >> students[i].marks[j];
			averageMark += students[i].marks[j];
		}
		cout << "Financial situation = ";
		cin >> students[i].finance;
		averageMark /= numOfSubjects;
		students[i].scholarship = 500 * averageMark;
	}
	for (int i = 0; i < numOfStudents - 1; i++) {
		for (int j = 0; j < numOfStudents - i - 1; j++) {
			if (students[j].course > students[j + 1].course){
				swap(students[j].course, students[j + 1].course);
				swap(students[j].N_S_M, students[j + 1].N_S_M);
				swap(students[j].finance, students[j + 1].finance);
				swap(students[j].scholarship, students[j + 1].scholarship);
				for (int k = 0; k < numOfSubjects; k++) {
					swap(students[j].marks[k], students[j + 1].marks[k]);
				}
			}
		}
	}
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j < numOfStudents - 1; j++) {
			for (int k = 0; k < numOfStudents - j - 1; k++) {
				if (students[k].course == i && students[k + 1].course == i) {
					if (students[k].scholarship > students[k + 1].scholarship) {
						swap(students[k].course, students[k + 1].course);
						swap(students[k].N_S_M, students[k + 1].N_S_M);
						swap(students[k].finance, students[k + 1].finance);
						swap(students[k].scholarship, students[k + 1].scholarship);
						for (int q = 0; q < numOfSubjects; q++) {
							swap(students[k].marks[q], students[k + 1].marks[q]);
						}
					}
				}
			}
		}
	}
	showData(students, numOfStudents);
}