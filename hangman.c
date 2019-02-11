#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define MAX 30
void print_game();
int lives=7,i=0;
char answer[20]="", wrong_guesses[30]="";
int main() {
	srand(time(NULL));
	char a[MAX][20] = {
		"queue",
		"woody",
		"earning",
		"raccoon",
		"tiny",
		"youtube",
		"uranium",
		"island",
		"software",
		"oak",
		"pineapple",
		"apple",
		"disgusting",
		"freezed",
		"gary",
		"hypnosis",
		"lion",
		"cookie",
		"virus",
		"network",
	};
	char *word = a[rand()%20],	guess, guess_aux[2]="";
	int remaining=strlen(word);
	for(i=0;i<strlen(word);i++){
		answer[i]='_';
	}
	while(lives&&remaining){
		print_game();
		printf("\n\n\t\t\tGuess a letter: ");
		scanf(" %c",&guess);
		if(strchr(word,guess)){
			for(i=0;i<strlen(word);i++){
				if(word[i]==guess){
					answer[i]=guess;
					remaining--;
				}
			}
		}
		else if(!strchr(wrong_guesses,guess)){
			guess_aux[0]=guess;
			strcat(wrong_guesses,guess_aux);
			lives--;
		}
	}
	print_game();
	printf("\n\n\t\t -- GAME OVER --\n\n\t%s\n\tThe word was %s.\n\n",lives?"YOU WIN!!\n":"You lose, better luck next time...\n",word);
	system("pause");
}
void print_game(){
	system("cls");
	printf("\n\t  _______");
	for(i=0;i<strlen(wrong_guesses);i++)
		printf(" %c",wrong_guesses[i]);
	printf("\n\t  |/   | \n");
	printf("\t  |    %s \n",(lives<7)?"O":"");
	printf("\t  |   %s%s%s\n",(lives<5)?"_":" ",(lives<6)?"|":"",(lives<4)?"_":"");
	printf("\t  |    %s \n",(lives<3)?"|":"");
	printf("\t  |   %s %s\n",(lives<2)?"/":"",(lives)?"":"\\");
	printf("\t__|_________\t");
	for(i=0;i<strlen(answer);i++)
		printf("%c ",answer[i]);
}
