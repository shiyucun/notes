
#include "math.hpp"

int main() {
  auto v1 = MatrixScale(0.1, std::vector<double>(4, 5));
  std::cout << "MatrixScale(HasRet) v1:" << std::endl;
  for (const auto &item : v1) {
    std::cout << item << "  ";
  }
  std::cout << std::endl;

  MatrixScale(0.1, v1);
  std::cout << "MatrixScale(NoRet) v1:" << std::endl;
  for (const auto &item : v1) {
    std::cout << item << "  ";
  }
  std::cout << std::endl;

  std::vector<std::vector<double>> mat1;
  std::vector<double> mat2;
  mat2.push_back(1);
  mat2.push_back(1);
  mat2.push_back(1);
  mat2.push_back(1);
  mat1.push_back(mat2);
  mat1.push_back(mat2);
  mat1.push_back(mat2);
  auto v2 = MatrixMulti(mat1, mat2);

  std::cout << "MatrixMulti v2:" << std::endl;
  for (const auto &item : v2) {
    std::cout << item << "  ";
  }
  std::cout << std::endl;

  mat2.push_back(1);
  auto v3 = MatrixMulti(mat1, mat2);

  std::cout << "MatrixMulti v3:" << std::endl;
  for (const auto &item : v3) {
    std::cout << item << "  ";
  }
  std::cout << std::endl;

  double v4 = MatrixSum(mat1[0], mat1[1]);
  std::cout << "MatrixMulti v4: " << v4 << std::endl;

  double v5 = MatrixSum(mat1[0], mat2);
  std::cout << "MatrixMulti v5: " << v5 << std::endl;

  std::vector<std::vector<double>> mat3;
  std::vector<std::vector<double>> mat4;
  mat3.push_back(mat2);
  mat3.push_back(mat2);
  mat3.push_back(mat2);
  mat4.push_back(mat2);
  mat4.push_back(mat2);
  mat4.push_back(mat2);

  auto v6 = MatrixAdd(mat3, mat4);
  std::cout << "MatrixAdd v6:" << std::endl;
  for (const auto &it1 : v6) {
    for (const auto &it2 : it1) {
      std::cout << it2 << "  ";
    }
    std::cout << std::endl;
  }

  mat4.push_back(mat2);
  auto v7 = MatrixAdd(mat3, mat4);
  std::cout << "MatrixAdd v7:" << std::endl;
  for (const auto &it1 : v7) {
    for (const auto &it2 : it1) {
      std::cout << it2 << "  ";
    }
    std::cout << std::endl;
  }

  auto v8 = MatrixAdd(mat2, mat2);
  std::cout << "MatrixAdd v8:" << std::endl;
  for (const auto &item : v8) {
    std::cout << item << "  ";
  }
  std::cout << std::endl;

  double v9 = DegreeToRad(180 / M_PI);
  std::cout << "DegreeToRad: " << v9 << std::endl;

  double v10 = DegreeToRad(360 / M_PI);
  std::cout << "DegreeToRad: " << v10 << std::endl;

  double v11 = RadToDegree(1 * M_PI);
  std::cout << "RadToDegree: " << v11 << std::endl;

  double v12 = RadToDegree(3 * M_PI);
  std::cout << "RadToDegree: " << v12 << std::endl;

  double v13 = NonZero(0, "test1");
  std::cout << "NonZero: " << v13 << std::endl;

  double v14 = NonZero(0.1, "test2");
  std::cout << "NonZero: " << v14 << std::endl;

  double v16 = NormHeadingRad(M_PI);
  std::cout << "NormHeadingRad: " << v16 << std::endl;

  double v17 = NormHeadingRad(2 * M_PI);
  std::cout << "NormHeadingRad: " << v17 << std::endl;

  double v18 = NormHeadingRad(3 * M_PI);
  std::cout << "NormHeadingRad: " << v18 << std::endl;

  double v19 = NormHeadingRad(4 * M_PI);
  std::cout << "NormHeadingRad: " << v19 << std::endl;

  double v20 = NormHeadingRad(-M_PI);
  std::cout << "NormHeadingRad: " << v20 << std::endl;

  double v21 = NormHeadingRad(-2 * M_PI);
  std::cout << "NormHeadingRad: " << v21 << std::endl;

  double v22 = NormHeadingRad(-3 * M_PI);
  std::cout << "NormHeadingRad: " << v22 << std::endl;

  double v23 = NormHeadingRad(-4 * M_PI);
  std::cout << "NormHeadingRad: " << v23 << std::endl;

  double v24 = NormHeadingRad(M_PI / 2);
  std::cout << "NormHeadingRad: " << v24 << std::endl;

  double v25 = NormHeadingRad(M_PI + M_PI / 2);
  std::cout << "NormHeadingRad: " << v25 << std::endl;

  double v26 = NormHeadingRad(-M_PI / 2);
  std::cout << "NormHeadingRad: " << v26 << std::endl;

  double v27 = NormHeadingRad(-M_PI - M_PI / 2);
  std::cout << "NormHeadingRad: " << v27 << std::endl;

  double v28 = DistOfTwoPoints(0, 0, 1, 2);
  std::cout << "DistOfTwoPoints: " << v28 << std::endl;

  double v29 = LinearInterpolation(0, 1, 0, 1, 0.5);
  std::cout << "LinearInterpolation: " << v29 << std::endl;

  double v30 = LinearInterpolation(0, 1, 0, 1, 2);
  std::cout << "LinearInterpolation: " << v30 << std::endl;

  double v31 = LinearInterpolation(0, 1, 0, 1, -1);
  std::cout << "LinearInterpolation: " << v31 << std::endl;

  double v32 = LinearInterpolation(1, 1, 1, 2, 3);
  std::cout << "LinearInterpolation: " << v32 << std::endl;

  return 0;
}
