#include "ui/logonscreen.h"
#include "mangoapp.h"

int main(int argc, char *argv[])
{
    MangoApp application(argc, argv);

    LogonScreen logonScreen;
    logonScreen.show();

    return application.exec();
}


