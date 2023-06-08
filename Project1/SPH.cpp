#include "StdAfx.h"
#include "SPH.h"
#define PI 3.14159265358979323846264338327950L

Particle::Particle()
{
	m_Vel.Set(0, 0, 0);
	m_VelEval.Set(0, 0, 0);
	m_Acc.Set(0, 0, 0);
}

Particle::~Particle()
{

}

CSPH::CSPH(void)
{
	m_smoothLen = 0.01;
	m_timeStep = 0.001;
	m_curStep = 0;
	m_mass = 0.00020543f;
	m_K = 1.5f;
	m_Kpoly6 = 315 * m_mass / ((64 * PI) * pow(m_smoothLen, 9));
	m_Kspiky = 45.0f / (PI * pow(m_smoothLen, 6));
	m_Kviscosity = 0.2f;

	m_GlassRange[0] = -0.05;
	m_GlassRange[1] = 0.05;
	m_GlassRange[2] = 0;
	m_GlassRange[3] = 1;
	m_GlassRange[4] = -0.05;
	m_GlassRange[5] = 0.05;

	m_GlassNormal[0].Set(1, 0, 0);
	m_GlassNormal[1].Set(-1, 0, 0);
	m_GlassNormal[2].Set(0, 1, 0);
	m_GlassNormal[3].Set(0, -1, 0);
	m_GlassNormal[4].Set(0, 0, 1);
	m_GlassNormal[5].Set(0, 0, -1);

	m_gravity.Set(0, -9.8, 0);
	m_iMoveGlassDir = 0;

	ballPos[0] = 0;
	ballPos[1] = 0;
	ballPos[2] = 0;
	ballPos[3] = 0;
	ballPos[4] = 0;
	ballPos[5] = 0;

	fopen_s(&file, "force.txt", "w");
	countNum3 = 0;
}


