#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setUpCanvas();
    ui->ModelBox->addItem("Все модели");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    try
    {
        size_t index = ui->ModelBox->currentIndex() - 1;
        size_t cam_cnt = ui->CameraBox->currentIndex();

        if (event->key() == Qt::Key_Z)
        {
            ModelMoveAction action(this->offset, 0, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_X)
        {
            ModelMoveAction action(0, this->offset, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_C)
        {
            ModelMoveAction action(0, 0, this->offset, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_R)
        {
            ModelMoveAction action(-this->offset, 0, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_T)
        {
            ModelMoveAction action(0, -this->offset, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_Y)
        {
            ModelMoveAction action(0, 0, -this->offset, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_F)
        {
            ModelScaleAction action(scaleCoeff, scaleCoeff, scaleCoeff, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_G)
        {
            ModelScaleAction action(1 / scaleCoeff, 1 / scaleCoeff, 1 / scaleCoeff, \
                                             index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_Q)
        {
            ModelRotateAction action(angle, 0, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_W)
        {
            ModelRotateAction action(0, angle, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_E)
        {
            ModelRotateAction action(angle, 0, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_A)
        {
            ModelRotateAction action(-angle, 0, 0,  index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_S)
        {
            ModelRotateAction action(0, -angle, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_D)
        {
            ModelRotateAction action(-angle, 0, 0, index);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_J)
        {
            CameraRotateAction action(angle * 2, 0, 0, cam_cnt);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_K)
        {
            CameraRotateAction action(0, angle * 2, 0, cam_cnt);
            actionController.make_action(action);
        }
        else if (event->key() == Qt::Key_L)
        {
            CameraRotateAction action(angle * 2, 0, 0, cam_cnt);
            actionController.make_action(action);
        }
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Ошибка", QString(e.what()));
    }

    this->updateCanvas();
}

void Widget::setUpCanvas()
{
    this->canvas = new QGraphicsScene;
    ui->Canvas->installEventFilter(this);
    ui->Canvas->setScene(canvas);

    ui->AddButton->click();
}

void Widget::updateCanvas()
{
    this->canvas->clear();
    ModelDrawer drawer(this->canvas);

    size_t index = ui->CameraBox->currentIndex();
    ModelDrawAction action(drawer, index);
    actionController.make_action(action);
}

void Widget::on_AddButton_clicked()
{
    try
    {
        CameraAddAction action(0, 0, 0);
        actionController.make_action(action);

        ui->CameraBox->addItem("Камера " + QString::number(ui->CameraBox->count()));
        ui->CameraBox->setCurrentIndex(ui->CameraBox->count() - 1);
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Ошибка", QString(e.what()));
    }
}

void Widget::on_DeleteButton_clicked()
{
    try
    {
        if (ui->CameraBox->count() == 1)
            return;

        CameraDelAction action(ui->CameraBox->currentIndex());
        actionController.make_action(action);

        ui->CameraBox->removeItem(ui->CameraBox->currentIndex());
        ui->CameraBox->setCurrentIndex(0);
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Ошибка", QString(e.what()));
    }
}

void Widget::on_LoadButton_clicked()
{
    try
    {
        QString filePath = QFileDialog::getOpenFileName(this, "Открыть модель", "", \
                                                        "Wavefront (*.txt)");
        if (filePath.isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Не выбран файл");
            return;
        }

        ModelIOAction action(filePath.toStdString());
        actionController.make_action(action);

        ui->ModelBox->addItem("Модель " + QString::number(ui->ModelBox->count()));
        ui->ModelBox->setCurrentIndex(ui->ModelBox->count() - 1);

        this->updateCanvas();
    }
    catch (BaseException& e)
    {
        QMessageBox::warning(this, "Ошибка", QString(e.what()));
    }
}

void Widget::on_CameraBox_currentIndexChanged(int index)
{
    this->updateCanvas();
}
