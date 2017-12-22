#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count, folder;
bool dir, zx;

void dfs() {

	HANDLE hFind;
	WIN32_FIND_DATA fileinfo;

	hFind = FindFirstFile(L"*", &fileinfo);
	//wprintf(L"%s\n", fileinfo.cFileName);

	do {
		dir = (fileinfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
		if (dir) {
			folder++;
		}
		count++; // ��������� ����� �� ���������??
		if (count>2) {
			wprintf(L"file #%d, dir=%d, name <%s>\n", count - 2, dir, fileinfo.cFileName);
		}

		// ...
		// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &fileinfo) != 0);
	FindClose(hFind);

	SetCurrentDirectory(L"..");
}



int main() {
    	wchar_t s[512];              	// ������� �����
    	GetCurrentDirectory(512, s);	// �������� ������� �����
    	wprintf(L"Starting in: %s\n", s);
		zx = 1;
    	count = 0;                  	// �������� ������� ������    	
		folder = 0;
		dfs();
		printf("File count=%d, folder=%d\n", count-2, folder-2);
    	return 0;
}

