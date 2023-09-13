#pragma once

#include <QWidget>

QT_FORWARD_DECLARE_CLASS(QChartView)
QT_FORWARD_DECLARE_CLASS(QLineSeries)

class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = nullptr);

public slots:
    void onNewDataPoint(const QPointF& point);

    void clear();

protected:
    void resizeEvent(QResizeEvent *) override;

private:
    QLineSeries* m_defaultLineSeries;
    QChartView *m_defaultChartView;

    QPair<qreal, qreal> m_currentStats = qMakePair(0., 0.);
};
