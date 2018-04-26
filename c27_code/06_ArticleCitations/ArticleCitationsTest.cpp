#include "01_FirstAttempt/ArticleCitations.h"
#include <iostream>

using namespace std;

void processCitations(ArticleCitations cit)
{
	cout << cit.getArticle() << endl;
	int num = cit.getNumCitations();
	for (int i = 0; i < num; i++) {
		cout << cit.getCitation(i) << endl;
	}
}

int main()
{
	while (true) {
		cout << "Enter a file name (\"STOP\" to stop): ";
		string fileName;
		cin >> fileName;
		if (fileName == "STOP") {
			break;
		}

		ArticleCitations cit(fileName);
		processCitations(cit);
	}

	return 0;
}
