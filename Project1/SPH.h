#pragma once
#include "Vector3DF.h"
#include //OpenGL?

#define PARTICLE_NUM 4000  // The number of particles


class Particle
{
public:
	Particle();
	~Particle();
	Vector3DF m_pos;   //position
	double color[10];      //color, considering the masses of universe are various, I made it have 10 channels.

	float m_pressure;  //pressure
	float m_density;   //density

	Vector3DF m_Vel;   //velocity
	Vector3DF m_VelEval;  //velocity 
	Vector3DF m_Acc;   //acceleration

};


class CSPH
{
public:
	CSPH(void);
	~CSPH(void);
	void Init(int particleNum); //Initialization of the number of particles, and the number of phases 
	void InitPos();				//the initialization of particle positions
	void FindBound();			//Solve the boundaries of the grid, based on the maximum and minimum values of the particles to solve
	void FindNeighbour();		//Find Neighbor Particles

	void ComputeDensity();			//compute density
	void ComputeForce();			//compute force
	void DetectCollision(float timeStep);			//DetectCollision


	void UpdatePos(float timeStep); 
	void MoveGlass();				
	void ComputeTouchFroce();		

	void run(); //move

	void saveData(); //data save



	Particle* m_particle; //instant
	int m_particleNum;

	float m_K;			//p=m_K(ro-ro0)
	float m_mass;       //particle mass
	float m_Kpoly6;     //m_K in poly6
	float m_Kspiky;     //m_K in spiky
	float m_Kviscosity; //m_K in viscosityÅicurrently = 0.2fÅj

	Vector3DF m_gravity;  //external force, now is gravity

	//
	float m_smoothLen;//The smooth kernel function radius h.
	float m_timeStep; //now = 0.001
	int m_curStep;	  //the number of step


	//„§äi
	Vector3DF m_boundMin; //bottom
	Vector3DF m_boundMax; //top
	int m_gridNumX, m_gridNumY, m_gridNumZ; //size of grimÅCx*y*z
	int m_gridNum;
	int* Grid; //index of particles in every cell
	int* GridNum;   //how many particles in this cell

	//
	int m_particleIndexInGrid[PARTICLE_NUM]; //the position in cell

	//the information of neighbors
	int m_particleNeighbour[PARTICLE_NUM][100]; 
	int m_particleNeighbourNum[PARTICLE_NUM];   
	float m_particleNeighbourDistance[PARTICLE_NUM][100];  

	//Container(not contaioner in C++)
	float m_GlassRange[6]; //x(-+) y(-+) z(-+)
	Vector3DF m_GlassNormal[6];  //The normal vectors corresponding to the six faces
	int m_iMoveGlassDir;
	//double ballPos[6]; 
	//double ballPosPer[3];

	//
	FILE* file;
	int countNum3;
};
#pragma once
