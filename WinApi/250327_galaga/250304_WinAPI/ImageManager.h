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
	//�̹��� �ε� �Լ�
	Image* AddImage(string key, const wchar_t* filePath, int width, int height,
		 bool isTransparent, COLORREF transColor);
	//�̹��� ������ ������ �ε� �Լ�
	Image* AddFramedImage(string key, const wchar_t* filePath, int width, int height,
		int maxFrameX, int maxFrameY, bool isTransparent, COLORREF transColor);
	void DeleteImage(string key);
	Image* FindImage(string key); //map.find()�� ����� �̹��� ã��
};

