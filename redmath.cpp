#include "redmath.hpp"

using namespace math_op;

/* VECTOR */
const Vector2 Vector2::Left(-1, 0);
const Vector2 Vector2::Right(1, 0);
const Vector2 Vector2::Up(0, 1);
const Vector2 Vector2::Down(0, -1);
const Vector2 Vector2::Zero(0, 0);
const Vector2 Vector2::One(1, 1);

Vector2::Vector2(){
    this->x = 0;
    this->y = 0;
}
Vector2::Vector2(double v[2]){
    this->x = v[0];
    this->y = v[1];
}
Vector2::Vector2(double xv, double yv){
    this->x = xv;
    this->y = yv;
}

Vector2 & Vector2::operator = (Vector2 other){
    x = other.x;
    y = other.y;
    return *this;
}
/* DIV & MUL */
Vector2* Vector2::operator*(Vector2& rht){
    this->x *= rht.x;
    this->y *= rht.y;
    return this;
}
Vector2* Vector2::operator*=(double num){
    this->x *= num;
    this->y *= num;
    return this;
}
Vector2* Vector2::operator/(Vector2& rht){
    this->x /= rht.x;
    this->y /= rht.y;
    return this;
}
Vector2& Vector2::operator/=(double num){
    this->x /= num;
    this->y /= num;
    return *this;
}
/* SUB & SUM */
Vector2* Vector2::operator+(Vector2 & rht){
    this->x += rht.x;
    this->y += rht.y;
    return this;
}
Vector2* Vector2::operator-(Vector2 & rht){
    this->x -= rht.x;
    this->y -= rht.y;
    return this;
}  
/* COMP */
bool Vector2::operator==(Vector2 & val){
    return this->x == val.x && this->y == val.y;
}
void Vector2::Rotate(Vector2 point, double angle){
    double angleRad = angle * PI / 180;
    
    float newX = round(((this->x - point.x) * cos(angleRad) - (this->y - point.y) * sin(angleRad) + point.x) * 100) / 100;
    float newY = round(((this->x - point.x) * sin(angleRad) + (this->y - point.y) * cos(angleRad) + point.y) * 100) / 100;
    this->x = newX;
    this->y = newY;
}

void Vector2::Rotate(double angle){
    Rotate(Vector2(0, 0), angle);
}

double Vector2::GetAngle(){
    return atan2(this->y,this->x) * 180 / PI;
}

double Vector2::Size(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}

Vector2* Vector2::Normalize(){
    this->x = this->x / Size();
    this->y = this->y / Size();
    return this;
}
/* VECTOR END */

unsigned int math_op::GetFactorial(unsigned int number)
{
    return number <= 1 ? number : math_op::GetFactorial(number-1) * number;
}

double geom::area_of_polygon_inside_circle(double circle_radius, int number_sides) {
    double area  = number_sides * (0.5 * pow(circle_radius, 2) * sin(2 * PI / number_sides));
    return round(area * 1e3) / 1e3;
}

double geom::area_of_circle(double circle_radius) {
    double area  = PI * pow(circle_radius, 2);
    return round(area * 1e3) / 1e3;
}

/* LINE */
Line::Line(double v1[2], double v2[2]){
    from = Vector2(v1);
    to = Vector2(v2);
}
Line::Line(double coord[4]){
    from = Vector2(coord[0], coord[1]);
    to = Vector2(coord[2], coord[3]);
}
Line::Line(double x1, double y1, double x2, double y2){
    from = Vector2(x1, y1);
    to = Vector2(x2, y2);
}
Line::Line(Vector2 v1, Vector2 v2){
    from = v1;
    to = v2;
}
double Line::Size(){
    return sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2));
}
void Line::Rotate(Vector2 point, double angle){
    double angleRad = angle * PI_s / 180;

    Vector2 _from;
    _from.x = round(((this->from.x - point.x) * cos(angleRad) - (this->from.y - point.y) * sin(angleRad) + point.x) * 100) / 100;
    _from.y = round(((this->from.x - point.x) * sin(angleRad) + (this->from.y - point.y) * cos(angleRad) + point.y) * 100) / 100;
    this->from = _from;

    Vector2 _to;
    _to.x = round(((this->to.x - point.x) * cos(angleRad) - (this->to.y - point.y) * sin(angleRad) + point.x) * 100) / 100;
    _to.y = round(((this->to.x - point.x) * sin(angleRad) + (this->to.y - point.y) * cos(angleRad) + point.y) * 100) / 100;
    this->to = _to;
}
Vector2 Line::GetCenter(){
    return Vector2((from.x + to.x) / 2, (from.y + to.y) / 2);
}
Line* Line::Normalize(){
    from.Normalize();
    to.Normalize();
    return this;
}
Vector2 Line::Direction(){
    return *(this->to - this->from);
}
void Line::Move(Vector2 tv){
    this->from.x += tv.x;
    this->from.y += tv.y;
    this->to.x += tv.x;
    this->to.y += tv.y;
}
/* LINE END */


Vector3::Vector3(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Vector3::Vector3(double v[3]){
    this->x = v[0];
    this->y = v[1];
    this->z = v[2];
}
Vector3::Vector3(double xv, double yv, double zv){
    this->x = xv;
    this->y = yv;
    this->z = zv;
}
Vector3 & Vector3::operator = (Vector3 other){
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
}
Vector3* Vector3::operator*(Vector3& rht){
    this->x *= rht.x;
    this->y *= rht.y;
    this->z *= rht.z;
    return this;
}
Vector3* Vector3::operator*=(double num){
    this->x *= num;
    this->y *= num;
    this->z *= num;
    return this;
}
Vector3* Vector3::operator/(Vector3& rht){
    this->x /= rht.x;
    this->y /= rht.y;
    this->z /= rht.z;
    return this;
}
Vector3& Vector3::operator/=(double num){
    this->x /= num;
    this->y /= num;
    this->z /= num;
    return *this;
}
Vector3* Vector3::operator+(Vector3 & rht){
    this->x += rht.x;
    this->y += rht.y;
    this->z += rht.z;
    return this;
}
Vector3* Vector3::operator-(Vector3 & rht){
    this->x -= rht.x;
    this->y -= rht.y;
    this->z -= rht.z;
    return this;
}

double Vector3::Size(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}
Vector3* Vector3::Normalize(){
    this->x = this->x / Size();
    this->y = this->y / Size();
    this->z = this->z / Size();
    return this;
}

const Vector3 Vector3::Left(-1, 0, 0);
const Vector3 Vector3::Right(1, 0, 0);
const Vector3 Vector3::Up(0, 1, 0);
const Vector3 Vector3::Down(0, -1, 0);
const Vector3 Vector3::Forward(0, 0, 1);
const Vector3 Vector3::Backward(0, 0, -1);
const Vector3 Vector3::Zero(0, 0, 0);
const Vector3 Vector3::One(1, 1, 1);
