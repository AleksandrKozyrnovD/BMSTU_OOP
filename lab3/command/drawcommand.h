#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "basecommand.h"
#include <QGraphicsScene>
#include <QGraphicsView>

class DrawCommand : public BaseCommand {};


class ChangeDrawSimple : public DrawCommand
{
public:
    ChangeDrawSimple() = default;
    ChangeDrawSimple(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* view);
    ~ChangeDrawSimple() = default;

    void execute() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
    QGraphicsView* view;
};

class ChangeDrawComplex : public DrawCommand
{
public:
    ChangeDrawComplex() = default;
    ChangeDrawComplex(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* view);
    ~ChangeDrawComplex() = default;

    void execute() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
    QGraphicsView* view;
};

class Draw : public DrawCommand
{
public:
    Draw() = default;
    ~Draw() = default;

    void execute() override;
};


#endif // DRAWCOMMAND_H
