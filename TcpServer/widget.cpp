#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QTextBrowser>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLocalServer = new LocalServer(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startSrv_clicked()
{
    if(!mLocalServer->listen(QHostAddress::Any, ui->portSrv->value())){
        QMessageBox::critical(this,"Ошибка запуска", mLocalServer->errorString());
    } else {
        QMessageBox::information(this, "Запуск сервера", "Успешно");
    }

}


void Widget::on_exit_clicked()
{
    close();
}

void Widget::on_openFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath());
    QFile file(filename);
    QMessageBox::information(this, "Открыт файл", filename);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Внимание", "Файл не открылся");
    }
    ui->pathFile->setText(filename);

    QTextStream in(&file);
    QString text= in.readAll();
    ui->textBrowser->setPlainText(text);

    file.close();
}
void Widget::on_pushMsg_clicked()
{
    mLocalServer->pushMsg(ui->textBrowser->toPlainText());
}

