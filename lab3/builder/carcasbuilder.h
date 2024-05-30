#ifndef CARCASBUILDER_H
#define CARCASBUILDER_H

// #include "../object/carcas/AbstractCarcas.h"
#include "BaseCarcasBuilder.h"


class CarcasBuilder : public BaseCarcasBuilder
{
public:
    CarcasBuilder() = default;
    explicit CarcasBuilder(std::shared_ptr<AbstractReader> reader);
    ~CarcasBuilder();

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

#endif // CARCASBUILDER_H
