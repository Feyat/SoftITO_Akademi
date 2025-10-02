/*

    User defined types
        struct:
            -  
        , union, enum 
*/
#include <stdio.h>
#include <math.h>


typedef struct Point{
        double x;
        double y;
}Point;

typedef struct Date{
    int day;
    int month;
    int year;
} Date;

typedef struct GPIO{
        // mode bilgileri
        // spede bilgisi
} GPIO;

double distance_point(Point p1, Point p2){
    return (sqrt(pow(p2.x-p1.x, 2)+pow(p2.y-p1.y,2)));
}
void get_display_point(Point *p1,Point *p2){
    printf("Birinci noktanın koordinatları x = %.f, y = %.f\n", p1->x, p1->x);
    printf("İkinci noktanın koordinatları x = %.f, y = %.f\n", p2->x, p2->y);

}

void get_display_array_point(const Point *pa, size_t size){
    for(size_t i=0;i<size;i++)
        printf("\nBirinci noktanın koordinatları x = %.f, y = %.f\n", (pa+i)->x, (pa+i)->y);
}
int main(){
    // nickname, level, power, 
    Point p1;
    Point p2;
    p1.x = 20;
    p1.y = 10;
    p2.x = 28;
    p2.y = 16;
    Point par[2] = {p1, p2};
    Point *pa = par;
    printf("p1_x = %.f p1_y = %.f p2_x = %.f p2_y = %.f", par[0].x, par[0].y, par[1].x, par[1].y);
    size_t size = sizeof(par)/sizeof(par);
    printf("\n%zd\n", size);
    get_display_array_point(pa, size);
    Point *ptr = &p1;
    Point *ptr_2 = &p2;

    double distance_res = distance_point(p1, p2);
    
    printf("\nMesafe bu kadardır = %.f", distance_res);


}