#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // input/output operations
#include <string.h> // strcpy (), strcat (), strcmp (), strlen (), strtok ()
#include <stdlib.h> // malloc (), calloc (), free (), atoi (), rand (), srand ()
#include <ctype.h> // toupper (), tolower (), isalpha (), isdigit ()

typedef struct Duration
{
	int minutes;
	int seconds;
}duration;

typedef struct record
{
	char Artist[100];
	char AlbumTitle[100];
	char SongTitle[100];
	char Genre[100];
	duration duration;
	int TimesPlayed;
	int Rating;
}Record;


typedef struct node
{
	Record data;
	struct node* pLink;
	struct node* pPrev; // this lab is now using two links
} Node;

void load(Node** pList);

void mainMenu(Node**pList); //main menu function
void store(Node** pList); //store function
void display(Node** pList); //display function
void insert(Node** pList); //insert function
void delete(Node** pList); //delete function
void edit(Node** pList); //edit function
void sort(Node** pList); //sort function
void rate(Node** pList); //rate function
void play(Node** pList); //play function
void shuffle(Node** pList); //shuffle function
void Exit(Node** pList); //exit function


Node* createNode(Record newData);
int insertAtFront(Node** pList, Record newData);
int insertMusicInOrder(Node** pList, Record newData);
void print(Node* pList);
void fprint(Node* pList);
void editNode(Node** pList, int n);
int deleteNode(Node** pList, char* title);



