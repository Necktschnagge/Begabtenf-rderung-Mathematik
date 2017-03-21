#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdint.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_commandLinkButton_clicked()
{
    /* calculate the ggT of given numbers */
    ui->textBrowser->clear();

    int x {ui->lineEdit->text().toInt()};
    int y {ui->lineEdit_2->text().toInt()};
    int div {x / y};
    int mod {x % y};

    while (true){
        QString lineout {};
        lineout.append(QString::number(x));
        lineout.append("     =     ");
        lineout.append(QString::number(y));
        lineout.append(" * ");
        lineout.append(QString::number(div));
        lineout.append("   +   ");
        lineout.append(QString::number(mod));
        lineout.append("\n");

        ui->textBrowser->append(lineout);

        if (mod== 0){
            break;
        }

        // refresh values for next loop
        x = y;
        y = mod;
        div = x / y;
        mod = x % y;
    }
    QString lineout {"Der ggT der beiden Zahlen ist:  "};
    lineout.append(QString::number(y));
    ui->textBrowser->append(lineout);
}

int ggT(int a, int b) {
    if (b==0) return a;
    return ggT(b, a % b);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("Zuerst überprüfen wir die Lösbarkeit.\nDazu bestimmen wir den größten gemeinsamen Teiler der Koeffizienten:\n");

    int x {ui->lineEdit_3->text().toInt()};
    int y {ui->lineEdit_4->text().toInt()};
    int k = x;
    int l = y;
    int z = ui->lineEdit_5->text().toInt();

    int div {x / y};
    int mod {x % y};

    while (true){
        QString lineout {};
        lineout.append(QString::number(x));
        lineout.append("     =     ");
        lineout.append(QString::number(y));
        lineout.append(" * ");
        lineout.append(QString::number(div));
        lineout.append("   +   ");
        lineout.append(QString::number(mod));
        lineout.append("\n");

        ui->textBrowser_2->append(lineout);

        if (mod== 0){
            break;
        }

        // refresh values for next loop
        x = y;
        y = mod;
        div = x / y;
        mod = x % y;
    }
    QString lineout {"Der ggT der beiden Zahlen ist:  "};
    lineout.append(QString::number(y));
    ui->textBrowser_2->append(lineout);

    if (z % y){
        // Es gibt keine Lösung.
        ui->textBrowser_2->append("\n >>>>>KEINE LÖSUNG<<<<<\nEs gibt keine Lösung, weil der ggT der Koeffizienten das Absolutglied nicht teilt.\n\nENDE");
    } else {
        ui->textBrowser_2->append("\n Wir reduzieren falls ggT>1 die Gleichung und erhalten:\n");

        QString lo{};
        lo.append(QString::number(k));
        lo.append(" / ");
        lo.append(QString::number(y));
        lo.append("   =   ");
        k /= y;
        lo.append(QString::number(k));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();


        lo.append(QString::number(l));
        lo.append(" / ");
        lo.append(QString::number(y));
        lo.append("   =   ");
        l /= y;
        lo.append(QString::number(l));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();



        lo.append(QString::number(z));
        lo.append(" / ");
        lo.append(QString::number(y));
        lo.append("   =   ");
        z /= y;
        lo.append(QString::number(z));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();


        lo.append(QString::number(k));
        lo.append(" * a   +   ");
        lo.append(QString::number(l));
        lo.append(" * b     =     ");
        lo.append(QString::number(z));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        ui->textBrowser_2->append("========================================================\nJetzt versuchen wir, die Gleichung zu lösen...\nBetrachten wir die Gleichung dazu modulo des Koeffizienten von a:\n");

        lo.append(QString::number(l));
        lo.append(" * b     =     ");
        lo.append(QString::number(z));
        lo.append("          (mod  ");
        lo.append(QString::number(k));
        lo.append(" )\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        ui->textBrowser_2->append("jetzt suchen wir das (multiplikative mod-)Inverse vom Koeffizienten von b:\n");

        int inv = 1;
        while (true) {
            if ((inv*l) % k == 1) break;
            ++inv;
        }// stupides Suchen vom Inversen.

        lo.append(QString::number(inv));
        lo.append(" * ");
        lo.append(QString::number(l));
        lo.append(" * b     =     ");
        lo.append(QString::number(inv));
        lo.append(" * ");
        lo.append(QString::number(z));
        lo.append("          (mod  ");
        lo.append(QString::number(k));
        lo.append(" )\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        lo.append("b     =     ");
        lo.append(QString::number((inv * z)%k));
        lo.append("          (mod  ");
        lo.append(QString::number(k));
        lo.append(" )\n");
        ui->textBrowser_2->append(lo);
        lo.clear();
        int b_rest = (inv * z) % k;

        ui->textBrowser_2->append("Wir führen einen neuen Parameter k element Z ein:");
        lo.append("b     =          ");
        lo.append(QString::number(k));
        lo.append(" * k   +   ");
        lo.append(QString::number(b_rest));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        ui->textBrowser_2->append("Und jetzt sind wir auch fast schon fertig:\n\nWir ersetzen jetzt b anhand dieser Gleichung und erhalten dann für jeden ganzen Parameterwert k ein Wertepaar (a,b) von ganzen Zahlen als Lösung:\n");

        lo.append(QString::number(k));
        lo.append(" * a     +     ");
        lo.append(QString::number(l));
        lo.append(" * ( ");
        lo.append(QString::number(k));
        lo.append(" * k   +   ");
        lo.append(QString::number(b_rest));
        lo.append(")          =          ");
        lo.append(QString::number(z));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();


        lo.append(QString::number(k));
        lo.append(" * a     +     ");
        lo.append(QString::number(l* k));
        lo.append(" * k   +   ");
        lo.append(QString::number(l*b_rest));
        lo.append("          =          ");
        lo.append(QString::number(z));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        lo.append(QString::number(k));
        lo.append(" * a     +     ");
        lo.append(QString::number(l* k));
        lo.append(" * k           =       ");
        lo.append(QString::number(z));
        lo.append(" - ");
        lo.append(QString::number(l*b_rest));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        lo.append(QString::number(k));
        lo.append(" * a     +     ");
        lo.append(QString::number(l* k));
        lo.append(" * k           =       ");
        lo.append(QString::number(z - l*b_rest));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        lo.append("a     +     ");
        lo.append(QString::number(l));
        lo.append(" * k           =       ");
        lo.append(QString::number((z - l*b_rest)/k));
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        lo.append("a        =         ");
        lo.append(QString::number((z - l*b_rest)/k));
        lo.append("   -   ");
        lo.append(QString::number(l));
        lo.append(" * k");
        lo.append("\n");
        ui->textBrowser_2->append(lo);
        lo.clear();

        ui->textBrowser_2->append("TADAAAA!!!\n\n Wir haben schon die Lösung.");

    }

}
