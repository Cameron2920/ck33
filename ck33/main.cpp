#include <QCoreApplication>
#include "Models/floor.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Floor* floor = new Floor;//("../standard_floor.txt");
//    std::cout << floor;

    return a.exec();
}
