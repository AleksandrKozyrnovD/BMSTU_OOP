#include <cmath>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "object/carcas/carcas.h"
#include "object/camera/camera.h"
#include "draw/drawall.h"
#include "draw/drawcomplex.h"
#include "draw/qtfactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    // facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    _scene = std::make_shared<QGraphicsScene>(this);

    ui->graphicsView->setScene(_scene.get());
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto cont = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, cont.width(), cont.height());
    this->cameraInd = 1;

    auto myScene = std::make_shared<Scene>(Scene());

    SolutionScene scene = SolutionScene(myScene);
    SolutionTransform transform = SolutionTransform();
    SolutionLoader loader = SolutionLoader();

    std::shared_ptr<Camera> camera = std::make_shared<Camera>(0,0,0);
    auto view = ui->graphicsView;
    auto visitor = DrawAll(std::make_shared<QTFactory>(this->_scene, view), camera);
    // std::shared_ptr<DrawAll> visitor = std::make_shared<DrawAll>(QTFactory(this->_scene), Camera(0,0,0));
    SolutionDraw drawer = SolutionDraw(std::make_shared<DrawAll>(visitor));

    this->facade = std::make_shared<Facade>(drawer, loader, transform, scene);
}

void MainWindow::updateScene()
{
    this->_scene->clear();

    // std::shared_ptr<Camera> camera = nullptr;

    // std::shared_ptr<AbstractObject> obj = std::make_shared<CompositeObject>();
    // ModelsGetCommand getcmd(obj);
    // this->facade->execute(getcmd);

    // auto cont = ui->graphicsView->contentsRect();
    // std::cout <<
    // MakeMoveCommand move1(cont.width() / 2.0, cont.height() / 2.0, 0);
    // this->facade->execute(move1);

    // ModelTransformCommand transform(obj);
    // this->facade->execute(transform);

    Draw cmd;
    if (this->_models.size())
    {
        this->facade->execute(cmd);
    }
    // MakeMoveCommand move2(-cont.width() / 2.0, -cont.height() / 2.0, 0);
    // this->facade->execute(move2);

    // this->facade->execute(transform);
}

void MainWindow::checkCamExist()
{
    if (!_cameras.size())
    {
        std::string msg = "No camera found.";
        throw CameraException(msg);
    }
}

void MainWindow::checkModelsExist()
{
    if (!_models.size())
    {
        std::string msg = "No models found.";
        throw ModelException(msg);
    }
}

void MainWindow::checkCamDelete()
{
    if (_cameras.size() <= 1 && _models.size())
    {
        std::string msg = "Can not delete the last camera with the loaded models";
        throw CameraException(msg);
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();

    auto id = std::make_shared<size_t>(0);

    Camera testcamera(0.0, 0.0, 0.0);
    std::shared_ptr<Camera> camera = std::make_shared<Camera>(testcamera);

    CameraAddCommand cmd = CameraAddCommand(camera);
    this->facade->execute(cmd);

    // _cameras.push_back(ui->cameraCB->count());
    this->_cameras.push_back(camera->get_id());

    CameraSetCommand set(camera->get_id());
    this->facade->execute(set);

    updateScene();

    auto cam = ui->cameraCB;

    std::string camName = std::string("Camera") + std::to_string(this->cameraInd++);
    cam->addItem(QString(camName.data()));

    ui->cameraCB->setCurrentIndex(ui->cameraCB->count() - 1);
    this->objectindex++;
}

void MainWindow::on_loadModelBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
        return;
    }

    auto path = QFileDialog::getOpenFileName(nullptr, "Загрузка модели", "../../../test");

    if (path.isNull())
        return;

    auto id = std::make_shared<size_t>(0);
    std::string pathFileName = path.toStdString();

    try
    {
        std::shared_ptr<AbstractObject> obj;
        if (ui->secreal->isChecked())
        {
            ModelLoadMatrix load(obj, pathFileName, ui->binfile->isChecked());
            this->facade->execute(load);
        }
        else if (ui->firstreal->isChecked())
        {
            ModelLoadCarcas load(obj, pathFileName, ui->binfile->isChecked());
            this->facade->execute(load);
        }
        else if (ui->addcomposite->isChecked())
        {
            ModelLoadCarcas load(obj, pathFileName, ui->binfile->isChecked());
            this->facade->execute(load);
        }
        else
        {

            ModelLoadCarcas load(obj, pathFileName, ui->binfile->isChecked());
            this->facade->execute(load);
        }

        ModelAddCarcas cmd(obj);
        this->facade->execute(cmd);

        this->_models.push_back(obj->get_id());
    }
    catch (const BaseException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка при загрузке файла!");
        return;
    }

    updateScene();
    this->modelInd++;
    auto fileName = QFileInfo(path.toUtf8().data()).fileName();
    QString figName = QString("CarcasModel") + QString::number(this->modelInd) + QString(" load from ") + QString(fileName);
    ui->modelsCB->addItem(figName);
    ui->modelsCB->setCurrentIndex(ui->modelsCB->count() - 1);
    this->objectindex++;
}

