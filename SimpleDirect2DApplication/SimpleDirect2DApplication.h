#pragma once

#include "resource.h"

class DemoApp
{
public:
	DemoApp();
	~DemoApp(); // Direct2D 관련 Resource 해제

	// Register the window class and call methods for instantiating drawing resources
	HRESULT Initialize();

	// Process and dispatch messages
	void RunMessageLoop();

private:
	// Initialize device-independent resources.
	HRESULT CreateDeviceIndependentResources();

	// Initialize device-dependent resources.
	HRESULT CreateDeviceResources();

	// Release device-dependent resource. 
	// Direct2D에 Error가 발생하여 Device Resource를 재생성 해야할 경우 호출
	void DiscardDeviceResources();

	// Draw content.
	HRESULT OnRender();

	// Resize the render target.
	void OnResize(
		UINT width,
		UINT height
		);

	// The windows procedure.
	static LRESULT CALLBACK WndProc(
		HWND hWnd,
		UINT message,
		WPARAM wParam,
		LPARAM lParam
		);

private:
	HWND m_hwnd;

	// Starting point for using Direct2D
	// Use to create other Direct2D resources
	// Device independent resource
	ID2D1Factory1* m_pDirect2dFactory;

	// Device dependent resource
	ID2D1HwndRenderTarget* m_pRenderTarget;
	ID2D1SolidColorBrush* m_pLightSlateGrayBrush;
	//ID2D1SolidColorBrush* m_pCornflowerBlueBrush;
	ID2D1StrokeStyle1* m_pStrokeStyle;

	ID2D1EllipseGeometry *m_pEllipseGeometry;

	float zoom;
	float x;
	float y;
};