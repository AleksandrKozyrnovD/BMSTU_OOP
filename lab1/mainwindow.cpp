#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "error_handler.h"
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    scene->setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);

    // viewscene.height = scene->height();
    // viewscene.width = scene->width();
    viewscene.scene = scene;
    viewscene.color = QPen(Qt::blue, 1);
}

MainWindow::~MainWindow()
{
    action_t action;
    action.action = FREE;
    do_action(action);

    delete ui;
}

void MainWindow::draw(void)
{
    action_t action;

    action.action = DRAW;

    action.scene = viewscene;

    errors_t return_code = do_action(action);

    handle_error(return_code);
}

void MainWindow::on_movebutton_clicked()
{
    action_t action;
    move_t move;

    move.dx = ui->dx->value();
    move.dy = ui->dy->value();
    move.dz = ui->dz->value();

    action.move = move;
    action.action = MOVE;

    errors_t rc = do_action(action);
    // printf("Rc = %d\n", rc);
    if (!rc)
        draw();

    // printf("Rc = %d\n", rc);
    handle_error(rc);
}


void MainWindow::on_scalebutton_clicked()
{
    scale_t scale;
    point_t center;
    action_t action;

    scale.kx = ui->kx->value();
    scale.ky = ui->ky->value();
    scale.kz = ui->kz->value();

    center.x = ui->xx->value();
    center.y = ui->yy->value();
    center.z = ui->zz->value();

    action.action = SCALE;
    action.center = center;
    action.scale = scale;

    errors_t rc = do_action(action);
    if (!rc)
        draw();

    handle_error(rc);
}

void MainWindow::on_rotatebutton_clicked()
{
    point_t center;
    rotate_t rotate;
    action_t action;

    rotate.ax = ui->ax->value();
    rotate.ay = ui->ay->value();
    rotate.az = ui->az->value();

    center.x = ui->xx->value();
    center.y = ui->yy->value();
    center.z = ui->zz->value();

    action.action = ROTATE;
    action.center = center;
    action.rotate = rotate;

    errors_t rc = do_action(action);
    if (!rc)
        draw();

    handle_error(rc);
}


void MainWindow::on_loadbutton_clicked()
{
    const char name[] = "../Lab1_OOP/data.txt";
    action_t action;

    action.filename = name;
    action.action = LOAD;

    errors_t rc = do_action(action);

    if (!rc)
        draw();
    handle_error(rc);
}


void MainWindow::on_savefigbutton_clicked()
{
    const char name[] = "../Lab1_OOP/out.txt";
    action_t action;

    action.action = SAVE;
    action.filename = name;

    errors_t rc = do_action(action);
    if (!rc)
        rc = scene_clear(viewscene);

    handle_error(rc);
}

