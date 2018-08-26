#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_patientIDCount(0)
{
    ui->setupUi(this);
    this->initializeWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeWidgets()
{
    ui->patientIDTextBox->setText(std::to_string(this->m_patientIDCount).c_str());
    ui->patientSexComboBox->addItems({"Male", "Female"});
}

void MainWindow::on_pushButton_clicked()//Temporary test function
{
    this->m_patientIDCount++;
    ui->patientIDTextBox->setText(std::to_string(this->m_patientIDCount).c_str());
    PatientInfo pi;
    pi.name = ui->patientNameTextBox->toPlainText().toStdString();
    //PillCard pc;
    //Patient p(pi, std::move(pc));
    //std::cout << p << std::endl;

    qDebug() << "'Add Patient' Button clicked!";

    if(!pi.name.empty() && pi.name[0] != ' ')
    {
        qDebug() << "Patient name entered : " << pi.name.c_str();
    }
}
