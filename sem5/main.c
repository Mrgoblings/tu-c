//
// Created by valer on 23-Apr-26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void task1() {
    int g_cnt = 0;
    do {
        printf("Enter guest count: ");
        scanf("%d", &g_cnt);
    } while (g_cnt <= 0);
    char comm[50];
    int chairs = 0, tables = 0, cups = 0, dishes = 0;

    while (1) {
        printf("Enter command: ");
        scanf("%s", comm);

        if (strcmp(comm, "Table") == 0) {
            tables++;
        } else if (strcmp(comm, "Chair") == 0) {
            chairs++;
        } else if (strcmp(comm, "Cups") == 0) {
            cups++;
        } else if (strcmp(comm, "Dishes") == 0) {
            dishes++;
        }
        if (strcmp(comm, "PARTY!") == 0) {
            break;
        }
    }
    float price = 0;
    price = chairs * 13.99 + tables * 42.00 + cups * 5.98 + dishes * 21.02;
    if (chairs >= g_cnt) {
        chairs = 0;
    } else chairs = g_cnt - chairs;
    int cups_temp = 0;
    if (cups * 6 >= g_cnt) cups = 0;
    else {
        cups = g_cnt - cups * 6;

        while (cups > 0) {
            cups_temp++;
            cups -= 6;
        }
    }
    int tables_temp = 0;
    if (tables * 8 >= g_cnt) tables = 0;
    else {
        tables = g_cnt - tables * 8;

        while (tables > 0) {
            tables_temp++;
            tables -= 8;
        }
    }
    int dishes_temp = 0;
    if (dishes * 6 >= g_cnt) dishes = 0;
    else {
        dishes = g_cnt - dishes * 6;

        while (dishes > 0) {
            dishes_temp++;
            dishes -= 6;
        }
    }

    printf("Price: %.2f\n", price);
    printf("Chairs: %d\n", chairs);
    printf("Tables: %d\n", tables_temp);
    printf("Dishes: %d\n", dishes_temp);
    printf("Cups: %d\n", cups_temp);
}

typedef struct Product {
    char name[120];
    float price;
    int id;
} Product;

typedef struct Order {
    char addr[120];
    int product_id;
} Order;

void task2() {
    Product product[50];
    Order order[50];
    int p_cnt = 0, o_cnt = 0;


    while (1) {
        char option = ' ';
        printf("P - Product, O - order, E - EXIT\nChoose an option: ");
        scanf("%c", &option);

        switch (option) {
            case 'P':
                printf("Enter product name: ");
                scanf("%s", product[p_cnt].name);
                printf("Enter product price: ");
                scanf("%f", &product[p_cnt].price);
                printf("Enter product id: ");
                scanf("%d", &product[p_cnt].id);

                for (int i = 0; i < o_cnt; i++) {
                    if (order[i].product_id == product[p_cnt].id) {
                        printf("Client %s ordered %s\n", order[i].addr, product[p_cnt].name);
                        for (int j = i; j < o_cnt - 1; j++) {
                            order[j] = order[j + 1];
                        }
                        p_cnt--;
                    }
                }
                p_cnt++;
                break;

            case 'O':
                printf("Enter address: ");
                scanf("%s", order[o_cnt].addr);
                printf("Enter product id: ");
                scanf("%d", &order[o_cnt].product_id);

                for (int i = 0; i < p_cnt; i++) {
                    if (order[o_cnt].product_id == product[i].id) {
                        printf("Client %s ordered %s\n", order[o_cnt].addr, product[i].name);
                        for (int j = i; j < p_cnt - 1; j++) {
                            product[j] = product[j + 1];
                        }
                        o_cnt--;
                    }
                }
                o_cnt++;
                break;
            case 'E':
                return;

            default:
                printf("Invalid option\n");
        }
    }
}

void task3() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Can't open input file\n");
        return;
    }

    int words_cnt = 0;
    char **words = NULL;
    char temp_word[51];

    if (fscanf(fp, "%s", temp_word) != EOF) {
        words_cnt = 1;
        words = (char **) malloc(sizeof(char *) * words_cnt);
        words[0] = strdup(temp_word);
    }

    while (fscanf(fp, "%s", temp_word) != EOF) {
        char *prev_word = NULL;
        if (words != NULL) {
            prev_word = words[words_cnt - 1];
            if (prev_word[strlen(prev_word) - 1] == temp_word[0]) {
                char **temp_ptr = (char **) realloc(words, (words_cnt + 1) * sizeof(char *));
                if (temp_ptr != NULL) {
                    words = temp_ptr;
                    words[words_cnt] = strdup(temp_word);
                    words_cnt++;
                }
            }
        }
    }
    fclose(fp);

    FILE *bin_out = fopen("result.bin", "wb");
    if (bin_out) {
        for (int i = 0; i < words_cnt; i++) {
            if (words != NULL) fwrite(words[i], sizeof(char), strlen(words[i]), bin_out);
            if (i < words_cnt - 1) {
                char space = ' ';
                fwrite(&space, sizeof(char), 1, bin_out);
            }
        }
        fclose(bin_out);
    }

    printf("Content of binary file:\n");
    FILE *bin_in = fopen("result.bin", "rb");
    if (bin_in) {
        char c;
        while (fread(&c, sizeof(char), 1, bin_in) == 1) {
            printf("%c", c);
        }
        fclose(bin_in);
        printf("\n");
    }

    for (int i = 0; i < words_cnt; i++) {
        if (words != NULL)
            free(words[i]);
    }
    free(words);
}

