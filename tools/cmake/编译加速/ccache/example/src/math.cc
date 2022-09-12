
#include "math.hpp"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <limits>

std::vector<double> MatrixScale(double scaler, const std::vector<double> &mat) {
  std::vector<double> v;

  for (const auto &item : mat) {
    v.push_back(scaler * item);
  }

  return v;
}

void MatrixScale(double scaler, std::vector<double> &mat) {
  for (auto &item : mat) {
    item *= scaler;
  }
}

std::vector<double> MatrixMulti(const std::vector<std::vector<double>> &mat1,
                                const std::vector<double> &mat2) {
  std::vector<double> v;

  for (const auto &mat : mat1) {
    double tmp = 0.0;
    if (mat.size() == mat2.size()) {
      for (std::size_t idx = 0; idx < mat.size(); idx++) {
        tmp += mat[idx] * mat2[idx];
      }
      v.push_back(tmp);
    } else {
      v.clear();
      printf("MatrixMulti matrix input diff in size.");
      break;
    }
  }

  return v;
}

double MatrixSum(const std::vector<double> &mat1, const std::vector<double> &mat2) {
  double result = 0;

  if (mat1.size() == mat2.size()) {
    for (std::size_t i = 0; i < mat1.size(); ++i) {
      result += mat1[i] + mat2[i];
    }
  } else {
    printf("MatrixSum matrix input diff in size.");
  }

  return result;
}

std::vector<std::vector<double>> MatrixAdd(const std::vector<std::vector<double>> &mat1,
                                           const std::vector<std::vector<double>> &mat2) {
  std::vector<std::vector<double>> v;

  if (mat1.size() == mat2.size()) {
    for (std::size_t i = 0; i < mat1.size(); ++i) {
      if (mat1[i].size() == mat2[i].size()) {
        std::vector<double> tmp;
        for (std::size_t j = 0; j < mat1.size(); ++j) {
          tmp.push_back(mat1[i][j] + mat2[i][j]);
        }
        v.push_back(tmp);
      } else {
        printf("MatrixAdd matrix input diff in sizeX.");
        v.clear();
        break;
      }
    }
  } else {
    printf("MatrixAdd matrix input diff in sizeY.");
  }

  return v;
}

std::vector<double> MatrixAdd(const std::vector<double> &mat1, const std::vector<double> &mat2) {
  std::vector<double> v;

  if (mat1.size() == mat2.size()) {
    for (std::size_t i = 0; i < mat1.size(); ++i) {
      v.push_back(mat1[i] + mat2[i]);
    }
  } else {
    printf("MatrixAdd matrix input diff in size.");
  }

  return v;
}

double DegreeToRad(const double angle) { return angle / 180.0 * M_PI; }

double RadToDegree(const double angle) { return angle / M_PI * 180.0; }

double NonZero(const double v, const std::string &var_name) {
  if (std::abs(v) < std::numeric_limits<double>::epsilon()) {
    printf("NonZero division by 0 occurred: %s.", var_name.c_str());
    return 0.001;
  }
  return v;
}

double NormHeadingRad(double rad) {
  int32_t flag = rad < 0 ? -1 : 1;

  rad = std::abs(rad);

  int32_t cnt_pi = static_cast<int32_t>(rad / M_PI);
  int32_t cnt_2pi = static_cast<int32_t>(rad / (M_PI * 2)) + (cnt_pi & 0x01);

  return flag * (rad - cnt_2pi * 2 * M_PI);
}

double DistOfTwoPoints(double x1, double x2, double y1, double y2) {
  return std::sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double LinearInterpolation(double x_min, double x_max, double y_min, double y_max, double x) {
  x = std::min(x, x_max);
  x = std::max(x, x_min);
  double k = (y_max - y_min) / NonZero(x_max - x_min, "LinearInterpolation");
  return k * (x - x_min) + y_min;
}
