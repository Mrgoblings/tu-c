#include <stdio.h>
#include <stdlib.h>
//
// Created by valer on 26-Mar-26.
//
double *inputArrayDouble(int *size) {
    do {
        printf("Enter number of elements >0: ");
        scanf("%d", size);
    } while (size <= 0);

    if (size == NULL) { return NULL; }
    double *array = (double *) malloc(*size * sizeof(double));
    for (int i = 0; i < *size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%lf", &array[i]);
    }

    return array;
}

int *inputArrayInt(int *size) {
    do {
        printf("Enter number of elements >0: ");
        scanf("%d", size);
    } while (size <= 0);

    if (size == NULL) { return NULL; }
    int *array = (int *) malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    return array;
}

void freeArrayDouble(double **array) {
    free(*array);
}

void freeArrayInt(int **array) {
    free(*array);
}

void task1() {
    int *size = (int *) malloc(sizeof(int));
    double *array = inputArrayDouble(size);
    double maxMetNum = 0;
    int lastMaxLen = 0;
    int maxLen = 1;
    double lastMet = array[0];
    maxMetNum = array[0];
    for (int i = 1; i < *size; i++) {
        if (array[i] == lastMet) {
            maxLen++;
        } else {
            if (maxLen > lastMaxLen) {
                lastMaxLen = maxLen;
                maxMetNum = array[i - 1];
            }
            lastMet = array[i];
            maxLen = 1;
        }
    }
    if (maxLen > lastMaxLen) {
        lastMaxLen = maxLen;
    }


    printf("The most met number is %.2f and is met %d times.\n", maxMetNum, lastMaxLen);

    free(size);
    freeArrayDouble(&array);
}

void task2() {
    int *size = (int *) malloc(sizeof(int));
    double *array = inputArrayDouble(size);

    if (size == NULL || *size < 2) {
        printf("Invalid array size!\n");
        free(size);
        freeArrayDouble(&array);
        return;
    }

    for (int i = 1; i < *size; i++) {
        if (i % 2 != 0) {
            if ((array[i] > array[i - 1] && (i + 1) > *size) || (array[i] > array[i - 1] && array[i + 1] < array[i])) {
                continue;
            }
            printf("Condition a0<a1>a2 is not met!\n");
            free(size);
            freeArrayDouble(&array);
            return;
        }
    }
    printf("Condition a0<a1>a2 is met!\n");

    free(size);
    freeArrayDouble(&array);
}

void task3() {
    int *size = (int *) malloc(sizeof(int));
    double *array = inputArrayDouble(size);
    double *array2 = (double *) malloc(*size * sizeof(double));

    for (int i = 0; i < *size; i++) {
        array2[i] = array[*size - i - 1];
        printf("%.2f ", array2[i]);
    }

    freeArrayDouble(&array2);
    free(size);
    freeArrayDouble(&array);
}

void task4() {
    int *size = (int *) malloc(sizeof(int));
    int *array = inputArrayInt(size);
    int k;
    do {
        printf("Enter k>0: ");
        scanf("%d", &k);
    } while (k <= 0);

    for (int i = 0; i < k; i++) {
        int last = array[*size - 1];
        for (int j = *size - 1; j > 0; j--) {
            array[j] = array[j - 1];
        }
        array[0] = last;
    }

    for (int i = 0; i < *size; i++) {
        printf("%d ", array[i]);
    }

    free(size);
    freeArrayInt(&array);
}

void task5() {
    int *size = (int *) malloc(sizeof(int));
    int *array = inputArrayInt(size);
    int k;
    do {
        printf("Enter k>0: ");
        scanf("%d", &k);
    } while (k <= 0);

    for (int i = 0; i < *size - 1; i++) {
        for (int j = 0; j < *size; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    int lastEl = array[*size - 1];
    for (int i = *size - 2; i >= 0; i--) {
        if (array[i] == lastEl) { continue; }
        k--;
        if (k == 1) {
            printf("The k lagerst number is %d.\n", array[i]);
            free(size);
            freeArrayInt(&array);
            return;
        }
    }
    printf("There is no k largest number!\n");
    free(size);
    freeArrayInt(&array);
}

void task6() {
    int *size = (int *) malloc(sizeof(int));
    int *array = inputArrayInt(size);

    int largestGrowing = 1;
    int largestDescending = 1;
    int lastLargestGrowing = 1;
    int lastLargestDescending = 1;
    int growingInx = 0;
    int descendingInx = 0;

    for (int i = 0; i < *size - 1; i++) {
        if (array[i] < array[i + 1]) {
            largestGrowing++;
            largestDescending = 1;
            if (largestGrowing > lastLargestGrowing) {
                lastLargestGrowing = largestGrowing;
                growingInx = i + 1;
            }
        } else if (array[i] > array[i + 1]) {
            largestDescending++;
            largestGrowing = 1;
            if (largestDescending > lastLargestDescending) {
                lastLargestDescending = largestDescending;
                descendingInx = i + 1;
            }
        } else {
            largestGrowing = 1;
            largestDescending = 1;
        }
    }

    if (lastLargestDescending > lastLargestGrowing) {
        printf("The largest descending subarray is %d in length: ", lastLargestDescending);
        for (int i = descendingInx - lastLargestDescending + 1; i <= descendingInx; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("The largest growing subarray is %d in length: ", lastLargestGrowing);
        for (int i = growingInx - lastLargestGrowing + 1; i <= growingInx; i++) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");

    free(size);
    freeArrayInt(&array);
}

void task7() {
    int *size = (int *) malloc(sizeof(int));
    int *array = inputArrayInt(size);
    int k;
    int idxs = 1;
    printf("Enter k: ");
    scanf("%d", &k);

    for (int i = 0; i < *size - 1; i++) {
        int sum = array[i];
        for (int j = i + 1; j < *size - 1; j++) {
            sum += array[j];
            if (sum > k)
                break;
            if (sum == k) {
                for (int l = i; l <= j; l++) {
                    printf("%d ", array[l]);
                }
                free(size);
                freeArrayInt(&array);
                return;
            }
        }
    }

    free(size);
    freeArrayInt(&array);
}

void task8() {
    int *array = (int *)malloc(20 * sizeof(int));
    int currentSize = 10;

    for (int i = 0; i < 10; i++) {
        printf("Eneter number: ");
        scanf("%d", &array[i]);
    }

    while (currentSize < 20) {
        int value, pos;
        printf("Eneter value: ");
        scanf("%d", &value);

        if (value == 0) {
            break;
        }

        printf("Eneter pos: ");
        scanf("%d", &pos);

        if (pos >= 0 && pos <= currentSize) {
            for (int i = currentSize; i > pos; i--) {
                array[i] = array[i - 1];
            }
            array[pos] = value;
            currentSize++;
        }
    }

    for (int i = 0; i < currentSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}

void task9() {
    int *size = (int *) malloc(sizeof(int));
    int *array = inputArrayInt(size);

    int bestLength = 0;
    int startIdx = 0;

    for (int i = 0; i < *size; i++) {
        int length = 0;
        for (int j = i; j < *size; j++) {
            if (array[j] == array[i]) {
                length++;
            } else {
                break;
            }
        }

        if (length > bestLength) {
            bestLength = length;
            startIdx = i;
        }
    }

    for (int i = startIdx; i < startIdx + bestLength; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(size);
    freeArrayInt(&array);
}


int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("Choose a task (1-9) or 0 to exit: ");
        scanf("%d", &choice);


        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 9.\n");
        }
    }

    printf("Exiting program...\n");
    return 0;
}