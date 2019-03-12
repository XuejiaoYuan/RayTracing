#include "Surface.h"

Surface::Surface()
{
	param = new double[10];
	for (int i = 0; i < 10; i++)
		param[i] = 0;
	frameBuffer = new GLfloat[3 * WINWIDTH*WINHEIGHT];

	eyeLoc = vec3(800, 0, 0);

	pLoc1 = vec3(eyeLoc.x / 4, -WINWIDTH / 2, WINHEIGHT / 2);
	pLoc2 = vec3(eyeLoc.x / 4, WINWIDTH / 2, WINHEIGHT / 2);
	pLoc3 = vec3(eyeLoc.x / 4, -WINWIDTH / 2, -WINHEIGHT / 2);

	yMax = INT_MAX;
	zMax = INT_MAX;

}

GLfloat * Surface::RayTracing()
{
	vec3 dy = vec3((pLoc2.x - pLoc1.x) / (WINWIDTH - 1),
		(pLoc2.y - pLoc1.y) / (WINWIDTH - 1),
		(pLoc2.z - pLoc1.z) / (WINWIDTH - 1)
	);
	vec3 dz = vec3((pLoc3.x - pLoc1.x) / (WINHEIGHT - 1),
		(pLoc3.y - pLoc1.y) / (WINHEIGHT - 1),
		(pLoc3.z - pLoc1.z) / (WINHEIGHT - 1)
	);

	int cnt = 3*WINHEIGHT*WINWIDTH-3;
	int n = 0;
	bool inner;

	for (int i = 0; i < WINHEIGHT; i++) {
		vec3 v = pLoc1 + vec3(i*dz.x, i*dz.y, i*dz.z);
		for (int j = 0; j < WINWIDTH; j++) {
			vec3 dir = v - eyeLoc;
			vec3 point;
			vec3 color(0, 0, 0);
			if (GetIntersection(dir, point, inner)) {
				GetColor(point, dir, color, inner);
				n++;
			}
            frameBuffer[cnt] = color.x;
            frameBuffer[cnt + 1] = color.y;
            frameBuffer[cnt + 2] = color.z;
            cnt -= 3;
            v += dy;
        }
    }
    return frameBuffer;

}



bool Surface::GetIntersection(vec3 dir, vec3 & intersectionPoint, bool & inner)
{
	double tMin, tMax, t;
	bool flag, noPoint = false;
	inner = false;

	flag = GetT(dir, tMin, tMax);

	if (flag) {
		double tmpZ1 = eyeLoc.z + tMin*dir.z;
		double tmpZ2 = eyeLoc.z + tMax*dir.z;
		double tmpY1 = eyeLoc.y + tMin*dir.y;
		double tmpY2 = eyeLoc.y + tMax*dir.y;

		if (tMin > 1 && tMax > 1) {
			if (tmpZ1 <= zMax&&tmpZ1 >= -zMax && tmpY1 <= yMax && tmpY1 >= -yMax)
				t = tMin;
			else if (tmpZ2 <= zMax&&tmpZ2 >= -zMax && tmpY2 <= yMax && tmpY2 >= -yMax) {
				t = tMax;
				inner = true;
			}
			else
				noPoint = true;
		}
		else if (tMax > 1) {
			if (tmpZ2 <= zMax&&tmpZ2 >= -zMax && tmpY2 <= yMax && tmpY2 >= -yMax) {
				t = tMax;
				inner = true;
			}
			else
				noPoint = true;
		}
		else
			noPoint = true;
	}
	else
		noPoint = true;

	if (noPoint) {
		intersectionPoint = vec3(0, 0, 0);
		return false;
	}
	else {
		intersectionPoint = vec3(eyeLoc.x + t*dir.x, eyeLoc.y + t*dir.y, eyeLoc.z + t*dir.z);
        if(index == 1 || index == 3 || index == 4)
            inner = false;
        return true;
	}
}

void Surface::GetColor(const vec3 & point, const vec3 & dir, vec3& color, bool inner)
{
	vec3 brightColor;
	if (inner)
		brightColor = vec3(0, 0.5, 0);
	else
		brightColor = vec3(1, 1, 0);
	vec3 normal;
	GetNormal(point, dir, normal);
	vec3 tmpDir = normalize(-dir);
	double intensity = tmpDir.x*normal.x +
					   tmpDir.y*normal.y +
					   tmpDir.z*normal.z;
	intensity = intensity > 0 ? intensity : 0;
	color = vec3(brightColor.x*intensity,
		brightColor.y*intensity,
		brightColor.z*intensity);
}

void Surface::GetNormal(const vec3 & point, const vec3 & dir, vec3 & normal)
{
	normal.x = 2 * param[0]*point.x + param[4]*point.z + param[5]*point.y + param[6];
	normal.y = 2 * param[1]*point.y + param[3]*point.z + param[5]*point.x + param[7];
	normal.z = 2 * param[2]*point.z + param[3]*point.y + param[4]*point.x + param[8];
	double dotRes = normal.x*dir.x +
		normal.y*dir.y +
		normal.z*dir.z;
	if (dotRes > 0) {
		normal = -normal;
	}
	normal = normalize(normal);
}

