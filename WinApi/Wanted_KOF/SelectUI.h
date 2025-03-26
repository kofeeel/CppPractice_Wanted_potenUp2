#pragma once
#include "config.h"
#include <bitset>

class Image;

class CharacterBox
{
public:
	enum class EHoverState : unsigned char
	{
		None = 0b00,
		P1 = 0b01,
		P2 = 0b10,
		PP = 0b11,
	};
private:
	const int BOXFRAMESIZE = 110;
private:
	int posX;
	int posY;
	CharacterName chName;
	wstring chWName;
	Image* icon;
	RECT iconBox;
	bool isSelected;
	EHoverState hoverState;
	std::bitset<2> hoverStateBit;
	// Draw
	HBRUSH hP1BoxBrush;
	HBRUSH hP2BoxBrush;
	HBRUSH hPPBoxBrush;
	HBRUSH hIcBoxBrush;
	RECT boxFrame;
	RECT boxIcon;
public:
	void Render(HDC hdc);

	~CharacterBox();

	void CreateCenter(int x, int y, CharacterName name);

	CharacterName Select();
	CharacterName GetName();
	wstring GetWName();

	//inline bool CheckIsOtherHover() { return hoverState != EHoverState::None; }
	void ChangeHoverState(int playerId);
	void Reset();

};

class PortraitBox
{
private:
	Image* img;
	int posX;
	int posY;
public:
	void Render(HDC hdc);
	~PortraitBox();

	void Create(int x, int y, Image* img);
	void ChangeImg(Image* img);
};

class SelectUI
{
private:
	const int CHARACTERBOXS_MARGIN = WINSIZE_X/4 + 20;
	const int CHARACTERBOXS_INTERVAL = 150;
	const int CHARACTERBOXS_PADDING = 20;
private:
	CharacterBox* characterBoxArray;
	int characterBoxArraySize;
	int p1Position;	
	int p2Position;
	bool isP1Selected;
	bool isP2Selected;

	// Name TextPoint
	POINT p1NamePos;
	POINT p2NamePos;
	// Potrait Box
	Image* portraitImages;
	PortraitBox* portraitBoxArray;
	int portraitBoxArraySize;
	POINT p1PotraitPos;
	POINT p2PotraitPos;
	// Logo
	Image* logo;
	// Background
	Image* background;
	// Name
	HFONT hFont;

public:
	SelectUI();
	~SelectUI();

	void Reset();
	void Render(HDC hdc);
	void Move(int playerIdx, int move);
	CharacterName Select(int playerIdx);

	void LoadCustomFont(const wchar_t* fontFilePath);
	inline bool GetPlayerIsSelect(int playerIdx)
	{
		if (playerIdx == 0)
		{
			return isP1Selected;
		}
		else
		{
			return isP2Selected;
		}
	}
};