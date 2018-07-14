#include"select.h"

extern CPossession GetPossession();

//flagは作成できるかどうか
extern int parts[30];
extern int weapon[30];
extern bool weaponflag[30];
extern char weaponname[30][20];
extern int gunpower[30];
extern int swordpower[30];
extern int armar[30];
extern int armarguard[30];
extern bool armarflag[30];

extern int wearweapon, weararmar;//どれを装備しているか


//銃と剣を統一

CSelect::CSelect() {
	stage = 0;
	count = 0;
	sentaku = 1;
	sentaku3 = 1;
	sentaku31 = 1;
	sentaku4 = 1;
	sentaku41 = 1;
	sentaku5 = 1;
	count2 = 0;
	mybagflag = false;
}

void CSelect::Load() {
	background = "stpic/home.png";
	background3 = "stpic/home3.png";
	background31_1 = "stpic/home31_1.png";
	background31_2 = "stpic/home31_2.png";
	background4 = "stpic/home4.png";
	background41_1 = "stpic/home41_1.png";
	background41_2 = "stpic/home41_2.png";
	redbar = "stpic/redbar2.png";
	redbar2 = "stpic/redbar5.png";
	redbar3 = "stpic/redbar4.png";
	blackbox = "stpic/blackbox.png";
	blackbox2 = "stpic/blackbox2.png";
	background51 = "stpic/help1.png";
	background52 = "stpic/help2.png";
	scene = 1;
	sozai = "stpic/sozai.png";
	seinou = "stpic/seinou.png";
	mybag = "stpic/mybag.png";
	swordicons = "stpic/swordicons.png";
	gunicons = "stpic/gunicons.png";
	armaricons = "stpic/armaricons.png";
}

