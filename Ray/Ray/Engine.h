#pragma once
#include "common.h"
#include "Primitive.h"
#include "Scene.h"

class Engine
{
public:
	Engine();
	virtual ~Engine();

	void setTarget(Pixel* dest, unsigned int width, unsigned int height);
	Scene &getScene(void);
	Primitive *raytrace(const Ray &ray, Color &acc, unsigned int depth, double rIndex, double &dist);
	void initRender(void);
	bool render(void);
protected:
	double  WX1, WY1, WX2, WY2, DX, DY, SX, SY;
	Scene scene;
	Pixel *dest;
	unsigned int width, height, currLine, ppos;
	Primitive **lastRow;
};

