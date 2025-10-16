char c = '1', *pc = 0;
const char cc = 'a';
const char* pcc = 0;
char* const cpc = &c;
const char* const cpcc = &cc;
char* const *pcpc;
char* const* const pccp = &cpc;

// void f() {
// c = cc; //1
// cc = c; //2
// pcc = &c; //3
// pcc = &cc; //4
// pc = &c; //5
// pc = &cc; //6
// pc = pcc; //7
// pc = cpcc; //8
// cpcc = pc; //9
// *pc = "ABCD"[2]; //10
// cc = a; //11
// *cpcc = *pc; //12
// pc = *pcpc; //13
// **pcpc = *pc; //14
// *pc = **pcpc; //15
// *pcc = 'b'; //16
// *pcpc = 'c'; //17
// *cpcc = 'd'; //18
// *pcpc = pc; //19
// pcpc = &cpc; //20
// pccp = &cpc; //21
// }
