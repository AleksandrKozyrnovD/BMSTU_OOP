#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

#include "BaseCarcasBuilder.h"

class MatrixBuilder : public BaseCarcasBuilder
{
public:
    MatrixBuilder() = default;
    explicit MatrixBuilder(std::shared_ptr<AbstractReader> reader);
    ~MatrixBuilder();

    bool build_points() override;
    bool build_links() override;

    void create_model() override;
    std::shared_ptr<Model> build() override;

protected:
    bool CheckLinkValidity(int size, const Link& link);

private:
    std::vector<Point> points;
    std::vector<Link> links;
    int stage = 0;
};

#endif // MATRIXBUILDER_H
