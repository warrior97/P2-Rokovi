#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Covek
{
	int A, B;
	unsigned int poruka : 1;
};
int Ucitaj(Covek *niz)
{
	int n = 0;
	printf("unesi broj osoba:");
	scanf("%d", &n);
	if (n > MAX && n < 0)
		return -1;
	for (int i = 0; i < n; i++)
	{
		printf("Unesi prijatelja za osobu %d: ",i);
		scanf("%d %d", &niz[i].A, &niz[i].B);
	}
	for(int i=0;i<n;i++)
	{
		if (niz[i].A > -1)
		{
			if (niz[niz[i].A].A != i && niz[niz[i].A].B != i)
				return -1;
		}
		else if(niz[i].B > -1)
		{
			if (niz[niz[i].B].A != i && niz[niz[i].B].B != i)
				return -1;
		}
	}

	return n;
}
int IzaberiOsobu(Covek *niz,int n)
{
	int num;
	printf("Izaberi osobu od poverenja:");
	scanf("%d", &num);
	if (num<n && num>-1)
	{
		niz[num].poruka = 1;
		return num;
	}
	else return -1;
}
void Prosledi(Covek *niz, int num)
{
	niz[num].poruka = 1;
	if (niz[num].A != -1)
		if(niz[niz[num].A].poruka == 0)
		Prosledi(niz, niz[num].A);
	if(niz[num].B != -1)
		if(niz[niz[num].B].poruka == 0)
		Prosledi(niz, niz[num].B);
		
}
void Print(Covek *niz, int n)
{
	for (int i = 0; i < n; i++)
	{
		if(niz[i].poruka==0)
			printf("Ne dobija %d \n", i);
	}
}
void main()
{
	Covek niz[MAX];
	int n;
	if ((n = Ucitaj(niz)) == -1)
	{
		printf("Error1");
		exit(0);
	}
	int num;
	if ((num=IzaberiOsobu(niz,n)) ==-1)
	{
		printf("Error2");
		exit(0);
	}
	Prosledi(niz, num);
	Print(niz, n);
	system("pause");

}