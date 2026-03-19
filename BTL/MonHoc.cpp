#include "MonHoc.h"
#include <iostream>
using namespace std;

int TimViTriMonHoc(DanhSachMonHoc& dsmh, string maMon) {
	for (int i = 0; i < dsmh.soluong; i++) {
		if (dsmh.ds[i].MaMon == maMon && dsmh.ds[i].DaHuy == false) {
			return i;
		}
	}
	return -1;
}

bool ThemMonHoc(DanhSachMonHoc& dsmh, MonHoc MonHocMoi) {
	if (dsmh.soluong > MAX) {
		cout << "Danh sach mon hoc da day" << endl;
		return false;
	}

	if (TimViTriMonHoc(dsmh, MonHocMoi.MaMon) != -1) {
		cout << "Loi: Ma mon hoc da ton tai" << endl;
		return false;
	}

	MonHocMoi.SiSo = 0;
	MonHocMoi.DaHuy = false;
	initQueue(MonHocMoi.HangDoi);

	dsmh.ds[dsmh.soluong] = MonHocMoi;
	dsmh.soluong++;

	return true;
}

bool XoaMonHoc(DanhSachMonHoc& dsmh, string maMon) {
	int ViTri = TimViTriMonHoc(dsmh, maMon);

	if (ViTri == -1) {
		cout << "LOI: khong tim thay mon hoc de xoa" << endl;
		return false;
	}

	if (dsmh.ds[ViTri].SiSo > 0) {
		dsmh.ds[ViTri].DaHuy = true;
		cout << "Mon hoc da co sinh vien dang ki. Da danh dau huy thanh cong!" << endl;
	}

	else {
		for (int i = 0; i < dsmh.soluong - 1; i++) {
			dsmh.ds[i] = dsmh.ds[i + 1];
		}
		dsmh.soluong--;
		cout << "Da xoa thanh cong!" << endl;
	}
	return true;
}

bool SuaMonHoc(DanhSachMonHoc& dsmh, string maMon) {
	int ViTri = TimViTriMonHoc(dsmh, maMon);

	if (ViTri == -1) {
		cout << "Khong tim thay mon hoc de sua!" << endl;
		return false;
	}

	cout << "Nhap ten mon hoc moi: ";
	getline(cin >> ws, dsmh.ds[ViTri].TenMon);
	cout << "Nhap so tin chi moi: "; cin >> dsmh.ds[ViTri].TinChi;
	cout << "Nhap tiet ly thuyet: "; cin >> dsmh.ds[ViTri].TietLyThuyet;
	cout << "Nhap tiet thuc hanh: "; cin >> dsmh.ds[ViTri].TietThucHanh;
	cout << "Nhap si so toi da: "; cin >> dsmh.ds[ViTri].SiSo;

	cout << "Cap nhap thanh cong!" << endl;
	return true;
}

void SapXepMonHoc(DanhSachMonHoc& dsmh) {
	for (int i = 0; i < dsmh.soluong - 1; i++) {
		int ViTriMax = i;
		for (int j = i + 1; j < dsmh.soluong; j++) {
			if (dsmh.ds[j].SiSoDangKy > dsmh.ds[ViTriMax].SiSoDangKy) {
				ViTriMax = j;
			}
		}

		if (ViTriMax != i) {
			MonHoc temp = dsmh.ds[i];
			dsmh.ds[i] = dsmh.ds[ViTriMax];
			dsmh.ds[ViTriMax] = temp;
		}
	}
	cout << "Da sap xep theo so luong sinh vien dang ki giam dan" << endl;
}

