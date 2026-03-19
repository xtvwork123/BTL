#pragma once
#include <iostream>
#include <string>
using namespace std;

struct MonDaDangKy {
	string MaMon;
	MonDaDangKy* next;
};

struct SinhVien {
	string MaSv;
	string HoTen;
	string GioiTinh;
	string NgaySinh;
	string MaLop;
	MonDaDangKy* dsMonHoc;
	SinhVien* next;
}; 

SinhVien* taoNodeSinhVien(string maSV, string hoTen, string gioiTinh, string ngaySinh, string maLop);
bool themSinhVien(SinhVien*& headSV, SinhVien* svMoi);
SinhVien* timKiemSinhVien(SinhVien* headSV, string maSV);
bool xoaSinhVien(SinhVien*& headSV, string maSV);
void sapXepSinhVien(SinhVien* headSV);