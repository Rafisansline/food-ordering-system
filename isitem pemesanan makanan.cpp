#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <cctype>

using namespace std;

struct Pesanan
{
    string nama;
    double harga;
    int jumlah;
    int jumlah_pesan;
    double harga_asli;
    double harga_diskon;
};

double total_harga = 0;
vector<Pesanan> keranjang;

void delay(int s)
{
    this_thread::sleep_for(chrono::seconds(s));
}

void clearscr()
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}

void bubbleSort(string items[], double prices[], int numItems)
{
    for (int i = 0; i < numItems - 1; i++)
    {   
        for (int j = 0; j < numItems - i - 1; j++)
        {
            if (prices[j] > prices[j + 1])
            {

                double tempPrice = prices[j];   
                prices[j] = prices[j + 1];
                prices[j + 1] = tempPrice;

                string tempItem = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempItem;
            }
        }
    }
}

void tampilkanMenuMakananDiskon(string makanan_diskon[], double harga_makanan_diskon[], int numDiskon)
{
    clearscr();
    bubbleSort(makanan_diskon, harga_makanan_diskon, numDiskon);
    cout << "\n=================================================================\n";
    cout << setw(40) << "DISKON PENGGUNA BRI\n";
    cout << "=================================================================\n";
    cout << setw(5) << "NO" << setw(15) << "MAKANAN" << setw(20) << "HARGA" << setw(23) << "POTONGAN 20%\n";

    for (int i = 0; i < numDiskon; ++i)
    {
        double diskon_persentase = 0.2;

        double harga_setelah_diskon = harga_makanan_diskon[i] * (1 - diskon_persentase);

        cout << setw(5) << i + 1 << setw(15) << makanan_diskon[i] << setw(18) << fixed << setprecision(0) << harga_makanan_diskon[i] << "K" << setw(18) << fixed << setprecision(0) << harga_setelah_diskon << "K\n";
    }

    cout << "-------------------------------------------------------------------\n";
}

void tampilkanMenuMakanan(string makanan[], double harga_makanan[], int numItems)
{
    clearscr();
    bubbleSort(makanan, harga_makanan, numItems);
    cout << "\n========================================\n";
    cout << setw(25) << "MENU MAKANAN\n";
    cout << "========================================\n";
    cout << setw(5) << "NO" << setw(15) << "MAKANAN" << setw(18) << "HARGA\n";
    for (int i = 0; i < numItems; ++i)
    {
        cout << setw(5) << i + 1 << setw(15) << makanan[i] << setw(15) << fixed << setprecision(0) << harga_makanan[i] << "K\n";
    }
    cout << "---------------------------------------------\n";
}

void tampilkanMenuTambahan()
{
    cout << "\n==================================\n";
    cout << "          MENU              \n";
    cout << "==================================\n";
    cout << " 1. Makanan\n";
    cout << " 2. Minuman\n";
    cout << " 3. Bayar\n";
    cout << "-----------------------------------\n";
}

void tampilkanMenuMinuman(string minuman[], double harga_minuman[], int numItemss)
{
    clearscr();
    bubbleSort(minuman, harga_minuman, numItemss);
    cout << "\n========================================\n";
    cout << setw(25) << "MENU MINUMAN \n";
    cout << "========================================\n";
    cout << setw(5) << "NO" << setw(15) << "MINUMAN" << setw(10) << "HARGA\n";
    for (int i = 0; i < numItemss; ++i)
    {
        cout << setw(5) << i + 1 << setw(15) << minuman[i] << setw(15) << fixed << setprecision(0) << harga_minuman[i] << "K\n";
    }
    cout << "-----------------------------------\n";
}
void tampilkanKeranjangDiskon()
{
    clearscr();
    cout << "==============================\n";
    cout << "          DISKON        \n";
    cout << "==============================\n";
    cout << setw(5) << "MENU" << setw(30) << "HARGA" << setw(15) << "JUMLAH\n";

    for (const Pesanan &pesanan : keranjang)
    {
        cout << setw(5) << pesanan.nama << setw(20) << fixed << setprecision(0) << pesanan.harga_diskon << "K" << setw(15) << pesanan.jumlah << "\n";
    }

    cout << setw(5) << "\n TOTAL: " << fixed << setprecision(0) << total_harga << "K\n";
    cout << "------------------------------\n";
}

