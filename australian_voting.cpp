#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<map>

using namespace std;




int main()
{

    ifstream f("aust.txt");
    
    int cases;
    f >> cases;

    while (cases > 0)
    {
        int candidates;
        f >> candidates;
        vector<string> names(candidates);
        vector<bool> active;
        vector<vector<int> > mapa;

        f.ignore();

        for (int i = 0; i < candidates; i++)
        {
            getline(f, names[i]);
            active.push_back(true);
        }

        
        while (true)
        {
            string vote;
            getline(f, vote);

            if (vote == "")
            {
                break;
            }

            stringstream s(vote);

           
            vector<int> votes(candidates);

            for (int i = 0; i < candidates; i++)
            {

                s >> votes[i];
               
            }

            mapa.push_back(votes);

        }

        int numRatings = mapa.size();
        vector<int> posInRatings(numRatings, 0);        
        vector<int> count(candidates, 0);
  
        while (true)
        {
            for (int i = 0; i < numRatings; i++)
            {
                for (int j = 0; j < candidates; j++)
                {
                    if (active[mapa[i][j] - 1]) {
                        ++count[mapa[i][j] - 1];
                        break;
                    }
                }
                
            }
            int max_v = 0;
            int min_v = 1000;

            for (int i = 0; i < count.size(); i++)
            {
                if (active[i])
                {
     
                    if (count[i] > max_v)
                    {
                        max_v = count[i];
                    }
                    if (min_v > count[i])
                    {
                        min_v = count[i];
                    }
                }

            }

            if (min_v == max_v)
            {

                for (int i = 0; i < candidates; i++)
                {
                    if(active[i])

                    cout << names[i] << endl;

                }
                break;
            }

            else if (2 * max_v > numRatings)
            {
                for (int i = 0; i < candidates; i++)
                {
                    if (count[i] == max_v)
                    {
                        cout << names[i] << endl;
                    }
                }
                break;
            }

            else
            {

                for (int i = 0; i < candidates; i++)
                {
                    if (count[i] == min_v)
                    {
                        
                        active[i] = false;

                    }
                }

                fill(count.begin(), count.end(), 0);
            }


        }

        cases--;
        if (cases != 0) {
            cout << endl;
        }
    }



    f.close();
    return 0;

}