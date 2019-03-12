#include "TabWidget/paraboloidtab.h"
#include <QLabel>
#include <QValidator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QString>

ParaboloidTab::ParaboloidTab(QWidget *parent) : QWidget(parent)
{
    QGroupBox *paraGroupBox = new QGroupBox("Paraboloid", this);
    QLabel *surfaceFunction = new QLabel(tr("(x/a)^2 + (y/b)^2 - z = 0"));
    //QLabel *rangeLabel = new QLabel(tr("\t(0 <= z <= zMax)"));
    QLabel *aLabel = new QLabel(tr("a (a>0):"));
    QLabel *bLabel = new QLabel(tr("b (b>0):"));
    QLabel *zLabel = new QLabel(tr("zMax (0<=z<=zMax):"));

    QValidator *doubleValidator = new QDoubleValidator();
    aEdit = new QLineEdit();
    bEdit = new QLineEdit();
    zEdit = new QLineEdit();

    aEdit->setValidator(doubleValidator);
    bEdit->setValidator(doubleValidator);
    zEdit->setValidator(doubleValidator);

    QVBoxLayout *paraLayout = new QVBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *aLayout = new QHBoxLayout;
    QHBoxLayout *bLayout = new QHBoxLayout;
    QHBoxLayout *zLayout = new QHBoxLayout;

    aLayout->addWidget(aLabel);
    aLayout->addWidget(aEdit);
    bLayout->addWidget(bLabel);
    bLayout->addWidget(bEdit);
    zLayout->addWidget(zLabel);
    zLayout->addWidget(zEdit);

    paraLayout->addWidget(surfaceFunction);
    paraLayout->addLayout(aLayout);
    paraLayout->addLayout(bLayout);
    paraLayout->addLayout(zLayout);
    paraLayout->addStretch();
    paraGroupBox->setLayout(paraLayout);
    mainLayout->addWidget(paraGroupBox);
    //mainLayout->addStretch();

    setLayout(mainLayout);
}

void ParaboloidTab::getParameters(std::vector<double> &param)
{
    QString str = aEdit->text();
    double a = str.toDouble();
    param.push_back(a);

    str = bEdit->text();
    a = str.toDouble();
    param.push_back(a);

    str = zEdit->text();
    a = str.toDouble();
    param.push_back(a);
}

void ParaboloidTab::clearLineEdit()
{
    aEdit->clear();
    bEdit->clear();
    zEdit->clear();
}
