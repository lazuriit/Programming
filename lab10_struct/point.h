#ifndef POINT_H
#define POINT_H

typedef struct {
    double x;
    double y;
    double z;
} Point3D;

Point3D createPoint(double x, double y, double z);
double distance(Point3D a, Point3D b);

#endif
