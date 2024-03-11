#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "visualizedSorts.h"

//Programm: VisualizedQuicksort

/*
* ANSI-Steuerzeichen und Sequenzen:
* \33\[2A => Cursor 2 Zeilen nach oben
* \33\[2B => Cursor 2 Zeilen nach unten
* \33\[s => Aktuelle Cursorposition speichern
* \33\[u => Cursor auf die gespeicherte Position setzen
*/

void main()
{
    system("chcp 1252");
    system("cls");

    srand(time(NULL));
    rand();

    int i = 0;
    int size = 20;
    int randomNumbers[size];
    for(i=0; i<size; i++)
        randomNumbers[i]=rand()%100+1;

    int initialPivotPrint[size];
    initialPivotPrint[0] = 80;
    for(i=1; i<size; i++) initialPivotPrint[i] = 45;

    int initialIndicesPrint[size];
    for(i=0; i<size; i++) initialIndicesPrint[i] = 45;

    int initialSortedPrint[size];
    for(i=0; i<size; i++) initialSortedPrint[i] = 45;

    //##### Konsolenausgabe
    printf("\t##### >>> QUICKSORT <<< #####\n\n");
    int lineSize = 120;
    for(i=0; i<lineSize; i++) printf("*");
    printf("\n");
    for(i=0; i<size; i++) printf("a[%2d] ", i);
    printf("\n");
    for(i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(i=0; i<size; i++) printf(" %3d  ", randomNumbers[i]); //Gespeicherte Cursorposition (Zeilenanfang)
    printf("\n");
    for(i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(i=0; i<size; i++) printf(" %3c  ", initialPivotPrint[i]);
    printf("\n");
    for(i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(i=0; i<size; i++) printf(" %3c  ", initialIndicesPrint[i]);
    printf("\n");
    for(i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(i=0; i<size; i++) printf(" %3c  ", initialSortedPrint[i]);
    printf("\n");
    for(i=0; i<lineSize; i++) printf("*");
    printf("\n");

    printf("\33\[12A\33\[s\33\[14B");
    printf("P = Pivot. Diese Zahl wird gerade an die korrekte Stelle sortiert.\n"
           "S = Sortierte Zahl.\n\n");
    printf("Index l: Läuft von P aus nach rechts, bis eine Zahl > P erreicht ist.\n"
           "Index r: Läuft von der rechten Grenze aus nach links, bis eine Zahl < P erreicht ist.\n"
           "Solange l < r ist, werden die Zahlen getauscht. Das Ganze wird fortgesetzt, bis r schließlich l übertritt.\n"
           "Ist der Wert bei Index r < P, werden die Zahlen getauscht.\n"
           "P ist jetzt korrekt einsortiert, da sich alle Zahlen < P auf der linken Seite befinden und alle Zahlen > P auf der rechten.\n\n"
           "Als nächstes ruft sich die rekursive Funktion 2 x selbst auf.\n"
           "1 x für den Array-Bereich links und 1 x für den Array-Bereich rechts der zuletzt einsortierten Zahl.\n\n"
           "Der zu sortierende Bereich wird daher bei jedem Aufruf kleiner.\n"
           "Die linke und rechte Grenze (Index von - bis) werden bei jedem Aufruf neu festgelegt.\n"
           "P steht bei jedem Aufruf links im zugewiesenen Bereich.\n\n");
    printf("*** Konsole evtl. auf Vollbild!\n*** Sortierung beginnen: ");
    system("pause");
    //##### Ende Konsolenausgabe

    visualizedQuicksort(&randomNumbers[0], 0, size-1, &initialPivotPrint[0], &initialIndicesPrint[0], &initialSortedPrint[0]);

    printf("\33\[u");
    for(i=0; i<28; i++)
        printf("\n");

    printf("*** Konsolenausgabe schließen:\n");
    system("pause");
}
