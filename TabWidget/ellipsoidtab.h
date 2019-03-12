#ifndef ELLIPSOIDTAB_H
#define ELLIPSOIDTAB_H

#include <QWidget>
#include <QLineEdit>
#include <vector>

class EllipsoidTab : public QWidget
{
    Q_OBJECT
public:
    explicit EllipsoidTab(QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();

signals:

public slots:

private:
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *cEdit;
};

#endif // ELLIPSOIDTAB_H
