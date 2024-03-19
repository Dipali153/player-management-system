#include <stdio.h>
#include <string.h>
struct Player 
{
    int JerseyNumber;
    char PlayerName[100];
    int Runs;
    int Wickets;
    int MatchesPlayed;
};

void AddPlayer(struct Player players[], int* numPlayers, int size);
void RemovePlayer(struct Player players[], int* numPlayers);
void SearchPlayer(struct Player players[], int numPlayers);
void UpdatePlayerData(struct Player players[], int numPlayers);
void DisplayTop3Players(struct Player players[], int numPlayers);
void DisplayAllPlayers(struct Player players[], int numPlayers);
void store(struct Player players[], int* numPlayers);

int main() 
{
    int size = 100;
    struct Player players[size];
    int numPlayers = 0;
    int choice;

    do {
        printf("\n\t**---------------------------------\n");
        printf("\t* Player Management System Menu *\n");
        printf("\t---------------------------------**\n\n");
        printf("\t1. Store Player\n");
        printf("\t2. Display All Players\n");
        printf("\t3. Add Player\n");
        printf("\t4. Remove Player\n");
        printf("\t5. Search Player\n");
        printf("\t6. Update Player Data\n");
        printf("\t7. Display Top 3 Players\n");
        printf("\t8. Exit\n\n");

        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                store(players, &numPlayers); 
                break;
            case 2:
                DisplayAllPlayers(players, numPlayers);
                break;
            case 3:
                AddPlayer(players, &numPlayers, size);
                break;
            case 4:
                RemovePlayer(players, &numPlayers);
                break;
            case 5:
                SearchPlayer(players, numPlayers);
                break;
            case 6:
                UpdatePlayerData(players, numPlayers);
                break;
            case 7:
                DisplayTop3Players(players, numPlayers);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

void store(struct Player players[], int* numPlayers) {
    players[0].JerseyNumber = 12;
   strcpy(players[0].PlayerName, "sachin");
    players[0].MatchesPlayed = 100;
    players[0].Runs = 3000;
    players[0].Wickets = 10;

    players[1].JerseyNumber = 10;
    strcpy(players[1].PlayerName, "dhoni");
    players[1].MatchesPlayed = 90;
    players[1].Runs = 2000;
    players[1].Wickets = 9;

    players[2].JerseyNumber = 11;
    strcpy(players[2].PlayerName, "virat");
    players[2].MatchesPlayed = 80;
    players[2].Runs = 1500;
    players[2].Wickets = 7;
    
    players[3].JerseyNumber = 13;
    strcpy(players[3].PlayerName, "jadeja");
    players[3].MatchesPlayed = 70;
    players[3].Runs = 75;
    players[3].Wickets = 12;

    players[4].JerseyNumber = 14;
    strcpy(players[4].PlayerName, "gambir");
    players[4].MatchesPlayed = 60;
    players[4].Runs = 50;
    players[4].Wickets = 4;

    (*numPlayers) = 5; 
}
void DisplayAllPlayers(struct Player players[], int numPlayers) 
{
    if (numPlayers == 0) {
        printf("Player database is empty. No players to display.\n");
        return;
    }

    printf("\n");
    printf("+---------------+---------------------+------------+---------+-----------------+\n");
    printf("| Jersey Number |      Player Name    |    Runs    | Wickets | Matches Played  |\n");
    printf("+---------------+---------------------+------------+---------+-----------------+\n");

    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("| %-13d | %-19s | %-10d | %-7d | %-15d |\n",
               players[i].JerseyNumber, players[i].PlayerName, players[i].Runs, players[i].Wickets, players[i].MatchesPlayed);
    }
    printf("+---------------+---------------------+------------+---------+-----------------+\n");
}


void AddPlayer(struct Player players[], int* numPlayers, int size) 
{
    if (*numPlayers >= size) {
        printf("Player database is full. Cannot add more players.\n");
        return;
    }

    struct Player newPlayer;
    printf("Enter Jersey Number: ");
    scanf("%d", &newPlayer.JerseyNumber);
    printf("Enter Player Name: ");
    scanf("%s", newPlayer.PlayerName);
    printf("Enter Runs: ");
    scanf("%d", &newPlayer.Runs);
    printf("Enter Wickets: ");
    scanf("%d", &newPlayer.Wickets);
    printf("Enter Matches Played: ");
    scanf("%d", &newPlayer.MatchesPlayed);

    players[*numPlayers] = newPlayer;
    (*numPlayers)++;
    printf("Player added successfully.\n");
}

void RemovePlayer(struct Player players[], int* numPlayers) 
{
    if (*numPlayers == 0) {
        printf("Player database is empty. Cannot remove a player.\n");
        return;
    }
    int choice;
    printf("How would you like to remove the player?\n");
    printf("1. Remove by Jersey Number\n");
    printf("2. Remove by Player Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int JerseyToRemove;
        printf("Enter the Jersey Number of the player you want to remove: ");
        scanf("%d", &JerseyToRemove);

        int i, j;
        int found = 0;
        for (i = 0; i < *numPlayers; i++) {
            if (players[i].JerseyNumber == JerseyToRemove) {
                for (j = i; j < *numPlayers - 1; j++) {
                    players[j] = players[j + 1];
                }
                (*numPlayers)--;
                printf("Player with Jersey Number %d is removed.\n", JerseyToRemove);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Player with Jersey Number %d not found.\n", JerseyToRemove);
        }
    } else if (choice == 2) {
        char NameToRemove[100];
        printf("Enter the name of the player you want to remove: ");
        scanf("%s", NameToRemove);
        int i, j;
        int found = 0;
        for (i = 0; i < *numPlayers; i++) {
            if (strcmp(players[i].PlayerName, NameToRemove) == 0) {
                for (j = i; j < *numPlayers - 1; j++) {
                    players[j] = players[j + 1];
                }
                (*numPlayers)--;
                printf("Player with Name '%s' is removed.\n", NameToRemove);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Player with Name '%s' not found.\n", NameToRemove);
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void SearchPlayer(struct Player players[], int numPlayers) 
{
    if (numPlayers == 0) {
        printf("Player database is empty. Cannot search for a player.\n");
        return;
    }

    int choice;
    printf("How would you like to search the player?\n");
    printf("1. Search by Jersey Number\n");
    printf("2. Search by Player Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int SearchJersey;
        printf("Enter the Jersey Number of the player you want to search: ");
        scanf("%d", &SearchJersey);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++) {
            if (players[i].JerseyNumber == SearchJersey) {
                printf("Player found:\n");
                printf("Jersey Number: %d Player Name: %s Runs: %d Wickets: %d  Matches Played: %d\n",
                       players[i].JerseyNumber, players[i].PlayerName, players[i].Runs, players[i].Wickets, players[i].MatchesPlayed);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Player with Jersey Number %d not found.\n", SearchJersey);
        }
    } else if (choice == 2) {
        char SearchName[200];
        printf("Enter the name of the player you want to search: ");
        scanf("%s", SearchName); 

        int i, found = 0;
        for (i = 0; i < numPlayers; i++) {
            if (strcmp(players[i].PlayerName, SearchName) == 0) {
                printf("Player found:\n");
                printf("Jersey Number: %d Player Name: %s Runs: %d Wickets: %d Matches Played: %d\n",
                       players[i].JerseyNumber, players[i].PlayerName, players[i].Runs, players[i].Wickets, players[i].MatchesPlayed);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Player with name '%s' not found.\n", SearchName);
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void UpdatePlayerData(struct Player players[], int numPlayers) 
{
    if (numPlayers == 0) {
        printf("Player is empty. Cannot update player data.\n");
        return;
    }

    int choice;
    printf("How would you like to update the player's data?\n");
    printf("1. Update by Jersey Number\n");
    printf("2. Update by Player Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int UpdateJersey;
        printf("Enter the Jersey Number of the player you want to update: ");
        scanf("%d", &UpdateJersey);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++) {
            if (players[i].JerseyNumber == UpdateJersey) {
                printf("Player found:\n");
                printf("Jersey Number: %d  Player Name: %s  Runs: %dWickets: %d Matches Played: %d\n",
                       players[i].JerseyNumber, players[i].PlayerName, players[i].Runs, players[i].Wickets, players[i].MatchesPlayed);

                printf("Enter new Runs: ");
                scanf("%d", &players[i].Runs);
                printf("Enter new Wickets: ");
                scanf("%d", &players[i].Wickets);
                printf("Enter new Matches Played: ");
                scanf("%d", &players[i].MatchesPlayed);

                printf("Player data updated successfully.\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Player with Jersey Number %d not found.\n", UpdateJersey);
        }
    } else if (choice == 2) {
        char UpdateName[200];
        printf("Enter the name of the player you want to update: ");
        scanf("%s", UpdateName);

        int i, found = 0;
        for (i = 0; i < numPlayers; i++) {
            if (strcmp(players[i].PlayerName, UpdateName) == 0) {
                printf("Player found:\n");
                printf("Jersey Number: %d Player Name: %s Runs: %d Wickets: %d Matches Played: %d\n",
                       players[i].JerseyNumber, players[i].PlayerName, players[i].Runs, players[i].Wickets, players[i].MatchesPlayed);

                printf("Enter new Runs: ");
                scanf("%d", &players[i].Runs);
                printf("Enter new Wickets: ");
                scanf("%d", &players[i].Wickets);
                printf("Enter new Matches Played: ");
                scanf("%d", &players[i].MatchesPlayed);

                printf("Player data updated successfully.\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Player with name '%s' not found.\n", UpdateName);
        }
    } else {
        printf("Invalid choice.\n");
    }
}

void DisplayTop3Players(struct Player players[], int numPlayers) 
{
    if (numPlayers == 0) {
        printf("Player database is empty. Cannot display top players.\n");
        return;
    }

    int i, j;
    struct Player temp;
    for (i = 0; i < numPlayers - 1; i++) {
        for (j = 0; j < numPlayers - 1 - i; j++) {
            if (players[j].Runs < players[j + 1].Runs) {
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }

    printf("\n");
    printf("+---------------+---------------------+------------+---------+-----------------+\n");
    printf("| Jersey Number |      Player Name    |    Runs    | Wickets | Matches Played  |\n");
    printf("+---------------+---------------------+------------+---------+-----------------+\n");

    for (i = 0; i < 3 && i < numPlayers; i++) {
        printf("| %-13d | %-19s | %-10d | %-7d | %-15d |\n",
               players[i].JerseyNumber, players[i].PlayerName, players[i].Runs, players[i].Wickets, players[i].MatchesPlayed);
    }
    printf("+---------------+---------------------+------------+---------+-----------------+\n");
}
