#ifndef CAMERAMODIFICATIONS_H
#define CAMERAMODIFICATIONS_H

#include "invisiblemodification.h"
#include "camera.h"

class CameraModification: public InvisibleModification
{

public:
    CameraModification() {}

    virtual void changeCamera(Camera *const camera) const = 0;
};

class CameraMove : public CameraModification
{
private:

    double delta;

public:
    CameraMove(): delta(0) {}
    CameraMove(double d): delta(d) {}

    void setDelta(double d)
    {
        this->delta = d;
    }

    double getDelta() const
    {
        return this->delta;
    }

    void changeCamera(Camera *const camera) const
    {
        camera->setDistance(camera->getDistance()+=this->delta);
    }

};
#endif // CAMERAMODIFICATIONS_H
