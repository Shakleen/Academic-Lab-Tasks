#include <stdio.h>
#include <stdlib.h>

int main()
{
    double radius, pi=3.1415926, area;
    printf("Enter Radius:");
    scanf("%lf", &radius);

    printf("Area of the circle: %lf", pi*radius*radius);
    return 0;
}
