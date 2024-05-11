#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Start_clicked()
{
    float Arr[5];
    for(int i=0;i<5;i++){
        Arr[i]=QString(ui->Res->item(0,i)->text()).toDouble();
    }
    waveClass Sound1(Arr[0],Arr[1], QString(ui->Fs->text()).toDouble(),Arr[2],Arr[3],Arr[4]);
    for(int i=1;i<docAr.count();i++){
        for(int j=0;j<5;j++){
            Arr[j]=QString(ui->Res->item(i,j)->text()).toDouble();
        }
        Sound1.subWave(Arr[0],Arr[1], QString(ui->Fs->text()).toDouble(),Arr[2],Arr[3],Arr[4]);
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранение файла"),"C:/Uwu.wav",".*wav");
    wavHeader write;
    write.createWavFile(fileName.toLocal8Bit(), (Sound1.Signal), Sound1.getSize());
}

void MainWindow::on_Input_clicked()
{
    QFile file;
    globPath=QFileDialog::getOpenFileName(nullptr,"","C:\\", "*.json");
    file.setFileName(globPath);
    if(file.open(QIODevice::ReadOnly|QFile::Text)){
        doc = QJsonDocument::fromJson(QByteArray(file.readAll()),&docError);
    }
    file.close();
    ui->Res->setRowCount(1);
    if (docError.errorString().toInt()==QJsonParseError::NoError){
        docAr=QJsonValue(doc.object().value("Signals")).toArray();
        ui->Res->setRowCount(docAr.count());
        for (int i=0;i<docAr.count();i++){
            ui->Res->setItem(i,0,new QTableWidgetItem(QString::number((docAr.at(i).toObject().value("A")).toDouble())));
            ui->Res->setItem(i,1,new QTableWidgetItem(QString::number((docAr.at(i).toObject().value("F")).toDouble())));
            ui->Res->setItem(i,2,new QTableWidgetItem(QString::number((docAr.at(i).toObject().value("Tb")).toDouble())));
            ui->Res->setItem(i,3,new QTableWidgetItem(QString::number((docAr.at(i).toObject().value("T0")).toDouble())));
            ui->Res->setItem(i,4,new QTableWidgetItem(QString::number((docAr.at(i).toObject().value("Phase")).toDouble())));
        }
    }

}
