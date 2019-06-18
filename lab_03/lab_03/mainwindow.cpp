#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "lift.h"
#include "cage.h"
#include "doors.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    lift(new Ui::MainWindow)
{
    lift->setupUi(this);
    connect(this, SIGNAL(floor_btn_pressed(int)), &el, SLOT(floor_btn_pressed(int)));

    connect(&el, SIGNAL(state_text_changed(QString)), this, SLOT(lift_state_changed(QString)));
    connect(&el, SIGNAL(cage_state_text_changed(QString)), this, SLOT(cage_state_changed(QString)));
    connect(&el, SIGNAL(doors_state_text_changed(QString)), this, SLOT(doors_state_changed(QString)));
    connect(&el, SIGNAL(floor_changed(int)), this, SLOT(cage_floor_changed(int)));

    el.update_state();
}

MainWindow::~MainWindow()
{
    delete lift;
}

void MainWindow::on_lift_bt1_clicked()
{
    emit floor_btn_pressed(1);
}

void MainWindow::on_lift_bt2_clicked()
{
    emit floor_btn_pressed(2);
}

void MainWindow::on_lift_bt3_clicked()
{
    emit floor_btn_pressed(3);
}

void MainWindow::on_lift_bt4_clicked()
{
    emit floor_btn_pressed(4);
}

void MainWindow::on_lift_bt5_clicked()
{
    emit floor_btn_pressed(5);
}

void MainWindow::on_lift_bt6_clicked()
{
    emit floor_btn_pressed(6);
}

void MainWindow::on_lift_bt7_clicked()
{
    emit floor_btn_pressed(7);
}

void MainWindow::on_lift_bt8_clicked()
{
    emit floor_btn_pressed(8);
}

void MainWindow::on_lift_bt9_clicked()
{
    emit floor_btn_pressed(9);
}

void MainWindow::on_floor_bt1_clicked()
{
    emit floor_btn_pressed(1);
}

void MainWindow::on_floor_bt2_clicked()
{
    emit floor_btn_pressed(2);
}

void MainWindow::on_floor_bt3_clicked()
{
    emit floor_btn_pressed(3);
}

void MainWindow::on_floor_bt4_clicked()
{
    emit floor_btn_pressed(4);
}

void MainWindow::on_floor_bt5_clicked()
{
    emit floor_btn_pressed(5);
}

void MainWindow::on_floor_bt6_clicked()
{
    emit floor_btn_pressed(6);
}

void MainWindow::on_floor_bt7_clicked()
{
    emit floor_btn_pressed(7);
}

void MainWindow::on_floor_bt8_clicked()
{
    emit floor_btn_pressed(8);
}

void MainWindow::on_floor_bt9_clicked()
{
    emit floor_btn_pressed(9);
}

void MainWindow::lift_state_changed(QString state_text)
{
    lift->state_lift->setText(state_text);
    //lift->stage_lift_2->update();
    update();
}

void MainWindow::cage_floor_changed(int floor)
{
    lift->lift_num->setText(QString("%1").arg(floor));
    lift->floor_num->setText(QString("%1").arg(floor));

    //lift->floors->update();
    //lift->floors_2->update();
    update();
}

void MainWindow::cage_state_changed(QString state_text)
{
    lift->state_cage->setText(state_text);
    //lift->stage_lift->update();
    update();
}

void MainWindow::doors_state_changed(QString state_text)
{
    lift->state_doors->setText(state_text);
    //lift->stage_doors->update();
    update();
}
