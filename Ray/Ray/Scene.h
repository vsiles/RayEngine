#pragma once

#include <vector>
#include <memory>
#include "Primitive.h"

typedef std::vector<std::unique_ptr<Primitive>> primitives;

class Scene
{
public:
	Scene();
	virtual ~Scene();

	// Load an hardcoded scene
	void initScene();
	// returns the number of primitives in the scene
	size_t getPrimitivesNumber() const;
	// Returns a reference to the primitive at index [idx]. Raise an [out_of_range] exception if [idx] is too high
	std::unique_ptr<Primitive> &getPrimitive(unsigned int idx);
	// Gives acces to the primitives vector (typically to iterate on it)
	primitives &getPrimitives(void);

protected:
	primitives prims;
};
