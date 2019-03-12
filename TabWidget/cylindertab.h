#ifndef CYLINDERTAB_H
#define CYLINDERTAB_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QStackedWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <vector>

class HyperGroupBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit HyperGroupBox(const QString& title, QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();

private:
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *zEdit;
    QLineEdit *yEdit;
    QVBoxLayout *hyperLayout;
};

class EllipGroupBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit EllipGroupBox(const QString& title, QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();

private:
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *zEdit;
    QVBoxLayout *ellipLayout;
};

class ParaGroupBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit ParaGroupBox(const QString& title, QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();

private:
    QLineEdit *aEdit;
    QLineEdit *zEdit;
    QLineEdit *yEdit;
    QVBoxLayout *paraLayout;
};

class CylinderTab : public QWidget
{
    Q_OBJECT
public:
    explicit CylinderTab(QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();
    typedef enum{
        Hyperbolic,
        Ellipstic,
        Parabolic
    }cylinderType;

signals:

private slots:
    void btnClicked(int);

private:
    QVBoxLayout *mainLayout;
    QStackedWidget *pStackedWidget;
    QButtonGroup *btnGroup;
    QRadioButton *paraBtn;
    QRadioButton *ellipBtn;
    QRadioButton *hyperBtn;

    HyperGroupBox *hyperGroupBox;
    EllipGroupBox *ellipGroupBox;
    ParaGroupBox *paraGroupBox;
};

#endif // CYLINDERTAB_H
