#include "ui/mainwindow.h"
#include "ui/loggindialog.h"
#include "../MangoService/helper.h"

#include "mangoapp.h"


int main(int argc, char *argv[])
{
    MangoApp application(argc, argv);

    // ask for authentication
    LogginDialog dialog;
    dialog.exec();

    if ( !dialog.isAccepted() ) {
        Services::Helper::runSoundFile(Services::Helper::errorSoundFile);
        QMessageBox::warning(0, "Invalid Data", "username and password is not correct"
                             " ,System will closed now!");
        return (0);
    }

    int userId = dialog.getUserID();
    Services::Helper::runSoundFile(Services::Helper::logonSoundFile);
    MainWindow w(userId);
    w.show();

    return application.exec();
}


