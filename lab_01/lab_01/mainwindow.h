#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include "choice.h"

ModelResponseAction handleModelProcResult(char *message, error result);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    char message[MAX_STRING];

    void clearScreen() const;
    void update(const controller& contr, ModelResponseAction action);


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonTranslate_clicked();
    void on_actionLoadModel_triggered();
    void on_buttonRotate_clicked();
    void on_buttonScale_clicked();
    void on_actionSave_triggered();
};

#endif // MAINWINDOW_H
