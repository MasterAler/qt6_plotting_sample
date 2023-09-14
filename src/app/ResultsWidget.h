#pragma once

#include <QScrollArea>

QT_FORWARD_DECLARE_CLASS(ResultsWidgetPrivate)

class ResultsWidget : public QScrollArea
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(ResultsWidget)

public:
    explicit ResultsWidget(QWidget *parent = nullptr);

public slots:
    /*!
     * \brief addResult -- adds stats pair
     * \param result    -- stat data pair
     */
    void addResult(const QPair<qreal, qreal>& result);

    /*!
     * \brief clear -- clears items
     */
    void clear();

private:
    QScopedPointer<ResultsWidgetPrivate> d_ptr;
};
