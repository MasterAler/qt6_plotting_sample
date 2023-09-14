#include "MainWidget.h"
#include "./ui_MainWidget.h"

#include <QDebug>

#include "DataGenerator.h"

namespace  {
static const int DATA_RANGE = 100;
static const ulong DATA_INTEVAL_MS = 1500;
}

class MainWidgetPrivate
{
    Q_DECLARE_PUBLIC(MainWidget)

public:
    MainWidgetPrivate(MainWidget* ownerPtr)
        : q_ptr(ownerPtr)
        , ui(new Ui::MainWidget)
        , m_dataGenerator(new DataGenerator(DATA_RANGE, DATA_INTEVAL_MS))
    {}

    MainWidget * const              q_ptr;
    QScopedPointer<Ui::MainWidget>  ui;
    QScopedPointer<DataGenerator>   m_dataGenerator;

    void configUI()
    {
        QObject::connect(ui->startPushButton, &QPushButton::toggled, [this](bool checked) {
            ui->startPushButton->setText(checked ? QObject::tr("Stop") : QObject::tr("Start"));
            m_dataGenerator->setEnabled(checked);
        });

        QObject::connect(ui->resetPushButton, &QAbstractButton::clicked, [this]{
            bool wasEnabled = m_dataGenerator->isEnabled();
            m_dataGenerator->setEnabled(false);
            m_dataGenerator->clearTicks();
            ui->plotWidget->clear();
            m_dataGenerator->setEnabled(wasEnabled);
        });

        QObject::connect(ui->savePushButton, &QAbstractButton::clicked, [this]{
            ui->resultsWidget->addResult(ui->plotWidget->getStats());
        });

        QObject::connect(ui->clearPushButton, &QAbstractButton::clicked, ui->resultsWidget, &ResultsWidget::clear);

        QObject::connect(m_dataGenerator.data(), &DataGenerator::newDataPoint, ui->plotWidget, &PlotWidget::onNewDataPoint, Qt::QueuedConnection);
    }
};

// -------------------------------------------------------------------------------------

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new MainWidgetPrivate(this))
{
    Q_D(MainWidget);

    d->ui->setupUi(this);
    d->configUI();
}

MainWidget::~MainWidget()
{ }

