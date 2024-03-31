#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_UNIVERSITIES = 3;


struct University {
    string name;
    string location;
    string about;
    int establishmentYear;
    string accreditation;
    int ranking;
};

int searchUniversity(const vector<University> &universities, const string &keyword) {
    for (int i = 0; i < universities.size(); ++i) {
        if (universities[i].name == keyword) {
            return i;
        }
    }
    return -1;
}

void sortUniversities(vector<University> &universities) {
    sort(universities.begin(), universities.end(), [](const University &a, const University &b) {
        return a.ranking < b.ranking;
    });
}

int main() {
    vector<University> universities(MAX_UNIVERSITIES);

    char choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Masukkan Informasi Universitas\n";
        cout << "2. Cari Universitas\n";
        cout << "3. Lihat Universitas\n";
        cout << "4. Urutan Peringkat Universitas\n";
        cout << "5. keluar\n";
        cout << "Pilih Opsi: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': {
                cout << "Masukkan Informasi Universitas:\n"; 
                for (int i = 0; i < MAX_UNIVERSITIES; ++i) {
                    cout << "Universitas ke-" << i + 1 << ":\n"; 
                    cout << "Nama: ";
                    getline(cin, universities[i].name);
                    cout << "Lokasi: ";
                    getline(cin, universities[i].location);
                    cout << "Tentang: ";
                    getline(cin, universities[i].about);
                    cout << "Tahun Berdiri: ";
                    cin >> universities[i].establishmentYear;
                    cout << "Akreditas: ";
                    cin >> universities[i].accreditation;
                    cout << "Peringkat: ";
                    cin >> universities[i].ranking;
                    cin.ignore(); 
                }
                break;
            }
            case '2': {
                string searchInput;
                cout << "Masukkan kata kunci untuk mencari Universitas: ";
                getline(cin, searchInput);

            stringstream ss(searchInput);
            string keyword;
            vector<string> keywords;
            while (ss >> keyword) {
                keywords.push_back(keyword); 
            }

            bool found = false; 
            for (const auto &word : keywords) {
                int index = searchUniversity(universities, word);
                if (index != -1) {
                    found = true;
                    cout << "\nInformasi Universitas:\n";
                    cout << "Nama: " << universities[index].name << endl;
                    cout << "Lokasi: " << universities[index].location << endl;
                    cout << "Tentang: " << universities[index].about << endl;
                    cout << "Tahun Berdiri: " << universities[index].establishmentYear << endl;
                    cout << "Akreditas: " << universities[index].accreditation << endl;
                    cout << "Peringkat: " << universities[index].ranking << endl;
                    break;
                }
            }
            if (!found) {
                cout << "Universitas tidak ditemukan.\n";
            }
            break;
        }
        case '3': {
            cout << "\nDaftar Universitas:\n";
            for (int i = 0; i < MAX_UNIVERSITIES; ++i){
                cout << "Universitas ke-" << i + 1 << ":\n";
                cout << "Nama: " << universities[i].name << endl;       
                cout << "Lokasi: " << universities[i].location << endl;    
                cout << "Tentang: " << universities[i].about << endl;  
                cout << "Tahun Berdiri: " << universities[i].establishmentYear << endl;     
                cout << "Akreditas: " << universities[i].accreditation << endl;  
                cout << "Peringkat: " << universities[i].ranking << endl;    
            }
            break;
        }
        case '4': {
            sortUniversities(universities); 
            cout << "\nUrutan Peringkat Universitas:\n";
            for (int i = 0; i < MAX_UNIVERSITIES; ++i) {
                cout << "Peringkat " << universities[i].ranking << ": " << universities[i].name << endl;
            }
          break;
        }
        case '5':{
            cout << "Terima kasih telah melakukan program.\n";
            break;
        }
        default:
            cout <<"Opsi tidak valid. Silahkan coba lagi.\n";
        }
    } while (choice !=5);

    return 0;
}