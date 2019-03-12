#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "TabWidget/ellipsoidtab.h"
#include "TabWidget/quadratictab.h"
#include "TabWidget/paraboloidtab.h"
#include "TabWidget/saddletab.h"
#include "TabWidget/cylindertab.h"

#include <QWidget>
#include <QTabWidget>
#include <vector>

class TabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = 0);
    int getCurrentIndex() { return tabWidget->currentIndex(); }
    void getCurrentParam(std::vector<double>& param);
    void clearLineEdit();

signals:

public slots:

private:
    QTabWidget *tabWidget;
    EllipsoidTab *ellipsoidTab;
    QuadraticTab *quadraticTab;
    ParaboloidTab *paraboloidTab;
    SaddleTab *saddleTab;
    CylinderTab *cylinderTab;

};

#endif // TABWIDGET_H
