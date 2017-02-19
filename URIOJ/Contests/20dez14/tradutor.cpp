#include <cstdio>
#include <cstring>
#define MAX 220

const char* langs[24] = {
	"brasil", "alemanha", "austria", "coreia", 
	"espanha", "grecia", "estados-unidos", "inglaterra", 
	"australia", "portugal", "suecia", "turquia",
	"argentina", "chile", "mexico", "antardida", 
	"canada", "irlanda", "belgica", "italia",
	"libia", "siria", "marrocos", "japao"
};

const char* ola[24] = {
	"Feliz Natal!", "Frohliche Weihnachten!",
	"Frohe Weihnacht!", "Chuk Sung Tan!",
	"Feliz Navidad!", "Kala Christougena!",
	"Merry Christmas!", "Merry Christmas!",
	"Merry Christmas!", "Feliz Natal!",
	"God Jul!", "Mutlu Noeller",
	"Feliz Navidad!", "Feliz Navidad!",
	"Feliz Navidad!", "Merry Christmas!",
	"Merry Christmas!", "Nollaig Shona Dhuit!",
	"Zalig Kerstfeest!", "Buon Natale!",
	"Buon Natale!", "Milad Mubarak!",
	"Milad Mubarak!", "Merii Kurisumasu!",
};

int main(){
	int flag, i;
	char s[MAX];
	while(scanf("%s", s)!=EOF){
		flag=1;
		for(i=0; i<24; i++){
			if(strcmp(s, langs[i])==0){ flag=0;
				puts(ola[i]); break; }
		}
		if(flag) puts("--- NOT FOUND ---");
	}
	return 0;
}
