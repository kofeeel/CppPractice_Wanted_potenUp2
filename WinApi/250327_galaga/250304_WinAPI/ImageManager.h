#pragma once
#include "config.h"
#include "Singleton.h"
#include <string>

using namespace std;

class Image;
class ImageManager: public Singleton<ImageManager>
{
private:
	map<string, Image*> mapImages; 
public:
	void Init();
	void Release();
	//이미지 로드 함수
	Image* AddImage(string key, const wchar_t* filePath, int width, int height,
		 bool isTransparent, COLORREF transColor);
	//이미지 프레임 포함한 로드 함수
	Image* AddFramedImage(string key, const wchar_t* filePath, int width, int height,
		int maxFrameX, int maxFrameY, bool isTransparent, COLORREF transColor);
	void DeleteImage(string key);
	Image* FindImage(string key); //map.find()로 저장된 이미지 찾기
};

