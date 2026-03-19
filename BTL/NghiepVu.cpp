#include "NghiepVu.h"
#include <iostream>
using namespace std;

bool KiemTraSinhVienDangKy(SinhVien* sv, string MaMon) {
	if (sv == NULL) return false;

	MonDaDangKy* p = sv->dsMonHoc;

	while (p != NULL) {
		if (p->MaMon == MaMon) return true;
		p = p->next;
	}
	return false;
}

void DangKyMonHoc	(SinhVien* headSV, DanhSachMonHoc& dsmh, string MaSV, string MaMon) {
	SinhVien* sv = timKiemSinhVien(headSV, MaSV);

	if (sv == NULL) {
		cout << "Khong tim thay ma sinh vien" << endl;
		return;
	}

	int ViTriMon = TimViTriMonHoc(dsmh, MaMon);

	if (ViTriMon == -1) {
		cout << "Khong tim thay mon hoc" << endl;
		return;
	}

	if (KiemTraSinhVienDangKy(headSV, MaMon)) {
		cout << "Sinh vien da dang ki mon nay roi" << endl;
		return;
	}

	if (dsmh.ds[ViTriMon].SiSo < dsmh.ds[ViTriMon].SiSoDangKy) {
		MonDaDangKy* monMoi = new MonDaDangKy;
		monMoi->MaMon = MaMon;

		monMoi->next = sv->dsMonHoc;
		sv->dsMonHoc = monMoi;

		dsmh.ds[ViTriMon].SiSo++;
		cout << " Da Dang ky thanh cong " << dsmh.ds[ViTriMon].TenMon << " cho sinh vien " << sv->HoTen << endl;
	}

	else {
		pushQueue(dsmh.ds[ViTriMon].HangDoi, MaSV);
		cout << "Thong bao: Lop da day. Sinh vien " << sv->HoTen << " da duoc dua vao danh sach cho " << endl;
	}
}

void DuyetQueueTuDong(SinhVien* headSV, DanhSachMonHoc& dsmh, string MaMon) {
	int ViTriMon = TimViTriMonHoc(dsmh, MaMon);
	if (ViTriMon == -1) return;
	// Kiem tra xem lop con cho trong va queue co hang doi khong
	if (dsmh.ds[ViTriMon].SiSo < dsmh.ds[ViTriMon].SiSoDangKy 
		&& !isEmpty(dsmh.ds[ViTriMon].HangDoi)) {
		// lay ng dau tien trong queue ra
		string MaSV_cho = popQueue(dsmh.ds[ViTriMon].HangDoi);
		
		if (MaSV_cho == ""){
			cout << "Co sinh vien cho trong hang cho mon" << MaMon << endl;
			DangKyMonHoc(headSV, dsmh, MaSV_cho, MaMon);
		}
	}
}

void HuyDangKy(SinhVien* headSV, DanhSachMonHoc& dsmh, string MaSV, string MaMon) {
	SinhVien* sv = timKiemSinhVien(headSV, MaSV);

	if (sv == NULL) return;

	int ViTriMon = TimViTriMonHoc(dsmh, MaMon);

	if (ViTriMon == -1) return;

	MonDaDangKy* p = sv->dsMonHoc;
	MonDaDangKy* prev = NULL;

	while (p != NULL && p->MaMon != MaMon) {
		prev = p;
		p = p->next;
	}
	
	if (p == NULL) {
		cout << "Sinh vien chua dang ky mon nay" << endl;
		return;
	}

	if (prev == NULL) {
		sv->dsMonHoc = p->next;
	}
	else {
		prev->next = p->next;
	}

	delete p;

	dsmh.ds[ViTriMon].SiSo--;

	cout << "Da Huy Dang ky mon " << " cho sinh vien " << sv->MaSv << endl;

	DuyetQueueTuDong(headSV, dsmh, MaMon);
}