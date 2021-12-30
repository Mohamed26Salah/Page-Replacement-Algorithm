

#include <iostream>
using namespace std;
int main()
{
    string name = "";
    cout << "Enter the name of the algorithm you want to try\n";
    cin >> name;
    if (name == "FIFO") {
		
		int i, j, Npage, ref_str[50], frame[10], Nframe, k, free, fcount = 0;
		
		cout << " ENTER THE NUMBER OF PAGES:" << endl;
		cin >> Npage;
		
		cout << "\n ENTER THE PAGE NUMBER :" << endl;
		for (i = 1; i <= Npage; i++)
			cin >> ref_str[i];
	
		cout << "\n ENTER THE NUMBER OF FRAMES :" << endl;
		cin >> Nframe;
		// 7ot kolo belnegative
		for (i = 0; i < Nframe; i++)
			frame[i] = -1;
		
		j = 0;
		cout << "\nreference string" << endl;
		for (i = 1; i <= Npage; i++)
		{
			cout << ref_str[i] << "\t\t";
			
			free = 0;
			for (k = 0; k < Nframe; k++)

				// byshofo law homa shbah b3d
				if (frame[k] == ref_str[i])
				{
					
					free = 1;
					for (k = 0; k < Nframe; k++)
						
						cout << frame[k] << "\t";
					
					cout << "HIT";
				}
			
			if (free == 0)
			{
				
				frame[j] = ref_str[i];
				
				j = (j + 1) % Nframe;
				
				fcount++;
				for (k = 0; k < Nframe; k++)
					// Print elframes
					cout << frame[k] << "\t";
				
				cout << "FAULT";
			}
			cout << "\n";
		}
		cout << "Page Fault Is : " << fcount;
		return 0;
    }
    else if (name == "LRU") {

    }
    else if (name == "OPTIMAL") {

    }
    else {
        cout << "Undefined name";
    }
}

