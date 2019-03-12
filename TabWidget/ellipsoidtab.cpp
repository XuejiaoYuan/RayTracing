#include "TabWidget/ellipsoidtab.h"
#include <QLabel>
#include <QValidator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QString>

EllipsoidTab::EllipsoidTab(QWidget *parent) : QWidget(parent)
{
    QGroupBox *ellipGroupBox = new QGroupBox("Ellipsoid", this);
    QLabel *surfaceFunction = new QLabel(tr("(x/a)^2 + (y/b)^2 + (z/c)^2 = 1"));
    QLabel *aLabel = new QLabel(tr("a (a>0):"));
    QLabel *bLabel = new QLabel(tr("b (b>0):"));
    QLabel *cLabel = new QLabel(tr("c (c>0):"));
    QValidator *doubleValidator = new QDoubleValidator();
    aEdit = new QLineEdit();
    bEdit = new QLineEdit();
    cEdit = new QLineEdit();
    aEdit->setValidator(doubleValidator);
    bEdit->setValidator(doubleValidator);
    cEdit->setValidator(doubleValidator);

    QVBoxLayout *ellipLayout = new QVBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *aLayout = new QHBoxLayout;
    QHBoxLayout *bLayout = new QHBoxLayout;
    QHBoxLayout *cLayout = new QHBoxLayout;
    aLayout->addWidget(aLabel);
    aLayout->addWidget(aEdit);
    bLayout->addWidget(bLabel);
    bLayout->addWidget(bEdit);
    cLayout->addWidget(cLabel);
    cLayout->addWidget(cEdit);


    ellipLayout->addWidget(surfaceFunction);
    ellipLayout->addLayout(aLayout);
    ellipLayout->addLayout(bLayout);
    ellipLayout->addLayout(cLayout);
    ellipLayout->addStretch();
    ellipGroupBox->setLayout(ellipLayout);
    mainLayout->addWidget(ellipGroupBox);
    //mainLayout->addStretch();

    setLayout(mainLayout);
}

void EllipsoidTab::getParameters(std::vector<double>& param)
{
    QString str = aEdit->text();
    double a = str.toDouble();
    param.push_back(a);

    str = bEdit->text();
    a = str.toDouble();
    param.push_back(a);

    str = cEdit->text();
    a = str.toDouble();
    param.push_back(a);
}

void EllipsoidTab::clearLineEdit()
{
    aEdit->clear();
    bEdit->clear();
    cEdit->clear();
}
