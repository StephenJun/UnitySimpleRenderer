#pragma once

#include "color.h"
#include "tool.h"
#include <stdlib.h>

enum TextureFilter 
{
	Filter_Point,
	Filter_Bilinear
};

class Texture
{
public:
	int width;
	int height;
	unsigned char* buffer;
	TextureFilter texFilter;

	Texture()
	{
		width = 0;
		height = 0;
		buffer = 0;
		texFilter = TextureFilter::Filter_Bilinear;
	}

	void UnLoad()
	{
		free(buffer);
		buffer = 0;
	}

	Color GetColor(int idx) const
	{
		//BGRA
		return Color(buffer[idx + 2], buffer[idx + 1], buffer[idx]);
	}

	void GetRGB(Vector2 uv, Color& c) const
	{
		if (width == 0)
		{
			c = Color::white;
			return;
		}
		if (texFilter == TextureFilter::Filter_Point)
		{
			int x = uv.x * (width - 1);
			//��ֱ����Ҫȡ��
			int y = (1 - uv.y) * (height - 1);
			int idx = (y * width + x) * 4;
			c = GetColor(idx);
		}
		else if (texFilter == TextureFilter::Filter_Bilinear)
		{
			float x = uv.x * (width - 1);
			float y = (1 - uv.y) * (height - 1);
			int floorx = floorf(x);
			int floory = floorf(y);
			int ceilx = ceilf(x);
			int ceily = ceilf(y);
			int lefttopidx = (floory * width + floorx) * 4;
			int leftbottomidx = (ceily * width + floorx) * 4;
			int righttopidx = (floory * width + ceilx) * 4;
			int rightbottomidx = (ceily * width + ceilx) * 4;
			Color topColor = Color::Lerp(GetColor(lefttopidx), GetColor(righttopidx), x - floorx);
			Color bottomColor = Color::Lerp(GetColor(leftbottomidx), GetColor(rightbottomidx), x - floorx);
			c = Color::Lerp(topColor, bottomColor, y - floory);
		}
	}
};