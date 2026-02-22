#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , genAlgorithm(0, 10)
{
    ui->setupUi(this);

    setWindowTitle("Лабораторна робота №7");

    drawGraphic();

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::drawGraphic() {
    QLineSeries* functionSeries = new QLineSeries();
    for (double x = genAlgorithm.getXmin(); x <= genAlgorithm.getXmax(); x += 0.01)
        functionSeries->append(x, genAlgorithm.function(x));
    functionSeries->setName("Функція Y(x)");
    functionSeries->setColor(Qt::darkGreen);

    double maxX = genAlgorithm.findMax();
    double minX = genAlgorithm.findMin();

    auto createPoint = [&](double x, Qt::GlobalColor color, const QString& name) {
        QScatterSeries* point = new QScatterSeries();
        point->append(x, genAlgorithm.function(x));
        point->setMarkerSize(12);
        point->setColor(color);
        point->setName(name);
        return point;
    };

    QChart* chart = new QChart();
    chart->addSeries(functionSeries);
    chart->addSeries(createPoint(maxX, Qt::red, "Максимум"));
    chart->addSeries(createPoint(minX, Qt::blue, "Мінімум"));
    chart->createDefaultAxes();
    chart->setTitle("Y(x) = -x^cos(5x)");

    auto axisX = qobject_cast<QValueAxis*>(chart->axes(Qt::Horizontal).first());
    auto axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());

    axisX->setRange(genAlgorithm.getXmin() - 0.25, genAlgorithm.getXmax() + 0.25);
    axisY->setRange(functionSeries->points().first().y() - 2,
                    functionSeries->points().last().y() + 2);

    chart->legend()->setAlignment(Qt::AlignBottom);
    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
}
