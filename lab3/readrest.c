#include <stdio.h>


int main(void)
{
    double x = -1;

    FILE *file = fopen("testbin", "rb");

    fread(&x, sizeof(double), 1, file);
    
    printf("size is %lf\n", x);

    fclose(file);

    return 0;
}
