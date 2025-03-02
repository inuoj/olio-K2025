#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    pQTimer = new QTimer(this);

    ui->label->setText("Valitse peliaika!");

    connect(ui->startGame, &QPushButton::clicked, this, &MainWindow::startHandler);
    connect(ui->stopGame, &QPushButton::clicked, this, &MainWindow::stopHandler);
    connect(ui->switch1, &QPushButton::clicked, this, &MainWindow::vuoronVaihto);
    connect(ui->switch2, &QPushButton::clicked, this, &MainWindow::vuoronVaihto);
    connect(ui->aika1, &QPushButton::clicked, this, &MainWindow::aikaLyhyt);
    connect(ui->aika2, &QPushButton::clicked, this, &MainWindow::aikaPitka);

    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeOut);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeOut()
{

    if(currentPlayer == 1){
        player1Time --;
        ui->palkki1->setValue(player1Time);
        a = QString::number(player1Time);
        ui->label->setText("Player 1 aika: " + a + " sek");
        if(player1Time <= 0){
            pQTimer->stop();
            ui->label->setText("Pelaaja 2 Voitti!");
        }
    } else {
        player2Time --;
        ui->palkki2->setValue(player2Time);
        a = QString::number(player2Time);
        ui->label->setText("Player 2 aika: " + a + " sek");
        if(player2Time <= 0){
            pQTimer->stop();
            ui->label->setText("Pelaaja 1 Voitti!");
        }
    }

}

void MainWindow::startHandler()
{
    currentPlayer = 1;
    player1Time = aika;
    player2Time = aika;
    ui->palkki1->setRange(0,aika);
    ui->palkki2->setRange(0,aika);
    pQTimer->start(1000);
}

void MainWindow::stopHandler()
{
    pQTimer->stop();
}

void MainWindow::aikaLyhyt()
{
    aika = 10;
    a = QString::number(aika);
    ui->label->setText("Lyhyempi aika: "+ a + " sekuntia");

}

void MainWindow::aikaPitka()
{
    aika = 60;
    a = QString::number(aika);
    ui->label->setText("Pidempi aika: "+ a + " sekuntia");
}


void MainWindow::vuoronVaihto()
{
    if(currentPlayer == 1){
        ui->label->setText("PLayer 2 vuoro");
        currentPlayer = 2;
    } else {
        ui->label->setText("PLayer 1 vuoro");
        currentPlayer = 1;
    }
}

