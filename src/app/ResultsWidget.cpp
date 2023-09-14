#include "ResultsWidget.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QDebug>

class ResultsWidgetPrivate
{
    Q_DECLARE_PUBLIC(ResultsWidget)
public:
    ResultsWidgetPrivate(ResultsWidget *owner)
        : q_ptr(owner)
        , m_resultsWidget(new QWidget)
        , m_itemsWidget(new QWidget(m_resultsWidget))
    {
        auto* titleLayout = new QHBoxLayout;
        titleLayout->setContentsMargins(0, 0, 0, 0);
        titleLayout->addWidget(new QLabel("#", m_resultsWidget));
        titleLayout->addWidget(new QLabel("Count", m_resultsWidget));
        titleLayout->addWidget(new QLabel("Sum", m_resultsWidget));

        m_itemsLayout = new QVBoxLayout;
        m_itemsWidget->setLayout(m_itemsLayout);
        m_itemsLayout->setContentsMargins(0, 0, 0, 0);

        auto* mainLayout = new QVBoxLayout;
        m_resultsWidget->setLayout(mainLayout);
        mainLayout->setContentsMargins(5, 0, 0, 0);
        mainLayout->addLayout(titleLayout);
        mainLayout->addWidget(m_itemsWidget);
        mainLayout->addStretch(1);

        owner->setWidget(m_resultsWidget);
        owner->setWidgetResizable(true);
    }

    ResultsWidget * const q_ptr;
    QWidget*              m_resultsWidget;
    QWidget*              m_itemsWidget;
    QVBoxLayout*          m_itemsLayout;
    int                   m_itemCount = 0;

    void addItem(qreal count, qreal sum) // We can put logic into pImpl
    {
        m_itemsLayout->removeItem(m_itemsLayout->itemAt(m_itemsLayout->count() - 1));

        auto* l = new QHBoxLayout;
        QWidget* w = new QWidget(m_itemsWidget);
        w->setLayout(l);
        l->setContentsMargins(0, 0, 0, 0);
        l->addWidget(new QLabel(QString::number(++m_itemCount), w));
        l->addWidget(new QLabel(QString::number(count), w));
        l->addWidget(new QLabel(QString::number(sum), w));

        m_itemsLayout->addWidget(w);
        m_itemsLayout->addStretch(1);
    }
};

// -------------------------------------------------------------------------------------

ResultsWidget::ResultsWidget(QWidget *parent)
    : QScrollArea(parent)
    , d_ptr(new ResultsWidgetPrivate(this))
{ }

void ResultsWidget::addResult(const QPair<qreal, qreal> &result)
{
    Q_D(ResultsWidget);
    d->addItem(result.first, result.second);
}

void ResultsWidget::clear() // ... or we can write code in widget's methods
{
    Q_D(ResultsWidget);
    while (d->m_itemsLayout->count() > 0) { // let's hope I remember correct, how it's done ^_^
        auto *item = d->m_itemsLayout->itemAt(0);
        d->m_itemsLayout->removeItem(item);
        item->widget()->deleteLater();
        delete item;
    }
    d->m_itemsLayout->addStretch(1);
    d->m_itemCount = 0;
}
