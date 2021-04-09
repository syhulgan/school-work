#pragma once
#include <string>
using namespace std;

struct Car
{
  string brand, model, color;
  int maxSpeed;
};

struct Output
{
  string outputBrandPath;
  string outputModelPath;
  string outputColorPath;
  string outputSpeedPath;
  string outputStatsPath;
};