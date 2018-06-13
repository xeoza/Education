#include "camera.h"
#include "cameramodifications.h"

Camera::Camera(): distance(0.0)
{
}

Camera::Camera(double d): distance(d)
{
}

void Camera::setDistance(double d)
{
    this->distance = d;
}

double &Camera::getDistance()
{
    return this->distance;
}

const double &Camera::getDistance() const
{
    return this->distance;
}

void Camera::change(const B_Modification &modif)
{
    ((const CameraModification&)modif).changeCamera(this);
}
