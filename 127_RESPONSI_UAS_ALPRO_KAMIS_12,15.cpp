#include<iostream>
#include<fstream>
using namespace std;
class nilai{
	private:
		
	public:
		void next();
		void pause();
		void menu();
};

void nilai::next() {
    cout << "Tekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
    system("cls");
}
void nilai::pause() {
	cout << "Tekan Enter untuk kembali ke menu...";
	cin.ignore();
	cin.get();
}
		
void nilai::menu(){
	nilai n;
	int nama=100, matkul=300, pilihmenu;
	string mahasiswa[nama][matkul];
	string matakuliah[matkul];
	string cetak1;
	do{
		cout<<"=== MENU ===\n";
		cout<<"1. Input Nilai\n";
		cout<<"2. Data Mahasiswa\n";
		cout<<"3. Informasi Kelulusan\n";
		cout<<"0. Keluar\n";
		cout<<"-==============================-\n";
		cout<<"masukkan nomor pilihan anda: ";
		cin>>pilihmenu;
		n.next();
				
		switch (pilihmenu){
			case 1:
			cout<<"ada berapa mahasiswa yang mau di inputkan?\n";
			cin>>nama;
			system("cls");
			cout<<"ada berapa matkul?\n";
			cin>>matkul;
			system("cls");
			for (int i = 0; i < matkul; i++){
				cout<<"Mata Kuliah Ke-"<<i+1<<": ";
				cin>>matakuliah[i];
			}
			system("cls");
						
			for (int i = 0; i < nama; i++){
				cout<<"-==========================================-\n";
				cout<<"Nama: ";
				cin>>mahasiswa[i][matkul];
				for(int j = 0; j < matkul; j++){
					cout<<"Nilai Mata Kuliah "<<matakuliah[j]<<": "	;
					cin>>mahasiswa[nama][j];
				}
			}
			cout<<"apakah anda ingin mencetak data nilai mahasiswa?(ya/no)!!\n";
			cin>>cetak1;
			if(cetak1 == "ya"){
							
				ofstream file("Nilai_Mahasiswa.txt", ios::app);
				for (int i = 0; i < nama; i++){
					file << "========================================\n";
					file<<"Nama: "<<mahasiswa[i][matkul]<<endl;
					for(int j = 0; j < matkul; j++){
						file<<"Nilai Mata Kuliah "<<matakuliah[j]<<": "<<mahasiswa[nama][j]<<endl;	
					}
				}
							
				file.close();
			}
			n.pause();
			break;
		case 2:
			cout<<"TERIMA KASIH\n";
			break;
		case 3:
			for (int i = 0; i < nama; i++){
				cout << "========================================\n";
				cout<<"Nama: "<<mahasiswa[i][matkul]<<endl;
				for(int j = 0; j < matkul; j++){
					cout<<"Nilai Mata Kuliah "<<matakuliah[j]<<": "<<mahasiswa[nama][j]<<endl;	
				}
				cout<<"Rata-Rata Nilai: ";
				for (int k; k<matkul; k++){
					cout<<mahasiswa[nama][k]<<"+";
				}
				
				cout<<endl;
			}
			cin.ignore();		
			break;
		case 0:
			cout<<"TERIMA KASIH\n";
			break;
				}
				
	}while (pilihmenu != 0);
}
int main(){
	nilai n;
	n.menu();
	cin.ignore();
	
	return 0;
}