void CSelect::Loop() {
	if (Input.GetKeyEnter(Input.key.BACK)) {
		if (count2 <= 0) {
			if (scene == 2 || scene == 3 || scene == 4 || scene == 51 || scene == 52) {
				scene = 1;
				count2 = 5;
				sentaku3 = 1;
				sentaku4 = 1;
				sentaku5 = 1;
			}
			else if (scene == 31 || scene == 32 || scene == 33) {
				scene = 3;
				count2 = 5;
				sentaku31 = 1;
			}
			else if (scene == 41 || scene == 42 || scene == 43) {
				scene = 4;
				count2 = 5;
				sentaku41 = 1;
			}
		}
	}
	
	if (scene == 1) {//ホーム画面での処理
		if (Input.GetKeyEnter(Input.key.DOWN)) {
			if (sentaku < 4) {
				sentaku++;
			}
		}
		if (Input.GetKeyEnter(Input.key.UP)) {
			if (sentaku > 1) {
				sentaku--;
			}
		}

		if (Input.GetKeyEnter(Input.key.RETURN)) {
			switch (sentaku) {
			case 1:
			default:
				count2 = 5;
				scene = 2;
				break;
			case 2:
				count2 = 5;
				scene = 3;
				break;
			case 3:
				count2 = 5;
				scene = 4;
				break;
			case 4:
				count2 = 5;
				scene = 51;
			}
		}
	}

	if (scene == 2) {//ステージ選択画面での処理
		if (count <= 0) {
			if (stage < 10) {
				if (Input.GetKeyDown(Input.key.RIGHT)) {
					stage++;
					count = 10;
				}
			}
			if (stage > 0) {
				if (Input.GetKeyDown(Input.key.LEFT)) {
					stage--;
					count = 10;
				}
			}
		}
	}

	if (scene == 3) {//カスタマイズ画面での処理
		if (Input.GetKeyEnter(Input.key.DOWN)) {
			if (sentaku3 < 3) {
				sentaku3++;
			}
		}
		if (Input.GetKeyEnter(Input.key.UP)) {
			if (sentaku3 > 1) {
				sentaku3--;
			}
		}
		if (Input.GetKeyEnter(Input.key.RETURN)) {
			if (count2 <= 0) {
				switch (sentaku3) {
				case 1:
				default:
					scene = 31;
					count2 = 5;
					break;
				case 2:
					scene = 32;
					count2 = 5;
					break;
				case 3:
					scene = 33;
					count2 = 5;
				}
			}
		}
	}
	if (scene == 31 || scene == 32 || scene == 33) {
		if (count2 <= 0) {
			if (Input.GetKeyEnter(Input.key.RIGHT)) {
				count2 = 2;
				if ((sentaku31 < 5) || (sentaku31 > 5 && sentaku31 < 10) || (sentaku31 > 10 && sentaku31 < 15) || (sentaku31 > 15 && sentaku31 < 20) || (sentaku31 > 20 && sentaku31 < 25)) {
					sentaku31++;
				}
				else {
					sentaku31 -= 4;
				}
			}
			if (Input.GetKeyEnter(Input.key.LEFT)) {
				count2 = 2;
				if ((sentaku31 > 1 && sentaku31 < 6) || (sentaku31 > 6 && sentaku31 < 11) || (sentaku31 > 11 && sentaku31 < 16) || (sentaku31 > 16 && sentaku31 < 21) || (sentaku31 > 21)) {
					sentaku31--;
				}
				else {
					sentaku31 += 4;
				}
			}
			if (Input.GetKeyEnter(Input.key.DOWN)) {
				count2 = 2;
				if (sentaku31 < 21) {
					sentaku31 += 5;
				}
			}
			if (Input.GetKeyEnter(Input.key.UP)) {
				count2 = 2;
				if (sentaku31 > 5) {
					sentaku31 -= 5;
				}
			}
		}
		if (Input.GetKeyEnter(Input.key.RETURN)) {
			if (count2 <= 0) {
				switch (scene) {
				case 31:
				default:
					if (armar[sentaku31] > 0 && weararmar != sentaku31) {
						weararmar = sentaku31;
						count2 = 5;
					}
					break;
				case 32:
					if (weapon[sentaku31] > 0 && wearweapon != sentaku31) {
						wearweapon = sentaku31;
						count2 = 5;
					}
					break;
				}
			}
		}
	}

	if (scene == 4) {//アイテム生成画面での処理
		if (Input.GetKeyEnter(Input.key.DOWN)) {
			if (sentaku4 < 3) {
				sentaku4++;
			}
		}
		if (Input.GetKeyEnter(Input.key.UP)) {
			if (sentaku4 > 1) {
				sentaku4--;
			}
		}
		if (Input.GetKeyEnter(Input.key.RETURN)) {
			if (count2 <= 0) {
				switch (sentaku4) {
				case 1:
				default:
					scene = 41;
					count2 = 5;
					break;
				case 2:
					scene = 42;
					count2 = 5;
					break;
				case 3:
					scene = 43;
					count2 = 5;
				}
			}
		}
	}
	if (scene == 41 || scene == 42 || scene == 43) {
		if (count2 <= 0) {
			if (Input.GetKeyEnter(Input.key.RIGHT)) {
				count2 = 2;
				if ((sentaku41 < 5) || (sentaku41 > 5 && sentaku41 < 10) || (sentaku41 > 10 && sentaku41 < 15) || (sentaku41 > 15 && sentaku41 < 20) || (sentaku41 > 20 && sentaku41 < 25)) {
					sentaku41++;
				}
				else {
					sentaku41 -= 4;
				}
			}
			if (Input.GetKeyEnter(Input.key.LEFT)) {
				count2 = 2;
				if ((sentaku41 > 1 && sentaku41 < 6) || (sentaku41 > 6 && sentaku41 < 11) || (sentaku41 > 11 && sentaku41 < 16) || (sentaku41 > 16 && sentaku41 < 21) || (sentaku41 > 21)) {
					sentaku41--;
				}
				else {
					sentaku41 += 4;
				}
			}
			if (Input.GetKeyEnter(Input.key.DOWN)) {
				count2 = 2;
				if (sentaku41 < 21) {
					sentaku41 += 5;
				}
			}
			if (Input.GetKeyEnter(Input.key.UP)) {
				count2 = 2;
				if (sentaku41 > 5) {
					sentaku41 -= 5;
				}
			}
		}

		if (Input.GetKeyEnter(Input.key.RETURN)) {
			if (mybagflag == false) {
				if (count2 <= 0) {
					switch (scene) {
					case 41:
					default:
						GetPossession().Createarmar(sentaku41);
						break;
					case 42:
						GetPossession().Createweapon(sentaku41);
						break;
					case 43:
						GetPossession().Createitem(sentaku41);
					}
				}
			}
		}

		if (Input.GetKeyEnter(Input.key.P)) {
			if (mybagflag == false) {
				mybagflag = true;
			}
			else {
				mybagflag = false;
			}
		}
	}

	if (scene == 51) {
		if (Input.GetKeyEnter(Input.key.RIGHT)) {
			scene = 52;
		}
	}
	if (scene == 52) {
		if (Input.GetKeyEnter(Input.key.LEFT)) {
			scene = 51;
		}
	}

	if (count > 0) {
		count--;
	}
	if (count2 > 0) {
		count2--;
	}
}

