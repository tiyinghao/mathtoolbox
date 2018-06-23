#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Core>
#include <mathtoolbox/gaussian-process-regression.hpp>

using Eigen::VectorXd;
using Eigen::MatrixXd;

namespace
{
    std::random_device seed;
    std::default_random_engine engine(seed());
    std::uniform_real_distribution<double> uniform_dist(0.0, 1.0);
    
    double CalculateFunction(double x)
    {
        return x * std::sin(10.0 * x);
    }
}

int main(int argc, char** argv)
{
    // Set a output directory path
    const std::string output_directory_path(argv[1]);

    // Generate (and export) scattered data
    constexpr int    number_of_samples = 6;
    constexpr double noise_intensity   = 0.0;
    std::ofstream scattered_data_stream(output_directory_path + "/scattered_data.csv");
    scattered_data_stream << "x,y" << std::endl;
    Eigen::MatrixXd X(1, number_of_samples);
    Eigen::VectorXd y(number_of_samples);
    for (int i = 0; i < number_of_samples; ++ i)
    {
        X(0, i) = uniform_dist(engine);
        y(i)    = CalculateFunction(X(0, i)) + noise_intensity * uniform_dist(engine);
        
        scattered_data_stream << X(0, i) << "," << y(i) << std::endl;
    }
    scattered_data_stream.close();
   
    // Instantiate the interpolation object
    mathtoolbox::GaussianProcessRegression regressor(X, y);
    
    // Calculate (and export) estimated values
    std::ofstream estimatedd_data_stream(output_directory_path + "/estimated_data.csv");
    estimatedd_data_stream << "x,y,s" << std::endl;
    for (int i = 0; i <= 100; ++ i)
    {
        const double x = (1.0 / 100.0) * i;
        const double y = regressor.EstimateY(Eigen::VectorXd::Constant(1, x));
        const double s = regressor.EstimateS(Eigen::VectorXd::Constant(1, x));

        estimatedd_data_stream << x << "," << y << "," << s << std::endl;
    }
    estimatedd_data_stream.close();
    
    return 0;
}