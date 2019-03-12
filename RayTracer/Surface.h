//
//二次曲面基类
//
#pragma once
#include "RayTracer/CommonFunc.h"

class Surface
{
public:
    GLfloat* frameBuffer;
	Surface();
    virtual void SetParameters(const vector<double>&) {}
    void setIndex(int _index){ index = _index; }
	GLfloat* RayTracing();
    virtual bool GetIntersection(vec3 dir, vec3& intersectionPoint, bool& inner);
    void Scale(double s);
    void RotationZ(double theta);
    void RotationY(double theta);

protected:
	double *param;
    int index;
    glm::vec3 eyeLoc;
    glm::vec3 pLoc1, pLoc2, pLoc3;	//成像平面三个顶点坐标
								//1———2
								//|		 |
								//3———*
	double zMax, yMax;
    void GetColor(const vec3&point, const vec3& dir, vec3&color, bool inner = false);
	void GetNormal(const vec3& point, const vec3&dir, vec3& normal);
	bool GetT(const vec3& dir,double& t1, double& t2);
	void EyeMovement(const vec3& cameraSpeed);

private:
	
};

