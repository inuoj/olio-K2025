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
private slots:
    void handleClick();     // Klikattu numero
    void clearHandler();    // Clearin funktio
    void enterHandler();    // Enterin funktio
    void lasku();           // Halutun laskun handleri
    void nollaaTeksti();    // Nollaa kaikki 3 tekstikenttää

private:
    Ui::MainWindow *ui;
    QString ekaNumero,tokaNumero;
    float tulos;
    int state = 0;
    short operand;
};
#endif // MAINWINDOW_H
