// projectHelper.cpp : Defines the entry point for the application.
//

#include "projectHelper.h"
namespace fs = std::filesystem;
using namespace std;


static string lower(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

fs::path closest_match(fs::path path, string query)
{
	fs::path closest = path;
	int closest_score = 0;
	query = lower(query);
	for (const auto &entry : fs::directory_iterator(path))
	{
		if (entry.is_directory())
		{
			string folder = entry.path().filename().string();
			folder = lower(folder);
			int score = rapidfuzz::fuzz::ratio(folder, query);
			if (score > closest_score)
			{
				closest = entry.path();
				closest_score = score;
			}
		}
	}
	return closest;
}

map<string, string> langCode = {
	{"py", "Python"},
	{"cpp", "C++"},
	{"js", "JavaScript"},
	{"java", "Java"},
	{"c++", "cpp"},
	{"c#", "Csharp"},
	{"web", "js"},
};

int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		cout << "Usage: p py|cpp|js folder1 folder2 ..." << endl;
		return 1;
	}

	string lang = argv[1];
	if (langCode.find(lang) != langCode.end())
	{
		lang = langCode[lang];
	}

		string codePath = getenv("CODE_PATH");
	if (codePath.empty())
	{
		cout << "`CODE_PATH` is not set" << endl;
		return 1;
	}
	fs::path code_dir(codePath);
	fs::path closest_match_folder = closest_match(code_dir, lang);
	for (int i = 2; i < argc; i++)
	{
		fs::path cl = closest_match(closest_match_folder, argv[i]);
		if (cl == closest_match_folder)
		{
			break;
		}
		closest_match_folder = cl;
	}
	cout << closest_match_folder << endl;

	return 0;
}
