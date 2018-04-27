#include "System.h"
#include "../GameEngine/Input.h"
#include "../Utility/Utility.h"

void suken::SystemSetting::SetWindowSize(int width, int height) {
	windowWidth = width;
	windowHeight = height;
#ifdef DEBUG
	debugWindowWidth = width;
	debugWindowHeight = height;
#endif // DEBUG
}

void suken::SystemSetting::SetLoadingGraph() {
	isUseLoading = false;
}

void suken::SystemSetting::SetLoadingGraph(const char* fileName, int sizeX, int sizeY, int flipTime, int positionX, int positionY) {
	isUseLoading = true;
	loadingGraphPath = fileName;
	loadingSizeX = sizeX;
	loadingSizeY = sizeY;
	loadingFlipTime = flipTime;
	loadingPosX = positionX;
	loadingPosY = positionY;
}

void suken::SystemSetting::InitScene(CScene* scene) {
	this->scene = scene;
	flip = Flip();
	isTransiton = false;
}

void suken::SystemSetting::InitScene(CScene* scene, const char* ruleGraph, unsigned char speed, unsigned char gradate) {
	this->scene = scene;
	flip = Flip(Flip::DEFAULT, ruleGraph, "", speed, gradate);
	isTransiton = true;
}

void suken::SystemSetting::InitScene(CScene* scene, const char* ruleGraph, const char* ruleGraph2, unsigned char speed, unsigned char gradate) {
	this->scene = scene;
	flip = Flip(Flip::DEFAULT, ruleGraph, ruleGraph2, speed, gradate);
	isTransiton = true;
}

void suken::SystemSetting::InitScene(CScene* scene, Flip::Type flipType, unsigned char speed) {
	this->scene = scene;
	flip = Flip(flipType, "", "", speed);
	isTransiton = true;
}

suken::CSystem::CSystem() {//�������K�{�ȓz����������
	m.cnt = 0;
	m.fps = 60.0f;
	m.flag = 0;
}

suken::CSystem::~CSystem(){}

void suken::CSystem::Escape() {
	m.flag |= isEscape;//bit���Z�@�t���O�I��
}

int suken::CSystem::GetWindowX()const {
	return m.windowWidth;
}

int suken::CSystem::GetWindowY()const {
	return m.windowHeight;
}

int suken::CSystem::GetDispX()const {
	return m.displayX;
}

int suken::CSystem::GetDispY()const {
	return m.displayY;
}

int suken::CSystem::GetFrame()const {
	return m.frame;
}

int suken::CSystem::GetNow()const {
	return m.now;
}

float suken::CSystem::GetFps()const {
	return m.fps;
}

void suken::CSystem::SetNextLoadTime(float nextLoadingMinTime) {
	m.nextLoadingMinTime = nextLoadingMinTime;
}

HINSTANCE suken::CSystem::GetHInstance() {
	return hInstance;
}

int suken::CSystem::GetNCmdShow() {
	return nCmdShow;
}

void suken::CSystem::SetDoadAnimation(Anim anim, int positionX, int positionY) {
	Game.loadingAnim.Set(anim.GetVec(), 1);
	Game.loadingFlipTime = anim.GetFlipTime();
	Game.loadingPosX = positionX;
	Game.loadingPosY = positionY;
}

