#pragma once

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QChartView)
QT_FORWARD_DECLARE_CLASS(QLineSeries)

/*!
 * \brief The PlotWidget class
 * is a line plot widget, can draw data pairs
 */
class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = nullptr);

    /*!
     * \brief getStats -- gets current stats
     * \return         -- (latest X, Sum(Y))
     */
    const QPair<qreal, qreal>& getStats() const;

public slots:
    /*!
     * \brief onNewDataPoint -- adds point to series
     * \param point          -- new data point
     */
    void onNewDataPoint(const QPointF& point);

    /*!
     * \brief clear -- resets widget
     */
    void clear();

protected:
    void resizeEvent(QResizeEvent *) override;

private: // no pImpl, widget is too simple
    QLineSeries* m_defaultLineSeries;
    QChartView *m_defaultChartView;

    QPair<qreal, qreal> m_currentStats = qMakePair(0., 0.);
};
