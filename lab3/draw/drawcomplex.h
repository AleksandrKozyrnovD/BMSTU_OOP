#ifndef DRAWCOMPLEX_H
#define DRAWCOMPLEX_H

#include "drawvisitor.h"
#include <vector>

class Triangle;
class Point;
class Link;


class DrawComplex : public DrawVisitor
{
public:
    DrawComplex();
    DrawComplex(std::shared_ptr<AbstractGraphicFactory> factory, std::shared_ptr<Camera>  camera);
    DrawComplex(const DrawComplex& visitor);
    ~DrawComplex() = default;

    void visit(Model& carcas) override;
    void visit(Camera& camera) override;
    void visit(CompositeObject& composite) override;

private:
    std::vector<Triangle> get_triangles(std::vector<Point> points, std::vector<Link> links);
};

#endif // DRAWCOMPLEX_H
