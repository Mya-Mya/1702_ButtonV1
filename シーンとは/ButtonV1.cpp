
#include"DxLib.h"

int HaveTouched;

/*戻り値一覧ーー！！
-1 : 座標範囲がおかしい！要確認！
0 : かざしてもいない
1 : クリックされて離された！
2 : 乗っかってるだけ！
3 : 押されてまーす！！
*/

//  ButtonV1(左上ｘ          左上ｙ          右下ｘ          右下ｙ          表示文字           文字色                     文字サイズ       ボタン標準色              カーソル合わせ時の色      ボタンクリック時の色
int ButtonV1(signed int LTx, signed int LTy, signed int RBx, signed int RBy, const TCHAR *name, unsigned int letter_color, int letter_size, unsigned int normal_color,unsigned int cursor_color,unsigned int clicking_color){

	int moux;//マウスx座標
	int mouy;//マウスy座標
	int moucond;//マウスクリック状況
	int making_color;//いざ作るときの色
	int font_handle;//文字の描画ハンドル
	int re;//returnのバッファー
	

	if (LTx > RBx || LTy > RBy) {//座標範囲に異常
		DrawFormatString(LTx, LTy, letter_color, "！座標範囲要確認");
		return -1;
	}

	//マウスの状態を調べる
	GetMousePoint(&moux, &mouy);
	moucond = GetMouseInput();

	if (moux > LTx && moux<RBx && mouy>LTy && mouy < RBy) {//もしマウスが座標範囲内に入っていたら
		if (moucond&MOUSE_INPUT_LEFT) {//もし今まさに左クリックされていたら 3
			making_color = clicking_color;
			HaveTouched=1;//押されてまーーす！！！！
			re = 3;//return 3;
		} else {//左クリックされていないにせよ
			if (HaveTouched!=0) {//さっきまで左クリックされていたら 1
				re = 1;///return 1;
				making_color = cursor_color;
				HaveTouched = 0;
			} else {//ただ単に乗っかってるだけだったら 2
				making_color = cursor_color;
				re = 2;/// return 2;
			}
		}
	} else {//もしマウスが座標範囲内に入っていなかったら 0
		making_color = normal_color;
		re = 0;/// return 0;
	}
	
	//ボックスの描画
	if (re == 3) {///もしも今まさに左クリックされているのなら
		DrawBox(LTx + 3, LTy + 3, RBx - 3, RBy - 3, making_color, TRUE);///少し小さくしてボックスを表示する
	}else {//それ以外だったら
		DrawBox(LTx, LTy, RBx, RBy, making_color, TRUE);///指定座標にのっとってボックスを表示する
	}
	
	//文字描画
	font_handle = CreateFontToHandle("ＭＳ　ゴシック", letter_size, 2, DX_FONTTYPE_NORMAL);
	DrawString(
		LTx+ (RBx - LTx) / 2 - GetDrawFormatStringWidth(name, strlen(name)) / 2,//左右中央
		LTy+ (RBy - LTy) / 2 - letter_size / 2,//上下中央
		name,
		letter_color,
		font_handle
	);

	switch (re)
	{
	case 0://マウスが座標範囲以内に入っていなかった
		return 0;
		break;
	case 1://さっきまで左クリックされていた
		return 1;
		break;
	case 2://ただ単に乗っかっているだけだった
		return 2;
		break;
	case 3://今まさに左クリックされていた
		return 3;
		break;
	}
}