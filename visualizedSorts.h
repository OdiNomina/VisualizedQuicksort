/*
* ANSI-Steuerzeichen und Sequenzen:
* \33\[2A => Cursor 2 Zeilen nach oben
* \33\[2B => Cursor 2 Zeilen nach unten
* \33\[s => Aktuelle Cursorposition speichern
* \33\[u => Cursor auf die gespeicherte Position setzen
*/

void visualizedQuicksort(int *numbersToSort, int leftLimit, int rightLimit, int *pivotPrint, int *indicesPrint, int *sortedPrint)
{
    if(leftLimit < rightLimit)
    {
        sleep(2);
        int sortedPivotPos = sortPivotToCorrectPos(&numbersToSort[0], leftLimit, rightLimit, &pivotPrint[0], &indicesPrint[0]);

        sortedPrint[sortedPivotPos] = 83;
        printf("\33\[u\33\[6B");
        for(int i=0; i<rightLimit+1; i++)
            printf(" %3c  ", sortedPrint[i]);
        sleep(2);

        visualizedQuicksort(&numbersToSort[0], leftLimit, sortedPivotPos-1, pivotPrint, indicesPrint, sortedPrint);
        visualizedQuicksort(&numbersToSort[0], sortedPivotPos+1, rightLimit, pivotPrint, indicesPrint, sortedPrint);
    }
}


int sortPivotToCorrectPos(int *numbersToSort, int leftLimit, int rightLimit, int *pivotPrint, int *indicesPrint)
{
    //##### Quicksort Funktionalität
    int pivotValue = numbersToSort[leftLimit];
    int i = leftLimit+1;
    int j = rightLimit;
    int tempNum;
    //#####

    int n, tempPivPos;

    for(n=0; n<rightLimit+1; n++)
        pivotPrint[n] = 45;

    pivotPrint[leftLimit] = 80;

    printf("\33\[u\33\[2B");
    for(n=0; n<rightLimit+1; n++)
        printf(" %3c  ", pivotPrint[n]);
    /*
    for(n=0; n<rightLimit+1; n++)
        indicesPrint[n] = 45;

    indicesPrint[i] = 105;
    indicesPrint[j] = 106;

    printf("\33\[u\33\[4B");
    for(n=0; n<rightLimit+1; n++)
        printf(" %3c  ", indicesPrint[n]);
    */
    sleep(2);

    while(i < j)
    {
        while(i < rightLimit && numbersToSort[i] <= pivotValue)
        {
            indicesPrint[i] = 45;

            //##### Quicksort Funktionalität
            i++;
            //#####
            /*
            indicesPrint[i] = 105;

            printf("\33\[u\33\[4B");
            for(n=0; n<rightLimit+1; n++)
                printf(" %3c  ", indicesPrint[n]);

            sleep(2);
            */
        }

        while(j > leftLimit && numbersToSort[j] > pivotValue)
        {
            indicesPrint[j]=45;

            //##### Quicksort Funktionalität
            j--;
            //#####
            /*
            indicesPrint[j]=106;

            printf("\33\[u\33\[4B");
            for(n=0; n<rightLimit+1; n++)
                printf(" %3c  ", indicesPrint[n]);

            sleep(2);
            */
        }

        if(i < j)
        {
            //##### Quicksort Funktionalität
            tempNum = numbersToSort[i];
            numbersToSort[i] = numbersToSort[j];
            numbersToSort[j] = tempNum;
            //#####

            printf("\33\[u");
            for(n=0; n<rightLimit+1; n++)
                printf(" %3d  ", numbersToSort[n]);
            /*
            tempPivPos = indicesPrint[i];
            indicesPrint[i] = indicesPrint[j];
            indicesPrint[j] = tempPivPos;

            printf("\33\[u\33\[4B");
            for(n=0; n<rightLimit+1; n++)
                printf(" %3c  ", indicesPrint[n]);
            */
            sleep(2);
        }
    }

    if(numbersToSort[j] < pivotValue)
    {
        //##### Quicksort Funktionalität
        tempNum = numbersToSort[j];
        numbersToSort[j] = numbersToSort[leftLimit];
        numbersToSort[leftLimit] = tempNum;
        //#####

        printf("\33\[u");
        for(n=0; n<rightLimit+1; n++)
            printf(" %3d  ", numbersToSort[n]);

        /*
        tempPivPos = indicesPrint[j];
        indicesPrint[j] = indicesPrint[leftLimit];
        indicesPrint[leftLimit] = tempPivPos;

        printf("\33\[u\33\[4B");
        for(n=0; n<rightLimit+1; n++)
            printf(" %3c  ", indicesPrint[n]);
        */
        sleep(2);
    }

    return j;
}
