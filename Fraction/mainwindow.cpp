/// Основное окно программы работы с обыкновенными дробями
/// @author Будаев Г.
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>


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


void MainWindow::on_pushButton_add_clicked() /// Обработчик на +
{
    f1.setNumeratorF(ui->spinBox_num1->text().toInt());
    f1.setDemoninatorF(ui->spinBox_denom1->text().toInt());
    f2.setNumeratorF(ui->spinBox_num2->text().toInt());
    f2.setDemoninatorF(ui->spinBox_denom2->text().toInt());
    f3 = f1.addF(f2);
    ui->spinBox_num3->setValue(f3.getNumeratorF());
    ui->spinBox_denom3->setValue(f3.getDenominatorF());
    ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " + " +
                                  QString::fromStdString (f2.stringFraction()) + " = " +
                                  QString::fromStdString (f3.stringFraction()));
    ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " + " +
                                       QString::fromStdString (f2.stringFraction()) + " = " +
                                       QString::fromStdString (f3.stringFraction()) + ";");
}


void MainWindow::on_pushButton_sub_clicked() /// Обработчик на -
{
    f1.setNumeratorF(ui->spinBox_num1->text().toInt());
    f1.setDemoninatorF(ui->spinBox_denom1->text().toInt());
    f2.setNumeratorF(ui->spinBox_num2->text().toInt());
    f2.setDemoninatorF(ui->spinBox_denom2->text().toInt());
    f3 = f1.subF(f2);
    ui->spinBox_num3->setValue(f3.getNumeratorF());
    ui->spinBox_denom3->setValue(f3.getDenominatorF());
    ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " - " +
                                  QString::fromStdString (f2.stringFraction()) + " = " +
                                  QString::fromStdString (f3.stringFraction()));
    ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " - " +
                                       QString::fromStdString (f2.stringFraction()) + " = " +
                                       QString::fromStdString (f3.stringFraction()) + ";");
}


void MainWindow::on_pushButton_mul_clicked() /// Обработчик на *
{
    f1.setNumeratorF(ui->spinBox_num1->text().toInt());
    f1.setDemoninatorF(ui->spinBox_denom1->text().toInt());
    f2.setNumeratorF(ui->spinBox_num2->text().toInt());
    f2.setDemoninatorF(ui->spinBox_denom2->text().toInt());
    f3 = f1.multF(f2);
    ui->spinBox_num3->setValue(f3.getNumeratorF());
    ui->spinBox_denom3->setValue(f3.getDenominatorF());
    ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " * " +
                                  QString::fromStdString (f2.stringFraction()) + " = " +
                                  QString::fromStdString (f3.stringFraction()));
    ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " * " +
                                       QString::fromStdString (f2.stringFraction()) + " = " +
                                       QString::fromStdString (f3.stringFraction()) + ";");
}


void MainWindow::on_pushButton_div_clicked() /// Обработчик на /
{
    f1.setNumeratorF(ui->spinBox_num1->text().toInt());
    f1.setDemoninatorF(ui->spinBox_denom1->text().toInt());
    f2.setNumeratorF(ui->spinBox_num2->text().toInt());
    f2.setDemoninatorF(ui->spinBox_denom2->text().toInt());
    f3 = f1.divF(f2);
    ui->spinBox_num3->setValue(f3.getNumeratorF());
    ui->spinBox_denom3->setValue(f3.getDenominatorF());
    ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " ÷ " +
                                  QString::fromStdString (f2.stringFraction()) + " = " +
                                  QString::fromStdString (f3.stringFraction()));
    ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " ÷ " +
                                       QString::fromStdString (f2.stringFraction()) + " = " +
                                       QString::fromStdString (f3.stringFraction()) + ";");
}


void MainWindow::on_pushButton_compare_clicked() /// Обработчик на Сравнить
{
    f1.setNumeratorF(ui->spinBox_num1->text().toInt());
    f1.setDemoninatorF(ui->spinBox_denom1->text().toInt());
    f2.setNumeratorF(ui->spinBox_num2->text().toInt());
    f2.setDemoninatorF(ui->spinBox_denom2->text().toInt());
    f3 = f1;
    if(f3.compareF(f2) < 0){
        ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " меньше, чем " +
                                           QString::fromStdString (f2.stringFraction()) + ";");
        ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " меньше, чем " +
                                      QString::fromStdString (f2.stringFraction()));
    }
    else
        if(f3.compareF(f2) > 0){
            ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " больше, чем " +
                                               QString::fromStdString (f2.stringFraction()) + ";");
            ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " больше, чем " +
                                          QString::fromStdString (f2.stringFraction()));
        }
        else{
            ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " равно " +
                                               QString::fromStdString (f2.stringFraction()) + ";");
            ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " равно " +
                                          QString::fromStdString (f2.stringFraction()));
        }
}



void MainWindow::on_pushButton_clicked() /// Обработчик выведения в десятичном виде
{
    f1.setNumeratorF(ui->spinBox_num3->text().toInt());
    f1.setDemoninatorF(ui->spinBox_denom3->text().toInt());
    ui->label_comparison->setText(QString::fromStdString (f1.stringFraction()) + " = " +QString::number(f1.convertToDoubleF()));
    ui->plainTextEdit->appendPlainText(QString::fromStdString (f1.stringFraction()) + " = " +QString::number(f1.convertToDoubleF()) + ";");
}


void MainWindow::on_action_about_triggered() /// Об авторе
{
    QMessageBox::about(this, "Об авторе", "Разработчик - Будаев Г.Б.");
}


void MainWindow::on_action_clear_triggered() /// Очистка PlainText
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_action_open_triggered()/// Загрузить данные из файла
{
    QFile file( QFileDialog::getOpenFileName(this, "Открыть отчёт","../",  "Documents (*.txt);; All files (*.*)"));
    if (file.open(QIODevice::ReadOnly) )
    {
        QTextStream stream( &file );
        QString text;
        text = stream.readAll();
        int k = 0;
        QStringList s1 = text.split("\n");
        for(int i = 0; i <= 2; i++){
                 if (k == 0){
                     QStringList ss1 = s1.at(0).split("/");
                     ui->spinBox_num1->setValue((ss1.at(0)).toInt());
                     ui->spinBox_denom1->setValue((ss1.at(1)).toInt());
                     k++;
                 }else
                 {
                     QStringList ss2 = s1.at(1).split("/");
                     ui->spinBox_num2->setValue((ss2.at(0)).toInt());
                     ui->spinBox_denom2->setValue((ss2.at(1)).toInt());
                 }
        }

        file.close();
    }
}

void MainWindow::on_action_save_rep_triggered()/// Сохранение отчёта
{
     QFile file( QFileDialog::getSaveFileName(this, "Сохранить отчёт","../",  "Documents (*.txt);; All files (*.*)"));
     if (file.open(QIODevice::ReadWrite) )
     {
         QTextStream stream( &file );
         stream << ui->plainTextEdit->toPlainText();
         file.close();
     }
}


void MainWindow::on_action_open_rep_triggered()/// Открытие отчёта
{
    QFile file( QFileDialog::getOpenFileName(this, "Открыть отчёт","../",  "Documents (*.txt);; All files (*.*)"));
    if (file.open(QIODevice::ReadOnly) )
    {
        QTextStream stream( &file );
        QString text;
        text = stream.readAll();

        ui->plainTextEdit->document()->setPlainText(text);
        file.close();
    }
}


