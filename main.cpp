#include <iostream>

using namespace std;

struct f {
	int numarator;
	int numitor;
};

bool is_Prim(int a) {
	if(a<2)
		return false;
	if(a==2)
		return true;
	for(int i=2;i*i<a;i++) {
		if(a%i==0)
			return false;
	
	}
	return true;
}

int cmmdc(int a, int b) {
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}

int cmmmc(int a, int b) {
	return a*b/cmmdc(a,b);
}

void simplifica(f &a) {
	int factor_simplificare = cmmdc(a.numarator, a.numitor);
	if(is_Prim(a.numitor)) {
		return;
	}
	else {
		a.numitor /= factor_simplificare;
		a.numarator /= factor_simplificare;
		simplifica(a);
	}
}

f aduna(f f1, f f2, f &f3) {
	if(f1.numitor==f2.numitor) {
		f3.numitor= f2.numitor;
		f3.numarator= f2.numarator + f1.numarator;
		simplifica(f3);
		return f3;
	}


		int factor_inmultire = cmmmc(f1.numitor, f2.numitor);
		f3.numitor = factor_inmultire;
		f3.numarator = f1.numarator*(factor_inmultire/f1.numitor) + f2.numarator*(factor_inmultire/f2.numitor);
		simplifica(f3);
		return f3;


}

f scade(f f1, f f2, f f3) {
	if(f1.numitor==f2.numitor) {
		f3.numitor= f2.numitor;
		f3.numarator= f2.numarator - f1.numarator;
		simplifica(f3);
		return f3;
	}


		int factor_inmultire = cmmmc(f1.numitor, f2.numitor);
		f3.numitor = factor_inmultire;
		f3.numarator = f1.numarator*(factor_inmultire/f1.numitor) - f2.numarator*(factor_inmultire/f2.numitor);
		simplifica(f3);
		return f3;
}

f produs(f f1, f f2, f f3) {
	f3.numarator = f1.numarator * f2.numarator;
	f3.numitor = f1.numitor * f2.numitor;
	simplifica(f3);
	return f3;
}

f impart(f f1, f f2, f f3) {
	f3.numarator = f1.numarator * f2.numitor;
	f3.numarator = f1.numitor * f2.numarator;
	simplifica(f3);
	return f3;
}

int compar(f f1, f f2) {
	int factor_inmultire = cmmmc(f1.numitor, f2.numitor);
	f1.numitor *= factor_inmultire;
	f1.numarator *= factor_inmultire;
	f2.numarator *= factor_inmultire;
	f2.numitor *= factor_inmultire;
	if(f1.numarator>f2.numarator) 
		return 1;
	if(f1.numarator<f2.numarator)
		return -1;
	if(f1.numarator==f2.numarator)
		return 0;
}

int sortare(int n, f F[]) { 
    int i, j;  
    for (i = 0; i < n-1; i++)      
    for (j = 0; j < n-i-1; j++)  
      if (compar(F[j],F[j+1])==1)  
        swap(F[j], F[j+1]);  
}

void afisareFractie(f f1) {
	cout<<f1.numarator<<"/"<<f1.numitor;
}

int main() {
  


}