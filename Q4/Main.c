#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fptr;
	fptr = fopen("Student.txt", "r");
	if (fptr == NULL) {
		printf("Error reading Student.txt\n");
		exit(-1);
	}
	
	printf(
		"            LIST OF STUDENTS\n"
		"Student ID   Name                    CGPA\n"
		"==========   ====                    ====\n"
	);
	
	char studentId[11], studentName[20];
	float cgpa;
	while (fscanf(fptr, "%[^|]|%[^|]|%f\n", studentId, studentName, &cgpa) == 3) {
		printf("%-10s   %-20s   %.2f\n", studentId, studentName, cgpa);
	}
		
	fclose(fptr);
}