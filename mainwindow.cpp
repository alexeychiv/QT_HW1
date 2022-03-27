#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_countRoots_clicked()
{
    int16_t a = ui->lineEdit_a->text().toInt();
    int16_t b = ui->lineEdit_b->text().toInt();
    int16_t c = ui->lineEdit_c->text().toInt();

    if (a == 0 && b == 0 && c == 0)
    {
        ui->label_result_squareEquation->setText("Infinite number of roots");
        return;
    }

    if (a == 0 && b == 0 && c != 0)
    {
        ui->label_result_squareEquation->setText("No roots");
        return;
    }

    if (a == 0 && b != 0)
    {
        double x = (double)-c / b;
        ui->label_result_squareEquation->setText("x = " + QString::number(x));
        return;
    }

    int d = b * b - 4 * a * c;

    if (d < 0)
    {
        ui->label_result_squareEquation->setText("No roots (d < 0)");
        return;
    }

    if (d == 0)
    {
        double x = (double)-b / (2 * a);
        ui->label_result_squareEquation->setText("x = " + QString::number(x) + " (d = 0)");
        return;
    }

    double x1 = (double)(-b + qSqrt(d)) / (2 * a);
    double x2 = (double)(-b - qSqrt(d)) / (2 * a);
    ui->label_result_squareEquation->setText("x1 = " + QString::number(x1) + " x2 = " + QString::number(x2) + " (d = " + QString::number(x2) + ")");
}


void MainWindow::on_pushButton_countTriangleSide_clicked()
{
    int16_t sideA = ui->lineEdit_triangleSideA->text().toInt();
    int16_t sideB = ui->lineEdit_triangleSideB->text().toInt();
    double angle = ui->lineEdit_triangleAngle->text().toDouble();

    if ((sideA == 0 && sideB == 0) || angle == 0)
    {
        ui->label_result_triangleSide->setText("Side C = 0");
        return;
    }

    if (sideA == 0)
    {
        ui->label_result_triangleSide->setText("Side C = " + QString::number(sideB));
        return;
    }

    if (sideA == 0)
    {
        ui->label_result_triangleSide->setText("Side C = " + QString::number(sideA));
        return;
    }

    if (ui->radioButton_degrees->isChecked())
        angle = angle * M_PI / 180;

    double sideC = qSqrt(sideA * sideA + sideB * sideB - 2 * sideA * sideB * cos(angle));
    ui->label_result_triangleSide->setText("Side C = " + QString::number(sideC));
}


void MainWindow::on_pushButton_addHello_clicked()
{
    ui->textEdit_1->moveCursor (QTextCursor::End);
    ui->textEdit_1->insertHtml("<font color='red'>Hello</font>");
    ui->textEdit_1->insertPlainText("\n");
    ui->textEdit_1->moveCursor (QTextCursor::End);
}


void MainWindow::on_pushButton_add1to2_clicked()
{
    ui->textEdit_2->moveCursor (QTextCursor::End);
    ui->textEdit_2->insertHtml(ui->textEdit_1->toHtml());
    ui->textEdit_2->moveCursor (QTextCursor::End);
}


void MainWindow::on_pushButton_replace2to1_clicked()
{
    ui->textEdit_2->clear();
    ui->textEdit_2->insertHtml(ui->textEdit_1->toHtml());
    ui->textEdit_2->moveCursor (QTextCursor::End);
}

