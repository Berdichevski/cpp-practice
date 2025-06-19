class Trinominal
{
	double* odds;
public:
	double* getOdds();
	Trinominal operator +(const Trinominal& trin2);
	void roots();
	double* rootsArr;
	int rootsAmount;
	Trinominal(double* odds);
};