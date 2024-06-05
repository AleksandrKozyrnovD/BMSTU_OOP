#include "drawall.h"
#include "../object/abstractobject.h"
#include "../object/camera/camera.h"
#include "../object/carcas/carcas.h"
#include "../object/model.h"


DrawAll::DrawAll() {}

DrawAll::DrawAll(std::shared_ptr<AbstractGraphicFactory> factory, std::shared_ptr<Camera>  camera)
{
    this->factory = factory;
    this->camera = camera;
}

DrawAll::DrawAll(const DrawAll& visitor)
{
    this->camera = visitor.camera;
    this->factory = visitor.factory;
}


void DrawAll::visit(Model& carcas)
{
    // carcas.accept(std::make_shared<DrawAll>(*this));

    auto points = carcas.model->get_points();
    auto links = carcas.model->get_links();

    auto drawer = this->factory->get_drawer();

    for (auto& link : links)
    {
        Point left = this->get_proection(points[link.get_left()]);
        Point right = this->get_proection(points[link.get_right()]);


        if (left.get_z() < -1 || right.get_z() < -1)
            continue;
        if (left.get_z() > 1 || right.get_z() > 1)
            continue;
        else if (left.get_z() > 0 && right.get_z() > 0)
            drawer->draw_line(left, right);
    }
}

// #include <iostream>

// void DrawAll::visit(Model& carcas)
// {
//     // carcas.accept(std::make_shared<DrawAll>(*this));

//     auto points = carcas.model->get_points();
//     auto links = carcas.model->get_links();

//     auto drawer = this->factory->get_drawer();

//     for (int i = 0; i < points.size() - 2; i += 3)
//     {
//         auto A = points[i];
//         auto B = points[i + 1];
//         auto C = points[i + 2];

//         double ABx = (B.get_x() - A.get_x());
//         double ABy = (B.get_y() - A.get_y());

//         double ACx = (C.get_x() - B.get_x());
//         double ACy = (C.get_y() - B.get_y());

//         double z = ABy * ACx - ABx * ACy;

//         A = this->get_proection(A);
//         B = this->get_proection(B);
//         C = this->get_proection(C);
//         if (A.get_z() < -1 || B.get_z() < -1 || C.get_z() < -1)
//             continue;
//         if (A.get_z() > 1 || B.get_z() > 1 || C.get_z() > 1)
//             continue;
//         else
//         {

//             if (z > 0)
//             {
//                 // std::cout << A.get_x() << " " << A.get_y() << std::endl;
//                 // std::cout << B.get_x() << " " << B.get_y() << std::endl;
//                 // std::cout << C.get_x() << " " << C.get_y() << std::endl;
//                 drawer->draw_line(A, B);
//                 drawer->draw_line(A, C);
//                 drawer->draw_line(C, B);
//             }
//         }
//     }
// }

void DrawAll::visit(Camera& camera)
{
    return;
}

void DrawAll::visit(CompositeObject& obj)
{
    obj.accept(std::make_shared<DrawAll>(*this));
}
