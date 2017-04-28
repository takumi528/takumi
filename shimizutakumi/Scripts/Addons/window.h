#pragma once

#include "../Suken.h"
#include <list>
#include <queue>
#include <string>
#include <Windows.h>

class CTextWindow{
private:
	Font font;
	std::list<std::string> display;
	std::queue<std::string> texts;
	Graph window,arrow;
	int cnt,interval;
	int intervalY;
	bool endDisplay;

	int Count(const std::string& str) {
		int index = 0, count = 0;
		while (index < str.size()) {
			if (IsDBCSLeadByte(str[index])) {
				index += 2;
			}
			else {
				++index;
			}
			++count;
		}
		return count;
	}

	int WLeft,
		WUp,
		WRight,
		WDown,
		SLeft,
		SUp,
		SRight,
		SDown,
		SWidth,
		SHigh;

public:
	

	void Loop() {
		if (Input.GetKeyEnter(Input.key.RETURN)) {
			if (endDisplay) {
				if (texts.empty()) {
					display.clear();
					cnt = 0;
				}
				else {
					display.pop_front();
					cnt = 0;
					for (auto it = display.begin(), end = display.end(); it != end; ++it) {
						cnt += Count(*it);
					}
					cnt *= interval;
				}
				endDisplay = false;
			}
		}

		cnt++;
	}
	void Draw() {

		window.DrawExtend(WLeft, WUp, WRight, WDown);
		std::string buf;
		int num = cnt / interval;
		int index = 0;
		int line = 0;
		bool isEnd = false;

		while (!texts.empty() && display.size() < SHigh / intervalY) {
			display.push_back(texts.front());
			texts.pop();
		}

		for (auto it = display.begin(), end = display.end(); it != end; ++it) {
			index = 0;
			while (num != 0 && index < it->size()) {
				if (IsDBCSLeadByte((*it)[index])) {
					buf += (*it)[index];
					buf += (*it)[index + 1];
					index += 2;
				}
				else {
					buf += (*it)[index];
					++index;
				}
				--num;
			}
			font.Draw(SLeft, SUp + intervalY*line, buf.c_str(), BLACK);
			if (num == 0) {
				isEnd = false;
				break;
			}
			else {
				isEnd = true;
			}
			++line;
			buf.clear();
		}
		if (isEnd) {
			endDisplay = true;
			if (cnt / interval / 4 % 2 == 0)
				arrow(SRight, SUp + intervalY * (line - 1));
		}
	}
	void SetFont(const Font& font) {
		this->font = font;
		intervalY = this->font.GetHeight() + 10;
	}
	void SetInterval(int time) {
		interval = time;
	}
	void SetWindowSize(int left, int right, int up, int down) {
		WLeft = left;
		WUp = right;
		WRight = up;
		WDown = down;
		SLeft = WLeft + 20;
		SUp = WUp + 20;
		SRight = WRight - 40;
		SDown = WDown - 10;
		SWidth = SRight - SLeft;
		SHigh = SDown - SUp;
	}
	void SetGraph(Graph window,Graph arrow = 0){
		if(window != 0){
			this->window = window;
		}
		if(arrow != 0){
			this->arrow = arrow;
		}
	}
	CTextWindow() {
		font.Set("MS P明朝", 24, 9, DX_FONTTYPE_ANTIALIASING);

		window = "SukenLibAsset/TextWindow.png";
		arrow = "SukenLibAsset/TextArrow.png";
		intervalY = font.GetHeight() + 10;
		cnt = 0;
		interval = 4;
		endDisplay = false;

		WLeft = 0;
		WRight = System.GetWindowX();
		WUp = System.GetWindowY() * 3 / 4;
		WDown = System.GetWindowY();
		SLeft = WLeft + 20;
		SUp = WUp + 20;
		SRight = WRight - 40;
		SDown = WDown - 10;
		SWidth = SRight - SLeft;
		SHigh = SDown - SUp;
	}
	CTextWindow(const char* text) {

		font.Set("MS P明朝", 24, 9, DX_FONTTYPE_ANTIALIASING);

		window = "SukenLibAsset/TextWindow.png";
		arrow = "SukenLibAsset/TextArrow.png";
		intervalY = font.GetHeight() + 10;
		cnt = 0;
		interval = 4;
		endDisplay = false;

		WLeft = 0;
		WRight = System.GetWindowX();
		WUp = System.GetWindowY() * 3 / 4;
		WDown = System.GetWindowY();
		SLeft = WLeft + 20;
		SUp = WUp + 20;
		SRight = WRight - 40;
		SDown = WDown - 10;
		SWidth = SRight - SLeft;
		SHigh = SDown - SUp;

		std::string buf = "";
		char charBuf[2];

		while (*text != '\0') {//text の先頭が終端文字かチェック


			if (IsDBCSLeadByte(*text) != 0) {//先行バイト判定
				charBuf[0] = text[0];
				charBuf[1] = text[1];
				text += 2;//二文字分ずらす
				if (font.GetWidth((buf).c_str(), buf.size()) + font.GetWidth(charBuf, 2) < SWidth) {
					buf += charBuf[0];
					buf += charBuf[1];
				}
				else {
					texts.push(buf);
					buf.clear();
					buf += charBuf[0];
					buf += charBuf[1];
				}
			}
			else {
				charBuf[0] = text[0];
				text += 1;//一文字分ずらす

				if (charBuf[0] == '\n') {
					texts.push(buf);
					buf.clear();
					continue;
				}

				if (font.GetWidth((buf).c_str(), buf.size()) + font.GetWidth(charBuf, 1) > SWidth) {
					texts.push(buf);
					buf.clear();
					buf += charBuf[0];
				}
				else {
					buf += charBuf[0];
				}
			}
		}

		if (!buf.empty()) {
			texts.push(buf);
		}
	}
	void PushText(const char* text) {
		std::string buf = "";
		char charBuf[2];

		while (*text != '\0') {//text の先頭が終端文字かチェック


			if (IsDBCSLeadByte(*text) != 0) {//先行バイト判定
				charBuf[0] = text[0];
				charBuf[1] = text[1];
				text += 2;//二文字分ずらす
				if (font.GetWidth((buf).c_str(), buf.size()) + font.GetWidth(charBuf, 2) < SWidth) {
					buf += charBuf[0];
					buf += charBuf[1];
				}
				else {
					texts.push(buf);
					buf.clear();
					buf += charBuf[0];
					buf += charBuf[1];
				}
				//			continue;
			}
			else {
				charBuf[0] = text[0];
				text += 1;//一文字分ずらす

				if (charBuf[0] == '\n') {
					texts.push(buf);
					buf.clear();
					continue;
				}

				if (font.GetWidth((buf).c_str(), buf.size()) + font.GetWidth(charBuf, 1) > SWidth) {
					texts.push(buf);
					buf.clear();
					buf += charBuf[0];
				}
				else {
					buf += charBuf[0];
				}
			}
		}

		if (!buf.empty()) {
			texts.push(buf);
		}
	}
	bool IsEmpty() {
		return display.empty() && texts.empty();
	}
};