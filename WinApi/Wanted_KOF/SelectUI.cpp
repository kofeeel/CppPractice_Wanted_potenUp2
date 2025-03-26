#include "SelectUI.h"
#include "CommonFunction.h"
#include <string>
#include "Image.h"

SelectUI::SelectUI()
{
	// Set CharacterBox
	characterBoxArraySize = 4;
	characterBoxArray = new CharacterBox[characterBoxArraySize];
	p1Position = 0;
	p2Position = characterBoxArraySize - 1;
	isP1Selected = false;
	isP2Selected = false;

	// Set Portrait
	portraitBoxArraySize = 2;
	portraitBoxArray = new PortraitBox[portraitBoxArraySize];
	p1PotraitPos.x = 20;
	p1PotraitPos.y = WINSIZE_Y / 2 - 200;
	p2PotraitPos.x = WINSIZE_X - 100 - 100;
	p2PotraitPos.y = WINSIZE_Y / 2 - 200;

	portraitImages = new Image[characterBoxArraySize];
	if (FAILED(portraitImages[0].Init(L"image/mature_select_icon.bmp", 200, 300, true, RGB(122, 153, 117))))
	{
		OutputDebugString(L"SFSAAAAA");
	}
	portraitImages[1].Init(L"image/ryo_select_icon.bmp", 200, 300, true, RGB(224, 63, 246));
	portraitImages[2].Init(L"image/terry_select_icon.bmp", 200, 300, true, RGB(138, 123, 160));
	portraitImages[3].Init(L"image/k_select_icon.bmp", 200, 300, true, RGB(224, 63, 246));

	// Set Font
	//LoadCustomFont(L"font/The King of Fighters Family.ttf");
	LoadCustomFont(L"font/Neogeo System Font.ttf");

	hFont = CreateFont(
		48,                 // 높이 (크기)
		0,                  // 폭
		0,                  // 문자 각도
		0,                  // 기준선 각도
		FW_NORMAL,          // 글꼴 두께
		FALSE,              // 이탤릭체 여부
		FALSE,              // 밑줄 여부
		FALSE,              // 취소선 여부
		DEFAULT_CHARSET,    // 문자 집합
		OUT_DEFAULT_PRECIS, // 출력 정밀도
		CLIP_DEFAULT_PRECIS,// 클리핑 정밀도
		DEFAULT_QUALITY,    // 출력 품질
		DEFAULT_PITCH | FF_SWISS, // 글꼴 피치와 스타일
		L"Neogeo System Font"    // 사용자 지정 글꼴 이름
	);

	// Set UI
	characterBoxArray[0].CreateCenter(CHARACTERBOXS_MARGIN + (CHARACTERBOXS_INTERVAL + CHARACTERBOXS_PADDING) * 0,
		CHARACTERBOXS_MARGIN, CharacterName::Mature);
	characterBoxArray[1].CreateCenter(CHARACTERBOXS_MARGIN + (CHARACTERBOXS_INTERVAL + CHARACTERBOXS_PADDING) * 1,
		CHARACTERBOXS_MARGIN, CharacterName::Ryo);
	characterBoxArray[2].CreateCenter(CHARACTERBOXS_MARGIN + (CHARACTERBOXS_INTERVAL + CHARACTERBOXS_PADDING) * 2,
		CHARACTERBOXS_MARGIN, CharacterName::Terry);
	characterBoxArray[3].CreateCenter(CHARACTERBOXS_MARGIN + (CHARACTERBOXS_INTERVAL + CHARACTERBOXS_PADDING) * 3,
		CHARACTERBOXS_MARGIN, CharacterName::K);

	characterBoxArray[p1Position].ChangeHoverState(1);
	characterBoxArray[p2Position].ChangeHoverState(2);

	portraitBoxArray[0].Create(p1PotraitPos.x, p1PotraitPos.y, &portraitImages[p1Position]);
	portraitBoxArray[1].Create(p2PotraitPos.x, p2PotraitPos.y, &portraitImages[p2Position]);

	logo = new Image();
	if (FAILED(logo->Init(L"image/logo.bmp", 400, 100, true, RGB(0,0,0))))
	{
		OutputDebugString(L"AFAF\n");
	}

	p1NamePos.x = 100;
	p1NamePos.y = WINSIZE_Y - 100;
	p2NamePos.x = WINSIZE_X - 100 - 100;
	p2NamePos.y = WINSIZE_Y - 100;

	background = new Image();
	background->Init(L"image/KOF_CharacterSelect_BG.bmp", WINSIZE_X, WINSIZE_Y);
}

