#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}

MainWindow::~MainWindow()
{
    controller contr = create_controller();
    error modelProcessRes = choice(contr, UserAction::Quit);
    handleModelProcResult(message, modelProcessRes);

    delete scene;
    delete ui;
}


/* Обработка ошибок */
ModelResponseAction handleModelProcResult(char *message, error result)
{
    ModelResponseAction res = ShowErrorMessage;


    const char IncorrectFileDataMessage[MAX_STRING] = "Некорректный файл!";
    const char fileNotFoundMessage[MAX_STRING] = "Файл не найден!";
    const char meshNotLoadedMessage[MAX_STRING] = "Каркас не найден!";
    const char unknownActionMessage[MAX_STRING] = "Неизвестное действие!";

    switch (result)
    {
    case (error::OK):
        res = Render;
        break;
    case (error::FileNotFound):
        res = ShowErrorMessage;
        strcpy(message, fileNotFoundMessage);
        break;
    case (error::MeshNotLoaded):
        res = ShowErrorMessage;
        strcpy(message, meshNotLoadedMessage);
        break;
    case (error::IncorrectFileData):
        res = ShowErrorMessage;
        strcpy(message, IncorrectFileDataMessage);
        break;
    case (error::UnknownAction):
        res = ShowErrorMessage;
        strcpy(message, unknownActionMessage);
        break;
    default:
        res = ShowErrorMessage;
        strcpy(message, unknownActionMessage);
        break;
    }

    return res;
}


void MainWindow::on_buttonTranslate_clicked()
{
    controller contr = create_controller();

    contr.userInput.dx = this->ui->lineEditTranslateX->text().toFloat();
    contr.userInput.dy = this->ui->lineEditTranslateY->text().toFloat();
    contr.userInput.dz = this->ui->lineEditTranslateZ->text().toFloat();

    error res = choice(contr, UserAction::Translate);

    if (res == error::OK)
    {
        choice(contr, UserAction::RenderModel);
    }
    ModelResponseAction action = handleModelProcResult(message, res);
    update(contr, action);
}

void MainWindow::on_buttonRotate_clicked()
{
    controller contr = create_controller();

    contr.userInput.rotateX = this->ui->lineEditRotateX->text().toFloat();
    contr.userInput.rotateY = this->ui->lineEditRotateY->text().toFloat();
    contr.userInput.rotateZ = this->ui->lineEditRotateZ->text().toFloat();

    error res = choice(contr, UserAction::Rotate);

    if (res == error::OK)
    {
        choice(contr, UserAction::RenderModel);
    }
    ModelResponseAction action = handleModelProcResult(message, res);
    update(contr, action);
}

void MainWindow::on_buttonScale_clicked()
{
    controller contr = create_controller();

    contr.userInput.scaleX = this->ui->lineEditScaleX->text().toFloat();
    contr.userInput.scaleY = this->ui->lineEditScaleY->text().toFloat();
    contr.userInput.scaleZ = this->ui->lineEditScaleZ->text().toFloat();

    if (contr.userInput.scaleX == 0.0)
        contr.userInput.scaleX = 1.0;
    if (contr.userInput.scaleY == 0.0)
        contr.userInput.scaleY = 1.0;
    if (contr.userInput.scaleZ == 0.0)
        contr.userInput.scaleZ = 1.0;

    error res = choice(contr, UserAction::Scale);

    if (res == error::OK)
    {
        choice(contr, UserAction::RenderModel);
    }
    ModelResponseAction action = handleModelProcResult(message, res);
    update(contr, action);
}

// Menu
void MainWindow::on_actionLoadModel_triggered()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Загрузить каркас", QDir::currentPath());

    controller contr = create_controller();
    contr.filename = filepath.toLocal8Bit().data();

    error res = choice(contr, UserAction::LoadModel);

    if (res == error::OK)
    {
        choice(contr, UserAction::RenderModel);
    }
    ModelResponseAction action = handleModelProcResult(message, res);
    update(contr, action);
}

void MainWindow::on_actionSave_triggered()
{
    QString filepath = QFileDialog::getOpenFileName(this, "Сохранить каркас", QDir::currentPath());
    if (filepath.isEmpty())
        filepath = "test/saved.txt";

    controller contr = create_controller();
    contr.filename = filepath.toLocal8Bit().data();

    error res = choice(contr, UserAction::SaveModel);
    ModelResponseAction action = handleModelProcResult(message, res);
    if (res == error::OK)
    {
        QMessageBox::information(this, "Сохранить каркас", "Сохранить: " + filepath);
    }

    update(contr, action);
}


void MainWindow::clearScreen() const
{
    scene->clear();
    scene->addRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height(),
                   QPen(Qt::white), QBrush(Qt::white));
}

void MainWindow::update(const controller& contr, ModelResponseAction action)
{
    if (action == Render)
    {
        clearScreen();

        int scrW = this->ui->graphicsView->width();
        int scrH = this->ui->graphicsView->height();

        // Drawcall here
        render_projected_points(scene, contr.projectedPoints,
                                       contr.pointsCount, scrW, scrH);
    }
    else
        QMessageBox::critical(this, "Ошибка", message);
}

