
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "search.hpp"
#include <QString>

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



void MainWindow::on_search_clicked()
{
    ui -> result->clear();
    res.clear();
    auto Qpath = ui -> path -> text();
    std::string pth = Qpath.toStdString();
    auto Qkeyword = ui -> keyword -> text();
    std::string keyword = Qkeyword.toStdString();
    search(pth, keyword);
    for(int i = 0; i < res.size()-1; i++)
    {
        ui -> result -> append(QString::fromStdString(res[i]));
    }
}

