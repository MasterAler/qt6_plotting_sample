#include "DataGenerator.h"

#include <QThread>

DataGenerator::DataGenerator(int range, ulong frequency)
    : QObject(nullptr)
    , m_workerThread(new QThread(this))
    , m_range(range)
    , m_frequency(frequency)
{
    moveToThread(m_workerThread);
    m_workerThread->start();
    QMetaObject::invokeMethod(this, &DataGenerator::doGeneration);
}

DataGenerator::~DataGenerator()
{
    m_needStop = true;
    m_workerThread->quit();
    m_workerThread->wait();
}

void DataGenerator::setEnabled(bool enabled)
{
    m_isWorking = enabled;
}

void DataGenerator::doGeneration()
{
    while (!m_needStop) {
        QThread::msleep(m_frequency);
        if (m_isWorking) {
            emit newDataPoint({1. * (rand() % m_range), 1. * (rand() % m_range)});
        }
    }
}
