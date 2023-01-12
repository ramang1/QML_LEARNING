#include "someclas.h"
#include <QDebug>
#include <QThread>
#include <QCoreApplication>
SomeClass::SomeClass(QObject *parent)
    : QObject(parent)
    , m_percent(0)
{
    qDebug() << "Da tao classed" << m_percent;


}

int SomeClass::percentValue()
{
    return m_percent;
}

void SomeClass::setPercentValue(int newPercent)
{
    if (newPercent != m_percent){
        m_percent = newPercent;
        emit percentValueChanged();
    }
}

void SomeClass::callMe(int timersleep)
{
    qDebug() << "Ban da goi ham call me voi timersleep " << timersleep;

    if (timersleep <= 0) return;
    int tmpValue = 0;
    while (tmpValue < 100){
        tmpValue ++;
        setPercentValue(tmpValue);
        QThread::msleep(100);
        QCoreApplication::processEvents();
        qDebug() << "gia tri percent " << QString::number(m_percent, 'f', 2) << "%";

    }

}
