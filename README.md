# Fuzzy-Library

A C++ library for fuzzy logic with Mamdani-style output and weighted average aggregation.

## Description

This library provides a Fuzzy class that can be used for fuzzy logic computations. It includes support for defining linguistic variables, setting limits, and performing fuzzy inference using Mamdani-style rules. The library also supports both Mamdani-style output aggregation and weighted average aggregation.

## Usage

### Linguistic Variables

The library includes three linguistic variables: `Angle`, `AngularVel`, and `Gain`. Each variable is associated with a set of membership functions that define fuzzy regions.

### Rule Matrix

The rule matrix defines the relationships between input linguistic variables and the corresponding output linguistic variable. The values in the matrix represent the linguistic label associated with the output.

```plaintext
-------------------------------------
|  X  |  VN |  N  |  Z  |  P  |  VP |
-------------------------------------
|  VN |  VP | VP  |  P  |  P  |  Z  |     VN  = Very Negative  = 0
-------------------------------------
|  N  |  VP |  P  |  P  |  Z  |  N  |     N   = Negative       = 1
-------------------------------------
|  Z  |  P  |  P  |  Z  |  N  |  N  |     Z   = Zero           = 2
-------------------------------------
|  P  |  P  |  Z  |  N  |  N  |  VN |     P   = Positive       = 3
-------------------------------------
|  VP |  Z  |  N  |  N  |  VN |  VN |     VP  = Very Positive  = 4
-------------------------------------
```

### Setting Limits

Use the `setLimit` method to set the limits for each linguistic variable.

```cpp
Angle.setLimit(-10, -5, 0, 5, 10);
AngularVel.setLimit(-10, -5, 0, 5, 10);
Gain.setLimit(-10, -5, 0, 5, 10);
```

### Fuzzy Inference

Perform fuzzy inference by inputting values for the linguistic variables and obtaining the output.

```cpp
Eigen::VectorXd membership = Gain.membership(Angle.predicate(inputAngle), AngularVel.predicate(inputAngular));
Eigen::VectorXd membershipVal = Gain.membershipVal(membership);
double Output = Gain.outputWeightAvg(membership, membershipVal);
```

## Example

```cpp
int main(int argc, char const *argv[]) {
  double inputAngle, inputAngular;

  // Set limits for linguistic variables
  Angle.setLimit(-10, -5, 0, 5, 10);
  AngularVel.setLimit(-10, -5, 0, 5, 10);
  Gain.setLimit(-10, -5, 0, 5, 10);

  while (true) {
    std::cout << "Angle\t";
    std::cin >> inputAngle;
    std::cout << "Angular\t";
    std::cin >> inputAngular;

    Eigen::VectorXd membership = Gain.membership(Angle.predicate(inputAngle), AngularVel.predicate(inputAngular));
    Eigen::VectorXd membershipVal = Gain.membershipVal(membership);
    double Output = Gain.outputWeightAvg(membership, membershipVal);

    std::cout << "Output: " << Output << '\n';
  }

  return 0;
}
```
