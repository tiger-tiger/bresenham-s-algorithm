#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    refresher = false;
}

void GLWidget::initializeGL()
{
    WIDTH = this->width();
    HEIGHT = this->height();
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);//Two-dimensional orthographic viewing region
}

void GLWidget::paintGL()
{
    myDisplay(x1, y1, x2, y2);
}

void GLWidget::myDisplay(int x1, int y1, int x2, int y2)
{
    drawAches();
    if(refresher)
    {
        drawLine(x1 + WIDTH/2, y1 + HEIGHT/2, x2 + WIDTH/2, y2 + HEIGHT/2);
    }

    glFlush();
}

void GLWidget::drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void GLWidget::sign()
{
    refresher = true;
}

void GLWidget::set_Points(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

void GLWidget::drawLine(int x1, int y1, int x2, int y2)
{
    glColor3f( 34, 139, 34 );
    int lengthX = abs(x2 - x1);
    int lengthY = abs(y2 - y1);

    /*Is needed for moving in all of 4 segments*/
    int dx = (x2 - x1 >= 0 ? 1 : -1);
    int dy = (y2 - y1 >= 0 ? 1 : -1);

    int MainLength = std::max(lengthX, lengthY);

    if (MainLength == 0)
    {
        drawPixel(x1, y1);
    }

    /*Set begin values*/
    int x = x1;
    int y = y1;
    MainLength++;

    if(lengthX > lengthY)
    {
        int d = -lengthX;

        /*Main loop*/
        while(MainLength--)
        {
            drawPixel(x, y);
            x += dx;
            d += 2 * lengthY;

            if(d > 0)
            {
                d -= (2 * lengthX);
                y += dy;
            }
        }
    }
    else if(lengthY > lengthX)
    {
        int d = -lengthY;

        /*Main loop*/
        while(MainLength--)
        {
            drawPixel(x, y);
            y += dy;
            d += 2 * lengthX;

            if(d > 0)
            {
                d -= (2 * lengthY);
                x += dx;
            }
        }
    }
    else
    {
        /*Main loop*/
        /*Move only across diagonal pixels*/
        while(MainLength--)
        {
            drawPixel(x,y);
            x += dx;
            y += dy;
        }
    }
}

void GLWidget::drawAches()
{
    const int START_X = 0;
    const int START_Y = 0;
    const int ARROW_LENGTH = 20;
    const int ARROW_SHIFT = 10;

    glLineWidth(2);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);

    /*Draw X ache and arrows*/
    glVertex2f(START_X, HEIGHT/2);
    glVertex2f(WIDTH, HEIGHT/2);

    glVertex2f(WIDTH, HEIGHT/2);
    glVertex2f(WIDTH - ARROW_LENGTH, HEIGHT/2 - ARROW_SHIFT);
    glVertex2f(WIDTH, HEIGHT/2);
    glVertex2f(WIDTH - ARROW_LENGTH, HEIGHT/2 + ARROW_SHIFT);

    /*Draw Y ache and arrows*/
    glVertex2f(WIDTH/2, START_Y);
    glVertex2f(WIDTH/2, HEIGHT);

    glVertex2f(WIDTH/2, HEIGHT);
    glVertex2f(WIDTH/2 - ARROW_SHIFT, HEIGHT - ARROW_LENGTH);
    glVertex2f(WIDTH/2, HEIGHT);
    glVertex2f(WIDTH/2 + ARROW_SHIFT, HEIGHT - ARROW_LENGTH);
    glEnd();
}
