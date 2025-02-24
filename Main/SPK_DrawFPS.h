#pragma once
class SPKXemFps
{
	public:
	void SPKXemFps::MainFps(float x, float y, float w, float h);
	void SPKXemFps::RenderObjectFps();
	bool SPKXemFps::CombinedChecks();
	int lastReport;
	int frameCount;
	int frameRate;
	int iniciador;
	char FPS_REAL[30];
};
extern SPKXemFps gFpsView;