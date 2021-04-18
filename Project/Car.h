#pragma once
#include <string>
using namespace std;

struct Car //storing the cars
{
  string brand, model, color;
  int maxSpeed;
};

struct Output //storing output paths
{
  string outputBrandPath;
  string outputModelPath;
  string outputColorPath;
  string outputSpeedPath;
  string outputStatsPath;
};