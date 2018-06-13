#ifndef CAMERA_H
#define CAMERA_H

#include "invisibleobject.h"

class CameraModification;

class Camera : public InvisibleObject
{
private:

 double distance;

public:
    Camera();
    Camera(double);

    void setDistance(double);
    double& getDistance();
    const double& getDistance() const;

    void change(const B_Modification& modif);
};

#endif // CAMERA_H
