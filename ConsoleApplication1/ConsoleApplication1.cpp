// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//koppenclimate
//climate classifer

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
	float a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, ll;
	//input values
	cout << "Mean January max (in dC): ";
	cin >> a;
	cout << "Mean February max: ";
	cin >> b;
	cout << "Mean March max: ";
	cin >> c;
	cout << "Mean April max: ";
	cin >> d;
	cout << "Mean May max: ";
	cin >> e;
	cout << "Mean June max: ";
	cin >> f;
	cout << "Mean July max: ";
	cin >> g;
	cout << "Mean August max: ";
	cin >> h;
	cout << "Mean September max: ";
	cin >> i;
	cout << "Mean October max: ";
	cin >> j;
	cout << "Mean November max: ";
	cin >> k;
	cout << "Mean December max: ";
	cin >> l;
	cout << "Mean January min: ";
	cin >> m;
	cout << "Mean February min: ";
	cin >> n;
	cout << "Mean March min: ";
	cin >> o;
	cout << "Mean April min: ";
	cin >> p;
	cout << "Mean May min: ";
	cin >> q;
	cout << "Mean June min: ";
	cin >> r;
	cout << "Mean July min: ";
	cin >> s;
	cout << "Mean August min: ";
	cin >> t;
	cout << "Mean Septmeber min: ";
	cin >> u;
	cout << "Mean October min: ";
	cin >> v;
	cout << "Mean November min: ";
	cin >> w;
	cout << "Mean December min: ";
	cin >> x;

	cout << "Mean January precipitation (in mm): ";
	cin >> aa;
	cout << "Mean February precipitation: ";
	cin >> bb;
	cout << "Mean March precipitation: ";
	cin >> cc;
	cout << "Mean April precipitation: ";
	cin >> dd;
	cout << "Mean May precipitation: ";
	cin >> ee;
	cout << "Mean June precipitation: ";
	cin >> ff;
	cout << "Mean July precipitation: ";
	cin >> gg;
	cout << "Mean August precipitation: ";
	cin >> hh;
	cout << "Mean September precipitation: ";
	cin >> ii;
	cout << "Mean October precipitation: ";
	cin >> jj;
	cout << "Mean November precipitation: ";
	cin >> kk;
	cout << "Mean December precipitation: ";
	cin >> ll;

	float alt, delta, nors;
	cout << "Height above sea level (nearest m): ";
	cin >> alt;
	delta = alt / 1000 * 6.4;
	cout << "Northern or Southern hemisphere location (N=0, S=1): ";
	cin >> nors;
	cout << "All data entered"<<endl;

	float y[12] = { a,b,c,d,e,f,g,h,i,j,k,l }; //temp max
	float z[12] = { m,n,o,p,q,r,s,t,u,v,w,x }; //temp min
	float yy[12] = { aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll }; //rainfall

	int A = 0, B = 0, C = 0, D = 0, E = 0, Af = 0, Am = 0, Aw = 0, As = 0, BW = 0, BS = 0, Bh = 0, Bk = 0, Bhw = 0, Bhs = 0, Bhf = 0, Bnc = 0, Bkw = 0, Bks = 0, Bkf = 0, Cf = 0, Cw = 0, Cs = 0, Da = 0, Db = 0, Dc = 0, Dd = 0, ET = 0, EF = 0, Ef = 0, Ew = 0, Es = 0, Enc = 0;

	//averages
	int zz = 0, aaa = 0, bbb = 0;
	float avtmx = 0; //average max temp 
	float avtmn = 0; //average min temp
	float avr = 0; //average rainfall

	while (zz<11.1)
	{
		avtmx = avtmx + y[zz];
		zz++;
	}
	avtmx = avtmx / 12.0;
	while (aaa<11.1)
	{
		avtmn = avtmn + z[aaa];
		aaa++;
	}
	avtmn = avtmn / 12.0;
	while (bbb<11.1)
	{
		avr = avr + z[bbb];
		bbb++;
	}
	avr = avr / 12.0;
	float avt = (avtmx + avtmn) / 2.0; //average temp
	float avmt[12] = { (y[0] + z[0]) / 2.0,(y[1] + z[1]) / 2.0,(y[2] + z[2]) / 2.0,(y[3] + z[3]) / 2.0,(y[4] + z[4]) / 2.0,(y[5] + z[5]) / 2.0,(y[6] + z[6]) / 2.0,(y[7] + z[7]) / 2.0,(y[8] + z[8]) / 2.0,(y[9] + z[9]) / 2.0,(y[10] + z[10]) / 2.0,(y[11] + z[11]) / 2.0 }; //average monthly temp
	//cout << avmt[0] << " " << avmt[1] << " " << avmt[2] << " " << avmt[3] << " " << avmt[4] << " " << avmt[5] << " " << avmt[6] << " " << avmt[7] << " " << avmt[8] << " " << avmt[9] << " " << avmt[10] << " " << avmt[11] << endl;
	float mnr, mxr, totr, mnavt, mxavt, mon, sh, sl;
	mnr = *min_element(yy, yy + 12); //min rainfall
	mxr = *max_element(yy, yy + 12); //max rainfall
	totr = 0; //total rainfall
	int co;
	for (co = 0; co<12; co++)
	{
		totr = totr + yy[co];
	}
	mnavt = *min_element(avmt, avmt + 12); //min average monthly temperature
	mxavt = *max_element(avmt, avmt + 12); //max average monthly temperature
	mon = 100 - totr / 25.0; //monsoon
	sh = yy[3] + yy[4] + yy[5] + yy[6] + yy[7] + yy[8]; //sun high rain
	sl = yy[0] + yy[1] + yy[2] + yy[9] + yy[10] + yy[11]; //sun low rain
	float shr[6] = { yy[3],yy[4],yy[5],yy[6],yy[7],yy[8] }; //sun high / summer
	float slr[6] = { yy[0],yy[1],yy[2],yy[9],yy[10],yy[11] }; //sun low / winter
	float tt;
	float ttt[6];
	//int s, w;
	s = 0; w = 0;
	if (nors == 1) //north/south swap
	{
		tt = sh;
		sl == tt;
		tt = 0;
		ttt[0] = shr[0]; ttt[1] = shr[1]; ttt[2] = shr[2]; ttt[3] = shr[3]; ttt[4] = shr[4]; ttt[5] = shr[5];
		shr[0] = slr[0]; shr[1] = slr[1]; shr[2] = slr[2]; shr[3] = slr[3]; shr[4] = slr[4]; shr[5] = slr[5];
		slr[0] = ttt[0]; slr[1] = ttt[1]; slr[2] = ttt[2]; slr[3] = ttt[3]; slr[4] = ttt[4]; slr[5] = ttt[5];
		ttt[0] = 0; ttt[1] = 0; ttt[2] = 0; ttt[3] = 0; ttt[4] = 0; ttt[5] = 0;
	}
	else
	{
		tt = 0;
		ttt[0] = 0; ttt[1] = 0; ttt[2] = 0; ttt[3] = 0; ttt[4] = 0; ttt[5] = 0;
	}
	if (mnr == *min_element(shr, shr + 6)) { s = 1; }
	else
	if (mnr == *min_element(slr, slr + 6)) { w = 1; }
	else { w = 0; s = 0; }
	vector <float> mn10; //inital for months of 10dC or more
	int ab;
	for (ab = 0; ab<12; ab++)
	{
		if (avmt[ab]>10) { mn10.push_back(avmt[ab]); }
	}
	int mn10n = mn10.size();
	float mxsr, mxwr, mnsr, mnwr;
	mxsr = *max_element(shr, shr + 6);
	mxwr = *max_element(slr, slr + 6);
	mnsr = *min_element(shr, shr + 6);
	mnwr = *min_element(slr, slr + 6);
	int mr60 = 0;
	for (co = 0; co<12; co++)
	{
		if (yy[co]<60) { mr60 = mr60 + 1; }
		else { mr60 = mr60; }
	}
	//potential evapourtraspiration test
	cout << " " << endl;
	int etf = 0; //evapourtraspiration factor
	float rf = sh / totr; //sun high rain fraction
	if (rf >= 0.7) { etf = 280; }
	else
	if (rf>30 && rf<70) { etf = 140; }
	else
	if (rf <= 30) { etf = 0; }
	else { cout << "er1" << endl; }
	float pet = 20 * avt + etf;
	cout << "Potential evapouration: " << pet << " mm" << endl;
	cout << "Actual precipitation: " << totr << " mm" << endl;
	if (totr<(0.5*pet)) //desert
	{
		BW = 1;
		cout << "Desert test passed: precipitation is less than 1/2 the potential evapouration" << endl;
		B = 1;
	}
	else
	if (totr >= (0.5*pet) && totr<pet) //steppe
	{
		BS = 1;
		cout << "Steppe test passed: precipitation is less than the potential evapouration, but more than 1/2 the potential evapouration" << endl;
		B = 1;
	}
	else
	{
		BW = 0;
		BS = 0;
	}
	//temperature test
	if (BW == 0 && BS == 0)
	{
		if (mnavt >= 18)
		{
			A = 1;
			cout << "Tropical temperature test passed: min monthley average temperature " << mnavt << " dC is greater or equal to 18 dC" << endl;
		}
		else
		if (mxavt<10)
		{
			E = 1;
			cout << "Polar temperature test passed: max monthley average temperature " << mxavt << " dC is less than 10 dC" << endl;
		}
		else
			if (mxavt >= 10 && mnavt < 18)
			{
				cout << "Temperate temperature test passed: min monthley average temperature " << mnavt << " dC is less than 18 dC and the max average temperature " << mxavt << " dC is greater than or equal to 10 dC" << endl;
				if (mnavt > -3) //can be 0dC
				{
					C = 1;
					cout << "Coastal temperature test passed: min monthley average temperature " << mnavt << " dC is greater than -3 dC" << endl;
				}
				else
					if (mnavt <= -3) //cane be 0dC
					{
						D = 1;
						cout << "Continential temperature test passed: min monthley average temperature " << mnavt << " dC is less than or equal to -3 dC" << endl;
					}
					else { cout << "er2" << endl; }
			}
		else { cout << "er3" << endl; }
	}
	//temperature heat test
	if (A == 1) { A = 1; }
	else
	if (B == 1)
	{
		if (avt<18) //can be 0dC
		{
			Bk = 1;
			cout << "Cold arid test passed: average temperature " << avt << " dC is less than 18 dC" << endl;
		}
		else
		{
			Bh = 1;
			cout << "Hot arid test passed: average temperature " << avt << " dC is greater or equal to 18 dC" << endl;
		}
	}
	else
	if (C == 1 || D == 1)
	{
		if (mxavt>22 && mn10n>3)
		{
			Da = 1;
			cout << "Sub tropical degree of heat test passed: max average temperature " << mxavt << " dC is greater than or equal to 22 dC and " << mn10n << " months are greater than the 10 dC average monthly and greater than or equal to the 4 months required" << endl;
		}
		else
		if (mxavt<22 && mn10n>3)
		{
			Db = 1;
			cout << "Warm degree of heat test passed: max monthley average temperature " << mxavt << " dC is less than 22 dC and " << mn10n << " months are greater than the 10 dC average monthly temperature and greater than or equal to the 4 months required" << endl;
		}
		else
		if (mn10n<4)
		{
			Dc = 1;
			cout << "Cold degree of heat test passed: max monthley average temperature " << mxavt << " dC is less than 22 dC and " << mn10n << " months are greater than the 10 dC average monthly temperature and less than or equal to the 3 months required" << endl;
		}
		else { cout << "er4" << endl; }
		if (mnavt<-38)
		{
			Dd = 1;
			Da = 0;
			Db = 0;
			Dc = 0;
			cout << "Extreme cold degree of heat passed: min monthley average temperature " << mnavt << " dC is less than -38 dC" << endl;
		}
	}
	else
	if (E == 1)
	{
		if (mxavt>0)
		{
			ET = 1;
			cout << "Polar tundra test passed: max monthley average temperature " << mxavt << " dC is greater than 0 dC" << endl;
		}
		else
		if (mxavt <= 0)
		{
			EF = 1;
			cout << "Polar ice cap test passed: max monthley average temperature " << mxavt << " dC is less than or equal to 0 dC" << endl;
		}
		else { cout << "er5" << endl; }
	}
	//rainfall test
	if (A == 1)
	{
		if (mnr > 60)
		{
			Af = 1;
			cout << "Even and required precipitation test passed: greater than of equal to 60 mm of rain a month, with the min monthly rainfall of " << mnr << " mm" << endl;
		}
		else
		if (mnr < 60 && mnr >= mon)
		{
			Am = 1;
			cout << "Monsoonal precipitation test passed: there are " << mnr << " mm with precipitation less than 60 mm and the min monthley rainfall of " << mnr << " mm that is greater than or equal to the " << mon << " mm monsonal limit" << endl;
		}
		else
		if (mnr < 60 && mnr < mon)
		{
			if (w == 1)
			{
				Aw = 1;
				cout << "Wet + dry precipitation test passed: there are " << mr60 << " month  with precipitation less than 60 mm and the min monthley rainfall of " << mnr << " mm that is less than the " << mon << " mm monsonal limit" << endl;
				cout << "Winter dry peciputation test passed: winter precipitation of " << sl << " mm is less than summer precipitation of " << sh << " mm, with " << rf * 100 << "% of the precipitation in the summer" << endl;
			}
			else
			if (s == 1)
			{
				As = 1;
				cout << "Wet + dry precipitation test passed: there are " << mr60 << " month with precipitation less than 60 mm and the min monthley rainfall of " << mnr << " mm that is less than the " << mon << " mm monsonal limit" << endl;
				cout << "Summer dry peciputation test passed: winter precipitation of " << sl << " mm is greater than summer precipitation of " << sh << " mm, with " << rf * 100 << "% of the precipitation in the summer" << endl;
			}
			else { cout << "er6" << endl; }
		}
		else { cout << "er7" << endl; }
	}
	else
	if (B == 1)
	{
		if (Bh == 1) //pos modification
		{
			if (mxr >= 60 && rf > 0.7)
			{
				Bhw = 1;
				cout << "Winter dry pecipitation test passed: winter precipitation of " << sl << " mm is less than summer precipitation of " << sh << " mm, with " << rf * 100 << "% of the precipitation in the summer and the max precipitation of " << mxr << " mm is greater than 60 mm and rain fraction greater than or equal to 70%" << endl;
			}
			else
			if (mxr >= 60 && rf <= 0.3)
			{
				Bhs = 1;
				cout << "Summer dry pecipitation test passed: winter precipitation of " << sl << " mm is greater than summer precipitation of " << sh << " mm, with " << rf * 100 << "% of the precipitation in the summer and the max precipitation of " << mxr << " mm is greater than 60 mm and rain fraction less than or equal to 30%" << endl;
			}
			else
			if (mxr >= 60)
			{
				Bhf = 1;
				cout << "Even and required precipitation test passed: there was " << rf * 100 << "% of the precipitation in the summer, which is between the 30-70% required and the max precipitation of " << mxr << " mm is greater than 60 mm" << endl;
			}
			else
			{
				Bnc = 1;
				cout << "Precipitation test failed : the max rainfall " << mxr << " is less than 60 mm" << endl;
			}
		}
		else
		if (Bk == 1) //pos mod
		{
			if (mxr >= 30 && rf >= 0.7)
			{
				Bkw = 1;
				cout << "Winter dry pecipitation test passed: winter precipitation of " << sl << " mm is less than summer precipitation of " << sh << " mm, with " << rf * 100 << "% of the precipitation in the summer and the max precipitation of " << mxr << " mm is greater than 30 mm and rain fraction greater than or equal to 70%" << endl;
			}
			else 
			if (mxr>=30 && rf<=0.3)
			{
				Bks = 1;
				cout << "Summer dry pecipitation test passed: winter precipitation of " << sl << " mm is greater than summer precipitation of " << sh << " mm, with " << rf * 100 << "% of the precipitation in the summer and the max precipitation of " << mxr << " mm is greater than 30 mm and rain fraction less than or equal to 30%" << endl;
			}
			else
			if (mxr >= 30)
			{
				Bkf = 1;
				cout << "Even and required precipitation test passed: there was " << rf * 100 << "% of the precipitation in the summer, which is between the 30-70% required and the max precipitation of " << mxr << " mm is greater than 30 mm" << endl;
			}
			else
			{
				Bnc = 1;
				cout << "Precipitation test failed: the max precipitation " << mxr << " mm is less than 30 mm" << endl;
			}
		}
	}
	else
	if (C == 1 || D == 1)
	{
		if (s == 1 && mnsr < (1 / 3.0*mxwr) && mnsr < 30) //30mm min
		{
			Cs = 1;
			cout << "Summer dry pecipitation test passed: the driest summer precipitation of " << mnsr << " mm is less than x1/3 the wettest winter precipitation of " << mxwr << " mm, with " << rf * 100 << "% of the precipitation in the summer and the min summer precipitation of " << mnsr << " mm is less than 30 mm" << endl;
		}
		else
		if (w == 1 && mnwr < (1 / 10.0*mxsr) && mnwr < 30) //30mm min
		{
			Cw = 1;
			cout << "Winter dry pecipitation test passed: the driest winter precipitation of " << mnwr << " mm is x1/10 less than the wettest summer precipitation of " << mxsr << " mm, with " << rf * 100 << "% of the precipitation in the summer and the min winter precipitation of " << mnwr <<  "mm is less than 30 mm" << endl;
		}
		else
		{
			Cf = 1;
			cout << "Even precipitation test passed: the driest winter precipitation of " << mnwr << " mm is not less than the wettest summer precipitation threshold of " << 1 / 10.0 * mxsr << " mm and the driest summer precipitation of " << mnsr << " mm is not less than the westtest winter precipitation threshold of " << 1 / 3.0 * mxwr << " mm or all months rainfall are greater than 30 mm" << endl;
		}
	}
	else
	if (E == 1)
	{
		if (mxr >= 30)
		{
			if (s == 1 && mnsr < (1 / 3.0*mxwr)) //30mm min
			{
				Es = 1;
				cout << "Summer dry pecipitation test passed: the driest summer precipitation of " << mnsr << " mm is less than x1/3 the wettest winter precipitation of " << mxwr << " mm, with " << rf * 100 << "% of the precipitation in the summer and the min summer precipitation of " << mnsr << " mm is less than 30 mm" << endl;
			}
			else
				if (w == 1 && mnwr < (1 / 10.0*mxsr))
				{
					Ew = 1;
					cout << "Winter dry pecipitation test passed: the driest winter precipitation of " << mnwr << " mm is x1/10 less than the wettest summer precipitation of " << mxsr << " mm, with " << rf * 100 << "% of the precipitation in the summer and the min winter precipitation of " << mnwr << " mm is less than 30 mm" << endl;
				}
				else
				{
					Ef = 1;
					cout << "Even precipitation test passed: the driest winter precipitation of " << mnwr << " mm is not less than the wettest summer precipitation threshold of " << 1 / 10 * mxsr << " mm and the driest summer precipitation of " << mnsr << " mm is not less than the westtest winter precipitation threshold of " << 1 / 3 * mxwr << " mm or all months rainfall are greater than 30 mm" << endl;
				}
		}
		else 
		{
			Enc = 1;
			cout << "Precipitation test failed: the max precipitation " << mxr << " mm is less than 30 mm" << endl;
		}
	}
	else
	{
		cout << "er8" << endl;
	}
	//classification
	int v1[5] = { A * 1,B * 2,C * 3,D * 4,E * 5 };
	int vA[4] = { Af * 1,Am * 2,Aw * 3,As * 4 };
	int vB[2] = { BW * 1, BS * 2 };
	int vB2[2] = { Bh * 1, Bk * 2 };
	int vB3[7] = { Bhw * 1, Bhs * 2, Bhf * 3, Bnc * 4, Bkw * 5, Bks * 6, Bkf * 7 };
	int vC[3] = { Cf * 1, Cw * 2, Cs * 3 };
	int vD[4] = { Da * 1, Db * 2, Dc * 3, Dd * 4 };
	int vE[2] = { ET * 1, EF * 2 };
	int vE2[4] = { Ef * 1, Ew * 2, Es * 3, Enc * 4 };
	unordered_map<int, string> v1dic = { {1,"A"},{2,"B"},{3,"C"},{4,"D"},{5,"E"} };
	unordered_map<int, string> vAdic = { {1,"f"},{2,"m"},{3,"w"},{4,"s"} };
	unordered_map<int, string> vBdic = { {1,"W"},{2,"S"} };
	unordered_map<int, string> vB2dic = { {1,"h"},{2,"k"} };
	unordered_map<int, string> vB3dic = { {1,"w"},{2,"s"},{3,"f"},{4,"n"},{5,"w"},{6,"s"},{7,"f"} };
	unordered_map<int, string> vCdic = { {1,"f" },{ 2,"w" },{ 3,"s"} };
	unordered_map<int, string> vDdic = { {1,"a"},{2,"b"},{3,"c"},{4,"d"} };
	unordered_map<int, string> vEdic = { {1,"T"},{2,"F"} };
	unordered_map<int, string> vE2dic = { {1,"f"},{2,"w"},{3,"s"},{4,"n"} };
	//classification combo
	vector <string> combo;
	string ct;
	if (*max_element(v1, v1 + 5) == 1)
	{
		combo.push_back(v1dic[*max_element(v1, v1 + 5)]);
		combo.push_back(vAdic[*max_element(vA, vA + 4)]);
		ct = combo.at(0) + combo.at(1);
	}
	else if (*max_element(v1, v1 + 5) == 2)
	{
		combo.push_back(v1dic[*max_element(v1, v1 + 5)]);
		combo.push_back(vBdic[*max_element(vB, vB + 2)]);
		combo.push_back(vB2dic[*max_element(vB2, vB2 + 2)]);
		combo.push_back(vB3dic[*max_element(vB3, vB3 + 7)]);
		ct = combo.at(0) + combo.at(1) + combo.at(2) + combo.at(3);
	}
	else if (*max_element(v1, v1 + 5) == 3 || *max_element(v1, v1 + 5) == 4)
	{
		combo.push_back(v1dic[*max_element(v1, v1 + 5)]);
		combo.push_back(vCdic[*max_element(vC, vC + 3)]);
		combo.push_back(vDdic[*max_element(vD, vD + 4)]);
		ct = combo.at(0) + combo.at(1) + combo.at(2);
	}
	else if (*max_element(v1, v1 + 5) == 5)
	{
		combo.push_back(v1dic[*max_element(v1, v1 + 5)]);
		combo.push_back(vEdic[*max_element(vE, vE + 2)]);
		combo.push_back(vE2dic[*max_element(vE2, vE2 + 4)]);
		ct = combo.at(0) + combo.at(1) + combo.at(2);
	}
	else { cout << "er: no class" << endl; }
	//plot
	//
	cout << "Climate type: " << ct << endl;

	int close;
	cout << "Enter any number to close";
	cin >> close;
	cout << "0" <<endl;

    return 0;
}

//A: >= 18dC, f : >= 60mm each month, m : 1 month <60mm and >100 - tot / 25, w / s : 1 month <60mm and <100 - tot / 25 (summer is apr - sep, winter is oct - mar)
//B : 20 * average_temperature + (280 for >0.7 rain in summer, 140 for 0.3 - 0.7, 0 for <0.3 rain in summer), BW : rain<0.5, BS : [<]1 - 0.5, h : avT >= 18dC or clodest month >0dC, k:avT<18dC or coldest month <= 0dC, w / s : >60mm for >= 18dC, >30mm for <18dC and 0.7 rain in that 1 / 2 of year
//C : avT >10dC in summer, coldest month >= -3dC or >0dC, w : driest month < 1 / 10 wettest summer month(and <30mm), s : driest month < 1 / 3 wettest month(and <30mm), f : neither, a : warmest month >= 22dC, b : warmest month <22dC + 4 months >10dC, c : <4 month >10dC(la)
//D : avT >10dC in summer, coldest month <-3dC or <=0dC, others same, d: <4 months >10dC + coldest month <-38dC
//E : all months <= 10dC, T : warmest month 0 - 10dC, F : all months <0dC, w / s / f >30mm in wettest + C / D useage