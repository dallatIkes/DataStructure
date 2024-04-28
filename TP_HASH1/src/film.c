#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>

#include "film.h"
#include "complexite.h"


enum {
	TCONST,
	TITLETYPE,
	PRIMARYTITLE,
	ORIGINALTITLE,
	ISADULT,
	STARTYEAR,
	ENDYEAR,
	RUNTIMEMINUTES,
	GENRES
};


t_film* creer_film(char* data)
{
	t_film* pt_film = (t_film*)allouer(sizeof(t_film));
	if (pt_film!=NULL)
	{
		//"tconst\ttitleType\tprimaryTitle\toriginalTitle\tisAdult\tstartYear\tendYear\truntimeMinutes\tgenres"
#ifdef DEBUG
		printf("------------\n");
		printf("%s:%d %s\n", __func__, __LINE__, data);
#endif

		int i=0;
		char * token = strtok(data,"\t");
		while (token !=NULL)
		{
			size_t l=strlen(token);

			switch(i)
			{
				case TCONST:
				  pt_film->num = atoi(&token[2]);
					break;
				case TITLETYPE:
					break;
				case PRIMARYTITLE:
					pt_film->titre = (char*)allouer((l+1)*sizeof(char));
					assert(pt_film->titre!=NULL);
					memcpy(pt_film->titre, token, l+1);
					break;
				case ORIGINALTITLE:
					break;
				case ISADULT:
					break;
				case STARTYEAR:
					pt_film->annee = atoi(token);
					break;
				case ENDYEAR:
					break;
				case RUNTIMEMINUTES:
					break;
				case GENRES:
					break;
				default:
#if DEBUG
					printf("%s:%d cas default non traité\n", __func__, __LINE__);
#endif
					break;
			}

			i=i+1;
			token = strtok(NULL,"\t");
		}

#if DEBUG
		printf("%s:%d nombre variables lues : %d/%d\n", __func__, __LINE__, i, GENRES+1);
		printf("------------\n");
#endif
		if (i!=GENRES+1) {
			liberer_film(pt_film);
			return NULL;
		}

	}
	return pt_film;
}

void liberer_film(t_film *pt_film)
{
	free(pt_film->titre);
	free(pt_film);
}

char* titre_film(t_film* pt_film)
{
	return pt_film->titre;
}

int annee_film(t_film* pt_film)
{
	return pt_film->annee;
}

void afficher_film(t_film *pt_film)
{
	printf("%d %s (%d)\n", pt_film->num, pt_film->titre, pt_film->annee);
}

bool equals(t_film f1, t_film f2)
{
	return(
		annee_film(&f1)==annee_film(&f2)&&
		!((bool)strcmp(titre_film(&f1), titre_film(&f2)))
	);
}
