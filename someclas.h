#ifndef SOMECLAS_H
#define SOMECLAS_H

#include <QObject>

class SomeClass : public QObject
{
    Q_OBJECT
public:
    explicit SomeClass(QObject *parent = nullptr);
    Q_PROPERTY(int percentValue READ percentValue WRITE setPercentValue NOTIFY percentValueChanged);
    Q_INVOKABLE int percentValue();
    Q_INVOKABLE void setPercentValue(int newPercent);
signals:
    void percentValueChanged();
public slots:
    void callMe(int timersleep);
private:
    int m_percent;

};

#endif // SOMECLAS_H
