#pragma once
class CKnapsackProblem
{
public:
	CKnapsackProblem();
	CKnapsackProblem(double dKnapsackSize, int iItemsCount, double dMaxValueItm, double dMaxSizeItm);
	CKnapsackProblem(double dKnapsackSize, int iItemsCount);
	~CKnapsackProblem();

	bool bSetNewValueOfItm(int iIndex, double iValue);
	bool bSetNewSizeOfItm(int iIndex, double iSize);
//	bool bSetNewSizeOfItmTable(int iIndex, int iSize);
	double dGetValueFromGen(int * piTable);
	double dGetSizeFromGen(int * piTable);

	int iGetItemsCount();
	double dGetKnapsackSize();

	void display();
private:
	//void generateItems(int maxValue, int maxSize, int countItems);
	int iGenerateInteger(int iFrom, int iTo);
	double dGenerateDouble(double iFrom, double iTo);
	double d_knapsack_size;
	int i_items_count;
	double ** ppd_items_table;
};

