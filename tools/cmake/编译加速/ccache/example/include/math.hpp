
#pragma once

#include <iostream>

#include <string>
#include <vector>
#include <cmath>

std::vector<double> MatrixScale(double scaler, const std::vector<double> &mat);

void MatrixScale(double scaler, std::vector<double> &mat);

std::vector<double> MatrixMulti(const std::vector<std::vector<double>> &mat1,
                                const std::vector<double> &mat2);

double MatrixSum(const std::vector<double> &mat1, const std::vector<double> &mat2);

std::vector<std::vector<double>> MatrixAdd(const std::vector<std::vector<double>> &mat1,
                                           const std::vector<std::vector<double>> &mat2);

std::vector<double> MatrixAdd(const std::vector<double> &mat1, const std::vector<double> &mat2);

double DegreeToRad(const double angle);

double RadToDegree(const double angle);

double NonZero(const double v, const std::string &var_name);

double NormHeadingRad(double rad);

double DistOfTwoPoints(double x1, double x2, double y1, double y2);

double LinearInterpolation(double x_min, double x_max, double y_min, double y_max, double x);
