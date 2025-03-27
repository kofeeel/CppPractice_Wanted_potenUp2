#include "ImageManager.h"
#include "Image.h"

void ImageManager::Init()
{
}

void ImageManager::Release()
{
    map<string, Image*>::iterator iter;
    for (iter = mapImages.begin(); iter != mapImages.end(); iter++)
    {
        if (iter->second)
        {
            iter->second->Release();
            delete iter->second;
            iter->second = nullptr;
        }
    }
    mapImages.clear();
    ReleaseInstance();
}

Image* ImageManager::AddImage(string key, const wchar_t* filePath, int width, int height, bool isTransparent, COLORREF transColor)
{
    
    Image* image = nullptr;
    image = FindImage(key);
    if (image) return image;

    image = new Image();

    if (FAILED(image->Init(filePath, width, height, isTransparent, transColor)))
    {
        image->Release();
        delete image;

        return nullptr;
    }

    mapImages.insert({ key, image }); //emplace(), insert(make_pair())
    return image;
}

Image* ImageManager::AddFramedImage(string key, const wchar_t* filePath, int width, int height, int maxFrameX, int maxFrameY, bool isTransparent, COLORREF transColor)
{
    Image* image = nullptr;
    image = FindImage(key);
    if (image) return image;

    image = new Image();

    if (FAILED(image->Init(filePath, width, height, maxFrameX, maxFrameY, isTransparent, transColor)))
    {
        image->Release();
        delete image;

        return nullptr;
    }
    mapImages.emplace(key, image);
    return image;
}

void ImageManager::DeleteImage(string key)
{
    map<string, Image*>::iterator iter;
    iter = mapImages.find(key); // iter = &Pair

    if (iter == mapImages.end()) return; //key값이 없을때 mapImages.end()반환

    (iter->second)->Release();//key .second: value
    delete iter->second;
    iter->second = nullptr;

    mapImages.erase(iter); //해당 이터레이터가 가리키는 공간을 삭제함
}

Image* ImageManager::FindImage(string key)
{
    Image* image = new Image();
    map<string, Image*>::iterator iter;
    iter = mapImages.find(key); // iter = &Pair

    if (iter == mapImages.end()) return nullptr;
    
    return iter->second;
}
