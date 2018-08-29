// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths. Assumed is that both numerator and denominator are 1 digit long.
int duration(string fraction)   //DONE
{
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';

    return numerator * (8 / denominator);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)      //DONE
{
    float distancetoa = 0;

    //Calculate distance from A to note, sans accidental and octave number.
    if (note[0] == 'B')
    {
        distancetoa = 2;
    }
    else if (note[0] == 'G')
    {
        distancetoa = -2;
    }
    else if (note[0] == 'F')
    {
        distancetoa = -4;
    }
    else if (note[0] == 'E')
    {
        distancetoa = -5;
    }
    else if (note[0] == 'D')
    {
        distancetoa = -7;
    }
    else if (note[0] == 'C')
    {
        distancetoa = -9;
    }

    //If there is an accidental, modify distancetoa accordingly
    if (note[1] == '#')
    {
        distancetoa++;
    }
    else if (note[1] == 'b')
    {
        distancetoa--;
    }

    //Identify place of octave number and store value
    int octave;
    if (note[1] == '#' || note[1] == 'b')
    {
        octave = note[2] - '0';
    }
    else
    {
        octave = note[1] - '0';
    }

    //Modify distancetoa according to octave
    distancetoa += 12 * (octave - 4);

    //return the answer to the formula: 2^(distancetoa/12)
    float base = 2.0;
    float power = distancetoa / 12;
    float freq = powf(base, power) * 440;

    return round(freq);

}

// Determines whether a string represents a rest
bool is_rest(string s)          //DONE
{
    //A rest is represented by an empty line with a \n. get_string returns "" if there is only a \n on a line.
    if (strcmp(s, "") == 0)
    {
        return true;
    }

    return false;
}
