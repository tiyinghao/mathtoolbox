# mathtoolbox

A library of mathematical tools (regression, interpolation, dimensionality reduction, clustering, etc.) written in C++11. Eigen http://eigen.tuxfamily.org/ is used for the interface and internal vector/matrix representation.

## Algorithms

- `interpolation`: This category includes algorithms for scattered data interpolation and scattered data approximation.
	- [`rbf-interpolation`](https://yuki-koyama.github.io/mathtoolbox/docs/rbf-interpolation): Radial basis function (RBF) network for interpolation.
- `dimensionality-reduction`: This category includes algorithms for dimensionality reduction and low-dimensional embedding.
	- [`metric-mds`](https://yuki-koyama.github.io/mathtoolbox/docs/metric-mds): Metric multi-dimensional scaling (MDS).

## Dependency

- Eigen http://eigen.tuxfamily.org/

## Licensing

The MIT License.