bool Surface::GetT(const vec3& dir, double & tMin, double & tMax)
{
	double a, b, c;
	double discriminant;

	a = param[0]*dir.x*dir.x +
		param[1]*dir.y*dir.y +
		param[2]*dir.z*dir.z +
		param[3]*dir.y*dir.z +
		param[4]*dir.x*dir.z +
		param[5]*dir.x*dir.y;
	b = 2 * (param[0]*eyeLoc.x*dir.x + param[1]*eyeLoc.y*dir.y + param[2]*eyeLoc.z*dir.z) +
		param[3]*(eyeLoc.y*dir.z + eyeLoc.z*dir.y) +
		param[4]*(eyeLoc.x*dir.z + eyeLoc.z*dir.x) +
		param[5]*(eyeLoc.x*dir.y + eyeLoc.y*dir.x) +
		param[6]*dir.x + param[7]*dir.y + param[8]*dir.z;
	c = param[0]*eyeLoc.x*eyeLoc.x + param[1]*eyeLoc.y*eyeLoc.y + param[2]*eyeLoc.z*eyeLoc.z +
		param[3]*eyeLoc.y*eyeLoc.z + param[4]*eyeLoc.x*eyeLoc.z + param[5]*eyeLoc.x*eyeLoc.y +
		param[6]*eyeLoc.x + param[7]*eyeLoc.y + param[8]*eyeLoc.z + param[9];

	discriminant = b*b - 4 * a*c;

	double t1, t2;
	if (discriminant < 0)
	{
		t1 = 0;
		t2 = 0;
		return false;
	}
	else {
		double sqDis = sqrt(discriminant);
		t1 = (-b - sqDis) / (2 * a);
		t2 = (-b + sqDis) / (2 * a);
		tMin = t1 < t2 ? t1 : t2;
		tMax = t1 < t2 ? t2 : t1;
		return true;
	}
}

void Surface::EyeMovement(const vec3 & cameraSpeed)
{
	eyeLoc += cameraSpeed;
	pLoc1 += cameraSpeed;
	pLoc2 += cameraSpeed;
	pLoc3 += cameraSpeed;
}

void Surface::Scale(double s)
{
	double l1 = length(pLoc2 - pLoc1);
	double l2 = length(pLoc3 - pLoc1);
	double m = l1 / l2;
	vec3 dir1 = normalize(pLoc2 - pLoc1);
	vec3 dir2 = normalize(pLoc3 - pLoc1);
	pLoc1 += vec3(s*dir1.x, s*dir1.y, s*dir1.z);
	pLoc2 -= vec3(s*dir1.x, s*dir1.y, s*dir1.z);
	pLoc3 += vec3(s*dir1.x, s*dir1.y, s*dir1.z);
	s /= m;
	pLoc1 += vec3(s*dir2.x, s*dir2.y, s*dir2.z);
	pLoc2 += vec3(s*dir2.x, s*dir2.y, s*dir2.z);
	pLoc3 -= vec3(s*dir2.x, s*dir2.y, s*dir2.z);

}

void Surface::RotationZ(double theta)
{
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    double tmpX = eyeLoc.x;
    double tmpY = eyeLoc.y;

    eyeLoc.x = cosTheta*tmpX - sinTheta*tmpY;
    eyeLoc.y = sinTheta*tmpX + cosTheta*tmpY;

    tmpX = pLoc1.x;
    tmpY = pLoc1.y;

    pLoc1.x = cosTheta*tmpX - sinTheta*tmpY;
    pLoc1.y = sinTheta*tmpX + cosTheta*tmpY;

    tmpX = pLoc2.x;
    tmpY = pLoc2.y;

    pLoc2.x = cosTheta*tmpX - sinTheta*tmpY;
    pLoc2.y = sinTheta*tmpX + cosTheta*tmpY;

    tmpX = pLoc3.x;
    tmpY = pLoc3.y;

    pLoc3.x = cosTheta*tmpX - sinTheta*tmpY;
    pLoc3.y = sinTheta*tmpX + cosTheta*tmpY;

}

void Surface::RotationY(double theta)
{
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);

    double tmpX = eyeLoc.x;
    double tmpZ = eyeLoc.z;

    eyeLoc.x = cosTheta*tmpX + sinTheta*tmpZ;
    eyeLoc.z = -sinTheta*tmpX + cosTheta*tmpZ;

    tmpX = pLoc1.x;
    tmpZ = pLoc1.z;

    pLoc1.x = cosTheta*tmpX + sinTheta*tmpZ;
    pLoc1.z = -sinTheta*tmpX + cosTheta*tmpZ;

    tmpX = pLoc2.x;
    tmpZ = pLoc2.z;

    pLoc2.x = cosTheta*tmpX + sinTheta*tmpZ;
    pLoc2.z = -sinTheta*tmpX + cosTheta*tmpZ;

    tmpX = pLoc3.x;
    tmpZ = pLoc3.z;

    pLoc3.x = cosTheta*tmpX + sinTheta*tmpZ;
    pLoc3.z = -sinTheta*tmpX + cosTheta*tmpZ;

}
