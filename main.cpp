/******************************************************************************
**
**  Copyright 2016 Dale Eason
**  This file is part of DFTFringe
**  is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, version 3 of the License

** DFTFringe is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with DFTFringe.  If not, see <http://www.gnu.org/licenses/>.

****************************************************************************/
#include "mainwindow.h"
#include <QApplication>
#include "singleapplication.h"
#include "messagereceiver.h"
#include "utils.h"
#include <QDebug>



int main(int argc, char *argv[])
{    // Allow secondary instances

    // SingleApplication app( argc, argv, true );

    // MessageReceiver msgReceiver;

    // // If this is a secondary instance
    // if( app.isSecondary() ) {
    //     app.sendMessage( app.arguments().join('\'').toUtf8() );
    //     return 0;
    // } else {
    //     QObject::connect(
    //         &app,
    //         &SingleApplication::receivedMessage,
    //         &msgReceiver,
    //         &MessageReceiver::receivedMessage
    //     );
    // }


    QApplication app(argc, argv);
    app.setOrganizationName("DFTFringe");
    app.setApplicationName("DFTFringe");
    MainWindow *w = new MainWindow;

    qDebug() << "mainWindow constructed";
    //    msgReceiver.m_mainWindow = w;

#if defined(_WIN32)
    //showmem();
#endif
    w->show();

    qDebug() << "about to exec";
    //fclose(logptr);
    return app.exec();
}
