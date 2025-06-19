//-----------------ÍÅ Î×ÅÍÜ ĞÀÁÎ×Àß ÏĞÎÃĞÀÌÌÀ ÏÎÄÑ×ÅÒÀ ÂÊËŞ×ÅÍÈÉ Â ÑÒĞÎÊÅ

//#include <fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string r = " .,:;!?-";
//	string s;
//	getline(cin, s);
//	int fr[100]{0};
//	int w = 0;
//	int i = 0;
//	while (s[i])
//	{
//		while (s[i] && !strchr(r, s[i]))
//		{
//			w++;
//			i++;
//		}
//		fr[w]++;
//		w = 0;
//		while (s[i] && strchr(r, s[i]))
//		{
//			i++;
//		}
//	}
//}

//----------ÑÏÎÑÎÁÛ ÂÇÀÈÌÎÄÅÉÑÒÂÈß Ñ ÔÀÉËÀÌÈ

//#include <fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	//----------------ÂÂÎÄ ÈÇ ÔÀÉËÀ
//	string s;
//	string k;
//	ifstream fin("in.txt");
//	//fin.is_open();
//	//fin.fail();
//	//fin >> k;
//	getline(fin, s);
//	//fin.class();
//	//----------------ÂÛÂÎÄ Â ÔÀÉË
//	ofstream fout("out.txt");
//	fout << k << ' ';
//	fout << endl;
//}

//#include <fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	ifstream fin;
//	ofstream fout;
//	fout.open("out.txt");
//	fin.open("in.txt");
//	while (!fin.eof())
//	{
//		int n, m;
//		fin >> n >> m;
//		int matrix[100][100];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				fin >> matrix[i][j];
//			}
//		}
//		if (n == m)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = i+1; j < n; j++)
//				{
//					int x = matrix[i][j];
//					matrix[i][j] = matrix[j][i];
//					matrix[j][i] = x;
//				}
//			}
//
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = 0; j < m; j++)
//				{
//					fout << matrix[i][j] << " ";
//				}
//				fout << endl;
//			}
//		}
//	}
//	fin.close();
//	fout.close();
//}

//#include <fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    ifstream fin("C:\Users\Berdi\OneDrive\Ğàáî÷èé ñòîë\CMD FILES\in.txt.txt");
//    ofstream fout("out.txt");
//
//    if (!fin.is_open())
//    {
//        cerr << "Failed to open input file." << endl;
//        return 1;
//    }
//
//    if (!fout.is_open())
//    {
//        cerr << "Failed to open output file." << endl;
//        return 1;
//    }
//
//    while (!fin.eof())
//    {
//        int n, m;
//        fin >> n >> m;
//        int matrix[100][100];
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                fin >> matrix[i][j];
//            }
//        }
//        if (n == m)
//        {
//            for (int i = 0; i < n; i++)
//            {
//                for (int j = i + 1; j < n; j++)
//                {
//                    int x = matrix[i][j];
//                    matrix[i][j] = matrix[j][i];
//                    matrix[j][i] = x;
//                }
//            }
//
//            for (int i = 0; i < n; i++)
//            {
//                for (int j = 0; j < m; j++)
//                {
//                    fout << matrix[i][j] << " ";
//                }
//                fout << endl;
//            }
//        }
//    }
//
//    fin.close();
//    fout.close();
//
//    return 0;
//}

//#include <fstream>
//
//#include <fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int* p;
//	int n;
//	cin >> n;
//	int* a = new int[n];


int** m = new int* [n];
for (int i = 0; i < n; i++)
{
	m[i] = new int[m];
}





