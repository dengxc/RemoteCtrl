#include <stdio.h>
#include "itmojun.h"
#include <windows.h>

// ���뵱ǰ�����µ�itmojun.lib�Լ�winmm���ļ�
#pragma comment(lib, "itmojun.lib") //AutoRun() �Լ� GetPCCmd()
#pragma comment(lib, "winmm.lib") //mciSendString()

int main()
{
	char cmd[301]; //��Ŵ�΢�Ž��ܵ���Ϣ
	AutoRun(); //����ǰ��������Ϊ�����Զ�����

	mciSendString("open bg.mp3 alias s", NULL, 0, NULL); //��ָ�������ļ���ָ�������Ϊs

	while(1)
	{
		//��΢�Ŷ˽���һ����Ϣ
		//��һ������Ϊ����id����ͬ���Խ���ʹ�ò�ͬid
		//�ڶ�������Ϊ������Ϣ������
		GetPCCmd("dxc", cmd);

		printf("%s\n", cmd);

		if(strstr(cmd, "�ػ�"))
		{
			//�ػ�ָ��
			WinExec("shutdown -s -t 0", 0);
		}
		else if(strstr(cmd, "����"))
		{
			WinExec("shutdown -r -t 0", 0);
		}
		else if(strstr(cmd, "����"))
		{
			static int kill_flag = 1;
			if (kill_flag)
			{
				//�ر�����
				WinExec("taskkill /f /im explorer.exe", 0);
			}
			else
			{
				//�ָ�����
				WinExec("C:\\Windows\\explorer.exe", 1);
			}
			kill_flag = !kill_flag;
		}
		else if(strstr(cmd, "�ر�QQ"))
		{
			WinExec("taskkill /f /im qq.exe", 0);
		}
		else if(strstr(cmd, "�ر�Ӣ������"))
		{
			WinExec("taskkill /f /im client.exe", 0);
		}
		else if(strstr(cmd, "���"))
		{
			//ǿ�ƴ򿪹��
			WinExec("explorer http://www.4399.com", 1);
		}
		else if(strstr(cmd, "����"))
		{
			mciSendString("play s repeat", NULL, 0, NULL); //�ظ�����s
		}
		else if(strstr(cmd, "��ͣ"))
		{
			mciSendString("pause s", NULL, 0, NULL);
		}
		else if(strstr(cmd, "ֹͣ"))
		{
			mciSendString("close s", NULL, 0, NULL);
		}
		


		Sleep(3000); //��ʱ3�룬�����յ��ظ���Ϣ����Ϊ��Ϣ���ڷ��������ݴ�3��
	}

	return 0;	
}
