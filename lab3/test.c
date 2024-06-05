#include <linux/limits.h>
#include <stdio.h>

typedef struct point
{
    double x, y, z;
} point_t;

typedef struct link
{
    double x, y;
} link_t;

int main(void)
{
    FILE *file = fopen("testbin", "wb");
    
    double x = 8;

    point_t point;
    link_t link;

    fwrite(&x, sizeof(x), 1, file);
    
    point.x = 0;
    point.y = 0;
    point.z = 0;
    fwrite(&point, sizeof(point_t), 1, file);
    point.x = 0;
    point.y = 100;
    point.z = 0;
    fwrite(&point, sizeof(point_t), 1, file);
    point.x = 100;
    point.y = 0;
    point.z = 0;
    fwrite(&point, sizeof(point_t), 1, file);
    point.x = 100;
    point.y = 100;
    point.z = 0;
    fwrite(&point, sizeof(point_t), 1, file);
    point.x = 0;
    point.y = 0;
    point.z = 100;
    fwrite(&point, sizeof(point_t), 1, file);
    point.x = 0;
    point.y = 100;
    point.z = 100;
    fwrite(&point, sizeof(point_t), 1, file);
    point.x = 100;
    point.y = 0;
    point.z = 100;
    fwrite(&point, sizeof(point_t), 1, file);
    point.x = 100;
    point.y = 100;
    point.z = 100;
    fwrite(&point, sizeof(point_t), 1, file);

    x = 12;
    fwrite(&x, sizeof(x), 1, file);

    link.x = 0;
    link.y = 1;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 0;
    link.y = 2;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 2;
    link.y = 3;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 1;
    link.y = 3;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 4;
    link.y = 5;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 4;
    link.y = 6;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 5;
    link.y = 7;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 6;
    link.y = 7;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 0;
    link.y = 4;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 1;
    link.y = 5;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 2;
    link.y = 6;
    fwrite(&link, sizeof(link_t), 1, file);
    link.x = 3;
    link.y = 7;
    fwrite(&link, sizeof(link_t), 1, file);

    fclose(file);

    return 0;
}
