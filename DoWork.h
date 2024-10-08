#ifndef DOWORK_H
#define DOWORK_H

#include <QObject>

class DoWork : public QObject
{
    Q_OBJECT
public:
    explicit DoWork(QObject *parent = nullptr);

public slots:
    void myworkerfunction();
signals:
    void workFinished();


private:

    int res;
};

#endif // DOWORK_H