void CSelect::Draw() {

	if (scene == 2) {
		DrawFormatString(400, 300, RED, "%d", stage);
	}
	if (scene == 1) {
		background(0, 0);
		redbar(0, 100 + 100 * (sentaku - 1));
	}

	if (scene == 3) {
		background3(0, 0);
		redbar2(0, sentaku3 * 120);
	}
	if (scene == 31) {
		if (armar[sentaku31] > 0 && weararmar != sentaku31) {
			background31_2(0, 0);
		}
		else {
			background31_1(0, 0);
		}
		for (int i = 1; i <= 25; i++) {
			if (armar[i] <= 0) {
				blackbox(250 + ((i - 1) % 5) * 100, 50 + ((i - 1) / 5) * 100);
			}
		}
	}
	if (scene == 32) {
		if (weapon[sentaku31] > 0 && wearweapon != sentaku31) {
			background31_2(0, 0);
		}
		else {
			background31_1(0, 0);
		}
		for (int i = 1; i <= 25; i++) {
			if (weapon[i] <= 0) {
				blackbox(250 + ((i - 1) % 5) * 100, 50 + ((i - 1) / 5) * 100);
			}
		}
	}
	if (scene == 33) {
		//アイテムのカスタマイズ画面での表示
	}
	if (scene == 31 || scene == 32 || scene == 33) {
		redbar3(250 + ((sentaku31 - 1) % 5) * 100, 50 + ((sentaku31 - 1) / 5) * 100);
	}

	if (scene == 4) {
		background4(0, 0);
		redbar2(0, sentaku4 * 120);
	}

	if (scene == 41) {
		if (armarflag[sentaku41] == false) {
			background41_1(0, 0);
		}
		else {
			background41_2(0, 0);
		}
		armaricons(250, 50);
		sozai(40, 150);
		seinou(40, 280);
		
		switch (sentaku41) {//素材の説明
		case 1:
		default:
			SetFontSize(20);
			DrawFormatString(50, 190, BLACK, "ネジ　…　40コ");
		}
		DrawFormatString(50, 320, BLACK, "守備力");
		DrawFormatString(110, 320, BLACK, "%d", armarguard[sentaku41]);

		for (int i = 1; i <= 25; i++) {
			if (armarflag[i] == false) {
				blackbox(250 + ((i - 1) % 5) * 100, 50 + ((i - 1) / 5) * 100);
			}
		}
	}
	if (scene == 42) {
		if (weaponflag[sentaku41] == false) {
			background41_1(0, 0);
		}
		else {
			background41_2(0, 0);
		}
		gunicons(250, 50);
		sozai(40, 150);
		seinou(40, 280);
		SetFontSize(20);
		switch (sentaku41) {//素材の説明
		case 1:
		default:
			DrawFormatString(50, 190, BLACK, "ネジ　…　30コ");
		}
		DrawFormatString(50, 320, BLACK, "攻撃力");
		DrawFormatString(110, 320, BLACK, "%d", gunpower[sentaku41]);
		for (int i = 1; i <= 25; i++) {
			if (weaponflag[i] == false) {
				blackbox(250 + ((i - 1) % 5) * 100, 50 + ((i - 1) / 5) * 100);
			}
		}
	}
	if (scene == 43) {
		//アイテム作成画面での表示
	}


	if (scene == 41 || scene == 42 || scene == 43) {
		redbar3(250 + ((sentaku41 - 1) % 5) * 100, 50 + ((sentaku41 - 1) / 5) * 100);
		if (mybagflag == true) {
			blackbox2(0, 0);
			mybag(210, 110);
			SetFontSize(30);
			DrawFormatString(320, 180, BLACK, "%d", parts[1]);
		}
	}

	if (scene == 51) {
		background51(0, 0);
	}
	if (scene == 52) {
		background52(0, 0);
	}
}

int CSelect::GetStage() {
	return stage;
}

int CSelect::GetScene() {
	return scene;
}

int CSelect::GetCount2() {
	return count2;
}