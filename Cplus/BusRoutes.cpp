#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int> >& routes, int S, int T) {
		if(S==T)
			return 0;
		set<int> terminal,visitedStation,visitedBus;
		for(int i=0;i<(int)routes.size();i++)
			for(int j=0;j<(int)routes[i].size();j++)
			{
				if(routes[i][j]==S)
					visitedBus.insert(i);
				else if(routes[i][j]==T)
					terminal.insert(i);
			}
		for(set<int>::iterator iter=visitedBus.begin();iter!=visitedBus.end();++iter)
		{
			if(terminal.find(*iter)!=terminal.end())
				return 1;
			for(int i=0;i<(int)routes[*iter].size();i++)
				visitedStation.insert(routes[*iter][i]);
		}
		bool flag=true;
		int res=1;
		set<int> tmp;
		while(flag)
		{
            tmp.clear();
			res++;
			flag=false;
			for(int i=0;i<(int)routes.size();i++)
			{
				if(visitedBus.find(i)!=visitedBus.end())
					continue;
				for(int j=0;j<(int)routes[i].size();j++)
				{
					if(visitedStation.find(routes[i][j])!=visitedStation.end())
					{
						visitedBus.insert(i);
						if(terminal.find(i)!=terminal.end())
							return res;
						for(int k=0;k<(int)routes[i].size();k++)
						 	tmp.insert(routes[i][k]);
						flag=true;
						break;
					}
				}
			}
			visitedStation.insert(tmp.begin(),tmp.end());
		}
		return -1;
    }
};
