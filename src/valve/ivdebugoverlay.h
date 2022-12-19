#pragma once

#include "cvector.h"
#include "cmatrix.h"
#include "ccolor.h"

class IVDebugOverlay
{
public:
	virtual void AddEntityTextOverlay(int entityIndex, int lineOffset, float duration, int r, int g, int b, int a, const char* fmt, ...) = 0;
	virtual void AddBoxOverlay(const CVector& origin, const CVector& min, const CVector& max, const CVector& orientation, int r, int g, int b, int a, float duration) = 0;
	virtual void AddSphereOverlay(const CVector& origin, float flRadius, int nTheta, int nPhi, int r, int g, int b, int a, float duration) = 0;
	virtual void AddTriangleOverlay(const CVector& p1, const CVector& p2, const CVector& p3, int r, int g, int b, int a, bool noDepthTest, float duration) = 0;
	virtual void AddLineOverlay(const CVector& origin, const CVector& dest, int r, int g, int b, bool noDepthTest, float duration) = 0;
	virtual void AddTextOverlay(const CVector& origin, float duration, const char* fmt, ...) = 0;
	virtual void AddTextOverlay(const CVector& origin, int lineOffset, float duration, const char* fmt, ...) = 0;
	virtual void AddScreenTextOverlay(float x, float y, float duration, int r, int g, int b, int a, const char* text) = 0;
	virtual void AddSweptBoxOverlay(const CVector& start, const CVector& end, const CVector& min, const CVector& max, const CVector& angles, int r, int g, int b, int a, float duration) = 0;
	virtual void AddGridOverlay(const CVector& origin) = 0;
	virtual void AddCoordFrameOverlay(const CMatrix3x4& frame, float scale, int colorTable[3][3] = nullptr) = 0;
	virtual int ScreenPosition(const CVector& worldPosition, CVector& screen) = 0;
	virtual int ScreenPosition(float flXPos, float flYPos, CVector& vecScreen) = 0;
	virtual void* GetFirst() = 0;
	virtual void* GetNext(void* pCurrent) = 0;
	virtual void ClearDeadOverlays() = 0;
	virtual void ClearAllOverlays() = 0;
	virtual void AddTextOverlayRGB(const CVector& vecOrigin, int iLineOffset, float flDuration, float r, float g, float b, float a, const char* fmt, ...) = 0;
	virtual void AddTextOverlayRGB(const CVector& vecOrigin, int iLineOffset, float flDuration, int r, int g, int b, int a, const char* fmt, ...) = 0;
	virtual void AddLineOverlayAlpha(const CVector& vecOrigin, const CVector& dest, int r, int g, int b, int a, bool bNoDepthTest, float flDuration) = 0;
	virtual void AddBoxOverlay2(const CVector& vecOrigin, const CVector& vecAbsMin, const CVector& vecAbsMax, const CVector& angOrientation, const CColor& faceColor, const CColor& edgeColor, float flDuration) = 0;
	virtual void AddLineOverlay(const CVector& vecOrigin, const CVector& vecDest, int r, int g, int b, int a, float flThickness, float flDuration) = 0;
	virtual void PurgeTextOverlays() = 0;
	virtual void AddCapsuleOverlay(const CVector& vecAbsMin, const CVector& vecAbsMax, const float& flRadius, int r, int g, int b, int a, float flDuration) = 0;
	virtual void DrawPill(CVector& vecAbsMin, CVector& vecAbsMax, float flRadius, int r, int g, int b, int a, float flDuration) = 0;
};
