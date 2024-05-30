#include "model.h"

Model::Model(const std::shared_ptr<AbstractCarcas>& model) noexcept
    : model(model)
{}


void Model::accept(std::shared_ptr<AbstractVisitor> visitor)
{
    visitor->visit(*this);
}

// Point& Model::get_center()
// {
//     return this->model->get_center();
// }

// void Model::move_to_center()
// {
//     this->model->move_to_center();
// }

// void Model::move_back()
// {
//     this->model->move_back();
// }

// void Model::accept(std::shared_ptr<DrawVisitor> visitor)
// {
//     visitor->visit(*(this->model));
// }

// std::vector<Point>& Model::get_points()
// {
//     return this->model->get_points();
// }

// std::vector<Link>& Model::get_links()
// {
//     return this->model->get_links();
// }
