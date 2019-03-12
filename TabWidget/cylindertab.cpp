#include "TabWidget/cylindertab.h"
#include <QRadioButton>
#include <QLabel>
#include <QValidator>
#include <QGroupBox>
#include <QString>

HyperGroupBox::HyperGroupBox(const QString& title, QWidget *parent) : QGroupBox(title, parent)
{
    QLabel *hyperbolicFunction = new QLabel(tr("(x/a)^2 - (y/b)^2 = 1"));
    QLabel *aLabel = new QLabel(tr("a (a>0):"));
    QLabel *bLabel = new QLabel(tr("b (b>0):"));
    QLabel *zLabel = new QLabel(tr("zMax (0<=z<=zMax):"));
    QLabel *yLabel = new QLabel(tr("yMax (0<=y<=yMax):"));

    QValidator *doubleValidator = new QDoubleValidator();
    aEdit = new QLineEdit();
    bEdit = new QLineEdit();
    zEdit = new QLineEdit();
    yEdit = new QLineEdit();

    aEdit->setValidator(doubleValidator);
    bEdit->setValidator(doubleValidator);
    zEdit->setValidator(doubleValidator);
    yEdit->setValidator(doubleValidator);

    QHBoxLayout *aLayout = new QHBoxLayout;
    QHBoxLayout *bLayout = new QHBoxLayout;
    QHBoxLayout *zLayout = new QHBoxLayout;
    QHBoxLayout *yLayout = new QHBoxLayout;
    hyperLayout = new QVBoxLayout;

    aLayout->addWidget(aLabel);
    aLayout->addWidget(aEdit);
    bLayout->addWidget(bLabel);
    bLayout->addWidget(bEdit);
    zLayout->addWidget(zLabel);
    zLayout->addWidget(zEdit);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yEdit);

    // [Hyperbolic]
    hyperLayout->addWidget(hyperbolicFunction);
    hyperLayout->addLayout(aLayout);
    hyperLayout->addLayout(bLayout);
    hyperLayout->addLayout(zLayout);
    hyperLayout->addLayout(yLayout);
    hyperLayout->addStretch();
    //! [Hyperbolic]
    this->setLayout(hyperLayout);
}

