#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <GL/glut.h>
#include <iostream>

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);
    void initializeGL();
    void paintGL();
    //void resizeGL(int w, int h);

private:
    int WIDTH;
    int HEIGHT;
    bool refresher;
    int x1, y1, x2, y2;

public:
    void myDisplay(int x1, int x2, int y1, int y2);
    void drawLine(int x1, int x2, int y1, int y2);
    void drawAches();
    void drawPixel(int x, int y);
    void sign();
    void set_Points(int x1, int y1, int x2, int y2);

};

#endif // GLWIDGET_H
