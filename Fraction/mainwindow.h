/// Основное окно программы работы с обыкновенными дробями
/// @author Будаев Г.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "fraction.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_add_clicked();/// Обработчик на +

    void on_pushButton_sub_clicked();/// Обработчик на -

    void on_pushButton_mul_clicked();/// Обработчик на *

    void on_pushButton_div_clicked();/// Обработчик на /

    void on_pushButton_compare_clicked();/// Обработчик на Сравнить

    void on_pushButton_clicked();/// Обработчик на вывод в десятичном виде

    void on_action_about_triggered();/// Обработчик об авторе

    void on_action_clear_triggered();/// Обработчик на очистку

    void on_action_open_triggered();/// Загрузить данные из файла

    void on_action_save_rep_triggered();/// Сохранить отчёт

    void on_action_open_rep_triggered();/// Загрузить отчёт

private:
    Ui::MainWindow *ui;
    Fraction f1, f2; /// Создание объектов с данными из формы
    Fraction f3;
};
#endif // MAINWINDOW_H
