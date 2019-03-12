#ifndef SADDLETAB_H
#define SADDLETAB_H

#include <QWidget>
#include <QLineEdit>
#include <vector>

class SaddleTab : public QWidget
{
    Q_OBJECT
public:
    explicit SaddleTab(QWidget *parent = 0);
    void getParameters(std::vector<double>& param);
    void clearLineEdit();

signals:

public slots:

private:
    QLineEdit *aEdit;
    QLineEdit *bEdit;
    QLineEdit *zEdit;
    QLineEdit *yEdit;
};

#endif // SADDLETAB_H
