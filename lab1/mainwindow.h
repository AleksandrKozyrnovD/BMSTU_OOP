#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// #include "figure.h"
// #include "drawer.h"
#include "domen.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

#define WIN_WIDTH 320
#define WIN_HEIGHT 240

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void on_pushButton_clicked();

    void on_movebutton_clicked();

    void on_scalebutton_clicked();

    void on_rotatebutton_clicked();

    void on_loadbutton_clicked();

    // void on_savebutton_clicked();

    void on_savefigbutton_clicked();


private:
    Ui::MainWindow *ui;
    figure_t figure;
    view_scene_t viewscene;

    void draw(void);
};
#endif // MAINWINDOW_H
