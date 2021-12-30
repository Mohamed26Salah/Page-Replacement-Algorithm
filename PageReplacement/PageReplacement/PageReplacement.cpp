

#include <iostream>
using namespace std;

int findLeastRecentlyUsed(int time[], int num) {
	int g, min = time[0], pos = 0;

	for (g = 1; g < num; ++g) {

		if (time[g] < min) {
			min = time[g];
			pos = g;
		}

	}
	return pos;
}
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
        int frame_num, page_num, frames[20], pages[50], counter = 0, time[20], flag_1, flag_2, i, j, pos, faults = 0, hit = 0;
        cout << "Enter the number of pages: ";
        cin >> page_num;

        cout << "Enter the reference string: ";
        for (i = 0; i < page_num; ++i) {
            cin >> pages[i];
        }

        cout << "Enter the number of frames: ";
        cin >> frame_num;

        //3by kolo be -1
        for (i = 0; i < frame_num; ++i) {
            frames[i] = -1;
        }
        //btlf 7waleen el reference string
        for (i = 0; i < page_num; ++i) {
            flag_1 = flag_2 = 0;
            //btshoof fe 7ad shbhaa wla l2
            for (j = 0; j < frame_num; ++j) {
                if (frames[j] == pages[i]) {
                    counter++;
                    time[j] = counter;
                    flag_1 = flag_2 = 1;
                    hit++;
                    break;
                }

            }
            //btshoof fe negative one wla l2
            if (flag_1 == 0) {
                for (j = 0; j < frame_num; ++j) {
                    if (frames[j] == -1) {
                        counter++;
                        faults++;
                        frames[j] = pages[i];
                        time[j] = counter;
                        flag_2 = 1;
                        break;
                    }
                }
            }
            //btshoof meen elvictim ely hytbdl
            if (flag_2 == 0) {
                pos = findLeastRecentlyUsed(time, frame_num);
                counter++;
                faults++;
                frames[pos] = pages[i];
                time[pos] = counter;
            }

            cout << "\n";
            // display the frames
            for (j = 0; j < frame_num; ++j) {
                cout << frames[j] << "\t";
            }
        }
        cout << "\n\nTotal Page Faults = " << faults;
        cout << "\nTotal number of hits = " << hit;
        return 0;
    }
    else if (name == "OPTIMAL") {
	int frame_num, page_num, frames[10], pages[30], hit = 0, temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
	cout << "Enter number of pages: ";
	cin >> page_num;
	cout << "Enter reference string: ";
	for (i = 0; i < page_num; ++i) {
		cin >> pages[i];
	}
	cout << "Enter number of frames: ";
	cin >> frame_num;
	//bt7ot kolo bel negative
	for (i = 0; i < frame_num; ++i) {
		frames[i] = -1;
	}
	//btshoof el7agat elshbah b3d
	for (i = 0; i < page_num; ++i) {
		flag1 = flag2 = 0;

		for (j = 0; j < frame_num; ++j) {
			if (frames[j] == pages[i]) {
				flag1 = flag2 = 1;
				hit++;
				break;
			}
		}
		//btshoof meen belnegative
		if (flag1 == 0) {
			for (j = 0; j < frame_num; ++j) {
				if (frames[j] == -1) {
					faults++;
					frames[j] = pages[i];
					flag2 = 1;
					break;
				}
			}
		}
		//optimal
		if (flag2 == 0) {
			flag3 = 0;
			for (j = 0; j < frame_num; ++j) {
				temp[j] = -1;
				for (k = i + 1; k < page_num; ++k) {
					if (frames[j] == pages[k])
					{
						temp[j] = k;
						break;
					}
				}
			}
			//fcfs 
			for (j = 0; j < frame_num; ++j) {
				if (temp[j] == -1)
				{
					pos = j;
					flag3 = 1;
					break;
				}

			}
			if (flag3 == 0)
			{
				max = temp[0];
				pos = 0;
				for (j = 1; j < frame_num; ++j)
				{
					if (temp[j] > max) {
						max = temp[j];
						pos = j;

					}
				}
			}
			frames[pos] = pages[i];
			faults++;
		}

		cout << "\n";

		for (j = 0; j < frame_num; ++j) {
			cout << frames[j] << "\t";
		}
	}
	cout << "\n\nTotal Page Faults = " << faults;
	cout << "\n The number of hits = " << hit;
	return 0;
    }
    else {
        cout << "Undefined name";
    }
}

