

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	// Declaration of variable required
	int i, j, Npage, ref_str[50], frame[10], Nframe, k, free, fcount = 0;  
	// total number of pages in reference string
	cout<< " ENTER THE NUMBER OF PAGES:"<<endl ;
	cin >> Npage;
	// accept entire reference string
	cout << "\n ENTER THE PAGE NUMBER :"<<endl ;
	for (i = 1;i <= Npage;i++)
		cin >> ref_str[i];
	// number of frames
	cout << "\n ENTER THE NUMBER OF FRAMES :"<<endl ;
	cin >> Nframe;
	// giving all page frames a -1 value
	for (i = 0;i < Nframe;i++)
		frame[i] = -1;  
	// initialize page frame pointer
	j = 0;                           
	cout << "\nreference string"<<endl ;
	for (i = 1;i <= Npage;i++)
	{
		cout <<ref_str[i] << "\t\t";
		// Default value of available flag is 0
		free = 0;          
		for (k = 0;k < Nframe;k++)

			// input of  page  requested is compared with existing content of FRAME
			if (frame[k] == ref_str[i]) 
			{
				// if page found free is turned 1
				free = 1;        
				for (k = 0;k < Nframe;k++)
					// Print Current state of FRAME
					cout <<frame[k] <<"\t" ;   
				// Indication of Page Hit
				cout << "HIT";                        
			}
		// input   page  requested NOT existing in  FRAME
		if (free == 0)  
		{
			// place page requested at j th location in FRAME
			frame[j] = ref_str[i];    
			// Update J for next Cycle
			j = (j + 1) % Nframe;
			// Increment Counter for Page Fault
			fcount++;                
			for (k = 0;k < Nframe;k++)
				// Print Current state of FRAME
				cout << frame[k] <<"\t" ;
			// Indication of Page Fault
			cout << "FAULT";            
		}
		cout << "\n";
	}
	cout << "Page Fault Is : "<< fcount;
	return 0;
}

