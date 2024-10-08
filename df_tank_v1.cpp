#include "df_tank_v1.h"
#include "ui_df_tank_v1.h"
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>



df_tank_v1::df_tank_v1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::df_tank_v1)
{
    ui->setupUi(this);

    QGraphicsView *graphicsView = new QGraphicsView(scene, this);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    ellipse = scene->addEllipse(0,0, 200, 200, QPen(Qt::white), QBrush(Qt::black));

    // Add text at a specific location (x=100, y=150)
    QGraphicsTextItem *textItem = scene->addText("N");
    textItem->setPos(90, 5); // Set position for the text

    // Add text at a specific location (x=100, y=150)
    QGraphicsTextItem *textItem2 = scene->addText("S");
    textItem2->setPos(90, 175); // Set position for the text

    // Add text at a specific location (x=100, y=150)
    QGraphicsTextItem *textItem3 = scene->addText("W");
    textItem3->setPos(5, 90); // Set position for the text

    // Add text at a specific location (x=100, y=150)
    QGraphicsTextItem *textItem4 = scene->addText("E");
    textItem4->setPos(175, 90); // Set position for the text

    // Add text at a specific location (x=100, y=150)
    //QGraphicsLineItem *lineItem = scene->addLine(175, 175, 80, 80);
    //lineItem->setPos(175, 90); // Set position for the text





    // Set layout
    ui->gridLayout_2->addWidget(graphicsView);
    setLayout( ui->gridLayout_2);



    //===========Initailzing Custom Plot==========================================================================

    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customplot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    freks = new QCPBars(   ui->customplot->xAxis,    ui->customplot->yAxis);

    freks->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    freks->setBrush(QColor(0, 168, 140));

    // Dummy data
    // QVector<QString> ticks = {"2200MHz", "2GHz", "3.5GHz", "4GHz", "5GHz"};  // X coordinates for bars
    // QVector<double> ticks = {0,30,60,90,120,150,180,210,240,270,300,330,360};  // X coordinates for bars


    QStringList labels = {"30", "60", "90", "120","150", "180", "210", "240", "270","300", "330", "360"};

    // prepare x axis with Data labels:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setTickLabelRotation(60);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0, 4);
    ui->customplot->xAxis->setRange(0, 13);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white));
    ui->customplot->xAxis->setTickPen(QPen(Qt::white));
    ui->customplot->xAxis->grid()->setVisible(true);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->setLabelColor(Qt::white);
    ui->customplot->xAxis->setLabel("Rotation Angles");


    // prepare y axis:
    ui->customplot->yAxis->setRange(0, 80);
    ui->customplot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customplot->yAxis->setLabel("dB Amplitude");
    ui->customplot->yAxis->setBasePen(QPen(Qt::white));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setLabelColor(Qt::white);
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


    freks->setData(ticks, values);

    // setup legend:
     //ui->customplot->legend->setVisible(true);
     //ui->customplot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
     //ui->customplot->legend->setBrush(QColor(255, 255, 255, 100));
     //ui->customplot->legend->setBorderPen(Qt::NoPen);
    //QFont legendFont = font();
    //legendFont.setPointSize(10);
    //ui->customplot->legend->setFont(legendFont);
    ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


    // ui->customplot->setBackground(QBrush(QColor(0, 0, 0))); // Set background color to black (RGB: 0, 0, 0)
    // ui->customplot->addGraph();
    // ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    // ui->customplot->graph(0)->setLineStyle(QCPGraph::lsLine);
    // ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    // // Set plot labels and titles
    // ui->customplot->xAxis->setLabel("Frequency (MHz/GHz)");
    // ui->customplot->yAxis->setLabel("Amplitude (Db)");


    // // Set font color to white for x-axis label
    // ui->customplot->xAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for y-axis label
    // ui->customplot->yAxis->setLabelColor(QColor(27, 196, 145));

    // // Set font color to white for graph text
    // ui->customplot->graph(0)->setPen(QColor(27, 196, 145));

    // // Set font color to white for axis ticks and labels
    // ui->customplot->xAxis->setTickLabelColor(QColor(27, 196, 145));
    // ui->customplot->yAxis->setTickLabelColor(QColor(27, 196, 145));

    // // Set font color to white for axis line
    // ui->customplot->xAxis->setBasePen(QColor(27, 196, 145));
    // ui->customplot->yAxis->setBasePen(QColor(27, 196, 145));

    // // Set font color to white for axis grid lines
    // ui->customplot->xAxis->grid()->setPen(QColor(212, 175, 55));
    // ui->customplot->yAxis->grid()->setPen(QColor(212, 175, 55));

    // // Set font color to white for legend
    // ui->customplot->legend->setBrush(QColor(27, 196, 145));
    // ui->customplot->legend->setTextColor(QColor(27, 196, 145));


    // QPen pen;
    // pen.setColor(Qt::red);  // Set color to red
    // ui->customplot->addGraph();
    // ui->customplot->graph(1)->setPen(pen);
    // ui->customplot->graph(1)->setScatterStyle(QCPScatterStyle::ssCircle);
    // ui->customplot->graph(1)->setLineStyle(QCPGraph::lsNone);
    //========================================Polar Satart=========================================================

    polarChartz = new QPolarChart();
    //polarChartz->setAnimationOptions(QChart::AllAnimations);

    // polarChart->setTitle("Direction Finder");
    QColor rgbaColor(43, 53, 86); // Red color with 50% transparency
    rgbaColor.setAlpha(30);
    QBrush brush(rgbaColor);
    polarChartz->setBackgroundBrush(brush);
    QColor rgbaColor3(0, 0, 0); // Red color with 50% transparency
    //rgbaColor3.setAlpha(80);
    QBrush brush3(rgbaColor3);
    polarChartz->setPlotAreaBackgroundVisible(true);
    polarChartz->setPlotAreaBackgroundBrush(brush3);


    // // Create angular and radial axes
    angularAxisz = new QValueAxis();
    angularAxisz->setTickCount(9); // 8 sectors + 1 to complete the circle
    angularAxisz->setLabelFormat("%.0f");
    angularAxisz->setRange(0, 360);
    angularAxisz->setLabelsColor(Qt::white);
    angularAxisz->setGridLineColor(Qt::green);
    polarChartz->addAxis(angularAxisz, QPolarChart::PolarOrientationAngular);

    radialAxisz = new QValueAxis();
    //radialAxisz->setShadesVisible(QGradient::TrueSunset);
    //radialAxisz->setShadesBrush(QBrush(QColor(249, 249, 55)));

    radialAxisz->setTickCount(10);
    radialAxisz->setLabelFormat("%.1f");
    radialAxisz->setRange(0, 90); // Example range, can be adjusted
    radialAxisz->setLabelsColor(Qt::white);
    radialAxisz->setGridLineColor(Qt::green);
    polarChartz->addAxis(radialAxisz,QPolarChart::PolarOrientationRadial);

    // // Create a scatter series to plot points in sector 7 (270 to 315 degrees)
    //series = new QScatterSeries();
    //series = new QLineSeries();
    seriez = new QSplineSeries();
    seriez->setPointsVisible(false);
    seriez->setMarkerSize(8);
    seriez->setName("Ploting Channel 7");
    seriez->append(45, 205); // Example point (angle, radius)
    seriez->append(75, 150);
    seriez->append(115, 50);
    seriez->append(0, 0);
    seriez->append(0, 0);
    seriez->append(225, 50); // main lobe start
    seriez->append(250, 100); // maib lobe mid
    seriez->append(275, 50); // main lobe end
    seriez->append(0, 0);
    seriez->append(0, 0);
    seriez->append(360,0);
    seriez->append(15, 105); //back lobe
    seriez->append(45, 205); //backlobe

    // series->sortByAngle();

    // // Set series properties
    // series->setConnectPoints(true); // Enable line connections between points
    // series->setWrapAround(true);

    //// Define area series for filling
    //QAreaSeries *areaSeries = new QAreaSeries(seriez, seriez2);
    //areaSeries->setName("Filled Area");

    //// Customize the appearance of the filled area
    //areaSeries->setBrush(QBrush(QColor(255, 0, 0, 100))); // Set fill color with transparency (e.g., semi-transparent red)
    //areaSeries->setPen(QPen(QColor(255, 0, 0))); // Set border color

    QBrush markerBrush(Qt::green);
    seriez->setBrush(markerBrush);
    // // Set the outline color of the points to black
    QPen black_pen = *new QPen();
    black_pen = seriez->pen(); // Get current pen settings
    black_pen.setColor(Qt::white); // Set outline color to black
    //black_pen.brush()
    black_pen.setWidth(2); // Set outline width (optional)
    seriez->setPen(black_pen); // Apply the updated pen to the series



    //polarChartz->addSeries(areaSeries);
    polarChartz->addSeries(seriez);

    //polarChartz->createDefaultAxes();

    // Attach the series to the axes
    seriez->attachAxis(angularAxisz);
    seriez->attachAxis(radialAxisz);

    // // Create a chart view with zooming enabled
    chartViewz = new QChartView(polarChartz);
    chartViewz->setRenderHint(QPainter::Antialiasing);

    QColor rgbaColor2(43, 53, 86); // Red color with 50% transparency
    rgbaColor2.setAlpha(30);
    QBrush brush2(rgbaColor2);

    chartViewz->setBackgroundBrush(brush2);

    // Create a scene and add the chart to it
    QGraphicsScene *scene = new QGraphicsScene(chartViewz);
    scene->addItem(polarChartz);
    chartViewz->setScene(scene);


    //chartView->setMinimumSize(200, 380);

    ui->gridLayout->addWidget(chartViewz);
}

