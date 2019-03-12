#include "window.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

Window::Window(QWidget *parent) : QWidget(parent)
{
    tabWidget = new TabWidget(parent);
    objectWidget = new Objects(this);

    btnGroup = new QButtonGroup;

    enterBtn = new QPushButton("Enter");
    clearBtn = new QPushButton("Clear");

    btnGroup->addButton(enterBtn, ENTER);
    btnGroup->addButton(clearBtn, CLEAR);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;

    btnLayout->addWidget(enterBtn);
    btnLayout->addWidget(clearBtn);

    leftLayout->addWidget(objectWidget);
    rightLayout->addWidget(tabWidget);
    rightLayout->addLayout(btnLayout);
    rightLayout->addStretch();

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setFixedSize(1050, 600);

    connect(btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(btnClicked(int)));
}

void Window::btnClicked(int key)
{
    int index = tabWidget->getCurrentIndex();
    std::vector<double> param;
    switch (key) {
    case ENTER:
        tabWidget->getCurrentParam(param);
        objectWidget->setParameters(index, param);
        objectWidget->repaint();
        break;
    case CLEAR:
        tabWidget->clearLineEdit();
        objectWidget->clearParameters();
        objectWidget->repaint();
        break;
    default:
        break;
    }
}
