#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeOut();
    
private slots:
    void startHandler();
    void stopHandler();
    void aikaLyhyt();
    void aikaPitka();
    void vuoronVaihto();
    
    
private:
    Ui::MainWindow *ui;
    QTimer *pQTimer;
    int aika = 100;
    QString a;
    short player1Time, player2Time;
    short currentPlayer = 1;
    
};
#endif // MAINWINDOW_H
