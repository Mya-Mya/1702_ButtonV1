#include"DxLib.h"
#include"ButtonV1.h"
#include<stdio.h>
#include<string.h>

int a_clock;
int b_clock;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//�{�^��a��\���Bswitch�ő����^�[�����z�����
		switch (ButtonV1(10, 10, 200, 100, "HelloWorld", GetColor(0, 0, 0), 6, GetColor(200, 100, 100), GetColor(150, 230, 150), GetColor(200, 200, 250))) {
		case 0://�������Ă����Ȃ���
			DrawFormatString(0, 100, GetColor(255, 255, 255), "�������Ă��Ȃ���");
			break;
		case 1://������ė����ꂽ
			a_clock = 180;
			break;
		case 2://��������Ă��鎞
			DrawFormatString(0, 100, GetColor(255, 255, 255), "�������Ă���");
			break;
		case 3://������Ă��鎞
			DrawFormatString(0, 100, GetColor(255, 255, 255), "������Ă���");
			break;
		};
		a_clock--;
		if (a_clock > 0) {
			DrawFormatString(0, 110, GetColor(255, 100, 100), "�����ė�����");
		}

		//�{�^��b��\���Bswitch�ő����^�[�����z�����
		switch (ButtonV1(250, 10, 440, 100, "SeeYouWorld", GetColor(255, 255, 255), 6, GetColor(30, 30, 30), GetColor(90, 90, 90), GetColor(120, 120, 120))) {
		case 0:
			DrawFormatString(240, 100, GetColor(250, 250, 250), "�������Ă��Ȃ���");
			break;
		case 1:
			b_clock = 180;
			break;
		case 2:
			DrawFormatString(240, 100, GetColor(250, 250, 250), "�������Ă���");
			break;
		case 3:
			DrawFormatString(240, 100, GetColor(250, 250, 250), "������Ă���");
			break;
		};
		b_clock--;
		if (b_clock > 0) {
			DrawFormatString(240, 110, GetColor(100, 255, 100), "�����ė�����");
		}

		//return -1��_��
		ButtonV1(450, 10, 530, 100, "Re-1", GetColor(30, 30, 30), 7, GetColor(200, 200, 200), GetColor(150, 150, 150), GetColor(120, 120, 120));
	}

	DxLib_End();
	return 0;
}
