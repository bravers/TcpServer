#include "localserver.h"
#include <QTcpSocket>
#include <QTextStream>

LocalServer::LocalServer(QObject *parent) : QTcpServer(parent)
{
    mSocket = nullptr;

    connect(this, &LocalServer::newConnection, [&](){
        mSocket = nextPendingConnection();
    });
}

void LocalServer::pushMsg(const QString &pushMsg){
   if (mSocket){
        QTextStream T(mSocket);
        T<< pushMsg;
        mSocket->flush();
   }
}
