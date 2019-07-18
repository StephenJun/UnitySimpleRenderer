#pragma once

#include "color.h"
#include "SDL.h"
#include "rect.h"
#include "vector2.h"
#include "vector3.h"
#include "material.h"
#include "zbuffer.h"

class Draw {
public:
	static void DrawPoint(SDL_Surface* surface, int x, int y, const Color& c);
	static void DrawHLine(SDL_Surface* surface, int x1, int x2, int y, const Color& c);
	static void DrawVLine(SDL_Surface* surface, int x, int y1, int y2, const Color& c);
	static void DrawDLine(SDL_Surface* surface, int x1, int y1, int x2, int y2, const Color& c);
	static void DrawGLine(SDL_Surface* surface, int x1, int y1, int x2, int y2, const Color& c);
	static void DrawLine(SDL_Surface* surface, int x1, int y1, int x2, int y2, const Color& c);
	static void DrawClipLine(SDL_Surface* surface, Rect& rect, int x1, int y1, int x2, int y2, const Color& c);
	static void DrawTopTriangle_Flat(SDL_Surface* surface, Rect& rect, float x1, float y1, float x2, float x3, float y3, const Color& c);
	static void DrawBottomTriangle_Flat(SDL_Surface* surface, Rect& rect, float x1, float y1, float x2, float x3, float y3, const Color& c);
	static void DrawTriangle_Flat(SDL_Surface* surface, Rect& rect, float x1, float y1, float x2, float y2, float x3, float y3, const Color& c);
	static void DrawTopTriangle_Gouraud(SDL_Surface* surface, Rect& rect, float x1, float y1, float x2, float x3, float y3, const Color& c1, const Color& c2, const Color& c3);
	static void DrawBottomTriangle_Gouraud(SDL_Surface* surface, Rect& rect, float x1, float y1, float x2, float x3, float y3, const Color& c1, const Color& c2, const Color& c3);
	static void DrawTriangle_Gouraud(SDL_Surface* surface, Rect& rect, float x1, float y1, float x2, float y2, float x3, float y3, const Color& c1, const Color& c2, const Color& c3);
	static void DrawTopTriangle_Tex_Gouraud(SDL_Surface* surface, Rect& rect, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector2& uv1, const Vector2& uv2, const Vector2& uv3, const Material& mat, const ZBuffer& zBuffer);
	static void DrawBottomTriangle_Tex_Gouraud(SDL_Surface* surface, Rect& rect, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector2& uv1, const Vector2& uv2, const Vector2& uv3, const Material& mat, const ZBuffer& zBuffer);
	static void DrawTriangle_Tex_Gouraud(SDL_Surface* surface, Rect& rect, const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector2& uv1, const Vector2& uv2, const Vector2& uv3, const Material& mat, const ZBuffer& zBuffer);
	static void DrawClearColor(SDL_Surface* surface, const Color& c);

private:
	static bool ClipTest(float p, float q, float& u1, float& u2);
};

