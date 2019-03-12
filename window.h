#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include "tabwidget.h"
#include "objects.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

signals:

public slots:

private slots:
    void btnClicked(int key);

private:
    typedef enum{
        ENTER,
        CLEAR
    }BtnType;

    Objects *objectWidget;
    TabWidget *tabWidget;
    QButtonGroup *btnGroup;
    QPushButton *enterBtn;
    QPushButton *clearBtn;
};

#endif // WINDOW_H