void tampilkanKeranjang()
{
    clearscr();
    cout << "==============================\n";
    cout << "          KERANJANG        \n";
    cout << "==============================\n";
    cout << setw(5) << "MENU" << setw(15) << "HARGA" << setw(15) << "JUMLAH\n";

    for (const Pesanan &pesanan : keranjang)
    {
        cout << setw(5) << pesanan.nama << setw(15) << fixed << setprecision(0) << pesanan.harga << "K" << setw(15) << pesanan.jumlah << "\n";
    }

    cout << setw(5) << "\n TOTAL: " << fixed << setprecision(0) << total_harga << "K\n";
    cout << "------------------------------\n";
}

void resetKeranjang()
{
    keranjang.clear();
    total_harga = 0;
}

void pembayaran()
{
    tampilkanKeranjang();
    cout << "==============================\n";
    cout << "          PEMBAYARAN        \n";
    cout << "==============================\n";
    cout << "Pilih metode pembayaran\n";
    cout << setw(5) << "1. Transfer\n";
    cout << setw(5) << "2. Tunai \n";
    cout << "------------------------------\n";
}
void pembayaranbri()
{
    tampilkanKeranjangDiskon();
    cout << "==============================\n";
    cout << "          PEMBAYARAN        \n";
    cout << "==============================\n";
    cout << "Pilih metode pembayaran\n";
    cout << setw(5) << "1. Bri Virtual Account\n";
    cout << "------------------------------\n";
}

void bank()
{
    clearscr();
    tampilkanKeranjang();
    cout << "==============================\n";
    cout << "          BANK        \n";
    cout << "==============================\n";
    cout << "Pilih bank\n";
    cout << setw(5) << "1. BRI\n"
         << setw(5) << "2. BNI \n";
    cout << "------------------------------\n";
}

void pesanMakanan(int nomor, int jumlah_pesanan, string makanan[], double harga_makanan[])
{
    clearscr();
    cout << "==============================\n";
    cout << "          KERANJANG        \n";
    cout << "==============================\n";
    cout << setw(5) << "MAKANAN" << setw(15) << "HARGA" << setw(15) << "JUMLAH\n";
    cout << setw(5) << makanan[nomor - 1] << setw(15) << fixed << setprecision(0) << harga_makanan[nomor - 1] << "K.\n";

    Pesanan pesanan;
    pesanan.nama = makanan[nomor - 1];
    pesanan.harga = harga_makanan[nomor - 1] * jumlah_pesanan;
    pesanan.jumlah = jumlah_pesanan;
    keranjang.push_back(pesanan);
    total_harga = pesanan.harga;
    cout << setw(5) << "\n TOTAL: " << fixed << setprecision(0) << total_harga << "K.\n";
    cout << "------------------------------\n";
}

void pesanMinuman(int nomor, string minuman[], double harga_minuman[])
{
    clearscr();
    cout << "==============================\n";
    cout << "          KERANJANG        \n";
    cout << "==============================\n";
    cout << setw(5) << "MINUMAN" << setw(15) << "HARGA" << setw(15) << "JUMLAH\n";
    cout << setw(5) << minuman[nomor - 1] << setw(15) << fixed << setprecision(0) << harga_minuman[nomor - 1] << "K.\n";

    Pesanan pesanan;
    pesanan.nama = minuman[nomor - 1];
    pesanan.harga = harga_minuman[nomor - 1];
    pesanan.jumlah = 1;
    keranjang.push_back(pesanan);

    total_harga += pesanan.harga;
    cout << setw(5) << "\n TOTAL: " << fixed << setprecision(0) << total_harga << "K.\n";
    cout << "------------------------------\n";
}

