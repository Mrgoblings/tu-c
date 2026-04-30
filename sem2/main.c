#include <stdio.h>
#include <math.h>

float inputNumber()
{
    float n;
    printf("Input number: ");
    scanf("%f", &n);
    return n;
}

int inputInteger()
{
    int n;
    printf("Input a whole number: ");
    scanf("%d", &n);
    return n;
}

int inputValidateInt(int min, int max)
{
    int n;
    do
    {
        printf("Enter a number between %d and %d: ", min, max);
        scanf("%d", &n);
    } while (n >= min && n <= max);
    return n;
}

float getMin(float a, float b) {
    if (a < b) {
        return a;
    }
    return b;
}

float getMax(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}

void demonstrateMinMax() {
    float current_num = inputNumber();
    
    if (current_num == 0) {
        printf("No numbers to evaluate.\n\n");
        return;
    }

    float min = current_num;
    float max = current_num;

    while (1) {
        current_num = inputNumber();
        
        if (current_num == 0) {
            break; 
        }

        min = getMin(min, current_num);
        max = getMax(max, current_num);
    }

    printf("%.2f is the smallest number you entered.\n", min);
    printf("%.2f is the largest number you entered.\n\n", max);
}

void showAfter15Min()
{
    int h, m;
    h = inputValidateInt(0, 23);
    m = inputValidateInt(0, 59);

    if ((m + 15) >= 60)
    {
        m = m + 15 - 60;
        h++;
    }
    else
    {
        m += 15;
    }
    if (h > 23)
    {
        h = 0;
    }

    if (m < 10)
    {
        printf("In 15 min it is going to be %d:0%d\n\n", h, m);
    }
    else
    {
        printf("In 15 min it is going to be %d:%d\n\n", h, m);
    }
}

void are3NumbersTheSame()
{
    int a, b, c;
    a = inputNumber();
    b = inputNumber();
    c = inputNumber();

    if (a == b && b == c)
    {
        printf("The numbers are the same\n\n");
    }
    else
    {
        printf("The numbers are not the same\n\n");
    }
}

void calcBonusPoints()
{
    int points = inputInteger();
    float bonus = 0;

    if (points <= 100)
    {
        bonus += 5;
    }
    else if (points > 100 && points <= 1000)
    {
        bonus += 0.2 * points;
    }
    else if (points > 1000)
    {
        bonus += 0.1 * points;
    }

    if (points % 2 == 0)
    {
        bonus += 1;
    }
    if (points % 10 == 5)
    {
        bonus += 2;
    }

    printf("Bonus points are %.2f, all points are %d.\n\n", bonus, (int)bonus + points);
}

void finishTime()
{
    int a, b, c;
    a = inputValidateInt(1, 50);
    b = inputValidateInt(1, 50);
    c = inputValidateInt(1, 50);

    int s = (a + b + c) % 60;
    int m = (a + b + c) / 60;

    if (s < 10)
    {
        printf("In 15 min it is going to be %d:0%d\n\n", m, s);
    }
    else
    {
        printf("In 15 min it is going to be %d:%d\n\n", m, s);
    }
}

void pointInsideARectangle()
{
    int x1, x2, y1, y2, x, y;
    printf("x2: ");
    x2 = inputInteger();
    printf("y2: ");
    y2 = inputInteger();
    printf("x1<x2: ");
    x1 = inputValidateInt(-999999999, x2 - 1);
    printf("y1<y2: ");
    y1 = inputValidateInt(-999999999, y2 - 1);
    printf("x: ");
    x = inputInteger();
    printf("y: ");
    y = inputInteger();

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
    {
        printf("Inside");
    }
    else
    {
        printf("Outside");
    }
}

void calcTransportPrice()
{
    int n = inputInteger();
    char t;
    printf("Enter D-day, N-night: ");
    scanf("%c", &t);

    float price = 0;

    if (n < 20)
    {
        if (t == 'D')
        {
            price += n * 0.79;
        }
        else if (t == 'N')
        {
            price += n * 0.90;
        }
        price += 0.7;
    }
    else if (n >= 20 && n <= 100)
    {
        price += n * 0.09;
    }
    else if (n > 100)
    {
        price += n * 0.06;
    }

    printf("Lowest transport price is: %.2f\n\n", price);
}

void poolFill()
{
    printf("V: ");
    int v = inputInteger();
    printf("N hours: ");
    int n = inputInteger();
    printf("P1: ");
    int p1 = inputInteger();
    printf("P2: ");
    int p2 = inputInteger();

    float fill = (p1 + p2) * n;
    float cap = v * 1000.0;

    printf("The pool will be %.2f percent full.\n\n", (fill / cap) * 100);
}

