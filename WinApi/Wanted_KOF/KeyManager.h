#pragma once

#include <bitset>
#include "config.h"
#include "Singleton.h"

#define MAX_KEY_COUNT 256


using namespace std;

class KeyManager : public Singleton<KeyManager>
{
	
private:
	bitset<MAX_KEY_COUNT> keyUp;
	bitset<MAX_KEY_COUNT> keyDown;

public:
	HRESULT Init();
	void Release();

	bool IsOnceKeyDown(int key);
	bool IsOnceKeyUp(int key);
	bool IsStayKeyDown(int key);

	void SetKeyDown(int key, bool state) { this->keyDown.set(key, state); }
	void SetKeyUp(int key, bool state) {this->keyUp.set(key, state); }

	inline bool IsValidInput(int& key)
	{
		return ('W' == key || 'A' == key || 'S' == key || 'D' == key ||
			'Z' == key || 'X' == key || 'C' == key || 'V' == key
			|| VK_SPACE == key); // 엔터가 뭐더라
	}
};