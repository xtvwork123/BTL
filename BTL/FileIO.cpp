#include "FileIO.h"
#include <ctime> // Thư viện để lấy thời gian thực cho Log
#pragma warning(disable: 4996) // Bỏ qua cảnh báo hàm lấy thời gian của C++ cũ
#include <sstream>
using namespace std;

// 1. Ghi Log hệ thống (Ghi nối thêm vào cuối file - ios::app)
void ghiLogHeThong(string thongBao) {
    ofstream fileOut("SystemLog.txt", ios::app);
    if (fileOut.is_open()) {
        // Lấy thời gian hiện tại của hệ thống
        time_t now = time(0);
        char* dt = ctime(&now);
        string thoiGian(dt);
        thoiGian.pop_back(); // Xóa dấu xuống dòng bị dư của ctime

        // Ghi vào file: [Thời gian] - Thông báo
        fileOut << "[" << thoiGian << "] " << thongBao << endl;
        fileOut.close();
    }
}

// 2. Ghi danh sách môn học (Duyệt mảng)
bool ghiFileMonHoc(DanhSachMonHoc& dsmh, string tenFile) {
    ofstream fileOut(tenFile);
    if (!fileOut.is_open()) return false;

    // Ghi số lượng môn học lên dòng đầu tiên để lúc đọc biết đường lặp
    fileOut << dsmh.soluong << endl;
    for (int i = 0; i < dsmh.soluong; i++) {
        fileOut << dsmh.ds[i].MaMon << ","
            << dsmh.ds[i].TenMon << ","
            << dsmh.ds[i].TinChi << ","
            << dsmh.ds[i].TietLyThuyet << ","
            << dsmh.ds[i].TietThucHanh << ","
            << dsmh.ds[i].SiSo << ","
            << dsmh.ds[i].SiSoDangKy << ","
            << dsmh.ds[i].DaHuy << endl;
    }
    fileOut.close();
    return true;
}

// 3. Đọc file môn học
bool docFileMonHoc(DanhSachMonHoc& dsmh, string tenFile) {
    ifstream fileIn(tenFile);
    if (!fileIn.is_open()) return false;

    dsmh.soluong = 0;
    string dongDau;
    getline(fileIn, dongDau); // Đọc số lượng bỏ qua

    string tam;
    while (fileIn.good()) {
        MonHoc mh;
        getline(fileIn, mh.MaMon, ',');
        if (mh.MaMon == "") break; // Hết file

        getline(fileIn, mh.TenMon, ',');

        getline(fileIn, tam, ','); mh.TinChi = stoi(tam);
        getline(fileIn, tam, ','); mh.TietLyThuyet = stoi(tam);
        getline(fileIn, tam, ','); mh.TietLyThuyet = stoi(tam);
        getline(fileIn, tam, ','); mh.SiSo = stoi(tam);
        getline(fileIn, tam, ','); mh.SiSoDangKy = stoi(tam);
        getline(fileIn, tam);      mh.DaHuy = stoi(tam); // Đọc đến hết dòng

        initQueue(mh.HangDoi); // Đừng quên khởi tạo Queue cho môn học này

        dsmh.ds[dsmh.soluong] = mh;
        dsmh.soluong++;
    }
    fileIn.close();
    return true;
}

bool ghiFileSinhVien(SinhVien* headSV, string TenFile) {
    ofstream FileOut(TenFile);

    if (!FileOut.is_open()) return false;

    SinhVien* p = headSV;

    while (p != NULL) {
        FileOut << p->MaSv << "," << p->HoTen << "," << p->GioiTinh << ","
            << p->NgaySinh << "," << p->MaLop << ",";

        int SoLuongMon = 0;
        MonDaDangKy* m = p->dsMonHoc;

        while (m != NULL) {
            SoLuongMon++;
            m = m->next;
        }
        FileOut << SoLuongMon;

        m = p->dsMonHoc;

        while (m != NULL) {
            FileOut << "," << m->MaMon;
            m = m->next;
        }
        FileOut << endl;
        p = p->next;
    }
    FileOut.close();
    return true;
}

bool docFileSinhVien(SinhVien*& headSV, string TenFile) {
    ifstream FileIn(TenFile);

    if (!FileIn.is_open()) return false;

    while (FileIn.good()) {
        string MaSV, HoTen, GioiTinh, NgaySinh, MaLop;

        getline(FileIn, MaSV, ',');
        if (MaSV == "") break;

        getline(FileIn, HoTen, ',');
        getline(FileIn, GioiTinh, ',');
        getline(FileIn, NgaySinh, ',');
        getline(FileIn, MaLop, ',');

        SinhVien* svMoi = taoNodeSinhVien(MaSV, HoTen,GioiTinh, NgaySinh, MaLop);

        string PhanConLai;
        getline(FileIn, PhanConLai);

        stringstream ss(PhanConLai);
        string tam;

        getline(ss, tam, ',');
        int SoLuongMon = 0;
        if (tam != "") SoLuongMon = stoi(tam);

        for (int i = 0; i < SoLuongMon; i++) {
            string MaMonDangKy;
            getline(ss, MaMonDangKy, ',');

            MonDaDangKy* MonNode = new MonDaDangKy;
            MonNode->MaMon = MaMonDangKy;
            MonNode->next = svMoi->dsMonHoc;
            svMoi->dsMonHoc = MonNode;
        }
        themSinhVien(headSV, svMoi);
    }
    FileIn.close();
    return true;
}

// 4. Chức năng Backup (Sao lưu toàn bộ)
void backupDuLieu(SinhVien* headSV, DanhSachMonHoc& dsmh) {
    if (ghiFileMonHoc(dsmh, "Backup_MonHoc.txt")) { // Tương tự sẽ gọi thêm ghiFileSinhVien
        cout << "Da sao luu du lieu Mon hoc thanh cong!" << endl;
        ghiLogHeThong("Thuc hien Backup du lieu mon hoc.");
    }
    else {
        cout << "Loi: Khong the tao file Backup!" << endl;
    }

    
    if (ghiFileSinhVien(headSV, "Backup_SinhVien.txt")) {
        cout << "Da sao luu du lieu Sinh vien thanh cong!" << endl;
        ghiLogHeThong("Thuc hien Backup du lieu sinh vien.");
    }

    else {
        cout << "Loi: Khong the tao file Backup!" << endl;
    }
    
}