void MainWindow::on_deleteModelBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    std::size_t id = _models.at(ui->modelsCB->currentIndex());
    // RemoveModel cmd(id);
    // this->facade->execute(cmd);

    ModelRemoveCommand cmd(id);
    this->facade->execute(cmd);

    _models.erase(_models.begin() + ui->modelsCB->currentIndex());
    ui->modelsCB->removeItem(ui->modelsCB->currentIndex());

    updateScene();
}

void MainWindow::on_deleteModelsBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    for (int i = ui->modelsCB->count() - 1; i >= 0; --i)
    {
        std::size_t id = _models.at(i);
        ModelRemoveCommand cmd(id);
        this->facade->execute(cmd);

        _models.erase(_models.begin() + i);
        ui->modelsCB->removeItem(i);
    }

    updateScene();
}


void MainWindow::on_cameraCB_currentIndexChanged(int index)
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    std::size_t id = _cameras.at(index);
    std::shared_ptr<Camera> camera = nullptr;
    CameraSetCommand cmd(id);
    this->facade->execute(cmd);

    updateScene();
}

void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        checkCamDelete();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Это последняя камера! Для удаления удалите модели!");
        return;
    }

    std::size_t id = _cameras.at(ui->cameraCB->currentIndex());
    CameraRemoveCommand cmd(id);
    this->facade->execute(cmd);

    _cameras.erase(_cameras.begin() + ui->cameraCB->currentIndex());
    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    updateScene();
}

void MainWindow::on_upBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(0, 10, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(0, -10, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_rigthBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(-10, 0, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);
    // updateScene();

    updateScene();
}

void MainWindow::on_rightUpBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(-10, 10, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);
    updateScene();
}

void MainWindow::on_rigntDownBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(-10, -10, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_leftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(10, 0, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_leftUpBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(10, 10, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_leftDownBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    auto camera = std::make_shared<Camera>();

    CameraGetCommand get_camera(camera);
    this->facade->execute(get_camera);

    MakeMoveCommand movecommand(10, -10, 0);
    this->facade->execute(movecommand);

    ModelTransformCommand transform(camera);
    this->facade->execute(transform);

    updateScene();
}


void MainWindow::on_moveBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет каркасных фигур!");
        return;
    }


    std::shared_ptr<AbstractObject> obj = std::make_shared<Model>();

    ModelGetCommand cmdget(obj, _models[ui->modelsCB->currentIndex()]);
    this->facade->execute(cmdget);

    MakeMoveCommand movecommand(ui->dxDSB->value(), ui->dyDSB->value(), ui->dzDSB->value());
    this->facade->execute(movecommand);

    ModelTransformCommand transform(obj);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_moveAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<AbstractObject> obj = std::make_shared<CompositeObject>();
    ModelsGetCommand cmdget(obj);
    this->facade->execute(cmdget);

    MakeMoveCommand movecommand(ui->dxDSB->value(), ui->dyDSB->value(), ui->dzDSB->value());
    this->facade->execute(movecommand);

    ModelTransformCommand transform(obj);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<AbstractObject> obj = std::make_shared<Model>();
    ModelGetCommand cmdget(obj, _models[ui->modelsCB->currentIndex()]);
    this->facade->execute(cmdget);

    // ModelScaleCommand cmdmove(obj, ui->kxDSB->value(), ui->kyDSB->value(), ui->kzDSB->value());

    MakeScaleCommand scalecommand(ui->kxDSB->value(), ui->kyDSB->value(), ui->kzDSB->value());
    this->facade->execute(scalecommand);

    ModelTransformCommand transform(obj);
    this->facade->execute(transform);


    updateScene();
}

void MainWindow::on_scaleAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<AbstractObject> obj = std::make_shared<CompositeObject>();
    ModelsGetCommand cmdget(obj);
    this->facade->execute(cmdget);

    MakeScaleCommand scalecommand(ui->kxDSB->value(), ui->kyDSB->value(), ui->kzDSB->value());
    this->facade->execute(scalecommand);

    ModelTransformCommand transform(obj);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<AbstractObject> obj = std::make_shared<Model>();
    ModelGetCommand cmdget(obj, _models[ui->modelsCB->currentIndex()]);
    this->facade->execute(cmdget);

    MakeRotateCommand Rotatecommand(ui->oxDSB->value(), ui->oyDSB->value(), ui->ozDSB->value());
    this->facade->execute(Rotatecommand);

    ModelTransformCommand transform(obj);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_camerarotate_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<Camera> obj = std::make_shared<Camera>();
    CameraGetCommand cmdget(obj);
    this->facade->execute(cmdget);

    MakeRotateCommand Rotatecommand(ui->oxDSB->value(), ui->oyDSB->value(), ui->ozDSB->value());
    this->facade->execute(Rotatecommand);

    ModelTransformCommand transform(obj);
    this->facade->execute(transform);

    updateScene();
}

void MainWindow::on_rotateAllBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    std::shared_ptr<AbstractObject> obj = std::make_shared<CompositeObject>();
    ModelsGetCommand cmdget(obj);
    this->facade->execute(cmdget);

    MakeRotateCommand Rotatecommand(ui->oxDSB->value(), ui->oyDSB->value(), ui->ozDSB->value());
    this->facade->execute(Rotatecommand);

    ModelTransformCommand transform(obj);
    this->facade->execute(transform);

    updateScene();
}
