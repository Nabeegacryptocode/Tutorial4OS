/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    for(int i = 0; i < 12; i++) {
    	strcpy(questions[i].category, categories[i % 3]);
    	questions[i].answered = false;
    	strcpy(questions[i].question, "Question");
    	strcpy(questions[i].answer, "Response");
    }

    questions[0].value = 200;
    strcpy(questions[0].question, "Until the 5th c. invention of stirrups, horses kneeled to be mounted like these desert animals");
    strcpy(questions[0].answer, "Camels");

    questions[1].value = 200;
    strcpy(questions[1].question, "The Waltons #1 son ");
    strcpy(questions[1].answer, "John Boy");

    questions[2].value = 200;
    strcpy(questions[2].question, "Country that gave us mousasaka and feta cheese");
    strcpy(questions[2].answer, "greece");

    questions[3].value = 200;
    strcpy(questions[3].question, "In 1942 as Woman of the Year she was paired with Spencer Tracy in the movie \"State of the Union\"");
    strcpy(questions[3].answer, "Katharine Hepburn");

    questions[4].value = 200;
    strcpy(questions[4].question, "If you put money in an IRA youre putting it in this");
    strcpy(questions[4].answer, "Individual Retirement Account");

    questions[5].value = 200;
    strcpy(questions[5].question, "The first Academy Awards were held in this year");
    strcpy(questions[5].answer, "1929");

    questions[6].value = 200;
    strcpy(questions[6].question, "The largest continent in the world");
    strcpy(questions[6].answer, "Asia");

    questions[7].value = 200;
    strcpy(questions[7].question, "The highest mountain in the world");
    strcpy(questions[7].answer, "Mount Everest");

    questions[8].value = 200;
    strcpy(questions[8].question, "The largest ocean in the world");
    strcpy(questions[8].answer, "Pacific Ocean");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    int width = 20;

    for (int i = 0; i < 3; ++i) {
		putchar('+');
		for (int j = 0; j < width; ++j)
			putchar('-');
	}
	printf("+\n");

	for(int i = 0; i < 3; i++) 
		printf("| %-*s", width - 1, categories[i]);
	printf("|\n");

	for (int i = 0; i < 3; ++i) {
		putchar('+');
		for (int j = 0; j < width; ++j)
			putchar('-');
	}

	for(int i = 0; i < 12; i++) {
		if(questions[i].answered == false) {
			printf("| $&-*d", width - 2, questions[i].value);
		} else {
			printf("| %-*s", width - 2, " - ");
		}

		if(i % 3 == 2)
			printf("|\n");
	}

	for (int i = 0; i < 3; ++i) {
		putchar('+');
		for (int j = 0; j < width; ++j)
			putchar('-');
	}
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	printf("Question (%s for $%d):\n", category, value);

	int num = qnum(category, value);
	if(num == -1)
		printf("question %s Invalid, %d\n", category, value);

	printf("\t%s\n", questions[num].question);
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
	int num = qnum(category, value);
	if(num == -1)
		printf("question %s Invalid, %d\n", category, value);

    // Look into string comparison functions
    return (strcasecmp(answer, questions[num].answer) == 0);
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
	for(int i = 0; i < 12; i++)
		if (questions[i].value == value && strcmp(questions[i].category, category) == 0)
			return questions[i].answered;

    // lookup the question and see if it's already been marked as answered
    return true;
}

void track_answered(char *category, int value) {
	for(int i = 0; i < 12; i++) 
		if(questions[i].value == value && strcmp(questions[i].category, category) == 0)
			questions[i].answered = true;
}

bool answered() {
	for(int i = 0; i < 12; i++)
		if(questions[i].answered == false)
			return false;

	return true;
}

int get_question_number(char *category, int value) {
	for(int i = 0; i < 12; i++)
		if(strcmp(questions[i].category, category) == 0 && questions[i].value == value)
			return i;


	return -1;
}