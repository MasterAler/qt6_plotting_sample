#pragma once

#include <atomic>

#include <QObject>
#include <QPoint>

/*!
 * \brief The DataGenerator class\
 * busy-loops in a separate thread, notofoes with data points
 */
class DataGenerator : public QObject
{
    Q_OBJECT
public:
    explicit DataGenerator(int range, ulong frequency);
    ~DataGenerator();

    /*!
     * \brief isEnabled -- notifies with new data or not
     * \return          -- on / off
     */
    bool isEnabled() const;

signals:
    void newDataPoint(const QPointF &point);

public slots:
    /*!
     * \brief setEnabled -- doesn't stop worker thread, pauses notifications with new data
     * \param enabled    -- on / off
     */
    void setEnabled(bool enabled);

    /*!
     * \brief clearTicks -- reset X counter
     */
    void clearTicks();

private:
    /*!
     * \brief doGeneration -- worker loop is here
     */
    void doGeneration();

private:
    QThread* m_workerThread = nullptr;
    std::atomic_bool m_isWorking = false;
    std::atomic_bool m_needStop = false;
    std::atomic_int m_tick = 0;
    int m_range;
    ulong m_frequency;
};
