#ifndef DF_TANK_V1_H
#define DF_TANK_V1_H

#include "qchartview.h"
#include "qcustomplot.h"
#include <QMainWindow>
#include <windows.h>
#include <QTimer>
#include <QVector>
#include <QUdpSocket>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLineSeries>
#include <QElapsedTimer>
#include <QtGui/QPixmap>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QAreaSeries>
#include <QDebug>
#include <QtCharts/QPolarChart>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

#include <QDebug>
#include <QtCharts/QSplineSeries>






QT_BEGIN_NAMESPACE
namespace Ui {
class df_tank_v1;
}
QT_END_NAMESPACE

class df_tank_v1 : public QMainWindow
{
    Q_OBJECT

public:
    df_tank_v1(QWidget *parent = nullptr);
    ~df_tank_v1();
private slots:
    void readDatagrams2();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
    void do_processing();
    void do_plotting();

private:
    Ui::df_tank_v1 *ui;
    QUdpSocket *socket2;
    int x_itr=1, x_lop=0,top_count;
    int numSamples = 1000000;    // 1 million samples
    int angl=10, pkt_loss=1, angl_info ;

    double f1=400000000;
    double f2=5900000000;
    int x_itr1z=0, x_lop1z=1;
    // float angle_to_addz=0.1757;
    float angle_to_addz=0.0078;
    int data_size = 5760;
    QVector<double> values = {1, 3, 2, 5, 4,15,11,9,7,6,4,1}; // Heights of bars
    QVector<double> ticks = {1,2,3,4,5,6,7,8,9,10,11,12};  // X coordinates for bars


    QVector <double> freq_list;

    QVector<double> xxDataz;
    QVector<double> yyDataz;
    QVector<double> yyDataz2;
    QVector<double> random_data;
    QVector<double> dB_list;
    QVector<double> index_list;

    QPolarChart *polarChartz;
    QLineSeries *series11z;
    QScatterSeries *series1z;
    QValueAxis *angularAxisz;
    QValueAxis *radialAxisz;
    QChartView *chartViewz;
    QSplineSeries *seriez;
    QSplineSeries *seriez2;
    QCPBars *freks;
    QCPItemText *label;
    QVector<QPointF> peaks_info; // New vector to store the highest point

    QGraphicsScene *scene = new QGraphicsScene(this);

    QGraphicsEllipseItem *ellipse;





};
#endif // DF_TANK_V1_H
