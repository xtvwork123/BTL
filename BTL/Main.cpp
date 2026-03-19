#include <iostream>
#include <string>
#include "NghiepVu.h"
#include "FileIO.h"

using namespace std;

void hienThiMenu() {
    cout << "\n==========================================================" << endl;
    cout << "   CHUONG TRINH QUAN LY DANG KY MON HOC - NHOM 5" << endl;
    cout << "==========================================================" << endl;
    cout << " 1. Quan ly Mon hoc (Them, Sua, Xoa, In danh sach)" << endl;
    cout << " 2. Quan ly Sinh vien (Them, Sua, Xoa, In danh sach)" << endl;
    cout << " 3. Sinh vien Dang ky mon hoc" << endl;
    cout << " 4. Sinh vien Huy dang ky mon hoc" << endl;
    cout << " 5. Sap xep danh sach (Sinh vien, Mon hoc)" << endl;
    cout << " 6. Thong ke & Bao cao (In danh sach lop, Top tin chi...)" << endl;
    cout << " 7. Sao luu & Phuc hoi du lieu (Backup/Restore)" << endl;
    cout << " 0. Luu du lieu va Thoat chuong trinh" << endl;
    cout << "==========================================================" << endl;
    cout << "Nhap lua chon cua ban (0-7): ";
}

