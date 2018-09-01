#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdint.h>
#include "PatientManager.h"
#include "Patient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addPatientPushButton_clicked();

private:
    Ui::MainWindow *ui;
    PatientManager m_patientManager;
    uint32_t m_patientIDCount;

    void InitializeWidgets();
    void SetPatientInfo(PatientInfo& pi);
};

#endif // MAINWINDOW_H
