#include "tabwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

TabWidget::TabWidget(QWidget *parent) : QWidget(parent)
{
    tabWidget = new QTabWidget;
    ellipsoidTab = new EllipsoidTab;
    quadraticTab = new QuadraticTab;
    paraboloidTab = new ParaboloidTab;
    saddleTab = new SaddleTab;
    cylinderTab = new CylinderTab;

    tabWidget->addTab(ellipsoidTab, tr("Ellipsoid"));
    tabWidget->addTab(quadraticTab, tr("Quadratic"));
    tabWidget->addTab(paraboloidTab, tr("Paraboloid"));
    tabWidget->addTab(saddleTab, tr("Saddle"));
    tabWidget->addTab(cylinderTab, tr("Cylinder"));

    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(tabWidget);

    setLayout(mainLayout);
}

void TabWidget::getCurrentParam(std::vector<double>& param)
{
    int index = tabWidget->currentIndex();
    switch (index) {
    case 0:
        ellipsoidTab->getParameters(param);
        break;
    case 1:
        quadraticTab->getParameters(param);
        break;
    case 2:
        paraboloidTab->getParameters(param);
        break;
    case 3:
        saddleTab->getParameters(param);
        break;
    case 4:
        cylinderTab->getParameters(param);
        break;
    default:
        break;
    }
}

void TabWidget::clearLineEdit()
{
    int index = tabWidget->currentIndex();
    switch (index) {
    case 0:
        ellipsoidTab->clearLineEdit();
        break;
    case 1:
        quadraticTab->clearLineEdit();
        break;
    case 2:
        paraboloidTab->clearLineEdit();
        break;
    case 3:
        saddleTab->clearLineEdit();
        break;
    case 4:
        cylinderTab->clearLineEdit();
        break;
    default:
        break;
    }
}