void suken::CSystem::Awake(SystemSetting s) {//m:�����o�ϐ��As:SystemSettings�̈���
	//DxLib�������`
	DxLib::SetWindowStyleMode(s.WindowSyle);
	DxLib::SetMainWindowText(s.WindowText.c_str());
	DxLib::SetWindowIconID(s.iconID);
	if (!s.isWindow) {
		s.windowWidth = 640;
		s.windowHeight = 480;
	}
	DxLib::SetGraphMode(s.windowWidth,s.windowHeight,32);
	DxLib::ChangeWindowMode(s.isWindow);
	DxLib::SetAlwaysRunFlag(true);
	DxLib::SetOutApplicationLogValidFlag(false);
	DxLib::LoadPauseGraph(s.startGraphPath.c_str());
	DxLib_Init();
	DxLib::SetSysCommandOffFlag(true);

	m.now = GetNowCount();//���Ԍv���̂��ߑ��߂Ɏ��s
	Game.screen = MakeScreen(s.windowWidth, s.windowHeight, true);
	Game.nextScreen = MakeScreen(s.windowWidth, s.windowHeight, true);
	DxLib::SetDrawScreen(Game.screen);
	Graph start(s.startGraphPath.c_str());//Graph�\���͎̂g���I������烁����������Ă���錫���q�B�R�s�R���A������Z�q�Ή��B
	start.DrawExtend(0, 0, s.windowWidth, s.windowHeight);
	if (s.isUseLoading) {
		Game.loadingAnim.Set(LoadDivGraph(s.loadingGraphPath.c_str(),6,3,2,s.loadingSizeX,s.loadingSizeY),1);//Anim�\���̂͊ȒP�ȃA�j���[�V������񋟂��܂��B
		Game.loadingFlipTime = s.loadingFlipTime;
		Game.loadingPosX = s.loadingPosX;
		Game.loadingPosY = s.loadingPosY;
		SetUseASyncLoadFlag(true);//�񓯊����[�h���\�ɂ����[�h���ɃA�j���[�V�����ł���悤�ɂ��閂�@�̎���
	}
	DxLib::SetDrawScreen(DX_SCREEN_BACK);
	Game.screen.Draw();
	DxLib::ScreenFlip();
	//�ϐ��������`
	m.windowWidth = s.windowWidth;
	m.windowHeight = s.windowHeight;
	m.displayX = GetSystemMetrics(SM_CXSCREEN);
	m.displayY = GetSystemMetrics(SM_CYSCREEN);
	m.targetRate = s.targetFps == 0 ? 0 : 1000.0f / s.targetFps;
	m.startTime = m.now + 1000;
	HDC hdc;
	hdc = GetDC(DxLib::GetMainWindowHandle());//�f�o�C�X�R���e�L�X�g�̎擾
	m.refreshRate = GetDeviceCaps(hdc, VREFRESH);//���t���b�V�����[�g�̎擾
	ReleaseDC(GetMainWindowHandle(), hdc);//�f�o�C�X�R���e�N�X�g�̉��
	m.loadingMinTime = s.startLoadingMinTime;
	m.nextLoadingMinTime = 0.0f;
	if (s.isUseLoading)m.flag |= isUseLoading;//bit���Z�@�t���O�I��
	if (s.isLaunchar)m.flag |= isLaunchar;//bit���Z�@�t���O�I��
	//�����ŏ����������Ⴈ���B
	if (s.isTransiton) {
		Game.Init(s.scene,s.flip);
	}
	else {
		Game.Init(s.scene);
	}
	suken::Awake();

	if (s.isUseLoading) {
		DxLib::SetUseASyncLoadFlag(false);//�񓯊����[�h�����܂ŁB
		m.flag |= isLoading;//Loading���s��Awake�I��
	}
	else {
		float restTime = s.startLoadingMinTime - (DxLib::GetNowCount() - m.now/*Init����̎��Ԃ͂����Ă�*/);
		if (restTime > 0) {
			DxLib::WaitTimer((int)restTime);//���Ԃ��΂���
		}
	}
#ifdef DEBUG
	debug.SetWindowSize(s.debugWindowWidth, s.debugWindowHeight);
#endif // DEBUG
}

void suken::CSystem::Start(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow) {
	this->hInstance = hInstance;
	this->hPreInst = hPreInst;
	this->lpszCmdLine = lpszCmdLine;
	this->nCmdShow = nCmdShow;
}

bool suken::CSystem::GetIsEscape() {
	return m.flag & isEscape;//bit���Z�@�t���O����
}

void suken::CSystem::Update() {
	m.now = DxLib::GetNowCount();

	if (m.cnt == m.refreshRate) {
		m.fps = (float)((double)1000 / ((m.now - m.startTime) / m.refreshRate));
		m.startTime = m.now;
		m.cnt = 0;
	}
	++m.cnt;
	++m.frame;
}

void suken::CSystem::Loop() {
#ifdef DEBUG
	debug.SetUp();
	SetBackgroundColor(0,0,0);
	if (debug.stopFlag) {
		Update();
		Input.Loop();
		goto SKIP; 
	}
#endif
	if ((m.flag & isLoading) == 0) {
		DxLib::ClearDrawScreen();
		suken::DebugLoopEnter();
		Update();
		Input.Loop();
		Game.Update();
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DxLib::SetDrawBright(255, 255, 255);
		Game.Graphic();
		Game.LoopEnd();
		suken::DebugLoopExit();
		SetScreenFlipTargetWindow(NULL);
		DxLib::ScreenFlip();
#ifdef DEBUG
		SKIP:
		DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DxLib::SetDrawBright(255, 255, 255);
		debug.Loop();
#endif
		Wait();
	}
	else {
		{
			int n = GetNowCount();
			m.cnt += n - m.now;
			m.now = n;
		}
		if (m.cnt > Game.loadingFlipTime*m.targetRate) {
			m.cnt = 0;
			DxLib::ClearDrawScreen();
			Game.DrawNowLoading();
			DxLib::ScreenFlip();
		}
		if (m.now - m.startTime > m.loadingMinTime && GetASyncLoadNum() == 0) {
			m.startTime = m.now;
			m.cnt = 0;
			m.flag &= ~isLoading;
		}
		Sleep(0);
	}
}

void suken::CSystem::GoLoading() {
	if (m.flag & isUseLoading) {
		m.flag |= isLoading;
		m.loadingMinTime = m.nextLoadingMinTime;
		m.nextLoadingMinTime = 0;
		m.startTime = m.now;
		m.cnt = 0;
		SetUseASyncLoadFlag(true);
	}
}

void suken::CSystem::EndLoad() {
	if (m.flag & isUseLoading) {
		SetUseASyncLoadFlag(false);
	}
}

void suken::CSystem::Wait() {
	if (m.targetRate != 0.0f) {
		int waitTime = (int)(m.cnt * m.targetRate - (m.now - m.startTime));
		if (waitTime > 0) {
			Sleep(waitTime);
		}
	}
	else {
		Sleep(0);
	}
}

void suken::CSystem::End() {
	DxLib::DxLib_End();
	if ((m.flag & isLaunchar) == 0) {//bit���Z�@�t���O����@�U
		ShellExecute(DxLib::GetMainWindowHandle(), "open", "Launcher.exe", nullptr, nullptr, SW_SHOW);
	}
}