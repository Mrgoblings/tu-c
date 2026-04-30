#include <stdio.h>
#include <stdlib.h>


int **input_array(int *n, int *m) {
    *m = 0;
    *n = 0;
    do {
        printf("Enter n: ");
        scanf("%d", n);
        printf("Enter m: ");
        scanf("%d", m);
    } while (*n < 0 || *m < 0);
    int **array = (int **) malloc(sizeof(int *) * (*n));
    for (int i = 0; i < (*n); i++) {
        array[i] = (int *) malloc(sizeof(int) * (*m));
    }
    for (int i = 0; i < (*n); i++) {
        for (int j = 0; j < (*m); j++) {
            printf("Enter number: ");
            scanf("%d", &array[i][j]);
        }
    }
    return array;
}

void free_array(int **array, int n) {
    if (array != NULL) {
        for (int i = 0; i < n; i++) {
            free(array[i]);
        }
        free(array);
    }
}

void task1(int **array, int n, int m) {
    if (array) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (array[i][j] > array[i][j + 1]) {
                    printf("Rows are not growing\n");
                    return;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (array[j][i] < array[j + 1][i]) {
                    printf("Cols are not descending\n");
                    return;
                }
            }
        }
        printf("Rows are growing and cols are descending\n");
    }
}

void task2(int **array, int n, int m) {
    if (array) {
        int max_sum = 0;
        int sum = 0;
        int number = array[0][0];
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    sum += array[i - 1][j];
                }
                if (i < n - 1) {
                    sum += array[i + 1][j];
                }
                if (j > 0) {
                    sum += array[i][j - 1];
                }
                if (j < m - 1) {
                    sum += array[i][j + 1];
                }
                if (i > 0 && j > 0) {
                    sum += array[i - 1][j - 1];
                }
                if (i < n - 1 && j > 0) {
                    sum += array[i + 1][j - 1];
                }
                if (i > 0 && j < m - 1) {
                    sum += array[i - 1][j + 1];
                }
                if (i < n - 1 && j < m - 1) {
                    sum += array[i + 1][j + 1];
                }

                if (sum > max_sum) {
                    max_sum = sum;
                    number = array[i][j];
                }
            }
        }
        printf("Max sum of neighbours is: %d and the number is: %d\n", max_sum, number);
    }
}

void task3(int **array, int n, int m) {
    if (array) {
        int min = array[0][0];
        int max = array[0][0];
        int row_min = 0;
        int row_max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (array[i][j] < min) {
                    min = array[i][j];
                    row_min = i;
                }
                if (array[i][j] > max) {
                    max = array[i][j];
                    row_max = i;
                }
            }
        }
        printf("Row min: %d and row max: %d\n", row_min, row_max);
    }
}

