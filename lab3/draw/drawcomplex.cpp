#include "drawcomplex.h"
#include "../object/abstractobject.h"
#include "../object/camera/camera.h"
#include "../object/carcas/carcas.h"
#include "../object/model.h"
#include <cmath>

struct Triangle
{
    Point A, B, C;

    Triangle(Point A, Point B, Point C)
        : A(A), B(B), C(C)
    {}

    double get_z()
    {
        return (B.get_x() - A.get_x())
               *(C.get_y() - A.get_y())
               -(B.get_y() - A.get_y())
               *(C.get_x() - A.get_y());
    }
};

DrawComplex::DrawComplex() {}

DrawComplex::DrawComplex(const DrawComplex& visitor)
{
    this->camera = visitor.camera;
    this->factory = visitor.factory;
}

DrawComplex::DrawComplex(std::shared_ptr<AbstractGraphicFactory> factory, std::shared_ptr<Camera>  camera)
{
    this->factory = factory;
    this->camera = camera;
}


std::vector<Triangle> DrawComplex::get_triangles(std::vector<Point> points, std::vector<Link> links)
{
    std::vector<Triangle> triangles;

    for (int i = 0; i < points.size() - 2; i += 3)
    {
        triangles.push_back(Triangle(points[i], points[i+1], points[i+2]));
    }

    return triangles;
}


void DrawComplex::visit(Model& carcas)
{
    // carcas.accept(std::make_shared<DrawComplex>(*this));

    auto points = carcas.model->get_points();
    auto links = carcas.model->get_links();

    auto drawer = this->factory->get_drawer();

    auto triangles = this->get_triangles(points, links);
    for (auto& triangle : triangles)
    {
        double z = triangle.get_z();
        if (z < 0)
        {
            drawer->draw_line(this->get_proection(triangle.A),
                              this->get_proection(triangle.B));
            drawer->draw_line(this->get_proection(triangle.A),
                              this->get_proection(triangle.C));
            drawer->draw_line(this->get_proection(triangle.B),
                              this->get_proection(triangle.C));
        }
    }
    // for (auto& link : links)
    // {
    //     drawer->draw_line(this->get_proection(points[link.get_left()]),
    //                       this->get_proection(points[link.get_right()]));
    // }

    return;
}

void DrawComplex::visit(Camera& camera)
{
    return;
}

void DrawComplex::visit(CompositeObject& obj)
{
    obj.accept(std::make_shared<DrawComplex>(*this));
}
