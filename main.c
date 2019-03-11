#include <stdio.h>
#include "itmojun.h"
#include <windows.h>

// 引入当前工程下的itmojun.lib库文件
#pragma comment(lib, "itmojun.lib")

int main()
{
	char cmd[301]; //存放从微信接受的消息
	AutoRun(); //将当前程序设置为开机自动运行

	while(1)
	{
		//从微信端接收一条消息
		//第一个参数为电脑id，不同电脑建议使用不同id
		//第二个参数为接收消息的数组
		GetPCCmd("dxc", cmd);

		printf("%s\n", cmd);

		if(strstr(cmd, "关机"))
		{
			//关机指令
			WinExec("shutdown -s -t 0", 0);
		}
		else if(strstr(cmd, "重启"))
		{
			WinExec("shutdown -r -t 0", 0);
		}
		else if(strstr(cmd, "桌面"))
		{
			static int kill_flag = 1;
			if (kill_flag)
			{
				//关闭桌面
				WinExec("taskkill /f /im explorer.exe", 0);
			}
			else
			{
				//恢复桌面
				WinExec("C:\\Windows\\explorer.exe", 1);
			}
			kill_flag = !kill_flag;
		}
		else if(strstr(cmd, "关闭QQ"))
		{
			WinExec("taskkill /f /im qq.exe", 0);
		}
		else if(strstr(cmd, "关闭英雄联盟"))
		{
			WinExec("taskkill /f /im client.exe", 0);
		}
		else if(strstr(cmd, "广告"))
		{
			//强制打开广告
			WinExec("explorer http://www.4399.com", 1);
		}
		


		Sleep(3000); //延时3秒，避免收到重复消息，因为消息会在服务器中暂存3秒
	}

	return 0;	
}