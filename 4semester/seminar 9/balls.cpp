#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


struct Ball
{
    float radius;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float mass;
};


int main()
{   
    float G = 6.6743 * pow(0.1, 5);
    float density = 10;
    srand(time(0));
    
    const int width = 1000;
    const int height = 800;
    const int n_balls = 10;

    // Шаг по времени
    const float delta_t = 0.1;

    // Создаём экземпляр класса окно
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    // Задаём максимальное количество кадров в секунду
    window.setFramerateLimit(600);

    // Так как sf::CircleShape занимает много памяти, создаём всего 1 экземпляр
    sf::CircleShape circle(50.0f);
    circle.setFillColor({200, 216, 200});

    std::vector<Ball> balls;
    balls.resize(n_balls);
    for (int i = 0; i < n_balls; i++)
    {
        balls[i].radius = 4 + rand() % 8;
        balls[i].position = {(float)(rand() % width), (float)(rand() % height)};
        // balls[i].velocity = {(float)(rand() % 100 - 50), (float)(rand() % 100 - 50)};
        balls[i].velocity = {(float)0, (float)0};
        balls[i].mass = pow(balls[i].radius, 2) * M_PI * density;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // В данном примере проверяем окно на закрытие
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // очистить скрытый холст черным цветом
        window.clear(sf::Color::Black);

        set<int> processed;

        for (int i = 0; i < n_balls; i++)
        {
            balls[i].position += balls[i].velocity * delta_t;

            if (balls[i].position.x < 0 || balls[i].position.x > width)
                balls[i].velocity.x = - balls[i].velocity.x;

            if (balls[i].position.y < 0 || balls[i].position.y > height)
                balls[i].velocity.y = - balls[i].velocity.y;
            
            
            for (int j = 0; j < n_balls; j++)
            {
                if (i != j && !processed.count(j))
                {
                    float distance_squared = pow(balls[i].position.x - balls[j].position.x, 2) + pow(balls[i].position.y - balls[j].position.y, 2);
                    if (distance_squared >= balls[i].radius + balls[j].radius)
                    {   
                        float added_velocity = G / distance_squared * delta_t * balls[i].mass * balls[j].mass;
                        float xdiff = balls[j].position.x - balls[i].position.x;
                        float ydiff = balls[j].position.y - balls[i].position.y;
                        float angle = atan(fabs(ydiff / xdiff));

                        float xvel = added_velocity * cos(angle);
                        float yvel = added_velocity * sin(angle);

                        if (xdiff > 0)
                        {
                            balls[i].velocity.x += xvel;
                            balls[j].velocity.x -= xvel;
                        }
                        else
                        {
                            balls[i].velocity.x -= xvel;
                            balls[j].velocity.x += xvel;
                        }

                        if (ydiff > 0)
                        {
                            balls[i].velocity.y += yvel;
                            balls[j].velocity.y -= yvel;
                        }
                        else
                        {
                            balls[i].velocity.y -= yvel;
                            balls[j].velocity.y += yvel;
                        }
                    }
                }
            }

            processed.insert(i);
            
            

            /*
            if (balls[i].position.x < 0)
                balls[i].position.x += width;
            if (balls[i].position.x > width)
                balls[i].position.x -= width;

            if (balls[i].position.y < 0)
                balls[i].position.y += height;
            if (balls[i].position.y > height)
                balls[i].position.y -= height;
            */

            // Используем 1 sf::CircleShape, чтобы нарисовать все шары
            circle.setRadius(balls[i].radius);
            // setOrigin - задаёт центр объекта
            // По умолчанию центр - в левом верхнем угле объекта
            // Строка ниже устанавливает центр в центре шарика
            // В дальнейшем функция, setPosition устанавливает положение шарика так, 
            // чтобы его центр был в точке balls[i].position
            circle.setOrigin(balls[i].radius, balls[i].radius);
            circle.setPosition(balls[i].position);
            
            window.draw(circle);
        }

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}