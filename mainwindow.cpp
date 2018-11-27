#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), x1(0), y1(0), z1(0), x2(0), y2(0), z2(0)
{
    ui->setupUi(this);

    setWindowTitle("Bresenham's algorithm");

    const QPixmap myRoPix ("://img/ro.png");
    const QPixmap myTetaPix ("://img/teta.png");
    const QPixmap myFeePix ("://img/fee.png");

    ui->label->setPixmap(myRoPix);
    ui->label_2->setPixmap(myTetaPix);
    ui->label_3->setPixmap(myFeePix);

    ui->label_7->setPixmap(myRoPix);
    ui->label_8->setPixmap(myTetaPix);
    ui->label_9->setPixmap(myFeePix);

    ui->xInput->setText(QString::number(x1));
    ui->yInput->setText(QString::number(y1));
    ui->zInput->setText(QString::number(z1));

    ui->xInput_2->setText(QString::number(x2));
    ui->yInput_2->setText(QString::number(y2));
    ui->zInput_2->setText(QString::number(z2));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_transformButton_clicked()
{

    convert(ui->roInput->text().toInt(), ui->tetaInput->text().toDouble(), ui->feeInput->text().toDouble(), true); //true means begin point
    ui->xInput->setText(QString::number(x1));
    ui->yInput->setText(QString::number(y1));
    ui->zInput->setText(QString::number(z1));
}

void MainWindow::on_transformButton_2_clicked()
{

    convert(ui->roInput_2->text().toInt(), ui->tetaInput_2->text().toDouble(), ui->feeInput_2->text().toDouble(), false); //false means end point
    ui->xInput_2->setText(QString::number(x2));
    ui->yInput_2->setText(QString::number(y2));
    ui->zInput_2->setText(QString::number(z2));
}


void MainWindow::on_drawButton_clicked()
{
    ui->openGLWidget->set_Points(x1, y1, x2, y2);
    ui->openGLWidget->sign();
    ui->openGLWidget->paintGL();
    ui->openGLWidget->update();
}

void MainWindow::convert(int ro, double lattd, double longtd, bool flag)
{
    const double PI = 3.14159265;
    const double RADIAN = 180.0;
    int* x = nullptr;
    int* y = nullptr;
    int* z = nullptr;

    /*For verifying first or last point*/
    if (flag)
    {
        x = &x1;
        y = &y1;
        z = &z1;
    }
    else
    {
        x = &x2;
        y = &y2;
        z = &z2;
    }

    lattd *= PI/RADIAN;
    longtd *= PI/RADIAN;

    *x = static_cast<int>(ro * sin(lattd) * cos(longtd));
    *y = static_cast<int>(ro * sin(lattd) * sin(longtd));
    *z = static_cast<int>(ro * cos(lattd));


}
