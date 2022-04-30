

#include <iostream>
using namespace std;

int findLeastRecentlyUsed(int array[], int num) {
	int g, min = array[0], position = 0;

	for (g = 1; g < num; ++g) {

		if (array[g] < min) {
			min = array[g];
			position = g;
		}

	}
	return position;
}
int main()
{
    string name = "";
    cout << "Enter the name of the algorithm you want to try (FIFO,LRU,OPTIMAL)\n";
    cin >> name;
    if (name == "FIFO") {
		
		int ll, hh, Npage, referenceStr[50], framesArray[10], Nframe, uu, free, framecount = 0;
		
		cout << "Enter the number of pages you want: " << endl;
		cin >> Npage;
		
		cout << "\nEnter the reference String:" << endl;
		for (ll = 1; ll <= Npage; ll++)
			cin >> referenceStr[ll];
	
		cout << "\n Enter the number of frames you want :" << endl;
		cin >> Nframe;
		// 7ot kolo belnegative
		for (ll = 0; ll < Nframe; ll++)
			framesArray[ll] = -1;
		
		hh = 0;
		cout << "\nreference String" << endl;
		for (ll = 1; ll <= Npage; ll++)
		{
			cout << referenceStr[ll] << "\t\t";
			
			free = 0;
			for (uu = 0; uu < Nframe; uu++)

				// byshofo law homa shbah b3d
				if (framesArray[uu] == referenceStr[ll])
				{
					
					free = 1;
					for (uu = 0; uu < Nframe; uu++)
						
						cout << framesArray[uu] << "\t";
					
					cout << "HIT";
				}
			
			if (free == 0)
			{
				
				framesArray[hh] = referenceStr[ll];
				
				hh = (hh + 1) % Nframe;
				
				framecount++;
				for (uu = 0; uu < Nframe; uu++)
					// Print elframes
					cout << framesArray[uu] << "\t";
				
				cout << "FAULT";
			}
			cout << "\n";
		}
		cout << "\n\nThe number of page faults = " << framecount;
		return 0;
    }////////////////////////////////////////////////////
    else if (name == "LRU") {
        int frame_num, page_num, framesArray[20], pagesArray[50], counter = 0, time[20], flag_1, flag_2, ii, jj, pos, faults = 0, numOfhits = 0;
        cout << "Enter the number of pages you want: ";
        cin >> page_num;

        cout << "\nEnter the reference String: ";
        for (ii = 0; ii < page_num; ++ii) {
            cin >> pagesArray[ii];
        }

        cout << "\n Enter the number of frames you want :";
        cin >> frame_num;

        //3by kolo be -1
        for (ii = 0; ii < frame_num; ++ii) {
			framesArray[ii] = -1;
        }
        //btlf 7waleen el reference string
        for (ii = 0; ii < page_num; ++ii) {
            flag_1 = flag_2 = 0;
            //btshoof fe 7ad shbhaa wla l2
            for (jj = 0; jj < frame_num; ++jj) {
                if (framesArray[jj] == pagesArray[ii]) {
					//small mistake here
					counter++;
					numOfhits++;
                    time[jj] = counter;
                    flag_1 = flag_2 = 1;
					
                    break;
                }

            }
            //btshoof fe negative one wla l2
            if (flag_1 == 0) {
                for (jj = 0; jj < frame_num; ++jj) {
                    if (framesArray[jj] == -1) {
                        counter++;
                        faults++;
						framesArray[jj] = pagesArray[ii];
                        time[jj] = counter;
                        flag_2 = 1;
                        break;
                    }
                }
            }
            //btshoof meen elvictim ely hytbdl
            if (flag_2 == 0) {
                pos = findLeastRecentlyUsed(time, frame_num);
				framesArray[pos] = pagesArray[ii];

                counter++;
               
                time[pos] = counter;
				faults++;
            }

            cout << "\n";
            // display the frames
            for (jj = 0; jj < frame_num; ++jj) {
                cout << framesArray[jj] << "\t";
            }
        }
        cout << "\n\nThe number of page faults = " << faults;
        cout << "\nThe number of hits = " << numOfhits;
        return 0;
    }/////////////////////////////////////////////////////////////////////////////////////////
    else if (name == "OPTIMAL") {
	int frame_num, page_num, ii, jj, kk, framesArray[10], pagesArray[30], hit = 0, temp[10], flag_1, flag_2, flag_3, position, max, numOffaults = 0;
	cout << "Enter the number of pages you want: ";
	cin >> page_num;
	cout << "\nEnter the reference String: ";
	for (ii = 0; ii < page_num; ++ii) {
		cin >> pagesArray[ii];
	}
	cout << "\n Enter the number of frames you want :";
	cin >> frame_num;
	//bt7ot kolo bel negative
	for (ii = 0; ii < frame_num; ++ii) {
		framesArray[ii] = -1;
	}
	
	for (ii = 0; ii < page_num; ++ii) {
		flag_1 = flag_2 = 0;
		//btshoof el7agat elshbah b3d
		for (jj = 0; jj < frame_num; ++jj) {
			if (framesArray[jj] == pagesArray[ii]) {
				flag_1 = flag_2 = 1;
				hit++;
				break;
			}
		}
		//btshoof meen belnegative
		if (flag_1 == 0) {
			for (jj = 0; jj < frame_num; ++jj) {
				if (framesArray[jj] == -1) {
					
					framesArray[jj] = pagesArray[ii];
					numOffaults++;
					flag_2 = 1;

					break;
				}
			}
		}
		//optimal
		if (flag_2 == 0) {
			flag_3 = 0;
			for (jj = 0; jj < frame_num; ++jj) {
				temp[jj] = -1;
				for (kk = ii + 1; kk < page_num; ++kk) {
					if (framesArray[jj] == pagesArray[kk])
					{
						temp[jj] = kk;
						break;
					}
				}
			}
			//fcfs 
			for (jj = 0; jj < frame_num; ++jj) {
				if (temp[jj] == -1)
				{
					flag_3 = 1;

					position = jj;
					
					break;
				}

			}
			if (flag_3 == 0)
			{
				max = temp[0];
				position = 0;
				for (jj = 1; jj < frame_num; ++jj)
				{
					if (temp[jj] > max) {
						max = temp[jj];
						position = jj;

					}
				}
			}
			numOffaults++;
			framesArray[position] = pagesArray[ii];
			
		}

		cout << "\n";

		for (jj = 0; jj < frame_num; ++jj) {
			cout << framesArray[jj] << "\t";
		}
	}
	cout << "\n\nThe number of page faults = " << numOffaults;
	cout << "\nThe number of hits = " << hit;
	return 0;
    }
    else {
        cout << "Undefined name";
    }
}