void orderMakanan(string makanan[], double harga_makanan[], string minuman[], double harga_minuman[], string no_rek[])
{
    const int numItems = 20;
    const int numItemss = 15;

    int nomor_makanan;
    int nomor_minuman;
    int jumlah_pesanan;

    tampilkanMenuMakanan(makanan, harga_makanan, numItems);
    cout << "Silahkan masukkan nomor menu yang ingin Anda pesan: ";
    cin >> nomor_makanan;

    if (nomor_makanan >= 1 && nomor_makanan <= numItems)
    {
        cout << " Masukan jumlah pesanan: ";
        cin >> jumlah_pesanan;
        pesanMakanan(nomor_makanan, jumlah_pesanan, makanan, harga_makanan);

        char jawab;
        cout << " Ingin menambah minuman dan pesanan lain? (Y/T): ";
        cin >> jawab;

        if (jawab == 'Y' || jawab == 'y')
        {
            tampilkanMenuMinuman(minuman, harga_minuman, numItemss);
            cout << "Silahkan masukkan nomor menu minuman yang ingin Anda pesan: ";
            cin >> nomor_minuman;

            if (nomor_minuman >= 1 && nomor_minuman <= numItemss)
            {
                pesanMinuman(nomor_minuman, minuman, harga_minuman);
                tampilkanKeranjang();
                cout << " Ingin menambah pesanan? (Y/T) : ";
                char pesan_tambah;
                cin >> pesan_tambah;
                while (tolower(pesan_tambah) == 'y')
                {
                    tampilkanMenuTambahan();
                    int jawab_tambah;
                    cout << "Silahkan masukkan nomor menu tambahan yang ingingin Anda pesan: ";
                    cin >> jawab_tambah;
                    if (jawab_tambah == 1)
                    {
                        tampilkanMenuMakanan(makanan, harga_makanan, numItems);
                        cout << "Silahkan masukkan nomor menu yang ingin Anda pesan: ";
                        cin >> nomor_makanan;
                        if (nomor_makanan >= 1 && nomor_makanan <= numItems)
                        {
                            pesanMakanan(nomor_makanan, jumlah_pesanan, makanan, harga_makanan);
                            tampilkanKeranjang();
                        }
                    }
                    else if (jawab_tambah == 2)
                    {
                        tampilkanMenuMinuman(minuman, harga_minuman, numItemss);
                        cout << "Silahkan masukkan nomor menu minuman yang ingin Anda pesan: ";
                        cin >> nomor_minuman;
                        if (nomor_minuman >= 1 && nomor_minuman <= numItemss)
                        {
                            pesanMinuman(nomor_minuman, minuman, harga_minuman);
                            tampilkanKeranjang();
                        }
                    }
                    else if (jawab_tambah == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << " Maaf pilihanmu tidak ada dalam daftar menu\n";
                    }
                }

                pembayaran();
                cout << "Pilih menu pembayaran: ";
                int bayar;
                cin >> bayar;

                while (bayar == 1)
                {
                    bank();
                    cout << " Pilih bank: ";
                    int pilih_bank;
                    cin >> pilih_bank;

                    cout << "\n=================================================\n";
                    cout << " NO REK : " << no_rek[pilih_bank - 1] << "\n Harap transfer ke nomor rekening ini \n";
                    cout << "\n==================================================\n";
                    cout << "\n Inputkan nama rekening anda (Thomas_Udin): ";
                    string namarek;
                    cin >> namarek;

                    cout << " Apakah sudah melakukan pembayaran atas nama " << namarek << " ? (1: Ya, 0: Tidak): ";
                    int konfirmasi;
                    cin >> konfirmasi;
                    cout << " Sistem sedang mengecek....\n";
                    delay(3);

                    if (konfirmasi == 1)
                    {
                        cout << " Pembayaran berhasil. Harap tunjukan struk pembayaran ketika pelayan datang! \n";
                        resetKeranjang();
                        bayar = 0;
                    }
                    else
                    {
                        cout << " Pembayaran dibatalkan.\n";
                    }
                    if (bayar == 2)
                    {
                        cout << " Harap membayar ketika pelayan datang!: ";
                    }
                }
            }
            else
            {
                pesanMakanan(nomor_makanan, jumlah_pesanan, makanan, harga_makanan);
            }
        }
        else if (jawab == 'T' || jawab == 't')
        {
            tampilkanKeranjang();
            pembayaran();
            cout << "Pilih menu pembayaran: ";
            int bayar;
            cin >> bayar;
            while (bayar == 1)
            {
                bank();
                cout << " Pilih bank: ";
                int pilih_bank;
                cin >> pilih_bank;

                cout << "====================================\n";
                cout << " NO REK : " << no_rek[pilih_bank - 1] << "\n Harap transfer ke nomor rekening ini \n";
                cout << "====================================\n";
                cout << "\n Inputkan nama rekening anda (Thomas_Udin): ";
                string namarek;
                cin >> namarek;

                cout << " Apakah sudah melakukan pembayaran atas nama " << namarek << " ? (1: Ya, 0: Tidak): ";
                int konfirmasi;
                cin >> konfirmasi;
                cout << " Sistem sedang mengecek....\n";
                delay(3);

                if (konfirmasi == 1)
                {
                    cout << " Pembayaran berhasil. Harap tunjukan struk pembayaran ketika pelayan datang! \n";
                    resetKeranjang();
                    bayar = 0;
                    break;
                }
                else
                {
                    cout << " Pembayaran dibatalkan.\n";
                }
                if (bayar == 2)
                {
                    cout << " Harap membayar ketika pelayan datang!: ";
                }
            }
        }
    }
}

