#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include "waveclass.h"
#include <fstream>
#include <iostream>
#include "wavheader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QJsonDocument doc;
    QJsonParseError docError;
    QString globPath;
    QJsonArray docAr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Start_clicked();

    void on_Input_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
