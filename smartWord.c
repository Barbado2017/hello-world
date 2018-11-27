/*
Authors (group members): Luke Lynch, Eric , Anh
Email addresses of group members: llynch2017@my.fit.edu
Group name: AEL
Course: CSE 2010
Section: 04
Description of the overall algorithm:

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "smartWord.h"

typedef struct NODE{
	char letters[30], guessed, end;
	int frequency; 
	struct NODE *next;
	struct NODE *parent;
	struct NODE *down;
}NODE;

typedef struct BASE{
	NODE *cap_ptr;
	NODE *lower_ptr;
}BASE;

BASE dictionary[26];

void add_word(int first_val, char curr_word[]);

//initialize smartWord by process a file of English dictionary words
void initSmartWord(char *wordFile){
	FILE *inp = fopen(wordFile, "r");
	char curr_word[30];
	char first_letter;
	int first_val;
	for(int i = 0; i < 26; i++){
		NODE *new = (NODE *)malloc(sizeof(NODE));
		new->letters[0] = 'a' + i;
		new->letters[1] = '\0';
		new->guessed = 'n'; new->end = 'y'; new->frequency = 0;
		new->next = NULL; new->parent = NULL; new->down = NULL;
		NODE *new_1 = (NODE *)malloc(sizeof(NODE));
		new_1->letters[0] = 'A' + i;
		new_1->letters[1] = '\0';
		new_1->guessed = 'n'; new_1->end = 'y'; new_1->frequency = 0;
		new_1->next = NULL; new_1->parent = NULL; new_1->down = NULL;
		dictionary[i].cap_ptr = new;
		dictionary[i].lower_ptr = new_1;
	}
	while(!feof(inp)){
		fscanf(inp, "%s", curr_word);
		first_letter = curr_word[0];
		tolower(first_letter);
		first_val = first_letter - 'A';
		add_word(first_val, curr_word);
	}
	fclose(inp);
}

void add_word(int first_val, char curr_word[]){
	NODE *before;
	if(curr_word[1] != '\0'){
		int i = 1;
		NODE *temp = (NODE *)malloc(sizeof(NODE));
		if(curr_word[0] > 'Z'){
			temp = dictionary[first_val].cap_ptr;
		}else{
			temp = dictionary[first_val].lower_ptr;
		}
		while(temp != NULL){
			if(curr_word[i] != '\0' && temp->down == NULL){
				NODE *new = (NODE *)malloc(sizeof(NODE));
				new->letters[0] = curr_word[i];
				new->next = NULL; new->parent = temp; new->down = NULL;
				new->frequency = 0; new->guessed = 'n';
				if(curr_word[i+1] == '\0'){
					new->end = 'y';
				}else{
					new->end = 'n';
				}
				if(temp->down == NULL){
					if(curr_word[i] != '\0'){
						temp->down = new;
					}
					temp = temp->down;
				}
			}
			if(temp->down->letters[0] != curr_word[i]){
				before = temp;
				temp = temp->down;
				while(temp != NULL || temp->letters[0] != curr_word[i]){
					temp = temp->next;
				}
				NODE *new = (NODE *)malloc(sizeof(NODE));
				new->letters[0] = curr_word[i];
				new->next = NULL; new->parent = before; new->down = NULL;
				new->frequency = 0; new->guessed = 'n';
				if(curr_word[i+1] == '\0'){
					new->end = 'y';
				}else{
					new->end = 'n';
				}
			}else{
				temp = temp->down;
			}
			i++;
		}
		
	}
}

// process old messages from oldMessageFile
void procOldMsgSmartWord(char *oldMessageFile){

  
}

// Given:
//   letter: letter typed in by the user (a-z, A-Z)
//   letterPosition:  position of the letter in the word, starts from 0
//   wordPosition: position of the word in a message, starts from 0
// Return via a parameter:
//   gueses: NUM_GUESSES (3) word guesses (case-insensive comparison is used) 

void guessSmartWord(char letter, int letterPosition, int wordPosition, char guesses[NUM_GUESSES][MAX_WORDLEN+1]){

  // just to show how to return 3 (poor) guesses
  strcpy(guesses[0], "abc");
  strcpy(guesses[1], "defgh");
  strcpy(guesses[2], "ijk");
}





// feedback on the 3 guesses from the user
// isCorrectGuess: true if one of the guesses is correct
// correctWord: 3 cases:
// a.  correct word if one of the guesses is correct
// b.  null if none of the guesses is correct, before the user has typed in 
//            the last letter
// c.  correct word if none of the guesses is correct, and the user has 
//            typed in the last letter
// That is:
// Case       isCorrectGuess      correctWord   
// a.         true                correct word
// b.         false               NULL
// c.         false               correct word

// values for bool: true (1), false (0)  

void feedbackSmartWord(bool isCorrectGuess, char *correctWord){

}

