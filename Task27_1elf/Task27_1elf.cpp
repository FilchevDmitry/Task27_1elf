#include<iostream>
#include<string>
#include<vector>
#include<ctime>

class Elf
{
private:
	std::string name;
public:
	Elf()
	{
		name = "None";
	}
	void getNameElf(std::string& inName)
	{
		inName= name;
	}
	void setNameElf(std::string& inName)
	{
		name = inName;
	}
};

class Branch
{
private:
	std::vector<std::vector<Elf>> home;
	Elf elf;
public:
	Branch(int inNumBranch)
	{ 
		srand(time(nullptr));
		for (int i = 0; i < inNumBranch; i++)
		{
			home.push_back(std::vector<Elf>());
			int num =rand() %2 +2;
			for (int j = 0; j < num; j++)
			{
				home[i].push_back(elf);
			}
		}
	}
	void getNameElf(int &i,int &j, std::string &inName)
	{
		home[i][j].getNameElf(inName);
	}
	void setNameElf()
	{
		for (int i = 0; i < home.size(); i++)
		{
			std::cout << "branch "<<i+1<< std::endl;
			for (int j = 0; j < home[i].size(); j++)
			{
				std::string inNameElf;
				std::cout <<"Input name elf : ";
				std::cin >> inNameElf;
				home[i][j].setNameElf(inNameElf);
			}
			std::cout <<"branch end"<<std::endl;
		}
	}
	int findElfsNeighbors(std::string &name, int &numBranch, bool &ok)
	{
		std::string outName;
		int count=0;
		
		for (int i = 0; i < home.size(); i++)
		{
			for (int j = 0; j < home[i].size(); j++)
			{
				home[i][j].getNameElf(outName);
				if (name == outName)
				{
					ok = true;
					numBranch = i;
					for (int k = 0; k < home[numBranch].size(); k++)
					{
						home[numBranch][k].getNameElf(outName);
						if (outName != "None"&& name != outName)
						{
							++count;
						}
					}
					return count;
					break;
				}
			}
		}
		return 0;
	}
};

int main()
{
	const int NUM_TREE = 5;
	std::string nameElf;
	srand(time(nullptr));
	std::vector<Branch> tree;
	for (int i = 0; i < NUM_TREE; i++)
	{
		int numBranch = rand() % 2 + 3;
		tree.push_back(Branch(numBranch));
	}
	for (int k = 0; k < NUM_TREE; k++)
	{
		std::cout << "Tree " << k + 1 << std::endl;
		tree[k].setNameElf();
	}
	std::cout << "Enter the name of the elf you want to find :";
	std::cin >> nameElf;
	int numBranch;
	int neighbors;
	bool end = false;
	for (int g = 0; g < NUM_TREE; g++)
	{	
		neighbors = 0;
		numBranch = 0;
		neighbors = tree[g].findElfsNeighbors(nameElf, numBranch,end);
		if (end)
		{
			std::cout << "The elf lives on the " << g+1 << "rd tree on the " << numBranch+1 << "th branch he has " << neighbors <<" neighbors\n";
		}
	}
	if (!end)
	{
		std::cout << "An elf with that name doesn't live in these trees!!!!" << std::endl;
	}
}