df_tank_v1::~df_tank_v1()
{
    delete ui;
    delete socket2;
}

void df_tank_v1::do_processing(){
    float x_freq=(f2-f1)/5760;
    //int pkt_nbr= yyDataz[1];

    //if(pkt_nbr <=89){
        for (int d = 0; d < random_data.size(); ++d) {

            float xfreq=f1+(x_freq*x_itr);
            xxDataz.append(xfreq);
            //xxDataz.append(x_itr);
            yyDataz2.append(random_data[d]);
            //qDebug() << " Y Value after Process :  "<< qAbs(yyDataz[d]);
            x_itr=x_itr+1;
            xxDataz.reserve(numSamples);
            yyDataz.reserve(numSamples);
            yyDataz2.reserve(numSamples);

        }
        for (int i=0;i<index_list.size();++i){
            freq_list.append(xxDataz[index_list[i]]);
        }
        //if(pkt_nbr ==89){
            do_plotting();
        //}
    //}

}

void df_tank_v1::do_plotting(){
    if(yyDataz2.size() == 5760){
        qDebug() << "Recived Packet number 90================================================ SIZE: " << yyDataz2.size() ;
        //qDebug() << "Recived Packet number 90================================================ XDATA SIZE: " << xxDataz.size() ;

        //values = {1, 3, 2, 5, 4,0,11,9,7,6,4,1}; // Heights of bars
        freks->setData(ticks, dB_list);
        QList<QCPItemText*> labelList;  // List to store the labels

        for (int i=0; i<dB_list.size(); ++i){
            // Add a label on top of the bar
            label = new QCPItemText(ui->customplot);
            label->position->setType(QCPItemPosition::ptPlotCoords);
            label->position->setCoords(ticks[i], dB_list[i]+1); // Position at the top of the bar
            label->setText(QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz"); // Set label text to the value
            label->setFont(QFont("sans", 10)); // Set font size
            label->setColor(Qt::white); // Set label color
            labelList.append(label); // Add label to list

            if(i==0){
                ui->label_32->setText( QString::number(dB_list[i]));
                ui->label_31->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }
            if(i==1){
                ui->label_37->setText( QString::number(dB_list[i]));
                ui->label_36->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }
            if(i==2){
                ui->label_42->setText( QString::number(dB_list[i]));
                ui->label_41->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }
            if(i==3){
                ui->label_47->setText( QString::number(dB_list[i]));
                ui->label_46->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }
            if(i==4){
                ui->label_52->setText( QString::number(dB_list[i]));
                ui->label_51->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }
            if(i==5){
                ui->label_57->setText( QString::number(dB_list[i]));
                ui->label_56->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }
            if(i==6){
                ui->label_67->setText( QString::number(dB_list[i]));
                ui->label_66->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }
            if(i==7){
                ui->label_72->setText( QString::number(dB_list[i]));
                ui->label_71->setText( QString::number(freq_list[i]/1000000000.0 ,'f', 2)+ " GHz");
            }




        }

        ui->customplot->replot();
        ui->customplot->update();
        //label->destroyed();

        for (int i = 0; i < labelList.size(); ++i) {
            ui->customplot->removeItem(labelList[i]);  // Remove label from plot
        }
        labelList.clear();









        // ui->customplot->graph(0)->setData(xxDataz, yyDataz2);
        // ui->customplot->xAxis->setRange(f1,f2);
        // ui->customplot->yAxis->setRange(-5,80); // Adjust range as needed
        // ui->customplot->replot();


        // //polar plotting start here---
        if(angl==1){
            float Qs=0.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel 1");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));
                //ui->label_31->setText( QString::number(xxDataz[z]));


                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_32->setText( QString::number(highestPoint.y()));
            ui->label_73->setText( QString::number(highestPoint.x()));


            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            //qDebug() << " Y high values ch 1 "<<highestPoint;

            //series->replace(newData);
            newData.clear();
        }
        if(angl==2){
            float Qs=45.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel 2");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_37->setText( QString::number(highestPoint.y()));
            ui->label_74->setText( QString::number(highestPoint.x()));
            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            qDebug() << " Y high values ch 2 "<<highestPoint;

            //series->replace(newData);
            newData.clear();

        }
        if(angl==3){
            float Qs=90.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel 3");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_42->setText( QString::number(highestPoint.y()));
            ui->label_75->setText( QString::number(highestPoint.x()));
            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            //qDebug() << " Y high values ch 3 "<<highestPoint;

            //series->replace(newData);
            newData.clear();
        }
        if(angl==4){
            float Qs=135.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            //seriez->setName("Ploting Channel 4");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_47->setText( QString::number(highestPoint.y()));
            ui->label_76->setText( QString::number(highestPoint.x()));
            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            //qDebug() << " Y high values ch 4 "<<highestPoint;

            //series->replace(newData);
            newData.clear();
        }
        if(angl==5){
            float Qs=180.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel 5");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_52->setText( QString::number(highestPoint.y()));
            ui->label_77->setText( QString::number(highestPoint.x()));
            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            //qDebug() << " Y high values ch 5 "<<highestPoint;

            //series->replace(newData);
            newData.clear();
        }
        if(angl==6){
            float Qs=225.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel 6");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_57->setText( QString::number(highestPoint.y()));
            ui->label_78->setText( QString::number(highestPoint.x()));
            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            //qDebug() << " Y high values ch 6 "<<highestPoint;

            //series->replace(newData);
            newData.clear();
        }
        if(angl==7){
            float Qs=270.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel 7");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_67->setText( QString::number(highestPoint.y()));
            ui->label_79->setText( QString::number(highestPoint.x()));
            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            //qDebug() << " Y high values ch 7 "<<highestPoint;

            //series->replace(newData);
            newData.clear();
        }
        if(angl==8){
            angl=0;
            float Qs=315.0;
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();

            float detaa=Qs+angle_to_addz;
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel 8");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(detaa, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_72->setText( QString::number(highestPoint.y()));
            ui->label_80->setText( QString::number(highestPoint.x()));
            // Store the highest point in newData1
            peaks_info.append(highestPoint);
            //qDebug() << " Y high values ch 8 "<<highestPoint;
            seriez->replace(peaks_info);
            //series->append(newData1);
            polarChartz->update();
            chartViewz->update();
            chartViewz->clearFocus();
            polarChartz->clearFocus();
            //series->replace(newData);
            newData.clear();
            peaks_info.clear();


        }
        if (angl==9){
            QPointF highestPoint;
            qreal maxY = std::numeric_limits<qreal>::lowest();
            QVector<QPointF> newData;

            seriez->setName("Ploting Channel");
            for(int z=0;z<yyDataz2.size();++z){
                newData.append(QPointF(angl_info, qAbs(yyDataz2[z])));

                //qDebug() << "Q theta Values: " << detaa << " Y values "<<yyData[z];

                // series->append(detaa,yyData[z]);
                //detaa=detaa+angle_to_addz;

            }

            for (const QPointF &point : newData) {
                if (point.y() > maxY) {
                    maxY = point.y();
                    highestPoint = point;
                }
            }

            ui->label_72->setText( QString::number(highestPoint.y()));
            ui->label_80->setText( QString::number(highestPoint.x()));
            ui->label_24->setText( QString::number(angl_info));

            // Store the highest point in
            peaks_info.append(QPointF(0,0));
            peaks_info.append(QPointF(highestPoint.x()-5,highestPoint.y()/2));
            //peaks_info.append(QPointF(highestPoint.x()-2,highestPoint.y()));
            peaks_info.append(highestPoint);
            //peaks_info.append(QPointF(highestPoint.x()+2,highestPoint.y()));

            peaks_info.append(QPointF(highestPoint.x()+5,highestPoint.y()/2));
            peaks_info.append(QPointF(0,0));


            //qDebug() << " Y high values ch 8 "<<highestPoint;
            seriez->replace(peaks_info);
            //series->append(newData1);
            polarChartz->update();
            chartViewz->update();
            chartViewz->clearFocus();
            polarChartz->clearFocus();
            //series->replace(newData);
            newData.clear();
            peaks_info.clear();

        }
        //after if
        angl +=1;





    }
    else{
        qDebug() << "Recived Packet number 90================================================ SIZE: " << yyDataz2.size() ;
        qDebug() << "Recived Packet number 90================================================ XDATA SIZE: " << xxDataz.size() ;
        qDebug() << "Total packet lost-------------------------------:  "<<pkt_loss;
        pkt_loss +=1;

    }
    //finally
    xxDataz.clear();
    yyDataz.clear();
    yyDataz2.clear();
    random_data.clear();
    dB_list.clear();
    freq_list.clear();
    index_list.clear();
    x_itr=1;

}

void df_tank_v1::readDatagrams2() {
    //qDebug() << " Inscope  :  ";

    while (socket2->hasPendingDatagrams()) {
        //qDebug() << " Enter While  :  ";

        //QElapsedTimer timer;
        seriez->clear();
        // Start the timer before the loop starts
        //timer.start();
        //xxDataz.clear();
        yyDataz.clear();
        //yyDataz2.clear();

        random_data.reserve(data_size);
        // Generate random double values less than 5
        for (int i = 0; i < data_size; ++i) {
            double random_value = QRandomGenerator::global()->bounded(60);
            random_data.append(random_value);

        }

        QByteArray datagram;
        datagram.resize(socket2->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket2->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        //Ensure the size of the received data is a multiple of 4 bytes (size of int32_t)
        if (datagram.size() % sizeof(int32_t) != 0) {
            qDebug() << "Received data size is not a multiple of 4 bytes";
            continue;
        }

        // // // Interpret the received data as int32_t values
        // //const  uint32_t *intArray = reinterpret_cast<const uint32_t*>(datagram.constData());
        // //int numInts = datagram.size() / sizeof(uint32_t);
        // //qDebug() << "Received Values : "<<numInts;

        // datagram=datagram.toHex();
        qDebug() << " Recived Complete Data Gram  :  ";

        // int chunkSize = 8;

        // for (int i = 0; i < datagram.size(); i += chunkSize) {
        //     // QString hexString;
        //     // hexString =&""+[datagram[i]]+datagram[i+1]+datagram[i+2]+datagram[i+3]+datagram[i+4]+datagram[i+5]+datagram[i+6]+datagram[i+7];

        //     QString chunk = datagram.mid(i, chunkSize);

        //     //qDebug() << " Recived Value Over WIFI HEX Individulae  :  "<< datagram[i];
        //     //qDebug() << " Recived Value Over WIFI HEX Chunk  :  "<< chunk;


        //     QString hexString =chunk;

        //     // Example hexadecimal string

        //     bool ok;
        //     int intValue = hexString.toInt(&ok, 16);  // 16 indicates hexadecimal base

        //     if (ok) {
        //         yyDataz.append(intValue);
        //         //qDebug() << "The integer value of :"<<chunk << "IS" << intValue;
        //     } else {
        //         qDebug() << "Conversion failed.";
        //     }
        //     //qDebug() << " Recived Value Over WIFI HEX Individulae  :  "<< datagram[i];


        // }
        // //qDebug() << "Before REMOVE :"<< yyDataz;

        // angl_info=yyDataz[yyDataz.size()-1];
        // ui->label_5->setText( QString::number(angl_info));

        // qDebug() << "Angle: "<< angl_info;

        // yyDataz.removeLast();
        // //qDebug() << "AFTRE REMOVE DATA :"<< yyDataz;


        for (int i=0; i<12;++i){
            double random_value_y = QRandomGenerator::global()->bounded(60);
            double random_value_x = QRandomGenerator::global()->bounded(60);

            dB_list.append(random_value_y);
            index_list.append(random_value_x);
        }
        // // for (int i=0; i<dB_list.size();++i){
        // //     qDebug() << "dB List :"<< dB_list[i];
        // //     qDebug() << "Index List"<<index_list[i];
        // // }
        // //qDebug() << "dB List :"<< dB_list;
        // //qDebug() << "Index List"<<index_list;

        for(int i=0; i<index_list.size();++i){
            //qDebug() << "Current value"<<random_data[index_list[i]];
            //qDebug() << "New value"<<dB_list[i];

            random_data[index_list[i]]=dB_list[i];

            //qDebug() << "Current After Chnage value"<<random_data[index_list[i]];

        }

        // //dB_list.clear();
        // //index_list.clear();

        // // for(int i=0; i<index_list.size();++i){
        // //     random_data[index_list[i]]=dB_list[i];
        // // }


        do_processing();

    }

}


void df_tank_v1::on_pushButton_clicked()
{
    //Start Button
    ui->pushButton->setStyleSheet("QPushButton { "
                                    "background-color:rgb(50, 82, 123);"
                                    "} "
                                    "QPushButton:hover { "
                                    "background-color: #a3a3a3; "
                                    "} ");
    qDebug() << " Clicked Start ";


    //qDebug() << "Rabdom Data Generated and Stored with Size :"<< random_data.size();


    socket2 = new QUdpSocket(this);
    //QString hostid="10.42.0.1";
    socket2->bind(QHostAddress::LocalHost, 9000); // Bind to localhost on port 2500
    //socket2->bind(QHostAddress::Any, 9000); // Bind to the specified local host address and port 7

    //ui->radioButton_2->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color: #1bc43a; }");
    qDebug() << " Port set  :  ";

    connect(socket2, &QUdpSocket::readyRead, this, &df_tank_v1::readDatagrams2);
    qDebug() << " Port Open  :  ";

}


void df_tank_v1::on_pushButton_2_clicked()
{
//Rest Button
    values = {1, 3, 2, 5, 4,0,11,9,7,6,4,1}; // Heights of bars
    freks->setData(ticks, values);

    for (int i=0; i<values.size(); ++i){
        // Add a label on top of the bar
        QCPItemText *label = new QCPItemText(ui->customplot);
        label->position->setType(QCPItemPosition::ptPlotCoords);
        label->position->setCoords(ticks[i], values[i]); // Position at the top of the bar
        label->setText(QString::number(values[i])); // Set label text to the value
        label->setFont(QFont("sans", 9)); // Set font size
        label->setColor(Qt::green); // Set label color
    }


    ui->customplot->replot();
    ui->customplot->update();




}


void df_tank_v1::on_pushButton_4_clicked()
{
    // send data udp

    QUdpSocket udpSocket;

    QString f1="4000000000";
    QString f2="5900000000000";


    // Convert the integers to QByteArray
    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream << f1 << f2;

    // Define the target address and port
    QHostAddress targetAddress("192.168.18.12"); // Change to your target IP address
    quint16 targetPort =6500; // Change to your target port

    // Send the datagram
    qint64 bytesWritten = udpSocket.writeDatagram(datagram, targetAddress, targetPort);

    if (bytesWritten == -1) {
        qCritical() << "Failed to send datagram:" << udpSocket.errorString();
    } else {
        qDebug() << "Datagram sent:" << bytesWritten << "bytes.";
    }
}


void df_tank_v1::on_pushButton_5_clicked()
{
    //Stop Button

    // Disconnect the readyRead signal
    disconnect(socket2, &QUdpSocket::readyRead, this, &df_tank_v1::readDatagrams2);

    // Close the UDP socket
    socket2->close();
}

