#include <iostream>
#include <string>

class balance {
	public:
		int balance;
		int currentBet;
};

void menu(balance aBalance);

int numbers[37] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};

char* colors[2] = {"red", "black"};

void getBet(balance myBalance) {
	system("clear");
	int bet = 0;
	while (1) {
		printf("How much is your bet? ");
		scanf("%d", &bet);
		if (bet > myBalance.balance) {
			printf("Invalid bet, your balance is lower.\n");
		} else {
			myBalance.balance = myBalance.balance + myBalance.currentBet;
			myBalance.balance = myBalance.balance - bet;
			myBalance.currentBet = bet;
			system("clear");
			break;
		}
	}
}

void betOnNum(balance myBalance) {
	getBet(myBalance);
	printf("******** ROULETTE ********\n");
	printf("* [1] Start              *\n");
	printf("* [2] Change Bet         *\n");
	printf("* [3] Return to menu     *\n");
	printf("**************************\n");
	while (1) {
		printf("Please enter a number: ");
		int input;
		scanf("%d", &input);
		if (input == 1) {
			int randNum = numbers[rand() % 37];
			if (randNum == myBalance.currentBet) {
				myBalance.balance = myBalance.balance + 2*(myBalance.currentBet);
				myBalance.currentBet = 0;
				printf("You won! (Chance: 1 to the 37)\n");
				printf("Your balance is %d$ \n", myBalance.balance);
				printf("Press ENTER to return to the menu...\n");
				fflush(stdin);
				char randChar[1];
				scanf("%c", &randChar);
				fflush(stdout);
				fflush(stdin);
				menu(myBalance);
			} else {
				myBalance.currentBet = 0;
				printf("You lost! Your balance: %d$\n", myBalance.balance);
				printf("Press ENTER to return to the menu...\n");
				fflush(stdin);
				char randChar[1];
				scanf("%c", &randChar);
				fflush(stdout);
				fflush(stdin);
				menu(myBalance);
			}
		}
		if (input == 2) {
			fflush(stdout);
			fflush(stdin);
			getBet(myBalance);
		}
		if (input == 3) {
			fflush(stdout);
			fflush(stdin);
			menu(myBalance);
		}
	}
}

void betOnColor(balance myBalance) {}

void playRoulette(balance myBalance) {
	system("clear");
	printf("******** ROULETTE ********\n");
	printf("* [1] Place bet on num.  *\n");
	printf("* [2] Place bet on col.  *\n");
	printf("* [3] Return to Menu     *\n");
	printf("**************************\n");
	fflush(stdin);
	int input;
	while (1) {
		printf("Please enter a number: ");
		scanf("%d", &input);
		if (input == 1) {
			betOnNum(myBalance);
		}
		if (input == 2) {
			
		}
		if (input == 3) {
			fflush(stdin);
			fflush(stdout);
			menu(myBalance);
		}
	}
}

void setBalance(balance myBalance) {
	system("clear");
	int desiredBalance;
	printf("Please enter what balance you want: ");
	scanf("%d", &desiredBalance);
	myBalance.balance = desiredBalance;
	printf("Your balance is now %d$.\n", myBalance.balance);
	printf("Press ENTER to return to the menu...\n");
	fflush(stdin);
	char randChar[1];
	scanf("%c", &randChar);
	menu(myBalance);
}

void menu(balance aBalance) {
	system("clear");
	printf("******** ROULETTE ********\n");
	printf("* [1] Set Balance        *\n");
	printf("* [2] Roulette           *\n");
	printf("* [3] Quit               *\n");
	printf("**************************\n");
	while (1) {
		int input;
		printf("Please enter a number: ");
		scanf("%d", &input);
		if (input == 1) {
			setBalance(aBalance);
		}
		if (input == 2) {
			playRoulette(aBalance);
		}
		if (input == 3) {
			system("clear");
			exit(1);
		}
	}
}

int main() {
	balance myBalance;
	myBalance.balance = 100;
	menu(myBalance);
}
