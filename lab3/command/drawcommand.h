#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "basecommand.h"
#include <QGraphicsScene>

class DrawCommand : public BaseCommand {};


class ChangeDrawSimple : public DrawCommand
{
public:
    ChangeDrawSimple() = default;
    ChangeDrawSimple(std::shared_ptr<QGraphicsScene> scene);
    ~ChangeDrawSimple() = default;

    void execute() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
};

class ChangeDrawComplex : public DrawCommand
{
public:
    ChangeDrawComplex() = default;
    ChangeDrawComplex(std::shared_ptr<QGraphicsScene> scene);
    ~ChangeDrawComplex() = default;

    void execute() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
};

class Draw : public DrawCommand
{
public:
    Draw() = default;
    ~Draw() = default;

    void execute() override;
};


#endif // DRAWCOMMAND_H
