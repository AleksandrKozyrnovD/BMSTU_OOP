#include "matrixcarcas.h"

MatrixCarcas::MatrixCarcas() {}

MatrixCarcas::MatrixCarcas(const MatrixCarcas& other)
    : center(center)
{
    for (auto& elem : other.points)
    {
        this->points.push_back(elem);
    }

    for (auto& line : other.links)
    {
        std::vector<size_t> matrixline;
        for (auto& elem : line)
        {
            matrixline.push_back(elem);
        }
        this->links.push_back(matrixline);
    }
}

MatrixCarcas::MatrixCarcas(std::vector<Point> points, std::vector<Link> links)
    : points(points)
{
    size_t size = this->points.size();

    for (size_t i = 0; i < size; i++)
    {
        std::vector<size_t> matrixline(size);
        this->links.push_back(matrixline);
    }

    for (auto& link : links)
    {
        auto A = link.get_left();
        auto B = link.get_right();
        this->links[A][B] = this->links[B][A] = 1;
    }
}

bool MatrixCarcas::add_point(const Point& point)
{
    this->points.push_back(point);

    for (auto& line : this->links)
    {
        line.push_back(0);
    }
    std::vector<size_t> newline(this->points.size());
    this->links.push_back(newline);

    return true;
}


bool MatrixCarcas::add_link(const Link& link)
{
    auto A = link.get_left();
    auto B = link.get_right();

    this->links[A][B] = this->links[B][A] = 1;

    return true;
}

std::vector<Point>& MatrixCarcas::get_points()
{
    return this->points;
}
std::vector<Link> MatrixCarcas::get_links()
{
    std::vector<Link> links;

    size_t size = this->links.size();
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (this->links[i][j] != 0)
            {
                links.push_back(Link(i, j));
            }
        }
    }

    return links;
}

Point& MatrixCarcas::get_center()
{
    return this->center;
}


void MatrixCarcas::move_to_center()
{
    for (auto& point : this->points)
    {
        point.set_x(point.get_x() - this->center.get_x());
        point.set_y(point.get_y() - this->center.get_y());
        point.set_z(point.get_z() - this->center.get_z());
    }
}

void MatrixCarcas::move_back()
{
    for (auto& point : this->points)
    {
        point.set_x(point.get_x() + this->center.get_x());
        point.set_y(point.get_y() + this->center.get_y());
        point.set_z(point.get_z() + this->center.get_z());
    }
}

void MatrixCarcas::revalue_center()
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
