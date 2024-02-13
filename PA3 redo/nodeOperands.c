#include "Header.h"

Node* createNode(Record newData)
{
    Node* pNew = malloc(sizeof(Node));

    if (pNew != NULL)
    {
        pNew->pPrev = pNew->pLink = NULL;
        strcpy(pNew->data.Artist, newData.AlbumTitle);
        strcpy(pNew->data.AlbumTitle, newData.AlbumTitle);
        strcpy(pNew->data.SongTitle, newData.AlbumTitle);
        strcpy(pNew->data.Genre, newData.AlbumTitle);
        pNew->data.duration.minutes = newData.duration.minutes;
        pNew->data.duration.seconds = newData.duration.seconds;
        pNew->data.TimesPlayed = newData.TimesPlayed;
        pNew->data.Rating = newData.Rating;

    }

    return pNew;
}
int insertAtFront(Node** pList, Record newData)
{
    int success = 0;
    Node* pMem = createNode(newData);

    if (pMem != NULL)
    {
        success = 1;
        if (*pList != NULL)
        {
            (*pList)->pPrev = pMem;
            pMem->pLink = *pList;
        }
        *pList = pMem;
    }

    return success;
}
int insertMusicInOrder(Node** pList, Record newData)
{
    Node* pMem = createNode(newData), * pCur = *pList, * pPrev = NULL;
    int success = 0;

    if (pMem != NULL)
    {
        success = 1;
        while (pCur != NULL && strcmp(newData.SongTitle, pCur->data.SongTitle) > 0)
        {
            pPrev = pCur;
            pCur = pCur->pLink;
        }
        if (pPrev == NULL)
        {
            pMem->pLink = pCur;
            *pList = pMem;
        }
        else
        {
            pMem->pLink = pCur;
            pPrev->pLink = pMem;
        }
    }

    return success;
}
int deleteNode(Node** pList, char* title)   
{
    Node* pPrev = NULL, * pCur = *pList;
    int success = 0;
    while (pCur != NULL && strcmp(title, pCur->data.SongTitle) != 0)
    {
        pPrev = pCur;
        pCur = pCur->pLink;
    }

    if (pCur != NULL)
    {
        success = 1;

        if (pPrev == NULL)
        {
            *pList = pCur->pLink;
        }
        else
        {
            pPrev->pLink = pCur->pLink;
        }
        free(pCur);
    }

    return success;
}

void editNode(Node** pList, int n)
{
    Node* pPrev = NULL, * pCur = *pList;
    int success = 0, input = 0;
    char title[50];
    if(n == 1){ //if it is rating
        printf("title of song you want to rate: \n");
        scanf("%s", &title);
        printf("\nwhat do you rate the song (1-5):\n");
    }
    else {
        printf("which value would you like to edit? \n 1) Artist \n 2) Album Title \n 3) Song title \n 4) Genre\n");
        scanf("%d", &input);

        printf("title of song you want to change: \n");
        scanf("%s", &title);

        printf("what do you want to change it to:\n");
    }



    while (pCur != NULL && strcmp(title, pCur->data.SongTitle) != 0)
    {
        pPrev = pCur;
        pCur = pCur->pLink;
    }

    if (pCur != NULL)
    {
        success = 1;
        
        
        if (n != 1) {
            if (input == 1) scanf("%s", &pCur->data.Artist);
            else if (input == 2) scanf("%s", &pCur->data.AlbumTitle);
            else if (input == 3) scanf("%s", &pCur->data.SongTitle);
            else if (input == 4) scanf("%s", &pCur->data.Genre);
            else
            {
                printf("invalid input");
                return;
            }
        }
        else scanf("%d", &pCur->data.Rating);
    }
}

void print(Node* pList)
{
    int in;
    char artist[100];
    printf("(1) print all records\n(2)print all records for an artist:\n");
    scanf("%d", &in);
    if (in == 2)
    {
        printf("input artist name:\n");
        scanf("%s", &artist);
    }
    while (pList != NULL)
    {
        putchar('\n');
        if (in == 2 && pList->data.Artist == artist) {
            printf("Title: %s\n %s, %s, %s, %d:%d, %d, %d", pList->data.Artist, pList->data.AlbumTitle, pList->data.SongTitle, pList->data.Genre, pList->data.duration.minutes, pList->data.duration.seconds, pList->data.TimesPlayed, pList->data.Rating);
        }
        else {
            printf("Title: %s\n %s, %s, %s, %d:%d, %d, %d", pList->data.Artist, pList->data.AlbumTitle, pList->data.SongTitle, pList->data.Genre, pList->data.duration.minutes, pList->data.duration.seconds, pList->data.TimesPlayed, pList->data.Rating);
        }
        pList = pList->pLink;
    }

    putchar('\n');
}
void fprint(Node* pList)
{
    FILE* output = fopen("musicPlayList.csv", "w");
    while (pList != NULL)
    {
        fprintf(output, "Title: %s\n %s, %s, %s, %d:%d, %d, %d", pList->data.Artist, pList->data.AlbumTitle, pList->data.SongTitle, pList->data.Genre, pList->data.duration.minutes, pList->data.duration.seconds, pList->data.TimesPlayed, pList->data.Rating);
        pList = pList->pLink;
    }
    fclose(output);
}
