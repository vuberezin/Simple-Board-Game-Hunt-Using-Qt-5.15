#include "game.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game g;
    g.setWindowTitle("Catch \"NULL\"");
    a.setWindowIcon(QIcon("./icon.ico"));
    g.resize(350,500);
    g.buildCellButtons(5, 3);
    g.startGame();
    g.setConnection();
    g.show();
  
    return a.exec();
}
