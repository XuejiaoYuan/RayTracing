#include "TabWidget/saddletab.h"
#include <QLabel>
#include <QValidator>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QString>

SaddleTab::SaddleTab(QWidget *parent) : QWidget(parent)
{
    QGroupBox *saddleGroupBox = new QGroupBox("Saddle", this);
    QLabel *surfaceFunction = new QLabel(tr("(x/a)^2 - (y/b)^2 - z = 0"));
    QLabel *aLabel = new QLabel(tr("a (a>0):"));
    QLabel *bLabel = new QLabel(tr("b (b>0):"));
    QLabel *zLabel = new QLabel(tr("zMax (0<=z<=zMax):"));
    QLabel *yLabel = new QLabel(tr("yMax (0<=y<=yMax)"));

    QValidator *doubleValidator = new QDoubleValidator();
    aEdit = new QLineEdit();
    bEdit = new QLineEdit();
    zEdit = new QLineEdit();
    yEdit = new QLineEdit();

    aEdit->setValidator(doubleValidator);
    bEdit->setValidator(doubleValidator);
    zEdit->setValidator(doubleValidator);
    yEdit->setValidator(doubleValidator);

    QVBoxLayout *saddleLayout = new QVBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *aLayout = new QHBoxLayout;
    QHBoxLayout *bLayout = new QHBoxLayout;
    QHBoxLayout *zLayout = new QHBoxLayout;
    QHBoxLayout *yLayout = new QHBoxLayout;

    aLayout->addWidget(aLabel);
    aLayout->addWidget(aEdit);
    bLayout->addWidget(bLabel);
    bLayout->addWidget(bEdit);
    zLayout->addWidget(zLabel);
    zLayout->addWidget(zEdit);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yEdit);

    saddleLayout->addWidget(surfaceFunction);
    saddleLayout->addLayout(aLayout);
    saddleLayout->addLayout(bLayout);
    saddleLayout->addLayout(zLayout);
    saddleLayout->addLayout(yLayout);
    saddleLayout->addStretch();
    saddleGroupBox->setLayout(saddleLayout);
    mainLayout->addWidget(saddleGroupBox);
    //mainLayout->addStretch();

    setLayout(mainLayout);
}

void SaddleTab::getParameters(std::vector<double> &param)
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

    str = yEdit->text();
    a = str.toDouble();
    param.push_back(a);
}

void SaddleTab::clearLineEdit()
{
    aEdit->clear();
    bEdit->clear();
    zEdit->clear();
    yEdit->clear();
}
