#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[30];
	char gender;
	char playerType;
	char countryCode[4];
	int ranking;
} Player;

char* generateplayerGameType(char gender, char gameType) {
	char* returnString = malloc(22 * sizeof(char));
	if (gender == 'M') strcat(returnString, "Men's ");
	else strcat(returnString, "Women's ");

	if (gameType == 'X') strcat(returnString, "Mixed Doubles");
	else if (gameType == 'S') strcat(returnString, "Singles");
	else strcat(returnString, "Doubles");
	return returnString;
}

int main() {
	FILE *fptr;
	fptr = fopen("badmintonPlayers.txt", "r");

	if (fptr == NULL) {
		printf("Error trying to read badmintonPlayers.txt\n");
		exit(-1);
	}

	Player p;
	printf(
		"LIST OF PLAYERS\n"
		"Name                          Gender   Country   Game Type            Ranking\n"
		"-----------------------------------------------------------------------------\n"
	);

	while (fscanf(fptr, "%[^|]|%c|%c|%[^|]|%d\n", p.name, &p.gender, &p.playerType, p.countryCode, &p.ranking) > 0) {
		char* gameTypeString = generateplayerGameType(p.gender, p.playerType);
		printf("%-29s %-8c %-9s %-22s %d\n", p.name, p.gender, p.countryCode, gameTypeString, p.ranking);
	}

	fclose(fptr);
}