int main()
{
    const int numItems = 20;
    string makanan[numItems] = {"Burger", "Pizza", "Steak", "Salad", "Spaghetti", "Sushi", "Fried Chicken", "Nasi Goreng", "Pasta", "Sandwich", "Soup", "Fish and Chips", "Ramen", "Tacos", "Chicken Wings", "Curry Rice", "Lasagna", "Hot Dog", "Caesar Salad", " Mushroom Risotto"};
    double harga_makanan[numItems] = {30.00, 40.00, 60.00, 20.00, 40.00, 50.00, 25.00, 15.00, 35.00, 18.00, 12.00, 22.00, 18.00, 15.00, 20.00, 25.00, 28.00, 15.00, 22.00, 20.00};

    const int numItemss = 15;
    string minuman[numItemss] = {"Smoothies", "Ice tea", "Americano", "Espresso", "Cappuccino", "Mojito", "Milkshake", "Lemonade", "Hot Chocolate", "Iced Coffee", "Green Tea", "Orange Juice", "Cola", " Pineapple Punch", " Watermelon Cooler"};
    double harga_minuman[numItemss] = {15.0, 15.0, 20.0, 20.0, 20.0, 18.0, 25.0, 12.0, 18.0, 15.0, 10.0, 12.0, 10.0, 15.0, 20.0};

    const int numDiskon = 4;
    string makanan_diskon[numDiskon] = {"Spaghetti", "Burger", "Pizza", "Steak"};
    double harga_makanan_diskon[numDiskon] = {40.00, 30.00, 45.00, 60.00};

    string no_rek[] = {"8926672368", "99876453", "9987263"};

    int pilihan = 0;
    char kembali;

    do
    {
        cout << "==============================\n";
        cout << "             HOME         \n";
        cout << "            MEJA 15         \n";
        cout << "==============================\n";
        cout << setw(20) << " \n";
        cout << "1. Order Makanan" << endl;
        cout << "2. Special Promo" << endl;
        cout << "------------------------------\n";
        cout << " Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            orderMakanan(makanan, harga_makanan, minuman, harga_minuman, no_rek);
            break;

        case 2:
        {
            clearscr();
            cout << "==============================\n";
            cout << "        SPESIAL PROMO       \n";
            cout << "==============================\n";
            cout << "1. Promo bagi pengguna bri diskon makanan 20% \n";
            cout << "------------------------------\n";
            cout << "Pilih Promo: ";

            int promo_choice;
            cin >> promo_choice;
            switch (promo_choice)
            {
            case 1:
            {

                tampilkanMenuMakananDiskon(makanan_diskon, harga_makanan_diskon, numDiskon);
                cout << "Makanan yang mendapatkan diskon 20%:\n"s;
                cout << " Pilih Makanan: ";
                int pi_menu;
                cin >> pi_menu;

                if (pi_menu >= 1 && pi_menu <= numDiskon)
                {
                    const double diskon_persentase = 0.2;

                    Pesanan diskon;
                    diskon.nama = makanan_diskon[pi_menu - 1];
                    diskon.harga_asli = harga_makanan_diskon[pi_menu - 1];
                    diskon.harga_diskon = diskon.harga_asli * (1 - diskon_persentase);
                    cout << "Masukkan jumlah pesanan max 2: ";
                    cin >> diskon.jumlah;

                    if (diskon.jumlah >= 1 && diskon.jumlah < 3)
                    {
                        keranjang.push_back(diskon);
                        total_harga += diskon.harga_diskon * diskon.jumlah;
                        pembayaranbri();
                        cout << "Pilih menu pembayaran: ";
                        int bayar;
                        cin >> bayar;

                        while (bayar == 1)
                        {
                            cout << "====================================\n";
                            cout << " NO REK : " << no_rek[2] << "\n Harap transfer ke nomor rekening ini \n";
                            cout << "====================================\n";
                            cout << "\n Inputkan nama rekening bri anda (Thomas_Udin): ";
                            string namarek;
                            cin >> namarek;

                            cout << " Apakah sudah melakukan pembayaran atas nama " << namarek << " ? (1:Ya, 0:Tidak): ";
                            int konfirmasi;
                            cin >> konfirmasi;
                            cout << " Sistem sedang mengecek....\n";
                            delay(3);

                            if (konfirmasi == 1)
                            {
                                cout << " Harap tunjukan struk pembayaran ketika pelayan datang! \n";
                                resetKeranjang();
                                bayar = 0;
                            }
                            else
                            {
                                cout << " Pembayaran dibatalkan.\n";
                            }
                        }
                    }
                    else
                    {
                        cout << "Jumlah tidak memenuhi persyaratan\n";
                    }
                }
                else
                {
                    cout << "Pilihan tidak valid.\n";
                }

                break;
            }

            default:
                cout << "Pilihan tidak valid.\n";
                break;
            }

            break;
        }


        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
            break;
        }
        
        
    } while (pilihan !=3);

    return 0;
}
