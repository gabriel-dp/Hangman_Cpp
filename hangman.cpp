#include <iostream>

using namespace std;

bool ended = false;

//shows the art of the game
void Game (string word, int lifes, string letters, string wrong) {
	system("cls");

	cout << "\n_____    ";

	//write the letters of the secret word and ends the game
	#pragma region SecretWord
	ended = true;
	bool flag = false;

	for (int i = 0; i < word.length(); i++) {
		//prints the right letters
		string finded = "-";
		for (int j = 0; j < letters.length(); j++) {
			if (word[i] == letters[j]) {
				finded = letters[j];
				break;
			}
		}
		cout << finded;

		//checks if the game ended
		if (finded == "-" && !flag) {
			flag = true;
			ended = false;
		}
	}

	//prints the wrong letters
	cout << "          " << wrong;
	#pragma endregion

	cout << "\n|   |\n|   ";
	if (lifes < 5) cout << "O";
	cout << "\n|  ";
	(lifes < 3) ? cout << "/" : cout << " ";
	if (lifes < 4) cout << "|";
	if (lifes < 3) cout << "\\";
	cout << "\n|  ";
	if (lifes < 2) cout << "/";
	if (lifes < 1) cout << " \\";
	cout << "\n|        ";
}

int main() {

	//player1 inputs the secret word
	cout << "\nType the secret word (UPPERCASE letters): ";
	string word;
	cin >> word;
	system("cls");

	//setup the game
	int lifes = 5;
	string right_letters;
	string wrong_letters;
	Game(word, lifes, right_letters, wrong_letters);

	do {
		checkpoint:

		//player2 inputs the letters
		char letter;
		cin >> letter;
		letter = toupper(letter);

		//checks if the input is corret or not
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == letter) {
				right_letters += letter;
				Game(word, lifes, right_letters, wrong_letters);
				if (!ended) goto checkpoint;
			}
		}

		//remove a life if player2 is wrong
		if (!ended) {
			lifes--;
			wrong_letters += letter;
			Game(word, lifes, right_letters, wrong_letters);
		}

	} while (lifes > 0 && !ended);

	//shows the result
	cout << "\n\n";
	if (lifes > 0) {
		cout << "You won the game!";
	} else {
		cout << "You lose the game..";
	}

	cout << "\n\n";
	system("pause");

	return 0;
}