void HyperGroupBox::getParameters(std::vector<double> &param)
{
    param.push_back(0);

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

void HyperGroupBox::clearLineEdit()
{
    aEdit->clear();
    bEdit->clear();
    zEdit->clear();
    yEdit->clear();
}

EllipGroupBox::EllipGroupBox(const QString& title, QWidget *parent) : QGroupBox(title, parent)
{
    QLabel *ellipticFunction = new QLabel(tr("(x/a)^2 + (y/b)^2 = 1"));

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

    QHBoxLayout *aLayout = new QHBoxLayout;
    QHBoxLayout *bLayout = new QHBoxLayout;
    QHBoxLayout *zLayout = new QHBoxLayout;
    ellipLayout = new QVBoxLayout;

    aLayout->addWidget(aLabel);
    aLayout->addWidget(aEdit);
    bLayout->addWidget(bLabel);
    bLayout->addWidget(bEdit);
    zLayout->addWidget(zLabel);
    zLayout->addWidget(zEdit);

    // [Elliptic]
    ellipLayout->addWidget(ellipticFunction);
    ellipLayout->addLayout(aLayout);
    ellipLayout->addLayout(bLayout);
    ellipLayout->addLayout(zLayout);
    ellipLayout->addStretch();
    //! [Elliptic]

    this->setLayout(ellipLayout);
}

void EllipGroupBox::getParameters(std::vector<double> &param)
{
    param.push_back(1);

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

void EllipGroupBox::clearLineEdit()
{
    aEdit->clear();
    bEdit->clear();
    zEdit->clear();
}

ParaGroupBox::ParaGroupBox(const QString& title, QWidget *parent) : QGroupBox(title, parent)
{
    QLabel *parabolicFunction = new QLabel(tr("x^2 + 2ay = 0"));

    QLabel *aLabel = new QLabel(tr("a (a>0):"));
    QLabel *zLabel = new QLabel(tr("zMax (0<=z<=zMax):"));
    QLabel *yLabel = new QLabel(tr("yMax (0<=y<=yMax)"));

    QValidator *doubleValidator = new QDoubleValidator();
    aEdit = new QLineEdit();
    zEdit = new QLineEdit();
    yEdit = new QLineEdit();

    aEdit->setValidator(doubleValidator);
    zEdit->setValidator(doubleValidator);
    yEdit->setValidator(doubleValidator);

    QHBoxLayout *aLayout = new QHBoxLayout;
    QHBoxLayout *zLayout = new QHBoxLayout;
    QHBoxLayout *yLayout = new QHBoxLayout;
    paraLayout = new QVBoxLayout;

    aLayout->addWidget(aLabel);
    aLayout->addWidget(aEdit);
    zLayout->addWidget(zLabel);
    zLayout->addWidget(zEdit);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yEdit);

    // [Parabolic]
    paraLayout->addWidget(parabolicFunction);
    paraLayout->addLayout(aLayout);
    paraLayout->addLayout(zLayout);
    paraLayout->addLayout(yLayout);
    paraLayout->addStretch();
    //! [Parabolic]

    this->setLayout(paraLayout);
}

void ParaGroupBox::getParameters(std::vector<double> &param)
{
    param.push_back(2);

    QString str = aEdit->text();
    double a = str.toDouble();
    param.push_back(a);

    str = zEdit->text();
    a = str.toDouble();
    param.push_back(a);

    str = yEdit->text();
    a = str.toDouble();
    param.push_back(a);
}

void ParaGroupBox::clearLineEdit()
{
    aEdit->clear();
    zEdit->clear();
    yEdit->clear();
}

CylinderTab::CylinderTab(QWidget *parent) : QWidget(parent)
{
    QGroupBox *btnGroupBox = new QGroupBox("Cylinder type", this);

    ellipBtn = new QRadioButton("Elliptic cylinder");
    hyperBtn = new QRadioButton("Hyperbolic cylinder");
    paraBtn = new QRadioButton("Parabolic cylinder");
    btnGroup = new QButtonGroup(this);

    btnGroup->addButton(hyperBtn, Hyperbolic);
    btnGroup->addButton(ellipBtn, Ellipstic);
    btnGroup->addButton(paraBtn, Parabolic);

    hyperBtn->setChecked(true);

    QVBoxLayout *btnLayout = new QVBoxLayout;

    btnLayout->addWidget(hyperBtn);
    btnLayout->addWidget(ellipBtn);
    btnLayout->addWidget(paraBtn);

    btnGroupBox->setLayout(btnLayout);

    hyperGroupBox = new HyperGroupBox("Hyperbolic Cylinder", this);
    ellipGroupBox = new EllipGroupBox("Elliptic Cylinder", this);
    paraGroupBox = new ParaGroupBox("Parabolic Cylinder", this);

    pStackedWidget = new QStackedWidget;
    pStackedWidget->addWidget(hyperGroupBox);
    pStackedWidget->addWidget(ellipGroupBox);
    pStackedWidget->addWidget(paraGroupBox);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(btnGroupBox);
    mainLayout->addWidget(pStackedWidget);
    //mainLayout->addStretch();

    setLayout(mainLayout);

    connect(btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(btnClicked(int)));

}

void CylinderTab::btnClicked(int id)
{
    if(id != pStackedWidget->currentIndex())
    {
        pStackedWidget->setCurrentIndex(id);
    }
}

void CylinderTab::getParameters(std::vector<double> &param)
{
    int id = btnGroup->checkedId();
    switch (id) {
    case 0:
        hyperGroupBox->getParameters(param);
        break;
    case 1:
        ellipGroupBox->getParameters(param);
        break;
    case 2:
        paraGroupBox->getParameters(param);
        break;
    default:
        break;
    }
}

void CylinderTab::clearLineEdit()
{
    int id = btnGroup->checkedId();
    switch (id) {
    case 0:
        hyperGroupBox->clearLineEdit();
        break;
    case 1:
        ellipGroupBox->clearLineEdit();
        break;
    case 2:
        paraGroupBox->clearLineEdit();
        break;
    default:
        break;
    }
}
