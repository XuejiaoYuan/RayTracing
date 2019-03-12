#ifndef QUADRATICTAB_H
#define QUADRATICTAB_H

#include <QWidget>
#include <QLineEdit>
#include <vector>

class QuadraticTab : public QWidget
{
    Q_OBJECT
public:
    explicit QuadraticTab(QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();

signals:

public slots:

private:
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *cEdit;
    QLineEdit *dEdit;
    QLineEdit *zEdit;
};

#endif // QUADRATICTAB_H
