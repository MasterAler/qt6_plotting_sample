#pragma once

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidgetPrivate;

class MainWidget : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(MainWidget)

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    QScopedPointer<MainWidgetPrivate> d_ptr;
};
