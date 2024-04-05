#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *studentFilePtr, *bookPrizeFilePtr;
	studentFilePtr = fopen("Student.txt", "r");
	bookPrizeFilePtr = fopen("BookPrize.txt", "w");
	if (studentFilePtr == NULL) {
		printf("Error reading Student.txt\n");
		exit(-1);
	}
	if (bookPrizeFilePtr == NULL) {
		printf("Error opening BookPrize.txt\n");
		exit(-1);
	}

	printf(
		"            LIST OF STUDENTS\n"
		"Student ID   Name                    CGPA\n"
		"==========   ====                    ====\n"
	);

	char studentId[11], studentName[20];
	float cgpa;
	int i = 0;
	while (fscanf(studentFilePtr, "%[^|]|%[^|]|%f\n", studentId, studentName, &cgpa) == 3) {

		if (cgpa >= 3.5) {
			printf("%-10s   %-20s   %.2f\n", studentId, studentName, cgpa);
			fprintf(bookPrizeFilePtr, "%s|%s|%.2f\n", studentId, studentName, cgpa);
			++i;
		}
	}
	fclose(studentFilePtr);
	fclose(bookPrizeFilePtr);
	printf("%d record(s) copied to BookPrize.txt\n", i);
}