#include "Header.h"

void mainMenu(Node** pHead) //main menu function
{
    system("cls");
    int in;
    printf("(1) load\n(2) store\n(3) display\n(4) insert\n(5) delete\n(6) edit\n(7) sort\n(8) rate\n(9) play\n(10) shuffle\n(11) exit\n");
    scanf("%d", &in);
    if (in == 1) load(&pHead); //insert at front function
    else if (in == 2) store(&pHead); //print function but to a file
    else if (in == 3) display(&pHead); //print function
    else if (in == 4) insert(&pHead); //insert at front function with prompted values
    else if (in == 5) delete(&pHead); //delete function
    else if (in == 6) edit(&pHead); //edit function by artist -- must prompt which of the artists songs
    else if (in == 7) sort(&pHead); //insert in order function
    else if (in == 8) rate(&pHead); //edit function
    else if (in == 9) play(&pHead); //plays songs in order
    else if (in == 10) shuffle(&pHead); //randomizes without edditing list
    else if (in == 11) Exit(&pHead); //saves list to file and exits
}
void load(Node** pList) { //load function
    FILE* input = fopen("musicPlayList.csv", "r");

    if (input == NULL) printf("Error opening file");
    char temp[100], tTemp[20];
    Record Temp;
    //while (!feof(input))
    while(fgets(&temp, 100, input) != NULL)
    {
        //fgets(&temp, 100, input);
        printf("%s\n", temp);
        if (temp[0] == 34) {
            strcpy(Temp.Artist, strtok(temp, ","));
            strcat(Temp.Artist, strtok(NULL, ","));
            printf("%s\n", Temp.Artist);
        }
        else {
            strcpy(Temp.Artist, strtok(temp, ","));
            printf("%s\n", Temp.Artist);
        }
        strcpy(Temp.AlbumTitle, strtok(NULL, ","));
        printf("%s\n", Temp.AlbumTitle);
        strcpy(Temp.SongTitle, strtok(NULL, ","));
        printf("%s\n", Temp.SongTitle);
        strcpy(Temp.Genre, strtok(NULL, ","));
        printf("%s\n", Temp.Genre);
        strcpy(tTemp, strtok(NULL, ","));
        printf("%s\n", tTemp);
        Temp.TimesPlayed = atoi(strtok(NULL, ","));
        printf("%d\n", Temp.TimesPlayed);
        Temp.Rating = atoi(strtok(NULL, ","));
        printf("%d\n", Temp.Rating);
        Temp.duration.minutes = atoi(strtok(tTemp, ":"));
        printf("%d\n", Temp.duration.minutes);
        Temp.duration.seconds = atoi(strtok(tTemp, ":"));
        printf("%d\n", Temp.duration.seconds);

        printf("%d\n\n", insertAtFront(&pList, Temp));
    }
    system("pause");
    fclose(input);
    mainMenu(&pList);
}
void store(Node**pList) { //store function
    fprint(&pList);
    mainMenu(&pList);
}
void display(Node** pList) { //display function
    int input;
    /*printf("1. Print all records \n 2. print all records that match current artist \n");
    scanf("%d", &input);
    if (input == 1)
    {

    }
    else
    {

    }*/
    print(&pList);
    mainMenu(&pList);
}
void insert(Node** pList) { //insert function TODO

    mainMenu(&pList);
}
void delete(Node** pList) { //delete function
    char title[100];
    printf("input song title you want to remove:\n");
    scanf("%s", &title);
    deleteNode(&pList, title);
    mainMenu(&pList);
}
void edit(Node** pList) { //edit function
    editNode(&pList, 0);
    mainMenu(&pList);
}
void sort(Node** pList) { //sort function TODO

    mainMenu(&pList);
}
void rate(Node** pList) { //rate function
    editNode(&pList, 1);
    mainMenu(&pList);
}
void play(Node** pList) { //play function TODO

    mainMenu(&pList);
}
void shuffle(Node** pList) { //shuffle function TODO

    mainMenu(&pList);
}
void Exit(Node** pList) { //exit function
    store(&pList);
    exit(0);
}