#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "lift.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lift_bt1_clicked();
    void on_lift_bt2_clicked();
    void on_lift_bt3_clicked();
    void on_lift_bt4_clicked();
    void on_lift_bt5_clicked();
    void on_lift_bt6_clicked();
    void on_lift_bt7_clicked();
    void on_lift_bt8_clicked();
    void on_lift_bt9_clicked();
    void on_floor_bt1_clicked();
    void on_floor_bt2_clicked();
    void on_floor_bt3_clicked();
    void on_floor_bt4_clicked();
    void on_floor_bt5_clicked();
    void on_floor_bt6_clicked();
    void on_floor_bt7_clicked();
    void on_floor_bt8_clicked();
    void on_floor_bt9_clicked();

signals:
    void floor_btn_pressed(int floor);

public slots:
    void lift_state_changed(QString state_text);
    void cage_floor_changed(int floor);
    void cage_state_changed(QString state_text);
    void doors_state_changed(QString state_text);

private:
    Ui::MainWindow *lift;
    Lift el;
};

#endif // MAINWINDOW_H
