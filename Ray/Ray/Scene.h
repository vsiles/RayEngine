#pragma once

#include <vector>
#include "Primitive.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	// Load an hardcoded scene
	void initScene();
	// returns the number of primitives in the scene
	size_t getPrimitivesNumber();
	// Returns a reference to the primitive at index [idx]. Raise an [out_of_range] exception if [idx] is too high
	const Primitive & getPrimitive(unsigned int idx);

protected:
	std::vector<Primitive> primitives;
};