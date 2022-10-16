#include <stdio.h>
#include <stdlib.h>


struct game
{
    char name[50];
    double rating;
};

typedef struct game Game;


int main()
{
    int n;
	scanf("%i", &n);

	Game* g = (Game*)malloc(n * sizeof(Game));

	for (int i = 0; i < n; ++i) {
		scanf("%[^:]", g[i].name);

		int k;
		scanf(":%i", &k);

		double sum = 0;

		for (int j = 0; j < k; ++j) {
			int temp;
			scanf("%i", &temp);
			sum += temp;
		}

		g[i].rating = sum / k;
	}

    double mid_ratings = 0;

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n - 1 - j; i += 1)
        {
            if (g[i].rating < g[i + 1].rating)
            {
                Game temp = g[i];
                g[i] = g[i + 1];
                g[i + 1] = temp;
            }
        }
        mid_ratings += g[j].rating;
    }

    for (int i = 0; i < n; i++)
        printf("%s: %.3lf\n", g[i].name, g[i].rating);

    printf("\nMedian rating: %.3lf\n", mid_ratings / n);
    
    free(g);
}