#ifndef CARCAS_H
#define CARCAS_H

#include <vector>
#include "AbstractCarcas.h"
// #include "../../draw/drawvisitor.h"


class Point
{
public:
    Point() noexcept = default;
    explicit Point(double mono) noexcept;
    Point(double x, double y, double z) noexcept;
    Point(const Point& other) noexcept;

    double get_x() const noexcept;
    double get_y() const noexcept;
    double get_z() const noexcept;

    void set_x(double x) noexcept;
    void set_y(double y) noexcept;
    void set_z(double z) noexcept;

    void move(double x, double y, double z) noexcept;
    void scale(double kx, double ky, double kz) noexcept;
    void rotate(double ax, double ay, double az) noexcept;
    void rotate(const Point& center, double ax, double ay, double az) noexcept;
protected:
    double x, y, z;

private:
    void rotate_x(double ax) noexcept;
    void rotate_y(double ay) noexcept;
    void rotate_z(double az) noexcept;
};

class Link
{
protected:
    int A, B;

public:
    Link() noexcept = default;
    Link(const Link& other) noexcept;
    explicit Link(int A, int B) noexcept;

    int get_left() const noexcept;
    int get_right() const noexcept;

    void set_left(int A) noexcept;
    void set_right(int B) noexcept;
};


class Carcas : public AbstractCarcas
{
public:
    Carcas() = default;
    explicit Carcas(const Carcas& other);
    Carcas(Carcas&& other) noexcept;
    Carcas(std::vector<Point> points, std::vector<Link> links) noexcept;

    std::vector<Point>& get_points() override;
    std::vector<Link> get_links() override;

    bool add_point(const Point& point) override;
    bool add_link(const Link& link) override;

    Point& get_center() override;
    void move_to_center() override;
    void move_back() override;

    // void accept(std::shared_ptr<ModelVisitor> visitor) override;
    // void accept(std::shared_ptr<DrawVisitor> visitor) override;

protected:
    std::vector<Point> points;
    std::vector<Link> links;
    Point center;

private:
    void revalue_center();
};



#endif // CARCAS_H
