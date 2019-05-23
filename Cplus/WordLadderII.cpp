#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
	vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
		map<string,unordered_set<string> > graph;
		for(int i=0;i<(int)wordList.size();i++)
			if(transform(beginWord,wordList[i])==1)
				graph[beginWord].insert(wordList[i]);

		for(int i=0;i<(int)wordList.size()-1;i++)
			for(int j=i+1;j<(int)wordList.size();j++)
				if(transform(wordList[i],wordList[j])==1)
				{
					graph[wordList[i]].insert(wordList[j]);
					graph[wordList[j]].insert(wordList[i]);
				}
		if(graph.find(endWord)==graph.end())
			return vector<vector<string> >();
		vector<vector<string> >  res;
		unordered_set<string> visited;

		queue<string> q;
		int depth=1;
		q.push(beginWord);
		while(!q.empty())
		{
			int n=q.size();
			depth+=1;
			while(--n>=0)
			{
				if(graph[q.front()].find(endWord)!=graph[q.front()].end())
				{
					//BFS
					visited.clear();
					vector<string> tmp(depth);
					tmp[0]=beginWord;
					tmp[depth-1]=endWord;
					findLadders(graph,res,tmp,visited,endWord,depth);
					return res;
				}
				for(unordered_set<string>::iterator iter=graph[q.front()].begin();iter!=graph[q.front()].end();++iter)
				{
					if(visited.find(*iter)==visited.end())
					{
						visited.insert(*iter);
						q.push(*iter);
					}
				}
				q.pop();
			}
		}
		return vector<vector<string> >();
	}
	//DFS
	void findLadders(map<string,unordered_set<string> >& graph,vector<vector<string> >& res,vector<string>& tmp,unordered_set<string>& visited,const string& dst,int depth)
	{
		if(depth<=2)
		{
			if(graph[tmp[tmp.size()-depth]].find(dst)!=graph[tmp[tmp.size()-depth]].end())
				res.push_back(tmp);
			return;
		}
		for(unordered_set<string>::iterator iter=graph[tmp[tmp.size()-depth]].begin();iter!=graph[tmp[tmp.size()-depth]].end();++iter)
		{
			if(visited.find(*iter)==visited.end())
			{
				visited.insert(*iter);
				tmp[tmp.size()-depth+1]=*iter;
				findLadders(graph,res,tmp,visited,dst,depth-1);
				visited.erase(visited.find(*iter));
			}
		}
	}

	int transform(const string& w1,const string& w2)
	{
		int res=0;
		for(int i=0;i<(int)w1.size();i++)
			if(w1[i]!=w2[i])
				res++;
		return res;
	}
};
