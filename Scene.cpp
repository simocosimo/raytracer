#include "Scene.h"

Scene::Scene(const Vector3& cam, const int skyType = skybox::gradient) : 
	camera(cam), skyboxType(skyType) {
	this->primary = Color(128, 179, 255);
	this->secondary = Color(255, 255, 255);
}

void Scene::setSkyboxType(const int type) {
	this->skyboxType = type;
}

void Scene::setSkyboxColors(const Color& first, const Color& second = NULL) {
	this->primary = first;
	if((&second) != NULL) this->secondary = second;
}