void task4() {
    int n, m;
    do {
        printf("Enter n: ");
        scanf("%d", &n);
        printf("Enter m: ");
        scanf("%d", &m);
    } while (n < 0 || m < 0 || n > 10000 || m > 1000000);
    int *friends_count = (int *) calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Friend: ");
        scanf("%d", &u);
        printf("is friends with: ");
        scanf("%d", &v);
        friends_count[u]++;
        friends_count[v]++;
    }
    int person;
    printf("Enter person number: ");
    scanf("%d", &person);
    if (person >= 1 && person <= n) {
        printf("Friends count: %d\n", friends_count[person]);
    }
    free(friends_count);
}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void task5() {
    int *arr = NULL;
    int size = 0, cmd, x;

    while (1) {
        printf("Enter command (1:add, 2:del, 3:small, 0:exit): ");
        if (scanf("%d", &cmd) != 1 || cmd == 0) break;

        printf("Enter x: ");
        scanf("%d", &x);

        if (cmd == 1) {
            int *temp = realloc(arr, (size + 1) * sizeof(int));
            if (temp != NULL) {
                arr = temp;
                arr[size] = x;
                size++;
            }
        } else if (cmd == 2) {
            int new_count = 0;
            if (arr)
                for (int i = 0; i < size; i++) {
                    if (arr[i] != x) new_count++;
                }

            if (new_count == 0) {
                free(arr);
                arr = NULL;
                size = 0;
            } else {
                int *new_arr = (int *) malloc(new_count * sizeof(int));
                if (new_arr != NULL) {
                    int k = 0;
                    if (arr)
                        for (int i = 0; i < size; i++) {
                            if (arr[i] != x) new_arr[k++] = arr[i];
                        }
                    free(arr);
                    arr = new_arr;
                    size = new_count;
                }
            }
        } else if (cmd == 3) {
            if (x > 0 && x <= size) {
                int *s = malloc(size * sizeof(int));
                if (s != NULL) {
                    if (arr)
                        for (int i = 0; i < size; i++) s[i] = arr[i];

                    for (int i = 0; i < size - 1; i++) {
                        for (int j = 0; j < size - i - 1; j++) {
                            if (s[j] > s[j + 1]) {
                                int t = s[j];
                                s[j] = s[j + 1];
                                s[j + 1] = t;
                            }
                        }
                    }
                    printf("Smallest: %d\n", s[x - 1]);
                    free(s);
                }
            } else {
                printf("Invalid position\n");
            }
        }
    }
    free(arr);
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void task6() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    int *primes = malloc(n * sizeof(int));
    int p_idx = 0, r_idx = 0;
    for (int i = 0; i < n; i++) {
        int val;
        printf("Enter number: ");
        scanf("%d", &val);
        if (is_prime(val)) primes[p_idx++] = val;
        else arr[r_idx++] = val;
    }
    printf("Remaining: ");
    for (int i = 0; i < r_idx; i++) printf("%d ", arr[i]);
    printf("\nPrimes: ");
    for (int i = 0; i < p_idx; i++) printf("%d ", primes[i]);
    printf("\n");
    free(arr);
    free(primes);
}

void task7(int **array, int n, int m) {
    if (array) {
        int max_sum = 0, bi = 0, bj = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                int current_sum = 0;
                for (int r = i; r < i + 3; r++)
                    for (int c = j; c < j + 3; c++) current_sum += array[r][c];
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    bi = i;
                    bj = j;
                }
            }
        }
        for (int i = bi; i < bi + 3; i++) {
            for (int j = bj; j < bj + 3; j++) printf("%d ", array[i][j]);
            printf("\n");
        }
    }
}

void task8() {
    int size = 10;
    int *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < 10; i++) {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    int num, pos;
    while (1) {
        printf("Enter number: ");
        scanf("%d", &num);
        if (num == 0) break;
        printf("Enter position: ");
        scanf("%d", &pos);
        if (pos < 0 || pos > size) {
            printf("Invalid position!\n");
            continue;
        }

        int *temp = realloc(arr, (size + 1) * sizeof(int));
        if (temp != NULL) {
            arr = temp;
            for (int i = size; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = num;
            size++;
        }
    }

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

int main() {
    int n, m, choice;
    int **arr = NULL;
    do {
        printf("\n--- Task Selector ---\n");
        printf("1. Check rows and cols (Task 1)\n");
        printf("2. Max sum of neighbours (Task 2)\n");
        printf("4. Friends count (Task 4)\n");
        printf("5. Child software (Task 5)\n");
        printf("6. Primes filter (Task 6)\n");
        printf("7. 3x3 Submatrix sum (Task 7)\n");
        printf("8. Index insertion (Task 8)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                arr = input_array(&n, &m);
                task1(arr, n, m);
                free_array(arr, n);
                arr = NULL;
                break;
            case 2:
                arr = input_array(&n, &m);
                task2(arr, n, m);
                free_array(arr, n);
                arr = NULL;
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                arr = input_array(&n, &m);
                task7(arr, n, m);
                free_array(arr, n);
                arr = NULL;
                break;
            case 8:
                task8();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
    free_array(arr, n);
    return 0;
}
