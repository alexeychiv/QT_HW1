#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_countRoots_clicked();

    void on_pushButton_countTriangleSide_clicked();

    void on_pushButton_addHello_clicked();

    void on_pushButton_add1to2_clicked();

    void on_pushButton_replace2to1_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
