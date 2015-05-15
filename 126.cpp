#include <unordered_set>
#include <string>
#include <vector>
#include <deque>

using namespace std;
struct word
{
	string this_word;
	unordered_set<word*> similar;
	int step;
	unordered_set<word*> pre;

	bool similarTo(const word* o) const
	{
		bool isSimilar = false;
		for (int i = 0; i < this_word.size(); i++)
		{
			if (this_word[i] != o->this_word[i])
			{
				if (!isSimilar)
					isSimilar = true;
				else
					return false;
			}
		}
		return isSimilar;
	}
};

vector<word*> wordList;

void build_word_map(string start, string end, unordered_set<string> &dict, word** pStartWord, word** pEndWord)
{
	auto dictSize = dict.size();

	auto startWord = new word;
	*pStartWord = startWord;
	startWord->this_word = start;
	startWord->step = 0;

	auto endWord = new word;
	*pEndWord = endWord;
	endWord->this_word = end;
	endWord->step = dictSize+3;

	for (auto i : dict)
	{
		auto tmpWord = new word;
		tmpWord->this_word = i;
		tmpWord->step = dictSize+2;
		wordList.push_back(tmpWord);
	}

	for (auto i = wordList.begin(); i != wordList.end(); i++)
	{
		for (auto j = i+1; j != wordList.end(); j++) {
			if ((*i)->similarTo(*j))
			{
				(*i)->similar.insert(*j);
				(*j)->similar.insert(*i);
			}
		}

		if ((*i)->similarTo(startWord))
		{
			(*i)->similar.insert(startWord);
			(startWord)->similar.insert(*i);
		}
		if ((*i)->similarTo(endWord))
		{
			(*i)->similar.insert(endWord);
			(endWord)->similar.insert(*i);
		}
	}

	return;
}



void search(word* start, word* end)
{
	deque<word*> mqueue;
	mqueue.clear();
	mqueue.push_back(start);
	while(!mqueue.empty())
	{
		word* t = mqueue.front();
		mqueue.pop_front();

		if (t == end)
			break;

		for (auto i : t->similar)
		{
			if (i->step > t->step + 1)
			{
				i->step = t->step + 1;
				i->pre.insert(t);
				mqueue.push_back(i);
			}
			else if (i->step == t->step + 1)
			{
				i->pre.insert(t);
			}
		}
	}
}

void printPath(word* endWord, vector<string> &res, vector<vector<string> > &result)
{
	res.push_back(endWord->this_word);
	if (endWord->step == 0)
	{
		result.push_back(res);
		reverse(result.back().begin( ), result.back().end());
	}
	else
	{
		for (auto i : endWord->pre)
		{
			printPath(i, res, result);
		}
	}
	res.pop_back();
}

class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		word *startWord, *endWord;
		build_word_map(start, end, dict, &startWord, &endWord);
		search(startWord, endWord);
		vector<vector<string>> result;
		vector<string> midRes;
		printPath(endWord, midRes, result);
		return result;
	}
};

int main(){
	Solution A;
	unordered_set<string> a = {"hot","dot","dog","lot","log"};
	A.findLadders("hit", "cog", a);
	return 0;
};