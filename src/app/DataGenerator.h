#pragma once

#include <atomic>

#include <QObject>
#include <QPoint>

class DataGenerator : public QObject
{
    Q_OBJECT
public:
    explicit DataGenerator(int range, ulong frequency);
    ~DataGenerator();

signals:
    void newDataPoint(const QPointF &point);

public slots:
    void setEnabled(bool enabled);

    void doGeneration();

private:
    QThread* m_workerThread = nullptr;
    std::atomic_bool m_isWorking = false;
    std::atomic_bool m_needStop = false;
    int m_range;
    ulong m_frequency;
};
