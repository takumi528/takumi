#include "Scrol.h"

#include "player.h"
#include "map.h"
//
//extern Player& GetPlayer();
//extern CMap& GetMap();
//
//extern int scrY;//画面の上端の座標
//extern int scrX;//画面の右端の座標
//
//CScrol::CScrol() {
//	fixset = false;
//}
//
//void CScrol::Loop(){
//	fixset = false;
//
//	if (GetMap().GetFix() == true) {
//		if (scrX < GetMap().GetFixX()) {
//			if (GetMap().GetFixX() - scrX > 5) {
//				scrX += 5;
//			}
//			else {
//				scrX += 1;
//			}
//				fixset = true;
//		}
//		if (scrX > GetMap().GetFixX()) {
//			if (scrX - GetMap().GetFixX() > 5) {
//				scrX -= 5;
//			}
//			else {
//				scrX -= 1;
//			}
//			fixset = true;
//		}
//		if (scrY < GetMap().GetFixY()) {
//			if (GetMap().GetFixY() - scrY > 5) {
//				scrY += 5;
//			}
//			else {
//				scrY += 1;
//			}
//			fixset = true;
//		}
//		if (scrY > GetMap().GetFixY()) {
//			if (scrY - GetMap().GetFixY() > 5) {
//				scrY -= 5;
//			}
//			else {
//				scrY -= 1;
//			}
//			fixset = true;
//		}
//	}
//
//	if (GetMap().GetFix() == false) {
//		if (GetPlayer().GetY() >= 300) {
//			if (GetPlayer().GetY() < 300 + scrY) {
//				scrY = GetPlayer().GetY() - (GetMap().GetHeight() * 40 - 300) + GetMap().GetHeight() * 40 - 600;
//			}
//		}
//		if (GetPlayer().GetY() <= GetMap().GetHeight() * 40 - 200) {
//			if (GetPlayer().GetY() > 400 + scrY) {
//				scrY = GetPlayer().GetY() - (GetMap().GetHeight() * 40 - 200) + GetMap().GetHeight() * 40 - 600;
//			}
//		}
//		if (GetPlayer().GetX() < GetMap().GetWidth() * 40 - 300 && GetPlayer().GetX() > 300) {
//			scrX = GetPlayer().GetX() - 300;
//		}
//	}
//	/*if (GetPlayer().GetX() >= 400) {
//	if(GetPlayer().GetX() < )
//	}*/
//}
//
//bool CScrol::GetFixset() {
//	return fixset;
//}