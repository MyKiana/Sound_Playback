#include <QApplication>
#include <QPushButton>
#include "src/Test.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
    Test *t = new Test();
    t->show();
    return QApplication::exec();
}
