#include "BoundingBox.h"

BoundingBox::BoundingBox() {
	c[0] = 0.0f;
	c[1] = 0.0f;
	c[2] = 0.0f;

	r[0] = 0.0f;
	r[1] = 0.0f;
	r[2] = 0.0f;
}

BoundingBox::BoundingBox( float c0, float c1, float c2,
                          float r0, float r1, float r2 )
{
    c[0] = c0;
    c[1] = c1;
    c[2] = c2;

    r[0] = r0;
    r[1] = r1;
    r[2] = r2;
}

BoundingBox::BoundingBox(M3DVector3f origin, M3DVector3f radii) {
	this->c[0] = origin[0];
	this->c[1] = origin[1];
	this->c[2] = origin[2];

	this->r[0] = radii[0];
	this->r[1] = radii[1];
	this->r[2] = radii[2];
}

BoundingBox::~BoundingBox()
{
}

void BoundingBox::setOrigin(M3DVector3f origin) {
	this->c[0] = origin[0];
	this->c[1] = origin[1];
	this->c[2] = origin[2];
}

void BoundingBox::setRadii(M3DVector3f radii) {
	this->r[0] = radii[0];
	this->r[1] = radii[1];
	this->r[2] = radii[2];
}

void BoundingBox::rotateX(float radians) {
	float tempX = this->r[0] * 1.0f;
	float tempY = (this->r[1] * cos(radians)) - (this->r[2] * sin(radians));
    float tempZ = this->r[1] * sin(radians) + this->r[2] * cos(radians);

	this->r[0] = tempX;
	this->r[1] = tempY;
	this->r[2] = tempZ;
}

void BoundingBox::rotateY(float radians) {
	float tempX = this->r[0] * cosf(radians) + this->r[2] * sinf(radians);
	float tempY = this->r[1] * 1.0f;
	float tempZ = this->r[2] * cosf(radians) - this->r[0] * sinf(radians);

	this->r[0] = tempX;
	this->r[1] = tempY;
	this->r[2] = tempZ;
}

void BoundingBox::rotateZ(float radians) {
	float tempX = this->r[0] * cosf(radians) - this->r[2] * sinf(radians);
	float tempY = this->r[0] * sinf(radians) + this->r[2] * cosf(radians);
	float tempZ = this->r[2] * 1.0f;

	this->r[0] = tempX;
	this->r[1] = tempY;
	this->r[2] = tempZ;
}

const bool BoundingBox::intersectsWith( const BoundingBox& b )
{
	if (fabsf(this->c[0] - b.c[0])>(this->r[0] + b.r[0])) return false;
	if (fabsf(this->c[1] - b.c[1])>(this->r[1] + b.r[1])) return false;
	if (fabsf(this->c[2] - b.c[2])>(this->r[2] + b.r[2])) return false;
    return true;
}