void wine()
{
    printf("X: ");
    float x = inputNumber();
    printf("Y: ");
    float y = inputNumber();
    printf("Z: ");
    float z = inputNumber();
    printf("Workers: ");
    int w = inputInteger();

    float wine = x * y * 0.4 / 2.5;

    if (wine >= z)
    {
        printf("The wine is enough and every worker recieves: %.2f liters of wine.\n\n", (wine - z) / (float)w);
    }
    else
    {
        printf("The wine is not enough.\n\n");
    }
}

void percents()
{
    int n = inputInteger();
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;

    for (int i = 0; i < n; i++)
    {
        float num = inputNumber();

        if (num < 200)
        {
            c1++;
        }
        else if (num >= 200 && num <= 399)
        {
            c2++;
        }
        else if (num >= 400 && num <= 599)
        {
            c3++;
        }
        else if (num >= 600 && num <= 799)
        {
            c4++;
        }
        else if (num >= 800)
        {
            c5++;
        }
    }

    printf("p1: %.2f%%\n", (c1 * 100.0) / n);
    printf("p2: %.2f%%\n", (c2 * 100.0) / n);
    printf("p3: %.2f%%\n", (c3 * 100.0) / n);
    printf("p4: %.2f%%\n", (c4 * 100.0) / n);
    printf("p5: %.2f%%\n", (c5 * 100.0) / n);
}

void drawCastle()
{
    int n = inputInteger();

    printf("/");
    for (int i = 0; i < floor(n / 2); i++)
        printf("^");
    printf("\\");

    for (int i = 0; i < n * 2 - (2 * floor(n / 2)) - 4; i++)
        printf("_");

    printf("/");
    for (int i = 0; i < floor(n / 2); i++)
        printf("^");
    printf("\\");

    for (int i = 0; i < n - 2 - 1; i++)
    {
        printf("\n|");
        for (int j = 0; j < 2 * n - 2; j++)
        {
            printf(" ");
        }
        printf("|");
    }

    printf("\n|");
    for (int i = 0; i < floor(n / 2) + 1; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < n * 2 - (2 * floor(n / 2)) - 4; i++)
        printf("_");
    for (int i = 0; i < floor(n / 2) + 1; i++)
    {
        printf(" ");
    }
    printf("|");

    printf("\n\\");
    for (int i = 0; i < floor(n / 2); i++)
        printf("_");
    printf("/");
    for (int i = 0; i < n * 2 - (2 * floor(n / 2)) - 4; i++)
        printf(" ");

    printf("\\");
    for (int i = 0; i < floor(n / 2); i++)
        printf("_");
    printf("/");
}

void drawButterfly()
{
    int n = inputInteger();

    for (int k = 0; k < 2 * (n - 2) / 2; k++)
    {
        printf("\n");
        if (k % 2 == 0)
        {
            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("*");
            }

            printf("\\ /");

            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("*");
            }
        }
        else
        {
            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("_");
            }

            printf("\\ /");

            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("_");
            }
        }
    }
    printf("\n");

    for (int i = 0; i < ((n * 2) - 3) / 2 + 1; i++)
    {
        printf(" ");
    }
    printf("@");
    for (int i = 0; i < ((n * 2) - 3) / 2 + 1; i++)
    {
        printf(" ");
    }

    for (int k = 0; k < 2 * (n - 2) / 2; k++)
    {
        printf("\n");
        if (k % 2 == 0)
        {
            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("*");
            }

            printf("\\ /");

            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("*");
            }
        }
        else
        {
            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("_");
            }

            printf("\\ /");

            for (int i = 0; i < ((n * 2) - 3) / 2; i++)
            {
                printf("_");
            }
        }
    }
}

int main()
{
    while (1)
    {
        int ch = 0;
        printf("\nEnter a choice(1-12) 13-Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            demonstrateMinMax();
            break;

        case 2:
            showAfter15Min();
            break;

        case 3:
            are3NumbersTheSame();
            break;

        case 4:
            calcBonusPoints();
            break;

        case 5:
            finishTime();
            break;

        case 6:
            pointInsideARectangle();
            break;

        case 7:
            calcTransportPrice();
            break;

        case 8:
            poolFill();
            break;

        case 9:
            wine();
            break;

        case 10:
            percents();
            break;

        case 11:
            drawCastle();
            break;

        case 12:
            drawButterfly();
            break;

        case 13:
            return 0;
        default:
            printf("invalid choice!\n");
            break;
        }
    }
    return 0;
}