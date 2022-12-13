#include<iostream>		//Library untuk input dan output
#include<ctime>			//supaya bener-bener random dadu yang muncul
#include<cstdlib>		//rand(); pake library ini
#include<ncurses/ncurses.h> //animasi loading
#include<windows.h> //animasi loading

using namespace std;
void loading(){
	initscr();
	int load=0;
	mvprintw(9, 27, "LOADING");
	mvprintw(10, 19, "[");
	for (int x=20; x<36; x++){
		refresh();
		mvprintw(10, x, "-|]]]]]");
		Sleep(100);
		mvprintw(10, x, " ");
		if (x==35&&load<4){
			mvprintw(10, x, "      "); //setiap x mentok di paling kanan yaitu 35, maka load increment
			load++;
			x=20;
		}
	}
	refresh();
	// untuk menutup layar mode ncurses
	endwin();
}

void rules()
{ 
	//menampilkan peraturan bermain
    system("cls");
    cout << "\t   CASINO NUMBER GUESSING RULES!     "<<endl;
    cout << "\t1. Pilih salah satu angka diantara 1-6 "<<endl;
    cout << "\t2. Pemenang taruhan akan mendapatkan 10 kali uang taruhan <3 "<<endl;
    cout << "\t3. Jika kalah taruhan Anda kehilangan jumlah uang yang Anda pertaruhkan :( "<<endl;
}
int main()
{
    string nama_pemain;			
    int saldo_taruhan;        	
    int jumlah_taruhan;			
    int tebakan;			
    int dadu;        		  
    char pilih;				
    srand(time(0)); //supaya bener-bener random dadunya
	cout<<"\n\n\n\t\t\t HEIYO!! WELCOM TO THE HEKSA KASINO ($ >>.<< $) "<<endl;		// HEADER
    cout << "\n\n\t\t\t\t What's your Name : ";	
    getline(cin, nama_pemain);
    cout << "\n\n Masukkan saldo awal untuk bermain game : $";
    cin >> saldo_taruhan;
    do
    {
        system("cls");
        rules();
        cout << "\n\n Saldo Anda sekarang adalah $" << saldo_taruhan << "\n";
		//menampilkan saldo taruhan pemain

        do
        {
            cout << " Hey, " << nama_pemain<<", Masukkan jumlah uang untuk bertaruh : $";
            cin >> jumlah_taruhan;
            if(jumlah_taruhan > saldo_taruhan)
                cout << "Taruhan tidak boleh lebih dari saldo saat ini!! \n";
                cout<<"\nMasukkan saldo kembali \n ";
        }while(jumlah_taruhan > saldo_taruhan);
        //supaya kalo input jumlah taruhan lebih dari saldo, akan terus ulang dari do lagi
        
        do
        {
		    cout << " Tebak nomor taruhan antara 1-6 : ";
            cin >> tebakan;
            if(tebakan <= 0 || tebakan > 6)
                cout << "\n Angka harus diantara 1-6!! \n"
                    <<"Masukkan nomor kembali : \n ";
        }while(tebakan <= 0 || tebakan > 6);
        //supaya kalo angka yang diinput bukan angka dadu, akan terus ulang
        
		loading();
		
        dadu = rand()%6 + 1;   // variabel penyimpan angka acak
        if(dadu == tebakan)
        {
            cout << "\n\n Yuhuu Anda beruntung!! Anda telah memenangkan $" << jumlah_taruhan * 10;
            saldo_taruhan = saldo_taruhan + jumlah_taruhan * 10;
        }
        else
        {
            cout << " Oops, Anda kurang beruntung. Anda kehilangan $"<< jumlah_taruhan <<"\n";
            saldo_taruhan = saldo_taruhan - jumlah_taruhan;
        }
        cout << "\n Nomor yang keluar adalah : " << dadu <<"\n";
        cout << "\n "<<nama_pemain<<", Anda memiliki saldo $" << saldo_taruhan << "\n";
        if(saldo_taruhan == 0)
        {
            cout << " Anda tidak punya uang untuk bermain :( ";
            break;
        }
        cout << "\n\n--> Apakah Anda ingin bermain lagi? (y/n)? ";
        cin >> pilih;
    }while(pilih =='Y'|| pilih=='y');
    cout << "\n\n\t Terima kasih telah bermain di Heksa Kasino <3. Saldo Anda adalah $ " << saldo_taruhan << "\n";
    return 0;
}
//Dewi Nurhaliza (2217051057)
//Ikhtiar Adli Wicaksono (2217051060)
//Jenitra Hafizhan (2217051135)
