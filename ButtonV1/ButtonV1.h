#pragma once
//  ButtonV1(左上ｘ          左上ｙ          右下ｘ          右下ｙ          表示文字           文字色                     文字サイズ       ボタン標準色              カーソル合わせ時の色      ボタンクリック時の色
int ButtonV1(signed int LTx, signed int LTy, signed int RBx, signed int RBy, const TCHAR *name, unsigned int letter_color, int letter_size, unsigned int normal_color, unsigned int cursor_color, unsigned int clicking_color);