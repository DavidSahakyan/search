#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "search.hpp"
#include <QString>
#include "execute_search_keywords.hpp"
#include "main_func.hpp"
#include "open_for_dif_OS.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Search");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_search_clicked()
{    
    ui -> search ->setEnabled(false);

    KI_checkbox = ui -> checkbox -> isChecked();
    regexp_checkbox = ui -> regexp_checkbox -> isChecked();

    ui -> result -> clear();
    auto Qpath = ui -> path -> text();
    std::string pth = Qpath.toStdString();
    auto Qkeyword = ui -> keyword -> text();
    std::string keyword = Qkeyword.toStdString();
    std::vector<std::filesystem::path> res = main_func(pth, keyword);
    for(int i = 0; i < res.size(); i++)
    {
        ui -> result -> addItem(QString::fromStdString(res[i].u8string()));
    }

    ui -> search -> setEnabled(true);
}



void MainWindow::on_result_itemDoubleClicked(QListWidgetItem *item)
{
    std::filesystem::path p = (item -> text()).toStdString();
    openf(p);
}

