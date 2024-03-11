/*
* ANSI-Steuerzeichen und Sequenzen:
* \33\[2A => Cursor 2 Zeilen nach oben
* \33\[2B => Cursor 2 Zeilen nach unten
* \33\[s => Aktuelle Cursorposition speichern
* \33\[u => Cursor auf die gespeicherte Position setzen
*/

void printPivotLine(int*, int, int);
void printInitialIndicesLine(int*, int, int, int);


void visualizedQuicksort(int *numbersToSort, int leftLimit, int rightLimit, int *pivotPrint, int *indicesPrint, int *sortedPrint)
{
    if(leftLimit < rightLimit)
    {
        int sortedPivotPos = sortPivotToCorrectPos(numbersToSort, leftLimit, rightLimit, pivotPrint, indicesPrint);

        //##### nur für Print
        sortedPrint[sortedPivotPos] = 83;
        printf("\33\[u\33\[6B");
        for(int i=0; i<rightLimit+1; i++)
            printf(" %3c  ", sortedPrint[i]);
        sleep(2);
        //##

        visualizedQuicksort(numbersToSort, leftLimit, sortedPivotPos-1, pivotPrint, indicesPrint, sortedPrint);
        visualizedQuicksort(numbersToSort, sortedPivotPos+1, rightLimit, pivotPrint, indicesPrint, sortedPrint);
    }
}


int sortPivotToCorrectPos(int *numbersToSort, int leftLimit, int rightLimit, int *pivotPrint, int *indicesPrint)
{
    // numbersToSort[leftLimit] => ist aktueller Pivotwert
    int l = leftLimit+1;
    int r = rightLimit;
    int tempNum;

    //#####
    int sleepDuration = 1;
    printPivotLine(pivotPrint, leftLimit, rightLimit+1);
    printInitialIndicesLine(indicesPrint, rightLimit+1, l, r);
    sleep(sleepDuration);

    int i;
    int tempPivPos;
    //##

    while(l < r)
    {
        while(l < rightLimit && numbersToSort[l] < numbersToSort[leftLimit])
        {
            //#####
            indicesPrint[l] = 45;
            //##

            l++;

            //#####
            indicesPrint[l] = 108;
            printf("\33\[u\33\[4B");
            for(i = 0; i < rightLimit+1; i++)
                printf(" %3c  ", indicesPrint[i]);

            sleep(sleepDuration);
            //##
        }

        while(r > leftLimit && numbersToSort[r] >= numbersToSort[leftLimit])
        {
            //#####
            indicesPrint[r]=45;
            //##

            r--;

            //#####
            indicesPrint[r]=114;
            printf("\33\[u\33\[4B");
            for(i = 0; i < rightLimit+1; i++)
                printf(" %3c  ", indicesPrint[i]);

            sleep(sleepDuration);
            //##
        }

        if(l < r)
        {
            tempNum = numbersToSort[l];
            numbersToSort[l] = numbersToSort[r];
            numbersToSort[r] = tempNum;

            //#####
            tempPivPos = indicesPrint[l];
            indicesPrint[l] = indicesPrint[r];
            indicesPrint[r] = tempPivPos;

            printf("\33\[u");
            for(i = 0; i < rightLimit+1; i++)
                printf(" %3d  ", numbersToSort[i]);

            printf("\33\[u\33\[4B");
            for(i = 0; i < rightLimit+1; i++)
                printf(" %3c  ", indicesPrint[i]);

            sleep(sleepDuration);
            //##
        }
    }

    if(numbersToSort[r] < numbersToSort[leftLimit])
    {
        tempNum = numbersToSort[r];
        numbersToSort[r] = numbersToSort[leftLimit];
        numbersToSort[leftLimit] = tempNum;

        //#####
        printf("\33\[u");
        for(int i = 0; i < rightLimit+1; i++)
            printf(" %3d  ", numbersToSort[i]);

        indicesPrint[r] = 45;
        printf("\33\[u\33\[4B");
        for(i = 0; i < rightLimit+1; i++)
            printf(" %3c  ", indicesPrint[i]);

        sleep(sleepDuration);
        //##
    }

    return r;  // r = sortedPivotPos
}


void printPivotLine(int* pivotPrint, int leftLimit, int arraySize)
{
    int i;
    for(i = 0; i < arraySize; i++)
        pivotPrint[i] = 45;

    pivotPrint[leftLimit] = 80;

    printf("\33\[u\33\[2B");
    for(i = 0; i < arraySize; i++)
        printf(" %3c  ", pivotPrint[i]);
}

void printInitialIndicesLine(int* indicesPrint, int arraySize, int leftIndex, int rightIndex)
{
    int i;
    for(i = 0; i < arraySize; i++)
        indicesPrint[i] = 45;

    indicesPrint[leftIndex] = 108;
    indicesPrint[rightIndex] = 114;

    printf("\33\[u\33\[4B");
    for(i = 0; i < arraySize; i++)
        printf(" %3c  ", indicesPrint[i]);
}
