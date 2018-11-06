#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

double rumus(double x1, double x2){
    x1 = exp(abs(1-sqrt(pow(x1,2))+pow(x2,2)/M_PI));
    x2 = -abs(sin(x1)*cos(x2)*x1);
    return x2;
}

double randomnumber_fs(){
    double x1 = rand() % 20 + (-10);
    return x1;
}

int main()
{
    //Penginisialisasi an nilai temp & cool_rate
    double temperatur = 999;
    double cool_rate = 0.3;

    //Penginisialisasi an function angka acak ke dalam suatu variable
    double x1 = randomnumber_fs();
    double x2 = randomnumber_fs();

    //Pengoutputan hasil angka random yang sudah diacak untuk dilihat keluaran nya
    double fs_scr = rumus(x1,x2);
    cout << "Temperature : " << temperatur <<endl;

    //Perulangan untuk pengecekan nilai random awal dan random baru untuk dibandingkan
    while(temperatur > 0){
        //Penginisialisasi an function angka acak kedua ke dalam suatu variable
        double y1 = randomnumber_fs();
        double y2 = randomnumber_fs();
        double sc_scr = rumus(x1,x2);

        //pengecekan nilai random awal dan random baru untuk dibandingkan
        if(sc_scr < fs_scr){
            x1 = y1;
            x2 = y2;
            fs_scr = sc_scr;
        }
        else{//perbedaan kondisi pengecekan nilai random awal dan random baru untuk dibandingkan
            double delta_scr = fs_scr - sc_scr;
            if(exp(-(delta_scr/temperatur)) / temperatur){
                    x1 = y1;
                    x2 = y2;
                    fs_scr = sc_scr;
            }
        }
        temperatur = temperatur - 0.0001;
    }
    //Outputan hasil akhir dari angka acak nya
    temperatur = temperatur*cool_rate;
    cout << "x1 nya : " << x1 <<endl;
    cout << endl;
    cout << "x2 nya : " << x2 <<endl;
    cout << endl;
    cout << "Hasil nya : " << fs_scr <<endl;
    cout << endl;
}
