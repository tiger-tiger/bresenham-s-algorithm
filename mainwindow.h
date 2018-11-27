#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_transformButton_clicked();
    void on_transformButton_2_clicked();
    void on_drawButton_clicked();

private:
    Ui::MainWindow *ui;
    int x1, y1, z1, x2, y2, z2;
    void convert(int ro, double lattd, double longtd, bool flag);
};

#endif // MAINWINDOW_H
