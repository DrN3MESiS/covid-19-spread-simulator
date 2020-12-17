#include <vector>

class Agent
{
public:
	// Position
	int id = 0;
	int x = 0;
	int y = 0;

	bool hasBeenAccountedFor = false;
	bool hasDied = false;

	// No infectado = 0
	// Infectado = 1
	// En Cuarentena = -1
	// Muerto = -2
	int S = 0;
	// Probabilidad de Contagio
	float Pcon = 0;
	// Probabilidad de Contagio Externa
	float Pext = 0;
	//Probabilidad mortalidad
	float Pfat = 0;
	// Probabilidad de movilidad
	float Pmov = 0;
	//Probabilidad de movilidad en peque�as distancias
	float Psmo = 0;
	//Tiempo de incubaci�n
	int Tinc = 0;
	//Tiempo de recuperaci�n
	int Trec = 14;
	//Constructor
	Agent(int x, int y, int i);
	Agent() = default;
	//Rango de probabilidad de contagio
	static float PconRange[2];
	//Rango de probabilidad externa de contagio
	static float PextRange[2];
	//Rango de probabilidad de mortalidad
	static float PfatRange[2];
	// Rango de probabilidad de movilidad
	static float PmovRange[2];
	// Rango de probabilidad de Movimiento en peque�a distancia
	static float PsmoRange[2];
	//Rango de tiempo de incubaci�n
	static int TincRange[2];
};

class GlobalState
{
public:
	//N�mero de agentes
	static int N;
	//M�ximo n�mero de d�as de simulaci�n
	static int Dmax;
	//M�ximo n�mero de movimientos por d�a
	static int Mmax;
	//Radio m�ximo permitido para movimientos locales
	static int lmax;
	//Distancia l�mite de contagio
	static int R;
	//�rea de simulaci�n, Dimensi�n 0:y, Dimensi�n 1:x
	static int mapSize[2];

	/* Estadisticas */
	// Infection
	// Dead
	// Cured
	static int infectedAgents;
	static int curedAgents;
	static int deadAgents;
	static int patientZeroDay;
	static int halfPopulationInfectedDay;
	static int fullPopulationInfectedDay;
	static int patientZeroCuredDay;
	static int halfPopulationCuredDay;
	static int fullPopulationCuredDay;
	static int patientZeroDeadDay;
	static int halfPopulationDeadDay;
	static int fullPopulationDeadDay;
};

class Operations
{
public:
	//First Operation
	static int hasBeenInfected(Agent* agent, std::vector<Agent*>* AgentList);
	//Second Operation
	static int isShortMovement(Agent* agent);
	static int XMovement(Agent* agent);
	static int YMovement(Agent* agent);
	static bool willMove(Agent* agent);
	//Third Operation
	static int hasBeenExternalInfected(Agent* agent);
	//Fourth Operation
	static int incubationTime(Agent* agent);
	static int hasSymptoms(Agent* agent);
	static int recuperationTime(Agent* agent);
	//Fifth Operation
	static int isInRecuperation(Agent* agent);
	static int isDead(Agent* agent);
	//Helpers
	static float GenerateRandomFloatBetween(float a, float b);
	static int GenerateRandomIntegerBetween(int a, int b);
	static int Clamp(int value, int low, int high);
};