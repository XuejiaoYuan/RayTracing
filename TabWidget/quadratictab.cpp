#include "TabWidget/quadratictab.h"
#include <QLabel>
#include <QValidator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QString>

QuadraticTab::QuadraticTab(QWidget *parent) : QWidget(parent)
{
    QGroupBox *quaGroupBox = new QGroupBox("Quadratic", this);
    QLabel *surfaceFunction = new QLabel(tr("(x/a)^2 + (y/b)^2 - (z/c)^2 = D"));
    //QLabel *rangeLabel = new QLabel(tr("\t(0 <= z <= zMax)"));
    QLabel *aLabel = new QLabel(tr("a (a>0):"));
    QLabel *bLabel = new QLabel(tr("b (b>0):"));
    QLabel *cLabel = new QLabel(tr("c (c>0):"));
    QLabel *dLabel = new QLabel(tr("D (D=1, 0, -1):"));
    QLabel *zLabel = new QLabel(tr("zMax (0<=z<=zMax):"));
    QValidator *doubleValidator = new QDoubleValidator();

    aEdit = new QLineEdit();
    bEdit = new QLineEdit();
    cEdit = new QLineEdit();
    dEdit = new QLineEdit();
    zEdit = new QLineEdit();

    aEdit->setValidator(doubleValidator);
    bEdit->setValidator(doubleValidator);
    cEdit->setValidator(doubleValidator);
    dEdit->setValidator(new QIntValidator);
    zEdit->setValidator(doubleValidator);

    QVBoxLayout *quaLayout = new QVBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *aLayout = new QHBoxLayout;
    QHBoxLayout *bLayout = new QHBoxLayout;
    QHBoxLayout *cLayout = new QHBoxLayout;
    QHBoxLayout *dLayout = new QHBoxLayout;
    QHBoxLayout *zLayout = new QHBoxLayout;

    aLayout->addWidget(aLabel);
    aLayout->addWidget(aEdit);
    bLayout->addWidget(bLabel);
    bLayout->addWidget(bEdit);
    cLayout->addWidget(cLabel);
    cLayout->addWidget(cEdit);
    dLayout->addWidget(dLabel);
    dLayout->addWidget(dEdit);
    zLayout->addWidget(zLabel);
    zLayout->addWidget(zEdit);

    quaLayout->addWidget(surfaceFunction);
    quaLayout->addLayout(aLayout);
    quaLayout->addLayout(bLayout);
    quaLayout->addLayout(cLayout);
    quaLayout->addLayout(dLayout);
    quaLayout->addLayout(zLayout);
    quaLayout->addStretch();
    quaGroupBox->setLayout(quaLayout);
    mainLayout->addWidget(quaGroupBox);
    //mainLayout->addStretch();

    setLayout(mainLayout);
}

void QuadraticTab::getParameters(std::vector<double> &param)
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

    str = dEdit->text();
    a = str.toDouble();
    param.push_back(a);

    str = zEdit->text();
    a = str.toDouble();
    param.push_back(a);
}

void QuadraticTab::clearLineEdit()
{
    aEdit->clear();
    bEdit->clear();
    cEdit->clear();
    dEdit->clear();
    zEdit->clear();
}
