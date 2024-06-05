#include "matrixbuilder.h"
#include "../object/carcas/matrixcarcas.h"


MatrixBuilder::MatrixBuilder(std::shared_ptr<AbstractReader> reader)
{
    this->reader = reader;

    this->reader->open();
}

MatrixBuilder::~MatrixBuilder()
{
    if (this->reader)
    {
        if (!this->reader->is_open())
        {
            this->reader->close();
        }
    }
}

// bool MatrixBuilder::build_point(const Point& point)
// {
//     return this->model->add_point(point);
// }

bool MatrixBuilder::CheckLinkValidity(int size, const Link& link)
{
    int left = link.get_left();
    int right = link.get_right();

    if (left < 0 || right < 0)
    {
        return false;
    }

    if (left == right)
    {
        return false;
    }

    if (left >= size || right >= size)
    {
        return false;
    }

    return true;
}

bool MatrixBuilder::build_points()
{
    this->stage = 1;
    int number_of_points = int(reader->read());
    bool correct = true;

    for (int i = 0; correct && i < number_of_points; i++)
    {
        double x, y, z;
        x = this->reader->read();
        y = this->reader->read();
        z = this->reader->read();

        this->points.push_back(Point(x, y, z));
    }

    return correct;
}

bool MatrixBuilder::build_links()
{
    if (stage != 1)
    {
        return false;
    }

    bool correct = true;
    int number_of_links = int(this->reader->read());
    for (int i = 0; correct && i < number_of_links; i++)
    {
        double A, B;
        A = this->reader->read();
        B = this->reader->read();

        this->links.push_back(Link(A, B));
    }

    return correct;
}


void MatrixBuilder::create_model()
{
    if (!this->model)
    {
        this->model = std::make_shared<MatrixCarcas>(this->points, this->links);
    }
}

std::shared_ptr<Model> MatrixBuilder::build()
{
    this->create_model();

    return std::make_shared<Model>(this->model);
}
