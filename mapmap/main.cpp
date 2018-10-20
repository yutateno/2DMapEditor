#include "DxLib.h"
#include "mapmake.h"
#include "input.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(640,480,16);
	SetDrawScreen(DX_SCREEN_BACK);

	MapMake* mapmake = new MapMake(0);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && KeyData::CheckEnd() == 1)
	{
		KeyData::UpDate();
		MouseData::Mouse_UpDate();
		MouseWheelData::MouseWheel_Update();
		mapmake->Update();
		if (KeyData::Get(KEY_INPUT_1) == 1)
		{
			delete mapmake;
			mapmake = new MapMake(0);
		}
		if (KeyData::Get(KEY_INPUT_2) == 1)
		{
			delete mapmake;
			mapmake = new MapMake(1);
		}
		if (KeyData::Get(KEY_INPUT_3) == 1)
		{
			delete mapmake;
			mapmake = new MapMake(2);
		}
	}

	delete mapmake;

	InitGraph();

	DxLib_End();
	return 0;
}