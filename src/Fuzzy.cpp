#include "Fuzzy.h"
// #define inputAngle   -9
// #define inputAngular -6

//    -------------------------------------
//    |  X  |  VN |  N  |  Z  |  P  |  VP |
//    -------------------------------------
//    |  VN |  VP | VP  |  P  |  P  |  Z  |     VN  = Very Negetive = 0
//    -------------------------------------
//    |  N  |  VP |  P  |  P  |  Z  |  N  |     N   = Negetive      = 1
//    -------------------------------------
//    |  Z  |  P  |  P  |  Z  |  N  |  N  |     Z  = Zero           = 2
//    -------------------------------------
//    |  P  |  P  |  Z  |  N  |  N  |  VN |     P  = Positive       = 3
//    -------------------------------------
//    |  VP |  Z  |  N  |  N  |  VN |  VN |     VP = Very Positive  = 4
//    -------------------------------------

int main(int argc, char const *argv[]) {

  double inputAngle, inputAngular;

  Angle.setLimit(-10, -5, 0, 5, 10);
  AngularVel.setLimit(-10, -5, 0, 5, 10);
  Gain.setLimit(-10, -5, 0, 5, 10);

while (true) {
  std::cout << "Angle\t";   std::cin >> inputAngle;
  std::cout << "Angular\t"; std::cin >> inputAngular;

  Eigen::VectorXd membership(5);
  Eigen::VectorXd membershipVal(5);
  double Output;

  membership    = Gain.membership(Angle.predicate(inputAngle), AngularVel.predicate(inputAngular));
  // Output = Gain.outputMoM(membership);

  membershipVal = Gain.membershipVal(membership);
  Output = Gain.outputWeightAvg(membership, membershipVal);
  // for (int i = 0; i < 5; i++) {
  //   std::cout << membership(i) << '\t';
  //   std::cout << membershipVal(i) << '\n';
  // }

  std::cout << Output << '\n';
}

  return 0;
}
