#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QColor>
#include <QMessageBox>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

using std::vector;
class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

  bool okX = true;
  bool okO = true;
  int max;
  int min;

  enum class BoardMarks :  char { Empty = ' ',
                                  X     = 'X',
                                  O     = 'O' };


   struct Cell {
      QPushButton *cellBtn = nullptr;
      int row ;
      int col ;
      int pl;
      Cell(QPushButton *cellBtn, int row, int col, int pl )
            : cellBtn(cellBtn), row(row), col(col), pl(pl) {}
    };


   vector<Cell> cells;
   vector<Cell> buildCellButtons(size_t rows,size_t cols);
   void startGame();
   void setConnection();
   int searchMaximum(QString str);
   void messageBox(QString str);
   bool checkThree(int x1, int x2, int x3);
   bool checkFour(int x1, int x2, int x3, int x4);
   void finishGame();

public slots:
   void updateGame(Cell &cell);

private:
    Ui::Game *ui;
};

#endif // GAME_H
