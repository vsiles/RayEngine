#include <limits>
#include <vector>
#include "Engine.h"
#include "Sphere.h"

Engine::Engine()
{
	lastRow = nullptr;
}


Engine::~Engine()
{
	delete [] lastRow;
}

void Engine::setTarget(Pixel *dest, unsigned int width, unsigned int height)
{
	this->dest = dest;
	this->width = width;
	this->height = height;
}

const Scene &Engine::getScene(void) const
{
	return scene;
}

Primitive *Engine::raytrace(const Ray &ray, Color &acc, unsigned int depth, double rIndex, double &dist)
{
	if (depth > TRACEDEPTH) return nullptr;
	// trace primary ray
	dist = std::numeric_limits<double>::max();
	Vector3 pi;
	primitives &primitives = scene.getPrimitives();
	Primitive *prim = nullptr;
	
	hitStatus result;

	// find the nearest intersection
	for (primitives::iterator s = primitives.begin(); s != primitives.end(); s++)
	{
		hitStatus res;
		if ((res = (*s)->Intersect(ray, dist)) != MISS)
		{
			prim = s->get();
			result = res; // 0 = miss, 1 = hit, -1 = hit from inside primitive
		}
	}

	// no hit, terminate ray
	if (!prim) return nullptr;

	// handle intersection
	if (prim->isLight())
	{
		// we hit a light, stop tracing
		acc = Color(1.0, 1.0, 1.0);
	}
	else
	{
		// determine color at point of intersection
		pi = ray.getOrigin() + (ray.getDirection() * dist);

		// trace lights
		for (primitives::iterator l = primitives.begin(); l != primitives.end(); l++)
		{
			if ((*l)->isLight())
			{
				Primitive* light = l->get();

				// calculate diffuse shading
				Vector3 L = ((Sphere *)light)->getCenter() - pi;
				L.normalize();
				Vector3 N = prim->getNormal(pi);
				if (prim->getMaterial().getDiffuse() > 0)
				{
					double dot = N * L;
					if (dot > 0)
					{
						double diff = dot * prim->getMaterial().getDiffuse();
						// add diffuse component to ray color
						acc += diff * (prim->getMaterial().getColor() * light->getMaterial().getColor());
					}
				}
			}
		}
	}
	// return pointer to primitive hit by primary ray
	return prim;
}

void Engine::initRender(void)
{
	// set first line to draw to
	currLine = 20;
	// set pixel buffer address of first pixel
	ppos = 20 * width;
	// screen plane in world space coordinates
	WX1 = -4.0;
	WX2 = 4.0;
	WY1 = SY = 3.0;
	WY2 = -3.0;
	// calculate deltas for interpolation
	DX = (WX2 - WX1) / width;
	DY = (WY2 - WY1) / height;
	SY += 20 * DY;

	// allocate space to store pointers to primitives for previous line
	lastRow = new Primitive*[width];
	memset(lastRow, 0, width * sizeof(Primitive *));
}

bool Engine::render(void)
{
	// TODO
	return false;
}