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

    int size = 20;
    int i, randomNumbers[size];
    for(i=0; i<size; i++)
        randomNumbers[i]=rand()%100+1;

    int initialPivotPrint[size];
    for(int i=0; i<size; i++) initialPivotPrint[i] = 45;

    int initialIndicesPrint[size];
    for(int i=0; i<size; i++) initialIndicesPrint[i] = 45;

    int initialSortedPrint[size];
    for(int i=0; i<size; i++) initialSortedPrint[i] = 45;

    //##### Konsolenausgabe
    int lineSize = 120;
    for(int i=0; i<lineSize; i++) printf("*");
    printf("\n");
    for(int i=0; i<size; i++) printf("a[%2d] ", i);
    printf("\n");
    for(int i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(int i=0; i<size; i++) printf(" %3d  ", randomNumbers[i]); //Gespeicherte Cursorposition (Zeilenanfang)
    printf("\n");
    for(int i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(int i=0; i<size; i++) printf(" %3c  ", initialPivotPrint[i]);
    printf("\n");
    for(int i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(int i=0; i<size; i++) printf(" %3c  ", initialIndicesPrint[i]);
    printf("\n");
    for(int i=0; i<lineSize; i++) printf("-");
    printf("\n");
    for(int i=0; i<size; i++) printf(" %3c  ", initialSortedPrint[i]);
    printf("\n");
    for(int i=0; i<lineSize; i++) printf("*");
    printf("\n");

    printf("\33\[9A\33\[s\33\[11B");
    printf("P = Pivot. Diese Zahl wird gerade an die korrekte Stelle sortiert.\n"
           "S = Sortierte Zahl.\n\n");
    printf("Index i: Läuft von P aus nach rechts, bis eine Zahl > P erreicht ist.\n"
           "Index j: Läuft von der rechten Grenze aus nach links, bis eine Zahl < P erreicht ist.\n"
           "Falls i > j ist, werden die Zahlen getauscht. Das Ganze wird fortgesetzt, bis sich i und j treffen.\n"
           "An dieser Stelle (i = j) ist P korrekt einsortiert, da sich alle Zahlen < P auf der linken Seite befinden und alle Zahlen > P auf der rechten.\n\n"
           "Als nächstes ruft sich die rekursive Funktion 2 x selbst auf.\n"
           "1 x für den Array-Bereich links und 1 x für den Array-Bereich rechts der zuletzt einsortierten Zahl.\n\n"
           "Der zu sortierende Bereich wird daher bei jedem Aufruf kleiner.\n"
           "Die linke und rechte Grenze (Index von - bis) werden bei jedem Aufruf neu festgelegt.\n"
           "P ist bei jedem Aufruf die erste Zahl links im Bereich (-> In dieser beispielhaften Implementierung!)\n\n");
    printf("*** Um die Sortierung zu beginnen:\n");
    system("pause");
    //##### Ende Konsolenausgabe

    visualizedQuicksort(&randomNumbers[0], 0, size-1, &initialPivotPrint[0], &initialIndicesPrint[0], &initialSortedPrint[0]);

    printf("\33\[u");
    for(int i=0; i<27; i++)
        printf("\n");

    printf("*** Konsolenausgabe schließen:\n");
    system("pause");
}
