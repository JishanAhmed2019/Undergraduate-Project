#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class graph
{
public:	
graph();
	void create(int n);
	void inputgraph();
	void dfs();
	void dfsn();
            void dfsvisit(int j);
	void dfsnvisit(int j);
	void transpose();
	void print();
	void dfsprint();
	void tracksort();
private:
	int** input;
	int** tinput;
	
	int* track;
	int* dis;
	int* fin;
	int* x;
	string* s1;
	int index;
	int hft;
            int time;
	int size;
};
graph::graph()
{
	input = 0;
	tinput = 0;
            track = 0;
	dis = 0;
	fin = 0;
	s1 = 0;
	index = 0;
	hft = 0;
	time = 0;
	size = 0;
}
void graph::create(int n)
{
	size = n;
            input = new int*[size+1];
	tinput = new int*[size+1];
            track = new int[size+1];

	dis = new int[size+1];
	fin = new int[size+1];
	s1 = new string[size+1];
	for(int i = 1; i <= size; i++)
	{
		input[i] = new int[size+1];
		tinput[i] = new int[size+1];
	}
}
void graph::inputgraph()
{
	ifstream infile("graph1.txt");
	int n;

	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
		{
			infile >> n;
			input[i][j] = n;
			tinput[i][j] = n;
		}
	}
}
void graph::transpose()
{
	for(int i = 1; i <= size; i++)
	{
                for(int j = 1; j <= size; j++)
		{
			input[j][i] = tinput[i][j];
		}
	}
}
void graph::dfs()
{
	for(int i = 1; i <= size; i++)
	{
		s1[i] = "white";
	}
	for(int j = 1; j <= size; j++)
	{
		if(s1[j] == "white")
                  {
			dfsvisit(j);
		}
	}
	Cout << “The contents of the reach array is: “
	for(int jj = 1; jj <= size; jj++)
	{
		cout << track[jj] << " ";
	}
	cout << endl;
}
void graph::dfsvisit(int j)
{
	s1[j] = "grey";
	time = time + 1;
	dis[j] = time;
	for(int k = 1; k <= size; k++)
	{
		if(input[j][k] != 0)
		{
			if(s1[k] == "white")
			{
				dfsvisit(k);
			}
		}
	}
	s1[j] = "black";
	time = time + 1;
	fin[j] = time;
	++index;
	track[index] = j;
}
void graph::dfsn()
{
	for(int i = 1; i <= size; i++)
	{
		s1[i] = "white";
                        }
	
	for(int j = 1; j <= size; j++)
	{
		if(s1[track[j]] == "white")
		{
			cout << "Strongly Connected Component are : " << endl;
			cout << track[j] << " ";
			dfsnvisit(track[j]);
            	}
	}
}
void graph::dfsnvisit(int j)
{
	s1[j] = "grey";
	
	for(int k = 1; k <= size; k++)
	{
		if(input[j][k] != 0)
		{
			if(s1[k] == "white")
			{
				cout << k << " ";
				dfsnvisit(k);
			}
		}
	}
	s1[j] = "black";
	cout << endl;
}
void graph::tracksort()
{
	int n = size;
	x = new int[size+1];
	for(int y = 1; y <= size; y++)
	{
		x[y] = track[n];
		--n;
	}
	for(int f = 1; f <= size; f++)
	
{	track[f] = x[f];
}	
for(int m = 1; m <= size; m++)
	
{
		cout << "track["<<m<<"] = " << track[m] << endl;
	}
}
void graph::print()
{
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
		{
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void graph::dfsprint()
{
	for(int i = 1; i <= size; i++)
	{
		cout <<"index = " << i << "So, fin["<<i<<"] = " << fin[i] << ", dis["<<i<<"] = " << dis[i] << endl;
	}
	cout << endl;
	for(int k = 1; k <= size; k++)
	{
		cout << "track["<<k<<"] = " << track[k] << endl;
	}
	cout << endl << endl;
}
int main()
{
	graph s;
	int n;
	cout << "Please Enter a input (Please Enter 9,because the file has 9*9 adjacency Matrix) : " << endl;
	cin >> n;
	s.create(n);
	s.inputgraph();
s.dfs();
	return 0;
}

