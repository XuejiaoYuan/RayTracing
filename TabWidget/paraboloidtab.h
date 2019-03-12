#ifndef PARABOLOIDTAB_H
#define PARABOLOIDTAB_H

#include <QWidget>
#include <QLineEdit>
#include <vector>

class ParaboloidTab : public QWidget
{
    Q_OBJECT
public:
    explicit ParaboloidTab(QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();

signals:

public slots:

private:
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *zEdit;
};

#endif // PARABOLOIDTAB_H