SelectUI::~SelectUI()
{
	if (characterBoxArray)
	{
		delete[] characterBoxArray;
	}

	if (portraitBoxArray)
	{
		delete[] portraitBoxArray;
	}

	if (portraitImages)
	{
		delete[] portraitImages;
	}

	if (logo)
	{
		delete logo;
	}

	if (background)
	{
		delete background;
	}

	DeleteObject(hFont);
}

void SelectUI::Reset()
{
	isP1Selected = false;
	isP2Selected = false;
	for (int i = 0; i < characterBoxArraySize; ++i)
	{
		characterBoxArray[i].Reset();
	}
	characterBoxArray[p1Position].ChangeHoverState(1);
	characterBoxArray[p2Position].ChangeHoverState(2);
	p1Position = 0;
	p2Position = characterBoxArraySize - 1;
	p1NamePos.x = 100;
	p1NamePos.y = WINSIZE_Y - 100;
	p2NamePos.x = WINSIZE_X - 100 - 100;
	p2NamePos.y = WINSIZE_Y - 100;
}

void SelectUI::Render(HDC hdc)
{
	if (background)
	{
		background->Render(hdc);
	}

	if (logo)
	{
		logo->Render(hdc, (WINSIZE_X / 2 - 200), 50);
	}

	if (portraitBoxArray)
	{
		for (int i = 0; i < portraitBoxArraySize; ++i)
		{
			portraitBoxArray[i].Render(hdc);
		}
	}

	if (characterBoxArray)
	{
		for (int i = 0; i < characterBoxArraySize; ++i)
		{
			characterBoxArray[i].Render(hdc);
		}
		
		// Set Text
		HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

		// Transparent Background
		SetBkMode(hdc, TRANSPARENT);
				
		TextOut(hdc, p1NamePos.x, p1NamePos.y, characterBoxArray[p1Position].GetWName().c_str(), characterBoxArray[p1Position].GetWName().length());
		TextOut(hdc, p2NamePos.x, p2NamePos.y, characterBoxArray[p2Position].GetWName().c_str(), characterBoxArray[p2Position].GetWName().length());

		SelectObject(hdc, hOldFont);
	}
}

void SelectUI::Move(int playerIdx, int move)
{
	if (playerIdx == 0)
	{
		characterBoxArray[p1Position].ChangeHoverState(1);
		//do
		//{
			p1Position = (p1Position + move + characterBoxArraySize) % characterBoxArraySize;
		//} while (p1Position == p2Position);
		characterBoxArray[p1Position].ChangeHoverState(1);
		portraitBoxArray[0].ChangeImg(&portraitImages[p1Position]);
	}
	else
	{
		characterBoxArray[p2Position].ChangeHoverState(2);
		//do
		//{
			p2Position = (p2Position + move + characterBoxArraySize) % characterBoxArraySize;
		//} while (p1Position == p2Position);
		characterBoxArray[p2Position].ChangeHoverState(2);
		portraitBoxArray[1].ChangeImg(&portraitImages[p2Position]);
	}
}

CharacterName SelectUI::Select(int playerIdx)
{
	if (playerIdx == 0)
	{
		isP1Selected = true;
		return characterBoxArray[p1Position].Select();
	}
	else
	{
		isP2Selected = true;
		return characterBoxArray[p2Position].Select();
	}
}

