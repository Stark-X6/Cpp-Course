int i = 1024;
const int ci = 1024;
double d = 3.14;
int f(int x) { return x; }
int& g(int& x) { return x; }

// int& ri_1 = i; //1
// int& ri_2 = ci; //2
// int& ri_3 = d; //3
// int& ri_4 = i * 2; //4
// int& ri_5; //5
// int& ri_6 = i++; //6
// int& ri_7 = --i; //7
// int& ri_8 = f(i); //8
// int& ri_9 = g(i); //9
// const int& cri_1 = i; //10
// const int& cri_2 = 1; //11
// const int& cri_3 = d; //12
// const int& cri_4 = 3.14; //13
// const int& cri_5 = f(); //14
// int& &rri_1 = 1; //15
// int& *pri; //16
// int&& rri_2 = 1; //17
// int&& rri_3 = i; //18
// int&& rri_4 = f(i); //19
// int&& rii_5 = rri_4; //20
// int& ri_10 = rri_4; //21