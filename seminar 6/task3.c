#include <stdio.h>
#include <string.h>


struct date
{
    int day, month, year;
};
typedef struct date Date;


struct address
{
    char country[10];
    char region[50];
    char city[30];
};
typedef struct address Address;


struct actor
{
    char name[32];
    char surname[32];
    int gender; // пол: 0 - мужской, 1 - женский
    int height;
    Date birth_date;
    Address birth_address;
};
typedef struct actor Actor;


struct movie
{
    char title[50];
    Date release_date;
    double rating;

    // Будем хранить номера актеров из массива actors структуры типа MovieDatabase
    int crew_size;
    int crew[20];
};
typedef struct movie Movie;


struct movie_database
{
    int number_of_movies;
    Movie movies[5000];

    int number_of_actors;
    Actor actors[5000];
};
typedef struct movie_database MovieDatabase;

// Функция, которая печатает информацию об одном актере в поток stream
// stream может быть или файлом или stdout
void print_actor(FILE* stream, const Actor* a)
{
    fprintf(stream, "%10s %15s. Height: %d cm. Birth date: %02d/%02d/%d. Birth Address: %s, %s, %s\n", a->name, a->surname,
           a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
           a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

// Функция, которая печатает информацию об одном фильме в поток stream
// stream может быть или файлом или stdout
void print_movie(FILE* stream, const Movie* a)
{
    fprintf(stream, "%20s. Rating: %.3lf. Release date: %02d/%02d/%d.\n", a->title, a->rating,
            a->release_date.day, a->release_date.month, a->release_date.year);
}

// Считывает актёров и возвращает их количество
// Главное чтобы массив actors был достаточно вместителен (иначе будет ошибка)
int read_actors_from_file(const char filename[], Actor actors[])
{
    FILE* fin = fopen(filename, "r");
    int number_of_actors;
    fscanf(fin, "%d", &number_of_actors);

    for (int i = 0; i < number_of_actors; ++i)
    {
        fscanf(fin, "%[^,],%[^,],%d,%d,%d/%d/%d,%[^,],%[^,],%[^\n]\n",
            actors[i].name, actors[i].surname, &actors[i].gender, &actors[i].height,
            &actors[i].birth_date.day, &actors[i].birth_date.month, &actors[i].birth_date.year, 
            actors[i].birth_address.country, actors[i].birth_address.region, actors[i].birth_address.city);
    }
    fclose(fin);
    return number_of_actors;
}

// Считывает фильмы и возвращает их количество
// Главное чтобы массив movies был достаточно вместителен (иначе будет ошибка)
int read_movies_from_file(const char filename[], Movie movies[])
{
    FILE* fin = fopen(filename, "r");
    int number_of_movies;
    fscanf(fin, "%d", &number_of_movies);
    for (int i = 0; i < number_of_movies; ++i)
    {
        
        fscanf(fin, "%[^,],%d/%d/%d,%lf,%d,", movies[i].title, &movies[i].release_date.day, 
            &movies[i].release_date.month, &movies[i].release_date.year, &movies[i].rating, &movies[i].crew_size);
        for (int j = 0; j < movies[i].crew_size; ++j)
        {
            fscanf(fin, "%d", &movies[i].crew[j]);
        }
    }
    fclose(fin);
    return number_of_movies;
}

// Считываем все данные из файлов в структуру типа MovieDatabase,
// которая содержится по адресу pmd (сокр. от Pointer to Movie Database)
void read_database(MovieDatabase* pmd, const char actors_file_name[], const char movies_file_name[])
{
    pmd->number_of_actors = read_actors_from_file(actors_file_name, pmd->actors);
    pmd->number_of_movies = read_movies_from_file(movies_file_name, pmd->movies);
}

// Печатает информацию о фильме под номером movie_id (номер в массиве movies структуры md)
// Кроме информации о самом фильме, печатает также всех актёров 
void print_movie_descriptive(FILE* stream, const MovieDatabase* pmd, int movie_id)
{
    print_movie(stdout, &pmd->movies[movie_id]);
    printf("Actors:\n");
    for (int i = 0; i < pmd->movies[movie_id].crew_size; ++i)
    {
        printf("\t");
        print_actor(stdout, &pmd->actors[pmd->movies[movie_id].crew[i]]);
    }
    printf("\n");
}

Movie find_best_movie_value(const MovieDatabase* pmd)
{
    double max_rating = 0;
    Movie best;

    for (int i = 0; i < pmd->number_of_movies; i++) {
        if (max_rating < pmd->movies[i].rating) {
            max_rating = pmd->movies[i].rating;
            best = pmd->movies[i];
        }
    }

    return best;
}

int find_best_movie_index(const MovieDatabase* pmd)
{
    double max_rating = 0;
    int best;

    for (int i = 0; i < pmd->number_of_movies; i++) {
        if (max_rating < pmd->movies[i].rating) {
            max_rating = pmd->movies[i].rating;
            best = i;
        }
    }

    return best;
}

Movie* find_best_movie_pointer(const MovieDatabase* pmd)
{
    double max_rating = 0;
    Movie* best;

    for (int i = 0; i < pmd->number_of_movies; i++) {
        if (max_rating < pmd->movies[i].rating) {
            max_rating = pmd->movies[i].rating;
            best = &pmd->movies[i];
        }
    }

    return best;
}

void find_best_movie_argument(const MovieDatabase* pmd, Movie* p_best_movie)
{
    double max_rating = 0;
    Movie best;

    for (int i = 0; i < pmd->number_of_movies; i++) {
        if (max_rating < pmd->movies[i].rating) {
            max_rating = pmd->movies[i].rating;
            best = pmd->movies[i];
        }
    }

    *p_best_movie = best;
    return;
}

void actor_filmography(const MovieDatabase* md, const char name[], const char surname[])
{   
    int index;
    for (int i = 0; i < md->number_of_actors; i++) {
        if (md->actors[i].name == name && md->actors[i].surname == surname) {
            index = i;
            break;
        }
    }
    for (int i = 0; i < md->number_of_movies; i++) {
        for (int j = 0; i < md->movies[i].crew_size; j++) {
            if (index == md->movies[i].crew[j]) {
                print_movie(stdout, &md->movies[i]);
                break;
            }
        }
    }
}

int best_actor(const MovieDatabase* md)
{   
    int actors[2100] = {0};
    int movies[2100] = {0};

    for (int i = 0; i < md->number_of_movies; i++) {
        for (int j = 0; i < md->movies[i].crew_size; j++) {
            actors[md->movies[i].crew[j]] += md->movies[i].rating;
            movies[md->movies[i].crew[j]]++;
        }
    }

    int temp;
    for (int i = 0; i < md->number_of_actors; i++) {
        temp = actors[i] / movies[i];
        actors[i] = temp;
    }

    temp = 0;
    int index = 0;

    for (int i = 0; i < md->number_of_actors; i++) {
        if (actors[i] > temp) {
            temp = actors[i];
            index = i;
        }
    }

    return index;
}

void movies_of_the_year(const MovieDatabase* md, int year)
{
    int pos = 0;
    Movie* movies[5100] = {0};
    double ratings[5100] = {0};

    for (int i = 0; i < md->number_of_movies; i++) {
        if (md->movies[i].release_date.year == year) {
            movies[pos] = &md->movies[i];
            pos++;
            ratings[pos] = md->movies[i].rating;
        }
    }

    for (int j = 0; j <= pos; ++j)
    {
        for (int i = 0; i < pos - j; i++)
        {
            if (ratings[i] > ratings[i + 1])
            {
                int temp = ratings[i];
                ratings[i] = ratings[i + 1];
                ratings[i + 1] = temp;
                Movie* temp1 = movies[i];
                movies[i] = movies[i + 1];
                movies[i + 1] = temp1;
            }
        }
    }

    for (int i = 0; i <= pos; i++)
        print_movie(stdout, movies[i]);
    
    return;
}

int main()
{
    MovieDatabase md;
    printf("%llu\n", sizeof(md));
    read_database(&md, "actors.csv", "movies.csv");
    
    printf("%i\n", find_best_movie_index(&md));
    print_movie(stdout, find_best_movie_pointer(&md));

    Movie e;

    find_best_movie_argument(&md, &e);

    print_movie(stdout, &e);

    printf("%i\n",best_actor(&md));

}