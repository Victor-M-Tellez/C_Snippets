#include <stdio.h> //The Preprocessor Directive
#include <stdlib.h>

double circularArea( double r); //Function declaration (prototypeForm)

int main(){

    double radius = 1.0, area = 0.0;

    printf("Area of Circles \n");
    printf("      Radius        Area\n");

    area = circularArea(radius);
    printf("%10.1f    %10.2f\n ", radius , area);



    printf("Hello world!\n");
    return 0;
}


//The function circularArea() calculates the area of a circle
//Parameters: the radius of the circle
//Return Value: the area of the circle
double circularArea( double r){

    const double pi = 3.14;
    return pi*r*r;
}
