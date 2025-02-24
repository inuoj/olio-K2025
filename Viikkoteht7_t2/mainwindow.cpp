#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpression>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Kaikkien nappien connecti
    connect(ui->num1,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num2,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num3,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num4,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num5,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num6,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num7,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num8,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num9,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->num0,&QPushButton::clicked,this,&MainWindow::handleClick);
    connect(ui->clrNappi,&QPushButton::clicked,this,&MainWindow::clearHandler);
    connect(ui->enterNappi,&QPushButton::clicked,this,&MainWindow::enterHandler);
    connect(ui->plus0,&QPushButton::clicked,this,&MainWindow::lasku);
    connect(ui->miin1,&QPushButton::clicked,this,&MainWindow::lasku);
    connect(ui->jako2,&QPushButton::clicked,this,&MainWindow::lasku);
    connect(ui->kert3,&QPushButton::clicked,this,&MainWindow::lasku);
    qDebug()<<"hepsheps";
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::handleClick()
{

    // Otetaan painetun napin nimi ja tallennetaan Name muuttujaan
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString name = button->objectName();

    if(state == 0) {    // State muuttuja tarkistaa onko laskumerkkiä annettu, jos on, syötetään luvut jälkimmäiseen tekstikenttään
        // Asetetaan ekan tekstikentän kohdalle nimimuuttujan 4. merkki
        ui->ekaNro->setText(ui->ekaNro->text()+name.at(3));
        qDebug()<<"Numero ekaan: "<<name;
    } else {
        ui->tokaNro->setText(ui->tokaNro->text()+name.at(3));
        qDebug()<<"Nro tokaan: "<<name;
    }


}


void MainWindow::lasku()
{
    QString m;      // Väliaikainen muuttuja

    // laskumerkin muuttaminen 0-3 integeriksi
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString name = button->objectName();

    // Poistetaan name stringistä kaikki muut, paitsi numerot
    name.remove(QRegularExpression("\\D"));
    // Tehdään namesta integer "merkki"
    operand = name.toInt();
    qDebug()<<operand;

    // Switch case lasku merkille
    switch(operand){
    case 0:
        m = "+";
        state = 1;
        break;
    case 1:
        m = "-";
        state = 1;
        break;
    case 2:
        m = "/";
        state = 1;
        break;
    case 3:
        m = "*";
        state = 1;
        break;
    }
    ui->laskuMerkki->setText(m);

}

void MainWindow::clearHandler()
{
    // Tyhjennetään tekstikentät ja asetetaan state = 0;
    nollaaTeksti();
    state = 0;
}

void MainWindow::enterHandler()
{
    // Muuttujien alustukset
    float eka, toka;
    ekaNumero = ui->ekaNro->text();
    tokaNumero = ui->tokaNro->text();
    eka = ekaNumero.toFloat();
    toka = tokaNumero.toFloat();

    // Laskutoimitusten switch case
    switch(operand){
    case 0:         // PLUSSA
        tulos = eka + toka;
        break;
    case 1:         // MIINUS
        tulos = eka - toka;
        break;
    case 2:         // JAKO
        tulos = eka / toka;
        break;
    case 3:         // KERTO
        tulos = eka * toka;
        break;
    }
    QString n = QString::number(tulos);
    ui->kolmasNro->setText(n);
}

void MainWindow::nollaaTeksti()
{
    // Nollataan kaikki kentät
    ui->ekaNro->setText("");
    ui->tokaNro->setText("");
    ui->laskuMerkki->setText("");
    ui->kolmasNro->setText("");
}