void SelectUI::LoadCustomFont(const wchar_t* fontFilePath)
{
	// 글꼴 파일 등록
	if (AddFontResource(fontFilePath) > 0) {
		// 성공적으로 등록됨
		SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0); // 시스템 갱신
	}
	else {
		// 등록 실패
		OutputDebugString(L"Failed to load font.\n");
	}
}

void CharacterBox::Render(HDC hdc)
{
	if (hoverState == EHoverState::None)
	{
		Rectangle(hdc, boxFrame.left, boxFrame.top, boxFrame.right, boxFrame.bottom);
	}
	else if (hoverState == EHoverState::P1)
	{
		FillRect(hdc, &boxFrame, hP1BoxBrush);
	}
	else if (hoverState == EHoverState::P2)
	{
		FillRect(hdc, &boxFrame, hP2BoxBrush);
	}
	else if (hoverState == EHoverState::PP)
	{
		FillRect(hdc, &boxFrame, hPPBoxBrush);
	}
	FillRect(hdc, &iconBox, hIcBoxBrush);
	icon->Render(hdc, iconBox.left, iconBox.top);
}

CharacterBox::~CharacterBox()
{
	if (icon)
	{
		icon->Release();
		delete icon;
	}

	DeleteObject(hP1BoxBrush);
	DeleteObject(hP2BoxBrush);
	DeleteObject(hPPBoxBrush);
	DeleteObject(hIcBoxBrush);
}

void CharacterBox::CreateCenter(int x, int y, CharacterName name)
{
	this->posX = x;
	this->posY = y;
	chName = name;
	Reset();

	hP1BoxBrush = CreateSolidBrush(RGB(255, 0, 0));
	hP2BoxBrush = CreateSolidBrush(RGB(0, 0, 255));
	hPPBoxBrush = CreateSolidBrush(RGB(255, 0, 255));
	hIcBoxBrush = CreateSolidBrush(RGB(100, 100, 100));

	boxFrame = GetRectAtCenter(x, y, BOXFRAMESIZE, BOXFRAMESIZE);
	iconBox = GetRectAtCenter(x, y, BOXFRAMESIZE - 10, BOXFRAMESIZE - 10);
	icon = new Image;
	int len = MultiByteToWideChar(CP_UTF8, 0, toCharacterName(chName).c_str(), -1, NULL, 0);
	std::wstring wstr(len - 1, 0);
	MultiByteToWideChar(CP_UTF8, 0, toCharacterName(chName).c_str(), -1, &wstr[0], len);
	chWName = wstr;
	wstring wfilePath = L"image/icon_" + chWName + L".bmp";
	if (FAILED(icon->Init(wfilePath.c_str(), BOXFRAMESIZE - 10, BOXFRAMESIZE - 10, true, RGB(248,0,248))))
	{
		OutputDebugString(wfilePath.c_str());
	}
}

CharacterName CharacterBox::Select()
{
	isSelected = true;

	return chName;
}

CharacterName CharacterBox::GetName()
{
	return chName;
}

wstring CharacterBox::GetWName()
{
	return chWName;
}

void CharacterBox::ChangeHoverState(int playerId)
{
	hoverStateBit ^= playerId;

	if (hoverStateBit == 0b00)
	{
		hoverState = EHoverState::None;
	}
	else if (hoverStateBit == 0b01)
	{
		hoverState = EHoverState::P1;
	}
	else if (hoverStateBit == 0b10)
	{
		hoverState = EHoverState::P2;
	}
	else if (hoverStateBit == 0b11)
	{
		hoverState = EHoverState::PP;
	}
}

void CharacterBox::Reset()
{
	hoverState = EHoverState::None;
	hoverStateBit = 0b00;
	isSelected = false;
}

void PortraitBox::Render(HDC hdc)
{
	if (img)
	{
		img->Render(hdc, posX, posY);
	}
}

PortraitBox::~PortraitBox()
{
	if (img)
	{
		img->Release();
		delete img;
	}
}

void PortraitBox::Create(int x, int y, Image* img)
{
	posX = x;
	posY = y;
	this->img = img;
}

void PortraitBox::ChangeImg(Image* img)
{
	this->img = img;
}
