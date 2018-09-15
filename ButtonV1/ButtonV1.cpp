
#include"DxLib.h"

int HaveTouched;

/*�߂�l�ꗗ�[�[�I�I
-1 : ���W�͈͂����������I�v�m�F�I
0 : �������Ă����Ȃ�
1 : �N���b�N����ė����ꂽ�I
2 : ��������Ă邾���I
3 : ������Ă܁[���I�I
*/

//  ButtonV1(���゘          ���゙          �E����          �E����          �\������           �����F                     �����T�C�Y       �{�^���W���F              �J�[�\�����킹���̐F      �{�^���N���b�N���̐F
int ButtonV1(signed int LTx, signed int LTy, signed int RBx, signed int RBy, const TCHAR *name, unsigned int letter_color, int letter_size, unsigned int normal_color,unsigned int cursor_color,unsigned int clicking_color){

	int moux;//�}�E�Xx���W
	int mouy;//�}�E�Xy���W
	int moucond;//�}�E�X�N���b�N��
	int making_color;//�������Ƃ��̐F
	int font_handle;//�����̕`��n���h��
	int re;//return�̃o�b�t�@�[
	

	if (LTx > RBx || LTy > RBy) {//���W�͈͂Ɉُ�
		DrawFormatString(LTx, LTy, letter_color, "�I���W�͈͗v�m�F");
		return -1;
	}

	//�}�E�X�̏�Ԃ𒲂ׂ�
	GetMousePoint(&moux, &mouy);
	moucond = GetMouseInput();

	if (moux > LTx && moux<RBx && mouy>LTy && mouy < RBy) {//�����}�E�X�����W�͈͓��ɓ����Ă�����
		if (moucond&MOUSE_INPUT_LEFT) {//�������܂��ɍ��N���b�N����Ă����� 3
			making_color = clicking_color;
			HaveTouched=1;//������Ă܁[�[���I�I�I�I
			re = 3;//return 3;
		} else {//���N���b�N����Ă��Ȃ��ɂ���
			if (HaveTouched!=0) {//�������܂ō��N���b�N����Ă����� 1
				re = 1;///return 1;
				making_color = cursor_color;
				HaveTouched = 0;
			} else {//�����P�ɏ�������Ă邾���������� 2
				making_color = cursor_color;
				re = 2;/// return 2;
			}
		}
	} else {//�����}�E�X�����W�͈͓��ɓ����Ă��Ȃ������� 0
		making_color = normal_color;
		re = 0;/// return 0;
	}
	
	//�{�b�N�X�̕`��
	if (re == 3) {///���������܂��ɍ��N���b�N����Ă���̂Ȃ�
		DrawBox(LTx + 3, LTy + 3, RBx - 3, RBy - 3, making_color, TRUE);///�������������ă{�b�N�X��\������
	}else {//����ȊO��������
		DrawBox(LTx, LTy, RBx, RBy, making_color, TRUE);///�w����W�ɂ̂��Ƃ��ă{�b�N�X��\������
	}
	
	//�����`��
	font_handle = CreateFontToHandle("�l�r�@�S�V�b�N", letter_size, 2, DX_FONTTYPE_NORMAL);
	DrawString(
		LTx+ (RBx - LTx) / 2 - GetDrawFormatStringWidth(name, strlen(name)) / 2,//���E����
		LTy+ (RBy - LTy) / 2 - letter_size / 2,//�㉺����
		name,
		letter_color,
		font_handle
	);

	switch (re)
	{
	case 0://�}�E�X�����W�͈͈ȓ��ɓ����Ă��Ȃ�����
		return 0;
		break;
	case 1://�������܂ō��N���b�N����Ă���
		return 1;
		break;
	case 2://�����P�ɏ�������Ă��邾��������
		return 2;
		break;
	case 3://���܂��ɍ��N���b�N����Ă���
		return 3;
		break;
	}
}