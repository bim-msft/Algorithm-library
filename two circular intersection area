// PID: poj 2546
// Link: http://poj.org/problem?id=2546
// Algorithm: Simple geometry

#include <cstdio>
#include <cmath>

using namespace std;

const double pi = 3.14159265359;

typedef struct __point
{
    double x, y;
}
point;

typedef struct __circle
{
    point o;
    double r;
}
circle;

double calc2pdis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double getInsArea(circle cir[2])
{
    double dis = calc2pdis(cir[0].o, cir[1].o);
    double rdis = cir[0].r + cir[1].r;
    double rdis2 = cir[1].r - cir[0].r;

    if (dis >= rdis)
        return 0.0;

    if (dis + cir[0].r <= cir[1].r)
        return pi * cir[0].r * cir[0].r;

    double area;

    if(dis >= sqrt(cir[1].r * cir[1].r - cir[0].r * cir[0].r))
    {
        double d = (dis * dis - cir[1].r * cir[1].r  + cir[0].r * cir[0].r) / (2 * dis);
        double y = sqrt(cir[0].r * cir[0].r - d * d);

        double angle1 = asin(y / cir[0].r);
        double sector1Area = (angle1 / (2 * pi)) * pi * cir[0].r * cir[0].r;
        double triangle1Area = d * y / 2;

        double angle2 = asin(y / cir[1].r);
        double sector2Area = (angle2 / (2 * pi)) * pi * cir[1].r * cir[1].r;
        double triangle2Area = (dis - d) * y / 2;

        area = (sector1Area - triangle1Area) * 2 + (sector2Area - triangle2Area) * 2;
    }
    else
    {
        double d = (cir[1].r * cir[1].r - cir[0].r * cir[0].r - dis * dis) / (2 * dis);
        double y = sqrt(cir[0].r * cir[0].r - d * d);

        double angle1 = asin(y / cir[0].r);
        double sector1Area = (angle1 / (2 * pi)) * pi * cir[0].r * cir[0].r;
        double triangle1Area = d * y / 2;

        double angle2 = asin(y / cir[1].r);
        double sector2Area = (angle2 / (2 * pi)) * pi * cir[1].r * cir[1].r;
        double triangle2Area = (dis + d) * y / 2;

        area = pi * cir[0].r * cir[0].r - fabs((sector1Area - triangle1Area) * 2 - (sector2Area - triangle2Area) * 2);
    }

    return area;
}

int main()
{
    circle cir[2];

    while (scanf("%lf%lf%lf%lf%lf%lf", &cir[0].o.x, &cir[0].o.y, &cir[0].r, &cir[1].o.x, &cir[1].o.y, &cir[1].r) > 0)
    {
        if (cir[0].r > cir[1].r)
        {
             circle tmp = cir[0];
             cir[0] = cir[1];
             cir[1] = tmp;
        }
        printf("%.3f\n", getInsArea(cir));
    }

    return 0;
}
