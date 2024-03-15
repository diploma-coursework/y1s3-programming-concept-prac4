#include <stdio.h>
#include <stdlib.h>

struct Student {
	char id[11];
	char name[31];
	double cgpa;
} student;

int main() {
	FILE *fptr;
	fptr = fopen("Student.txt", "a");
	if (fptr == NULL) {
		printf("Error opening Student.txt\n");
		exit(-1);
	}

	char decisionCode;
	do {
		printf("Enter student id > ");
		scanf(" %10s", student.id);

		printf("Enter student name > ");
		scanf(" %30[^\n]", student.name);

		printf("Enter student cgpa > ");
		scanf(" %f", &student.cgpa);

		fprintf(fptr, "%s|%s|%.2f\n", student.id, student.name, student.cgpa);
		
		printf("Any more records? (Y to continue) > ");
		scanf(" %c", &decisionCode);
	} while (decisionCode == 'Y');

	fclose(fptr);
}