void task4() {
    char input_filename[100];
    int key = 0;

    printf("Enter the name of the file to encode: ");
    scanf("%s", input_filename);

    do {
        printf("Enter encoding key (between 2 and 10): ");
        scanf("%d", &key);
    } while (key < 2 || key > 10);

    FILE *src = fopen(input_filename, "r");
    if (src == NULL) {
        printf("Error: Could not open source file.\n");
        return;
    }

    FILE *dest = fopen("encoded_output.txt", "w");
    if (dest == NULL) {
        printf("Error: Could not create output file.\n");
        fclose(src);
        return;
    }

    int ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch + key, dest);
    }

    fclose(src);
    fclose(dest);
}

void task5() {
    char secretWord[] = "concatenation";
    int length = strlen(secretWord);
    char hiddenWord[length + 1];
    int attempts = 0;
    int revealed = 0;
    char guess;

    for (int i = 0; i < length; i++) {
        hiddenWord[i] = '_';
    }
    hiddenWord[length] = '\0';

    while (revealed < length && attempts < length + 2) {
        printf("\nWord: ");
        for (int i = 0; i < length; i++) {
            printf("%c ", hiddenWord[i]);
        }

        printf("\nEnter a letter: ");
        scanf(" %c", &guess);
        attempts++;

        for (int i = 0; i < length; i++) {
            if (secretWord[i] == guess && hiddenWord[i] == '_') {
                hiddenWord[i] = guess;
                revealed++;
            }
        }
    }

    if (attempts < length + 2) {
        printf("YOU WIN!\n");
    } else {
        printf("YOU LOST! You took too many attempts.\n");
    }
}

int is_anagram(const char *str1, const char *str2) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    int counts[256] = {0};

    for (int i = 0; str1[i] != '\0'; i++) {
        counts[str1[i]]++;
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        counts[str2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (counts[i] != 0) {
            return 0;
        }
    }

    return 1;
}

void task6() {
    char word1[100], word2[100];

    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);

    if (is_anagram(word1, word2)) {
        printf("They are anagrams\n");
    } else {
        printf("Not anagrams\n");
    }
}

typedef struct {
    int id;
    float hourly_rate;
    float hours;
    float weekly_salary;
} Employee;

float calculate_net_salary(float hours, float rate) {
    float gross;
    if (hours <= 40) {
        gross = hours * rate;
    } else {
        gross = (40 * rate) + ((hours - 40) * rate * 1.5);
    }
    return gross - (gross * 0.0365);
}

void add_employee() {
    FILE *fp = fopen("staff.bin", "ab");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    Employee e;
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Hourly Rate: ");
    scanf("%f", &e.hourly_rate);
    printf("Enter Hours Worked: ");
    scanf("%f", &e.hours);

    e.weekly_salary = calculate_net_salary(e.hours, e.hourly_rate);

    fwrite(&e, sizeof(Employee), 1, fp);
    fclose(fp);
}

void display_salaries() {
    FILE *fp = fopen("staff.bin", "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    Employee e;
    printf("\nWeekly Salary Report:\n");
    while (fread(&e, sizeof(Employee), 1, fp)) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", e.id, e.hourly_rate, e.hours, e.weekly_salary);
    }
    fclose(fp);
}

void task7() {
    int choice;

    while (1) {
        printf("\n1. Add New Employee\n");
        printf("2. Display Weekly Salaries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_salaries();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Task 1: Product Structure Basics\n");
        printf("2. Task 2: Bakery Order Management\n");
        printf("3. Task 3: Word Chain (Binary File)\n");
        printf("4. Task 4: File Encoder (Caesar Cipher)\n");
        printf("5. Task 5: Hangman Game\n");
        printf("6. Task 6: Anagram Checker\n");
        printf("7. Task 7: Employee Payroll System\n");
        printf("0. Exit\n");
        printf("Choose a task: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
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
                task7();
                break;
            case 0:
                return 0;
            default:
                printf("Option not available. Try again.\n");
                break;
        }
    }
}
