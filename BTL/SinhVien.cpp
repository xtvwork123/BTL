#include "SinhVien.h"
#include <iostream>

SinhVien *taoNodeSinhVien(string MaSV, string HoTen, string GioiTinh, string NgaySinh, string MaLop) {
	SinhVien* sv = new SinhVien;

	if (sv == NULL) {
		cout << "Loi: Khong du bo nho!" << endl;
		return NULL;
	}

	sv->MaSv = MaSV;
	sv->HoTen = HoTen;
	sv->GioiTinh = GioiTinh;
	sv->NgaySinh = NgaySinh;
	sv->MaLop = MaLop;
	sv->dsMonHoc = NULL;
	sv->next = NULL;
	return sv;
}

SinhVien* timKiemSinhVien(SinhVien* headSV, string MaSV) {
	SinhVien* p = headSV;

	while (p != NULL) {
		if (p->MaSv == MaSV) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

bool themSinhVien(SinhVien*& headSV, SinhVien* svMoi) {
	if (svMoi == NULL) return false;

	if (timKiemSinhVien(headSV, svMoi->MaSv) != NULL) {
		cout << "Loi: Ma Sinh vien da ton tai!" << endl;
		return false;
	}
	
	if (headSV == NULL) {
		headSV = svMoi;
	}

	else {
		SinhVien* p = headSV;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = svMoi;
	}
	return true;
}

bool xoaSinhVien(SinhVien*& headSv, string MaSV) {
	if (headSv == NULL) return false;

	SinhVien* p = headSv;
	SinhVien* prev = NULL;

	while (p != NULL && p->MaSv != MaSV) {
		prev = p;
		p = p->next;
	}

	if (p == NULL) {
		cout << "Khong tim thay ten de xoa!" << endl;
		return false;
	}

	MonDaDangKy* MonNode = p->dsMonHoc;
	while (MonNode != NULL) {
		MonDaDangKy* tempMon = MonNode;
		MonNode = MonNode->next;
		delete tempMon;
	}

	if (prev == NULL) {
		headSv = headSv->next;
	}

	else {
		prev->next = p->next;
	}
	delete p;
	cout << "Da xoa sinh vien thanh cong!" << endl;
	return true;
}

void hoanDoiSinhVien(SinhVien* a, SinhVien* b) {
	swap(a->MaSv, b->MaSv);
	swap(a->HoTen, b->HoTen);
	swap(a->GioiTinh, b->GioiTinh);
	swap(a->NgaySinh, b->NgaySinh);
	swap(a->MaLop, b->MaLop);
	swap(a->dsMonHoc, b->dsMonHoc);
}

void sapXepSinhVien(SinhVien* headSV) {
	if (headSV == NULL || headSV->next == NULL) return;

	SinhVien* p = headSV;
	
	while (p->next != NULL) {
		SinhVien* minNode = p;
		SinhVien* q = p->next;

		while (q != NULL) {
			if (q->HoTen < minNode->HoTen) {
				minNode = q;
			}
			q = q->next;
		}
		if (minNode != p) {
			hoanDoiSinhVien(p, minNode);
		}
		p = p->next;
	}
	cout << "Da sap xep xong danh sach sinh vien" << endl;
}
