#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_patientIDCount(0)
{
    ui->setupUi(this);
    this->InitializeWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitializeWidgets()
{
    ui->patientIDTextBox->setText(std::to_string(this->m_patientIDCount).c_str());
    ui->patientSexComboBox->addItems({"Male", "Female"});
    ui->patientDOBDateEdit->setDate(QDate::currentDate());
    ui->patientPhoneLineEdit->setInputMask("(000) 000-0000");
    const QList<QString> abbrevs{//TODO: Read this list from file into memory at startup
        "AL",
        "AK",
        "AZ",
        "AR",
        "CA",
        "CO",
        "CT",
        "DE",
        "FL",
        "GA",
        "HI",
        "ID",
        "IL",
        "IN",
        "IA",
        "KS",
        "KY",
        "LA",
        "ME",
        "MD",
        "MA",
        "MI",
        "MN",
        "MS",
        "MO",
        "MT",
        "NE",
        "NV",
        "NH",
        "NJ",
        "NM",
        "NY",
        "NC",
        "ND",
        "OH",
        "OK",
        "OR",
        "PA",
        "RI",
        "SC",
        "SD",
        "TN",
        "TX",
        "UT",
        "VT",
        "VA",
        "WA",
        "WV",
        "WI",
        "WY"
    };
    ui->stateAbbreviationComboBox->addItems(abbrevs);
}


void MainWindow::SetPatientInfo(PatientInfo& pi)
{
    pi.id = std::stoul(ui->patientIDTextBox->toPlainText().toStdString());
    pi.name = ui->patientNameTextBox->toPlainText().toStdString();
    pi.sex = ui->patientSexComboBox->currentText() == "Male" ? 'M' : 'F';

    pi.dateOfBirth =
    {
        ui->patientDOBDateEdit->date().month(),
        ui->patientDOBDateEdit->date().day(),
        ui->patientDOBDateEdit->date().year()
    };

    pi.phone = ui->patientPhoneLineEdit->text().toStdString();
}

void MainWindow::on_addPatientPushButton_clicked()
{
    this->m_patientIDCount++;
    ui->patientIDTextBox->setText(std::to_string(this->m_patientIDCount).c_str());
    PatientInfo pi;
    this->SetPatientInfo(pi);
    PillCard pc;
    Patient p(pi, std::move(pc));
    std::cout << p << std::endl;
}
