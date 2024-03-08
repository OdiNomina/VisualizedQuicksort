#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "visualizedSorts.h"

//Programm FPA_05_03_01-03
//Quicksort visualisieren

void main()
{
    system("chcp 1252");
    system("cls");

    srand(time(NULL));
    rand();

    int i, randomNumbers[15];
    for(i=0; i<15; i++)
        randomNumbers[i]=rand()%100+1;

    int startPivotPrint[15]={45,45,45,45,45,45,45,45,45,45,45,45,45,45,45};
    int startIndicesPrint[15]={45,45,45,45,45,45,45,45,45,45,45,45,45,45,45};
    int startSortedPrint[15]={45,45,45,45,45,45,45,45,45,45,45,45,45,45,45};

    printf("*****************************************************************************************\n");
    for(int i=0; i<15; i++) printf("a[%2d] ", i);
    printf("\n-----------------------------------------------------------------------------------------\n");
    for(int i=0; i<15; i++) printf(" %3d  ", randomNumbers[i]); //Gespeicherte Cursorposition (Zeilenanfang)
    printf("\n-----------------------------------------------------------------------------------------\n");
    for(int i=0; i<15; i++) printf(" %3c  ", startPivotPrint[i]);
    printf("\n-----------------------------------------------------------------------------------------\n");
    for(int i=0; i<15; i++) printf(" %3c  ", startIndicesPrint[i]);
    printf("\n-----------------------------------------------------------------------------------------\n");
    for(int i=0; i<15; i++) printf(" %3c  ", startSortedPrint[i]);
    printf("\n*****************************************************************************************\n\n");

    /*
    * ANSI-Steuerzeichen und Sequenzen:
    * \33\[9A => Cursor 9 Zeilen nach oben
    * \33\[s => Aktuelle Cursorposition speichern
    * \33\[9B => Cursor 9 Zeilen nach unten
    */
    printf("\33\[9A\33\[s\33\[9B");
    printf("P = Aktueller Pivot-Wert, der an die korrekte Stelle sortiert wird.\n");
    printf("S = Sortierte Zahl.");

    visualizedQuicksort(&randomNumbers[0], 0, 14, &startPivotPrint[0], &startIndicesPrint[0], &startSortedPrint[0]);

    printf("\n\n\n\n\n\n");
    system("pause");
}
