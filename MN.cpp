#include<bits/stdc++.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 

int main(void)
{
	system("shutdown -s -t 120 -c ע�⣺�벻Ҫ��ͼ�ر��������");
	
	while (true)
	{
		if(KEY_DOWN('S') || KEY_DOWN('R'))
		{
			system("shutdown -a");
			system("shutdown -s -t 60 -c ���棺��ͼ�رս��̽����ٹر�");
		}
		if(KEY_DOWN('A'))
		{
			Sleep(2000);
			system("shutdown -s -t 60 -c ���棺��ͼ�رս��̽����ٹر�");
		}
		
		Sleep(20);
		system("cls");
	}
	
	return 0;
}
