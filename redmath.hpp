#ifndef REDMATH_HPP
#define REDMATH_HPP
#include <math.h>

namespace math_op
{
    
    static const double PI_s = 3.1415;
    static const double PI = 3.141592653589793;
    
    class Vector2
    {
    public:
        double x;
        double y;

        Vector2();
        Vector2(double v[2]);
        Vector2(double xv, double yv);

        Vector2 & operator = (Vector2 other);
        /* DIV & MUL */
        Vector2* operator*(Vector2& rht);
        Vector2* operator*=(double num);
        Vector2* operator/(Vector2& rht);
        Vector2& operator/=(double num);
        /* SUB & SUM */
        Vector2* operator+(Vector2 & rht);
        Vector2* operator-(Vector2 & rht);
        /* COMP */
        bool operator==(Vector2 & val);
        void Rotate(Vector2 point, double angle);

        void Rotate(double angle);

        double GetAngle();

        double Size();

        Vector2* Normalize();

        /* Popular Vector2 const */
        static const Vector2 Left;
        static const Vector2 Right;
        static const Vector2 Up;
        static const Vector2 Down;
        static const Vector2 Zero;
        static const Vector2 One;
    };

    class Vector3
    {
    public:
        double x;
        double y;
        double z;

        Vector3();
        Vector3(double v[3]);
        Vector3(double xv, double yv, double zv);

        Vector3 & operator = (Vector3 other);
        /* DIV & MUL */
        Vector3* operator*(Vector3& rht);
        Vector3* operator*=(double num);
        Vector3* operator/(Vector3& rht);
        Vector3& operator/=(double num);
        /* SUB & SUM */
        Vector3* operator+(Vector3 & rht);
        Vector3* operator-(Vector3 & rht);
        /* COMP */
        bool operator==(Vector3 & val);
        

        double Size();

        Vector3* Normalize();

        /* Popular Vector2 const */
        static const Vector3 Left;
        static const Vector3 Right;
        static const Vector3 Up;
        static const Vector3 Down;
        static const Vector3 Forward;
        static const Vector3 Backward;
        static const Vector3 Zero;
        static const Vector3 One;
    };

    class Line{
    public:
        Vector2 from;
        Vector2 to;

        Line(double v1[2], double v2[2]);
        Line(double coord[4]);
        Line(double x1, double y1, double x2, double y2);
        Line(Vector2 _from, Vector2 _to);
        double Size();
        void Rotate(Vector2 point, double angle);
        Vector2 GetCenter();
        Line* Normalize();
        Vector2 Direction();
        void Move(Vector2 tv);
    };

    unsigned int GetFactorial(unsigned int number);

    namespace geom
    {
        double area_of_polygon_inside_circle(double circle_radius, int number_sides);
        double area_of_circle(double circle_radius);
    }
}

#endif // REDMATH_HPP