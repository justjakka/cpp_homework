#include <math.h>
#include <stdio.h>


struct point
{
    double x, y;
};

typedef struct point Point;

struct triangle
{
    Point a, b, c;
};

typedef struct triangle Triangle;

void print_point(const Point* pnt)
{
    printf("%.2f %.2f\n", pnt->x, pnt->y);
}

void print_triangle(const Triangle* tngl)
{
    printf("{(%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)}\n", tngl->a.x, tngl->a.y, tngl->b.x, tngl->b.y, tngl->c.x, tngl->c.y);
}

double distance(const Point* p1, const Point* p2)
{
    double distance = (p1->x - p2->x) * (p1->x - p2->x);
    distance += (p1->y - p2->y) * (p1->y - p2->y);

    return sqrt(distance);
}

double get_triangle_perimeter(const Triangle* tng)
{
    double dist = distance(&(tng->a), &(tng->b));
    dist += distance(&(tng->b), &(tng->c));
    dist += distance(&(tng->c), &(tng->a));

    return dist;
}

double get_triangle_area(const Triangle* tng)
{
    double area;
    double a = distance(&(tng->a), &(tng->b));
    double b = distance(&(tng->b), &(tng->c));
    double c = distance(&(tng->c), &(tng->a));
    double s = get_triangle_perimeter(tng) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

Triangle moved_triangle(const Triangle* tng, const Point* vect)
{
    Point p1 = {tng->a.x + vect->x, tng->a.y + vect->y};
    Point p2 = {tng->b.x + vect->x, tng->b.y + vect->y};
    Point p3 = {tng->c.x + vect->x, tng->c.y + vect->y};

    Triangle res = {p1, p2, p3};

    return res;
}

void move_triangle(Triangle* tng, const Point* vect)
{
    Point p1 = {tng->a.x + vect->x, tng->a.y + vect->y};
    Point p2 = {tng->b.x + vect->x, tng->b.y + vect->y};
    Point p3 = {tng->c.x + vect->x, tng->c.y + vect->y};

    tng->a = p1;
    tng->b = p2;
    tng->c = p3;

    return;
}

Triangle rotated_triangle(const Triangle* t, const Point* origin, double alpha)
{
    Point p1 = {(t->a.x - origin->x) * cos(alpha) - (t->a.y - origin->y) * sin(alpha) + origin->x, (t->a.x - origin->x) * sin(alpha) + (t->a.y - origin->y) * cos(alpha) + origin->y};
    Point p2 = {(t->b.x - origin->x) * cos(alpha) - (t->b.y - origin->y) * sin(alpha) + origin->x, (t->b.x - origin->x) * sin(alpha) + (t->b.y - origin->y) * cos(alpha) + origin->y};
    Point p3 = {(t->a.x - origin->x) * cos(alpha) - (t->c.y - origin->y) * sin(alpha) + origin->x, (t->c.x - origin->x) * sin(alpha) + (t->c.y - origin->y) * cos(alpha) + origin->y};

    Triangle res = {p1, p2, p3};

    return res;
}

void rotate_triangle(Triangle* t, const Point* origin, double alpha)
{
    Point p1 = {(t->a.x - origin->x) * cos(alpha) - (t->a.y - origin->y) * sin(alpha) + origin->x, (t->a.x - origin->x) * sin(alpha) + (t->a.y - origin->y) * cos(alpha) + origin->y};
    Point p2 = {(t->b.x - origin->x) * cos(alpha) - (t->b.y - origin->y) * sin(alpha) + origin->x, (t->b.x - origin->x) * sin(alpha) + (t->b.y - origin->y) * cos(alpha) + origin->y};
    Point p3 = {(t->a.x - origin->x) * cos(alpha) - (t->c.y - origin->y) * sin(alpha) + origin->x, (t->c.x - origin->x) * sin(alpha) + (t->c.y - origin->y) * cos(alpha) + origin->y};

    t->a = p1;
    t->b = p2;
    t->c = p3;

    return;
}


int main()
{
    Point p1 = {0, 0};
    Point p2 = {0, 3};
    Point p3 = {4, 0};

    Triangle t = {p1, p2, p3};

    print_point(&p1);
    print_triangle(&t);

    printf("%lf\n", distance(&p1, &p2));

    printf("%lf\n", get_triangle_perimeter(&t));

    printf("%lf\n", get_triangle_area(&t));

    Triangle t1 = moved_triangle(&t, &p2);

    print_triangle(&t1);

    Triangle t2 = t;

    move_triangle(&t2, &p2);

    print_triangle(&t2);

    Triangle t3 = rotated_triangle(&t, &p2, 1.5708);

    print_triangle(&t3);

    rotate_triangle(&t, &p2, 1.5708);

    print_triangle(&t);
}