int main() {
    SinhVien* headSV = NULL;
    DanhSachMonHoc dsmh;
    dsmh.soluong = 0;

    cout << "Dang nap du lieu he thong..." << endl;
    docFileMonHoc(dsmh, "Data_MonHoc.txt");
    docFileSinhVien(headSV, "Data_SinhVien.txt");
    ghiLogHeThong("He thong khoi dong. Da nap du lieu.");

    int luaChon;
    do {
        hienThiMenu();
        cin >> luaChon;

        cin.ignore(256, '\n');

        switch (luaChon) {
        case 1: {
            int luachon;
            do {
                system("cls");
                cout << "\n--- QUAN LY MON HOC ---" << endl;
                cout << "1. Them Mon Hoc" << endl;
                cout << "2. Sua Mon Hoc" << endl;
                cout << "3. Xoa Mon Hoc" << endl;
                cout << "4. In Danh Sach Mon hoc" << endl;
                cout << "0. Quay tro lai menu chinh" << endl;
                cout << "Nhap vao lua chon cua ban: ";
                cin >> luachon;

                switch (luachon) {
                case 1: {
                    MonHoc MonHocMoi;
                    cout << "Nhap Ma Mon (khong khoang trang): ";
                    cin >> MonHocMoi.MaMon; 

                    cout << "Nhap Ten Mon: ";
                    getline(cin >> ws, MonHocMoi.TenMon);

                    cout << "Nhap so tin chi: "; cin >> MonHocMoi.TinChi;
                    cout << "Nhap so tiet ly thuyet: "; cin >> MonHocMoi.TietLyThuyet;
                    cout << "Nhap so tiet thuc hanh: "; cin >> MonHocMoi.TietThucHanh;
                    cout << "Nhap vao si so toi da: "; cin >> MonHocMoi.SiSoDangKy;

                    ThemMonHoc(dsmh, MonHocMoi);
                    break;
                }
                case 2: {
                    string MaMonHoc;
                    cout << "Nhap vao ma mon hoc ma ban muon sua: ";
                    cin >> MaMonHoc;

                    SuaMonHoc(dsmh, MaMonHoc);
                    break;
                }
                case 3: {
                    string MaMonHoc;
                    cout << "Nhap vao ma mon hoc can xoa: ";
                    cin >> MaMonHoc;

                    XoaMonHoc(dsmh, MaMonHoc);
                    break;
                }
                case 4: {
                    cout << "\n--- DANH SACH MON HOC ---" << endl;
                    for (int i = 0; i < dsmh.soluong; i++) {
                        if (!dsmh.ds[i].DaHuy) {
                            cout << "- Ma mon: " << dsmh.ds[i].MaMon
                                << " | Ten: " << dsmh.ds[i].TenMon
                                << " | Tin chi: " << dsmh.ds[i].TinChi << endl;
                        }
                    }
                    break;
                }
                case 0:
                    cout << "Dang quay lai Menu chinh..." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le!" << endl;
                }

                if (luachon != 0) {
                    cout << "\n";
                    system("pause");
                }

            } while (luachon != 0);

            system("cls");
            break;
        }

        case 2: {
            int LuaChonDoiVoiSinhVien;
            
            do {
                system("cls");
                cout << "\n--- QUAN LY SINH VIEN ---" << endl;
                cout << "1.Them sinh vien" << endl;
                cout << "2.Xoa sinh vien" << endl;
                cout << "3.Tim kiem sinh vien" << endl;
                cout << "4.In danh sach sinh vien" << endl;
                cout << "0.Quay lai menu chinh" << endl;
                cout << "Nhap vao lua chon cua ban: "; cin >> LuaChonDoiVoiSinhVien;

                switch (LuaChonDoiVoiSinhVien) {
                case 1: {
                    SinhVien* SinhVienMoi = new SinhVien;

                    SinhVienMoi->dsMonHoc = NULL;
                    SinhVienMoi->next = NULL;
                    cout << "Nhap vao ma sinh vien (khong can khoang trang): "; cin >> SinhVienMoi->MaSv;
                    cout << "Nhap vao ten sinh vien: "; getline(cin >> ws, SinhVienMoi->HoTen);
                    cout << "Nhap vao gioi tinh cua sinh vien: "; getline(cin >> ws, SinhVienMoi->GioiTinh);
                    cout << "Nhap vao vao ngay sinh(00/00/0000) cua sinh vien: "; getline(cin >> ws, SinhVienMoi->NgaySinh);
                    cout << "Nhap vao ma lop cua sinh vien: "; getline(cin >> ws, SinhVienMoi->MaLop);
                    themSinhVien(headSV, SinhVienMoi);
                    cout << "Da them sinh vien vao trong danh sach!" << endl;
                    break;
                }
                case 2: {
                    string MaSinhVien;
                    cout << "Nhap vao ma sinh vien ma ban muon xoa: "; cin >> MaSinhVien;

                    xoaSinhVien(headSV, MaSinhVien);
                    cout << "Cap nhap lai danh sach!" << endl;
                    break;
                }

                case 3: {
                    string MaSinhVien;
                    cout << "Nhap vao ma sinh vien ma ban muon tim: "; cin >> MaSinhVien;
                    SinhVien* p = headSV;
                    int Found = 0;
                    while (p != NULL) {
                        if (p->MaSv == MaSinhVien) {
                            Found = 1;
                            cout << "Ma Sinh Vien: " << p->MaSv << endl;
                            cout << "Ten Sinh Vien: " << p->HoTen << endl;
                            cout << "Gioi tinh: " << p->GioiTinh << endl;
                            cout << "Ngay Sinh: " << p->NgaySinh << endl;
                            cout << "Ma lop: " << p->MaLop << endl;
                   
                        }
                        p = p->next;
                    }

                    if (Found == 0) {
                        cout << "Khong tim thay sinh vien ban tim!" << endl;
                    }
      
                    break;
                }

                case 4: {
                    cout << "====DANH SACH SINH VIEN====" << endl;

                    if (headSV == NULL) {
                        cout << "Danh sach sinh vien dang trong. Chua co du lieu!" << endl;
                    }
                    else {
                        SinhVien* p = headSV;
                        int stt = 1;

                        cout << "=================================================================================================" << endl;
                        cout << "STT\t| Ma SV \t| Ho ten\t| Gioi tinh\t| Ngay Sinh\t| Lop" << endl;
                        cout << "=================================================================================================" << endl;

                        while (p != NULL) {
                            cout << stt++ << "\t| "
                                << p->MaSv << "\t\t| "
                                << p->HoTen << "\t\t| "
                                << p->GioiTinh << "\t\t| "
                                << p->NgaySinh << "\t| "
                                << p->MaLop << endl;
                            p = p->next;
                        }
                        cout << "-------------------------------------------------------------------------------------------------" << endl;
                    }
                    break;
                }
                }
                if (LuaChonDoiVoiSinhVien != 0) {
                    cout << "\n";
                    system("pause");
                }
       
            } while (LuaChonDoiVoiSinhVien != 0);
            break;
        }
        case 3: {
            cout << "\n--- DANG KY MON HOC ---" << endl;
            string maSV, maMon;
            cout << "Nhap Ma SV: "; cin >> maSV;
            cout << "Nhap Ma Mon can dang ky: "; cin >> maMon;
            DangKyMonHoc(headSV, dsmh, maSV, maMon);
            ghiLogHeThong("SV " + maSV + " thao tac dang ky mon " + maMon);
            break;
        }
        case 4: {
            cout << "\n--- HUY DANG KY MON HOC ---" << endl;
            string maSV, maMon;
            cout << "Nhap Ma SV: "; cin >> maSV;
            cout << "Nhap Ma Mon can huy: "; cin >> maMon;
            HuyDangKy(headSV, dsmh, maSV, maMon);
            ghiLogHeThong("SV " + maSV + " huy mon " + maMon);
            break;
        }
        case 5: {
            cout << "\n--- SAP XEP DANH SACH ---" << endl;
            sapXepSinhVien(headSV); 
            SapXepMonHoc(dsmh);     
            break;
        }
        case 6: {
            int chonThongKe;
            do {
                cout << "\n=============================================" << endl;
                cout << "           THONG KE & BAO CAO" << endl;
                cout << "=============================================" << endl;
                cout << " 1. In danh sach sinh vien cua 1 mon hoc" << endl;
                cout << " 2. Thong ke si so cac mon hoc (Dang bang)" << endl;
                cout << " 3. Tim sinh vien dang ky nhieu tin chi nhat" << endl;
                cout << " 4. In danh sach sinh vien dang cho (Queue)" << endl;
                cout << " 0. Quay lai menu chinh" << endl;
                cout << "=============================================" << endl;
                cout << "Chon chuc nang thong ke: ";
                cin >> chonThongKe;
                cin.ignore(256, '\n');

                switch (chonThongKe) {
                case 1: {
                    string maMonTK;
                    cout << "Nhap Ma mon can xem danh sach: ";
                    cin >> maMonTK;

                    int viTri = TimViTriMonHoc(dsmh, maMonTK);
                    if (viTri == -1) {
                        cout << "Mon hoc khong ton tai!" << endl;
                    }
                    else {
                        cout << "\n--- DANH SACH SINH VIEN MON " << dsmh.ds[viTri].TenMon << " ---" << endl;
                        int stt = 1;
                        SinhVien* p = headSV;
                        while (p != NULL) {
                            if (KiemTraSinhVienDangKy(p, maMonTK)) {
                                cout << stt++ << ". " << p->MaSv << " - " << p->HoTen << " - " << p->MaLop << endl;
                            }
                            p = p->next;
                        }
                        if (stt == 1) cout << "Chua co sinh vien nao dang ky!" << endl;
                    }
                    break;
                }
                case 2: {
                    cout << "\n--- THONG KE SI SO MON HOC ---" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Ma Mon\t| Ten Mon\t\t| Si So\t| Max\t| Tinh trang" << endl;
                    cout << "--------------------------------------------------------" << endl;
                    for (int i = 0; i < dsmh.soluong; i++) {
                        if (!dsmh.ds[i].DaHuy) {
                            cout << dsmh.ds[i].MaMon << "\t| "
                                << dsmh.ds[i].TenMon << "\t| "
                                << dsmh.ds[i].SiSo << "\t| "
                                << dsmh.ds[i].SiSoDangKy << "\t| ";
                            if (dsmh.ds[i].SiSo >= dsmh.ds[i].SiSoDangKy) cout << "DA DAY";
                            else cout << "CON CHO";
                            cout << endl;
                        }
                    }
                    cout << "--------------------------------------------------------" << endl;
                    break;
                }
                case 3: {
                    cout << "\n--- SINH VIEN DANG KY NHIEU TIN CHI NHAT ---" << endl;
                    if (headSV == NULL) {
                        cout << "Danh sach sinh vien rong!" << endl;
                        break;
                    }

                    SinhVien* p = headSV;
                    SinhVien* svTop = headSV;
                    int maxTinChi = 0;

                    while (p != NULL) {
                        int tongTinChi = 0;
                        MonDaDangKy* monNode = p->dsMonHoc;
                        while (monNode != NULL) {
                            int vt = TimViTriMonHoc(dsmh, monNode->MaMon);
                            if (vt != -1) tongTinChi += dsmh.ds[vt].TinChi;
                            monNode = monNode->next;
                        }

                        if (tongTinChi > maxTinChi) {
                            maxTinChi = tongTinChi;
                            svTop = p;
                        }
                        p = p->next;
                    }

                    if (maxTinChi > 0) {
                        cout << "Sinh vien cham chi nhat la: " << svTop->HoTen
                            << " (" << svTop->MaSv << ") voi tong " << maxTinChi << " tin chi!" << endl;
                    }
                    else {
                        cout << "Chua co sinh vien nao dang ky mon!" << endl;
                    }
                    break;
                }
                case 4: {
                    string maMonQ;
                    cout << "Nhap Ma mon can kiem tra hang doi (Queue): ";
                    cin >> maMonQ;

                    int viTri = TimViTriMonHoc(dsmh, maMonQ);
                    if (viTri == -1) {
                        cout << "Mon hoc khong ton tai!" << endl;
                    }
                    else {
                        cout << "\n--- DANH SACH CHO (WAITING LIST) MON " << dsmh.ds[viTri].TenMon << " ---" << endl;
                        // Duyệt Queue từ front đến NULL để in ra
                        QueueNode* qNode = dsmh.ds[viTri].HangDoi.front;
                        int stt = 1;
                        while (qNode != NULL) {
                            cout << stt++ << ". Ma SV: " << qNode->maSV << " (Dang cho xet duyet)" << endl;
                            qNode = qNode->next;
                        }
                        if (stt == 1) cout << "Khong co sinh vien nao dang cho!" << endl;
                    }
                    break;
                }
                case 0:
                    cout << "Quay lai menu chinh..." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le!" << endl;
                }
            } while (chonThongKe != 0);
            break;
        }
        case 7: {
            cout << "\n--- SAO LUU DU LIEU ---" << endl;
            backupDuLieu(headSV, dsmh); // [cite: 64]
            break;
        }
        case 0: {
            cout << "\nDang luu du lieu truoc khi thoat..." << endl;
            ghiFileMonHoc(dsmh, "Data_MonHoc.txt");
            ghiFileSinhVien(headSV, "Data_SinhVien.txt");
            ghiLogHeThong("He thong tat. Da luu du lieu.");

            //while (headSV != NULL) {
            //    xoaSinhVien(headSV, headSV->MaSv);
            //}
            break;
        }
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
        }
    } while (luaChon != 0);

    return 0;
}