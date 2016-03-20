//Travel Information Center
//Aps Island has many cities.In the summer, many travellers will come to the island and attend festive events in different cities.The festive events in Aps Island are crazy.Once it starts, it will never end.In the following sentences, the cities which have festive events are called festive cities.
//
//At the beginning, only city No. 1 is festive city.If a new city becomes festive city, the government will tell the information center about this news.
//
//Everyday, the information center will receive many inquiries from travellers from different cities of this land.They want to know the closest festive city, and calculate the distance(If current city has festive event, the distance is 0).
//
//Due to the growing number of the travellers, the information center is overloaded.The government wants to fix the problem by developing a system to handle the inquiries automatically.
//
//As a fact, cities in Aps Island are connected with highways(bidirectional, length of every highway is 1).Any two cities are connected directly or indirectly, and there is ONLY one path between any 2 cities.
//
//Input
//
//There are two integers in the first line, n(2 ≤ n ≤ 10 ^ 5) and m(1 ≤ m ≤ 10 ^ 5), n is the number of cities in the Aps Island and m is the number of queries.The coming n - 1 lines are the highways which connect two cities.In the line, there are two integers ai and bi(1 ≤ ai, bi ≤ n, ai ≠ bi), representing two cities.Each line means the highway connecting the two cities.
//
//Next m lines are inquiries from travellers or news from government.Each line has two integers qi and ci(1 ≤ qi ≤ 2, 1 ≤ ci ≤ n).If qi  = 1, the government announces a new festive city ci.If qi  = 2, you have to find and print the shortest distance from the city ci to the closest festive city.
//
//Output
//
//Results from each(qi = 2) Questions.Print every result with a new line.
//
//Limits
//
//Memory limit per test : 256 megabytes
//Time limit per test : The faster the better
//Compile & Environment
//
//C++
//
//g++ Main.cc - o Main - fno - asm - Wall - lm--static - std = c++0x - DONLINE_JUDGE

//Input
//n(2 ≤ n ≤ 10 ^ 5) and m(1 ≤ m ≤ 10 ^ 5)
//5 5
//n=5, m=5

//1 2
//1 3
//3 4
//3 5
//2 5
//2 3
//1 3
//2 3
//2 4

//2
//1
//0
//1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace Cities
{
	struct City
	{
		//festive flag
		int festive=0;
		vector<int> neighbours;
	};

	struct Connects
	{
		//current node
		int cur;
		//parent node
		int par;
		//acccumulated distance
		int dis;
	};
}

using namespace Cities;

int bfs(vector<City> all, int c, int n);

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	//Initialize a list of cities
	vector<City> allCities(n);

	allCities[0].festive = 1;
	int num = n;
	while (--num)
	{
		//City a and city b are connected
		cin >> a >> b;
		a--, b--;
		allCities[a].neighbours.push_back(b);
		allCities[b].neighbours.push_back(a);
	}

	int q, c, dis;
	while (m)
	{
		cin >> q>>c;
		c--;
		//q=1, government anounce a city
		if (q==1)
		{
			allCities[c].festive = 1;
		}

		//q=2, search for the nearst festive city
		if (q==2)
		{
			dis = bfs(allCities, c, n);
			printf("%d\n", dis);
		}

		m--;
	}
}

int bfs(vector<City> all, int c, int n)
{
	queue<Connects> que;
	//bfs search start from the root which is provide by c
	Connects root;
	root.cur = c;
	root.dis = 0;

	que.push(root);
	while (!que.empty())
	{
		//pop up a connect
		Connects now = que.front();
		que.pop();
		//
		if (all[now.cur].festive)
		{
			return now.dis;
		}
		//traverse through all of the connected nodes
		int search = all[now.cur].neighbours.size();
		while (search)
		{
			search--;
			//make sure the traverse does not go to the current node's parent node
			if (all[now.cur].neighbours[search]==now.par)
			{
				continue;
			}
			Connects push;
			push.par = now.cur;
			push.cur = all[now.cur].neighbours[search];
			push.dis = now.dis + 1;

			que.push(push);
			
		}

	}

}