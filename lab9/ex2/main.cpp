#include "mainwindow.h"

#include <QApplication>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplitter * splitter = new QSplitter(Qt::Vertical);
     MainWindow * dialog1 = new MainWindow();
     MainWindow * dialog2 = new MainWindow();
     splitter->addWidget( dialog1 );
     splitter->addWidget( dialog2 );
     splitter->show();
    return a.exec();
}
