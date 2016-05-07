#include "PlanePrim.h"
#include "Scene.h"
#include "Sphere.h"

Scene::Scene()
{
	primitives.clear();
}

Scene::~Scene()
{
	primitives.clear();
}


// Load an hardcoded scene
void Scene::initScene()
{
	primitives.clear();

	// ground plane
	PlanePrim *ground_plane = new PlanePrim(Vector3(0.0, 1.0, 0.0), 4.4);
	ground_plane->setName("plane");
	ground_plane->getMaterial().setReflection(0);
	ground_plane->getMaterial().setDiffuse(1.0);
	ground_plane->getMaterial().setColor(Color(0.4, 0.3, 0.3));

	std::unique_ptr<Primitive> pground_plane(ground_plane);
	primitives.push_back(std::move(pground_plane));
	
	// big sphere
	Sphere *big_sphere = new Sphere(Vector3(1.0, -0.8, 3), 2.5);
	big_sphere->setName("big sphere");
	big_sphere->getMaterial().setReflection(0.6);
	big_sphere->getMaterial().setColor(Color(0.7, 0.7, 0.7));
	std::unique_ptr<Primitive> pbig_sphere(big_sphere);
	primitives.push_back(std::move(pbig_sphere));

	// small sphere
	Sphere *small_sphere = new Sphere(Vector3(-5.5, -0.5, 7.0), 2.0);
	small_sphere->setName("small sphere");
	small_sphere->getMaterial().setReflection(1.0);
	small_sphere->getMaterial().setDiffuse(0.1);
	small_sphere->getMaterial().setColor(Color(0.7, 0.7, 1.0));
	std::unique_ptr<Primitive> psmall_sphere(small_sphere);
	primitives.push_back(std::move(psmall_sphere));

	// light source 1
	Sphere *light1 = new Sphere(Vector3(0.0, 5.0, 5.0), 0.1);
	light1->setLight(true);
	light1->getMaterial().setColor(Color(0.6, 0.6, 0.6));
	std::unique_ptr<Primitive> plight1(light1);
	primitives.push_back(std::move(plight1));

	// light source 2
	Sphere *light2 = new Sphere(Vector3(2.0, 5.0, 1.0), 0.1);
	light2->setLight(true);
	light2->getMaterial().setColor(Color(0.7, 0.7, 0.9));
	std::unique_ptr<Primitive> plight2(light2);
	primitives.push_back(std::move(plight2));
}


// returns the number of primitives in the scene
size_t Scene::getPrimitivesNumber()
{
	return primitives.size();
}


// Returns a reference to the primitive at index [idx]. Raise an [out_of_range] exception if [idx] is too high
std::unique_ptr<Primitive> &Scene::getPrimitive(unsigned int idx)
{
	return primitives.at(idx);
}
