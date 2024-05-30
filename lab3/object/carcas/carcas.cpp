#include "carcas.h"
#include <cmath>

double to_radians(double angle)
{
    return angle * (M_PI / 180);
}

Point::Point(double mono) noexcept
    : x(mono), y(mono), z(mono)
{}

Point::Point(double x, double y, double z) noexcept
    : x(x), y(y), z(z)
{}


Point::Point(const Point& other) noexcept
    : x(other.x), y(other.y), z(other.z)
{}

double Point::get_x() const noexcept
{
    return this->x;
}

double Point::get_y() const noexcept
{
    return this->y;
}

double Point::get_z() const noexcept
{
    return this->z;
}

void Point::set_x(double a) noexcept
{
    this->x = a;
}

void Point::set_y(double a) noexcept
{
    this->y = a;
}

void Point::set_z(double a) noexcept
{
    this->z = a;
}

void Point::move(double x, double y, double z) noexcept
{
    this->x += x;
    this->y += y;
    this->z += z;
}


void Point::scale(double kx, double ky, double kz) noexcept
{
    this->set_x(this->x * kx);
    this->set_y(this->y * ky);
    this->set_z(this->z * kz);
}

void Point::rotate_x(double ax) noexcept
{
    const double cos_rotate = cos(to_radians(ax));
    const double sin_rotate = sin(to_radians(ax));

    const double tmp = this->y;

    set_y(this->y * cos_rotate + this->z * sin_rotate);
    set_z(this->z * cos_rotate - tmp * sin_rotate);
}

void Point::rotate_y(double ay) noexcept
{
    const double cos_rotate = cos(to_radians(ay));
    const double sin_rotate = sin(to_radians(ay));

    const double tmp = this->x;

    set_x(this->x * cos_rotate + this->z * sin_rotate);
    set_z(this->z * cos_rotate - tmp * sin_rotate);
}

void Point::rotate_z(double az) noexcept
{
    const double cos_rotate = cos(to_radians(az));
    const double sin_rotate = sin(to_radians(az));

    const double tmp = this->x;

    set_x(this->x * cos_rotate + this->y * sin_rotate);
    set_y(this->y * cos_rotate - tmp * sin_rotate);
}

void Point::rotate(double ax, double ay, double az) noexcept
{
    this->rotate_x(ax);
    this->rotate_y(ay);
    this->rotate_z(az);
}

void Point::rotate(const Point& center, double ax, double ay, double az) noexcept
{
    x -= center.x;
    y -= center.y;
    z -= center.z;
    this->rotate_x(ax);
    this->rotate_y(ay);
    this->rotate_z(az);
    x += center.x;
    y += center.y;
    z += center.z;
}

Link::Link(const Link& other) noexcept
    : A(other.A), B(other.B)
{}

Link::Link(int A, int B) noexcept
    : A(A), B(B)
{}

int Link::get_left() const noexcept
{
    return A;
}

int Link::get_right() const noexcept
{
    return B;
}

void Link::set_left(int A) noexcept
{
    this->A = A;
}

void Link::set_right(int B) noexcept
{
    this->B = B;
}

Carcas::Carcas(const Carcas& other)
{
    for (auto& elem : other.points)
    {
        this->points.push_back(elem);
    }

    for (auto& elem : other.links)
    {
        this->links.push_back(elem);
    }
}

Carcas::Carcas(Carcas&& other) noexcept
    : points(std::move(other.points)), links(std::move(other.links))
{}

Carcas::Carcas(std::vector<Point> points, std::vector<Link> links) noexcept
    : points(points), links(links)
{
    this->revalue_center();
}

std::vector<Point>& Carcas::get_points()
{
    return this->points;
}

std::vector<Link>& Carcas::get_links()
{
    return this->links;
}


bool Carcas::add_point(const Point& point)
{
    this->points.push_back(point);

    this->revalue_center();

    return true;
}

bool Carcas::add_link(const Link& link)
{
    this->links.push_back(link);

    return true;
}

Point& Carcas::get_center()
{
    return this->center;
}

void Carcas::move_to_center()
{
    for (auto& point : this->points)
    {
        point.set_x(point.get_x() - this->center.get_x());
        point.set_y(point.get_y() - this->center.get_y());
        point.set_z(point.get_z() - this->center.get_z());
    }
}

void Carcas::move_back()
{
    for (auto& point : this->points)
    {
        point.set_x(point.get_x() + this->center.get_x());
        point.set_y(point.get_y() + this->center.get_y());
        point.set_z(point.get_z() + this->center.get_z());
    }
}

void Carcas::revalue_center()
{
    double x(0), y(0), z(0);

    for (auto& point : this->points)
    {
        x += point.get_x();
        y += point.get_y();
        z += point.get_z();
    }

    auto size = this->points.size();
    this->center.set_x(x / size);
    this->center.set_y(y / size);
    this->center.set_z(z / size);
}

// void Carcas::accept(std::shared_ptr<ModelVisitor> visitor)
// {
//     visitor->visit(*this);
// }

// void Carcas::accept(std::shared_ptr<DrawVisitor> visitor)
// {
//     visitor->visit(*this);
// }
