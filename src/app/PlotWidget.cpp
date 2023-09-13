#include "PlotWidget.h"

#include <QChart>
#include <QChartView>
#include <QLineSeries>

PlotWidget::PlotWidget(QWidget *parent)
    : QWidget(parent)
    , m_defaultLineSeries(new QLineSeries)
{
    QChart* chart = new QChart;
    chart->legend()->hide();
    chart->addSeries(m_defaultLineSeries);
    chart->setTitle("Mysterious Data");

    m_defaultChartView = new QChartView(chart, this);
    m_defaultChartView->setRenderHint(QPainter::Antialiasing);
}

void PlotWidget::onNewDataPoint(const QPointF &point)
{
    m_defaultChartView->chart()->removeSeries(m_defaultLineSeries);
    m_defaultLineSeries->append(point);
    m_defaultChartView->chart()->addSeries(m_defaultLineSeries);
    m_defaultChartView->chart()->createDefaultAxes();

    m_currentStats.first = point.x();
    m_currentStats.second += point.y();
}

void PlotWidget::clear()
{
    m_defaultChartView->chart()->removeSeries(m_defaultLineSeries);
    m_defaultLineSeries->clear();
    m_defaultChartView->chart()->addSeries(m_defaultLineSeries);
    m_currentStats = qMakePair(0., 0.);
}

void PlotWidget::resizeEvent(QResizeEvent *)
{
    if (m_defaultChartView)
        m_defaultChartView->resize(size());
}
