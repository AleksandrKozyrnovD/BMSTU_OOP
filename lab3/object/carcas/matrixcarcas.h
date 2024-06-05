#ifndef MATRIXCARCAS_H
#define MATRIXCARCAS_H

#include "AbstractCarcas.h"
#include "carcas.h"

class MatrixCarcas : public AbstractCarcas
{
public:
    MatrixCarcas();
    explicit MatrixCarcas(const MatrixCarcas& other);
    MatrixCarcas(MatrixCarcas&& other) noexcept = default;
    MatrixCarcas(std::vector<Point> points, std::vector<Link> links);

    std::vector<Point>& get_points() override;
    std::vector<Link> get_links() override;

    bool add_point(const Point& point) override;
    bool add_link(const Link& link) override;

    Point& get_center() override;
    void move_to_center() override;
    void move_back() override;

protected:
    std::vector<Point> points;
    std::vector<std::vector<size_t>> links;
    Point center;

private:
    void revalue_center();
};

#endif // MATRIXCARCAS_H
