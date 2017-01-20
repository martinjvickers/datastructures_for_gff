/* 
Compile: g++ -std=c++0x

A simple method to be able to store gff features in an unordered map. 
Useful if you wish to count the number of features.

Martin Vickers
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
 
using namespace std;
 
typedef pair<string,pair<int,int>> Record;

//override the hash operator so that a hash is created using the feature name, start and end position.
namespace std {
	template <>
		class hash<Record>{
		public :
			size_t operator()(const Record &record ) const
			{
				return hash<string>()(record.first) ^ hash<int>()(record.second.first) ^ hash<int>()(record.second.second);
			}
		};
};
 
int main(int argc, char* argv[])
{
	unordered_map<Record,int> ourmap;
	ourmap[Record("chr1",make_pair(322,362))]++;
	ourmap[Record("chr1",make_pair(322,363))]++;
	ourmap[Record("chr1",make_pair(322,363))]++;
	ourmap[Record("chr1",make_pair(322,363))]++;
	ourmap[Record("chr2",make_pair(322,363))]++;

	for (auto i=ourmap.begin(); i!=ourmap.end(); i++)
		cout << i->first.first << " " << i->first.second.first << " " << i->first.second.second << " " << i->second << endl;
	return 0;
}
