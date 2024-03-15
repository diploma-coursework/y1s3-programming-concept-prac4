#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[30];
	char gender;
	char playerType;
	char countryCode[4];
	int ranking;
} Player;

void writeToBadmintonPlayersTxtFile(Player *player) {
	FILE *fptr;
	fptr = fopen("badmintonPlayers.txt", "a");

	if (fptr == NULL) {
		printf("Cannot open badmintonPlayers.txt file.\n");
		exit(-1);
	}

	fprintf(
		fptr, "%s|%c|%c|%3s|%d\n",
		player->name,
		player->gender,
		player->playerType,
		player->countryCode,
		player->ranking
	);

	fclose(fptr);
}


int main() {
	Player p;

	while (1) {
		printf("Enter player name > ");
		scanf(" %29[^\n]s", p.name);

		if (!strcmp(p.name, "XXX")) exit(0);

		printf("Enter player gender (M/F) > ");
		scanf(" %c", &p.gender);

		printf("Enter player type (S = single, D = doubles, X = mixed doubles) > ");
		scanf(" %c", &p.playerType);

		printf("Enter player country code > ");
		scanf(" %3s", p.countryCode);

		printf("Enter player ranking > ");
		scanf(" %d", &p.ranking);
		
		writeToBadmintonPlayersTxtFile(&p);
	}
}