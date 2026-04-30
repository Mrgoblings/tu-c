#include <stdio.h>
#include <math.h>

void print1_to_10()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i + 1);
    }
}

void print_triangle()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_cage()
{
    char c;
    printf("Enter symbol: ");
    scanf("%c", &c);

    for (int i = 0; i < 10; i++)
    {
        printf("%c", c);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%c", c);
        printf("        ");
        printf("%c", c);
        printf("\n");
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%c", c);
    }
}

void inch_to_val()
{
    float in;
    char conv;
    printf("Enter inches: ");
    scanf("%f", &in);

    while (1)
    {
        printf("Enter conv val(m = millimeters, c = cantimeter, d = decimeter, M = meters, e = exit): ");
        scanf("%c", &conv);
        float val;

        switch (conv)
        {
            case 'm':
                val = 25.4*in;
                break;

            case 'c':
                val = 2.54*in;
                break;

            case 'd':
                val = 0.254*in;
                break;

            case 'M':
                val = 0.0254*in;
                break;

            case 'e':
                return;
                break;

            default:
                printf("Invalid conversion value!\n");
                continue;
            }

        printf("%.2f inches is equal to %.2f of your chosen value.\n", in, val);

    }
}

void cel_to_fahr() {
    float temp;
    printf("Enter temp in celsius: ");
    scanf("%f", &temp);
    temp = temp*1.8 + 32;
    printf("The temp in F is: %.2f", temp);
}

void deg_to_rad() {
    float deg;
    printf("Enter deg: ");
    scanf("%f", &deg);
    deg = 3.14/180*deg;
    printf("In rad: %.2f", deg);
}

void lev_to_val() {
    float lev;
    printf("Enter lev: ");
    scanf("%f", &lev);

    printf("%.2f lev is %.2f euro\n", lev, lev*0.511292);
    printf("%.2f lev is %.2f pounds\n", lev, lev*0.511292*0.87);
    printf("%.2f lev is %.2f dollars\n", lev, lev*0.511292*1.16);
}

void trap_area() {
    float a, b, h;
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter h: ");
    scanf("%f", &h);

    printf("The area is: %.2f\n", (a+b)/2*h);
}

void angle_to_val() {
    float angle;
    printf("Enter angle: ");
    scanf("%f", &angle);

    angle = 3.14/180*angle;

    printf("Sin is %.2f\n", sin(angle));
    printf("Cos is %.2f\n", cos(angle));
    printf("Tanis %.2f\n", tan(angle));
    printf("Cotan is %.2f\n", 1/tan(angle));
}

void rect_area() {
    float ax, ay, bx, by;

    printf("Enter ax: ");
    scanf("%f", &ax);
    printf("Enter ay: ");
    scanf("%f", &ay);
    printf("Enter bx: ");
    scanf("%f", &bx);
    printf("Enter by: ");
    scanf("%f", &by);

    float a, b;
    a = abs(ax-bx);
    b = abs(ay-by);

    printf("The area is: %.2f\n", a*b);
}

void triangle_area() {
    float ax, ay, bx, by, cx, cy;

    printf("Enter ax: ");
    scanf("%f", &ax);
    printf("Enter ay: ");
    scanf("%f", &ay);
    printf("Enter bx: ");
    scanf("%f", &bx);
    printf("Enter by: ");
    scanf("%f", &by);
    printf("Enter cx: ");
    scanf("%f", &cx);
    printf("Enter cy: ");
    scanf("%f", &cy);

    if (ax==bx || ax==cx || bx==cx || ay==by || ay==cy || by==cy) {
        printf("Dots in one plane!\n");
        return;
    }

    float area = area = 0.5 * fabs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));

    printf("The area of the triangle is %.2f\n", area); 
}

void calculate_seats() {
    float w, h;
    printf("Enter w: ");
    scanf("%f", &w);
    printf("Enter h: ");
    scanf("%f", &h);

    float w1, h1;
    w1 = (w*100) - 100;
    h1 = h*100;

    //w-120 h-70

    int seats = floor(w1/120) * floor(h1/70);
    seats -= 3;
    printf("The seats are: %d", seats);
}

void shop() {
    float price_veg, price_fruit;
    int kg_veg, kg_fruit;
    float total_bgn, total_euro;

    if (scanf("%lf", &price_veg));
    if (scanf("%lf", &price_fruit));
    if (scanf("%d", &kg_veg));
    if (scanf("%d", &kg_fruit));

    total_bgn = (price_veg * kg_veg) + (price_fruit * kg_fruit);

    total_euro = total_bgn / 1.95;

    printf("%.2f\n", total_euro);
}

void tiles() {
    float n, w, l, m, o;
    float plot_area, bench_area, tile_area, cover_area;
    float tiles_needed, time_needed;

    printf("Enter n: ");
    scanf("%f", &n);
    printf("Enter w: ");
    scanf("%f", &w);
    printf("Enter l: ");
    scanf("%f", &l);
    printf("Enter m: ");
    scanf("%f", &m);
    printf("Enter o: ");
    scanf("%f", &o);

    plot_area = n * n - 2;
    bench_area = m * o;
    tile_area = w * l;

    cover_area = plot_area - bench_area;

    tiles_needed = cover_area / tile_area;

    time_needed = tiles_needed * 0.2;

    printf("%.2f\n", tiles_needed);
    printf("%.2f\n", time_needed);

}

void calc_salary() {
    int n;
    float m, rate;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%f", &m);

    printf("Enter rate: ");
    scanf("%f", &rate);

    float total = 14.5*n*m*0.75;
    float avrg = total/365 * rate;

    printf("He earns %.2f lev a day", avrg);
}

int main()
{
    // print1_to_10();
    // print_triangle();
    // print_cage();
    // inch_to_val();
    // cel_to_fahr();
    // deg_to_rad();
    // trap_area();
    // angle_to_val();
    // rect_area();
    // triangle_area();
    // calculate_seats();
    // shop();
    // tiles();
    calc_salary();
    return 0;
}