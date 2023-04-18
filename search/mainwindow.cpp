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
    model = new QFileSystemModel(this);
    model -> setFilter(QDir::QDir::AllDirs);
    model -> setRootPath("");
    ui -> listView -> setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QDir Qpath = QDir::rootPath();

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    QFileInfo info = model -> fileInfo(index);
    if(info.fileName() == "..")
    {
        Qpath = info.dir();
        Qpath.cdUp();
        listView -> setRootIndex(model -> index(Qpath.absolutePath()));
    }
    else if(info.fileName() == ".")
    {
        Qpath = QDir::rootPath();
        listView -> setRootIndex(model -> index(""));
    }
    else
    {
        Qpath = info.absoluteFilePath();
        listView -> setRootIndex(index);
    }

}

void MainWindow::on_search_clicked()
{
    ui -> search ->setEnabled(false);

    KI_checkbox = ui -> checkbox -> isChecked();
    regexp_checkbox = ui -> regexp_checkbox -> isChecked();

    ui -> result -> clear();

    std::string pth = Qpath.path().toStdString();
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




