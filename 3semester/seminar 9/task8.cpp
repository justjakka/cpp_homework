#include "complex.h"
#include <cstdio>


Complex function(Complex z, Complex c)
{
    Complex result = z * z + c;
    return result;
}


int main()
{
    FILE* image = fopen("julia1.ppm", "w");
    fwrite("P3\n", sizeof(char) * 3, 1, image);
    fwrite("800 800\n", sizeof(char) * 8, 1, image);
    fwrite("255\n", sizeof(char) * 4, 1, image);

    float norm = 2 * sqrt(2);

    Complex c = {0, 0};

    Complex point = {1, 1};

    for (int a = 0; a < 20; a++)
    {
        Complex temp = function(point, c);
        std::cout << temp << "\n";
        point = temp;
        
    }


    for (int i = 0; i < 800; i++)
    {
        for (int j = 0; j < 800; j++)
        {   
            float real = ((j - 399) / 399) * 2;
            float img = ((i - 399) / 399) * 2;
            Complex point = {real, img};

            bool big = false;
            int brightness;

            for (int a = 0; a < 20; a++)
            {
                Complex temp = function(point, c);
                point = temp;
                if (abs(point) > 65536)
                    big = true;
            }
                
            if (big)
                brightness = 0;
            else
                round(255 - 255 * abs(point) / norm);

            for (int k = 0; k < 3; k++)
            {
                fwrite(&brightness, sizeof(brightness), 1, image);

                if (k != 2)
                    fwrite(" ", sizeof(char), 1, image);
                else
                {
                    if (j != 799)
                        fwrite(" ", sizeof(char), 1, image);
                }
            }
        }

        fwrite("\n", sizeof(char), 1, image);
    }
    fclose(image);
}