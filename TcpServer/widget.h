#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class LocalServer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startSrv_clicked();

    void on_pushMsg_clicked();

    void on_exit_clicked();

    void on_openFile_clicked();

private:
    Ui::Widget *ui;
    LocalServer *mLocalServer;
};
#endif // WIDGET_H
