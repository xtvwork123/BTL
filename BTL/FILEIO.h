#pragma once
#include "MonHoc.h"
#include "SinhVien.h"
#include <string>
#include <fstream>

using namespace std;

void ghiLogHeThong(string thongBao);

bool ghiFileMonHoc(DanhSachMonHoc& dsmh, string tenFile);
bool docFileMonHoc(DanhSachMonHoc& dsmh, string tenFile);

bool ghiFileSinhVien(SinhVien* headSV, string tenFile);
bool docFileSinhVien(SinhVien*& headSV, string tenFile);

void backupDuLieu(SinhVien* headSV, DanhSachMonHoc& dsmh);
void restoreDuLieu(SinhVien*& headSV, DanhSachMonHoc& dsmh);

