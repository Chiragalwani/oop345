#ifndef SICT_DATATABLE_H
#define SICT_DATATABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>


extern int FW;
extern int ND;


namespace sict 
{


	template<class T>
	
	class DataTable 
	{
		
		std::vector<std::pair<T, T>> record;

	public:
		

		DataTable(std::ifstream& fileobj)
		{

			bool keepReading = true;

			if (fileobj)
			{
				T x = { 0 };
				T y = { 0 };
				do {
					if (fileobj >> x >> y)
						
						record.push_back(std::make_pair(x, y));

					else

						keepReading = false;

				} while (keepReading);
			}
		}


		std::pair<T, T> sum_x_y() const 
		{
		
			T t_x = { 0 };
			T t_y = { 0 };

			t_x += std::accumulate(record.begin(), record.end(), static_cast<T>(0), [](auto& a, auto& b) { return a + b.first; });
			t_y += std::accumulate(record.begin(), record.end(), static_cast<T>(0), [](auto& a, auto& b) { return a + b.second; });

			return std::make_pair(t_x, t_y);
		}

		
		std::pair<std::vector<T>, std::vector<T>> xy_collection() const 
		{
		
			std::vector<T> x;
			std::vector<T> y;

			for (auto& i : record)
			{
				x.push_back(std::get<0>(i));
				y.push_back(std::get<1>(i));
			}
		
			return std::make_pair(x, y);
		
		}

	

		T mean() const 
		{
			std::pair<T, T> t_xy = sum_x_y();
		
			return std::get<1>(t_xy) / record.size();
		}

		

		T sigma() const 
		{
		
			T total = { 0 };
			std::pair<std::vector<T>, std::vector<T>> v_xy = xy_collection();
			std::vector<T> y = std::get<1>(v_xy);

			std::for_each(y.begin(), y.end(), [&](T& n) {
				total += std::pow(n - mean(), 2);
			});

			return std::sqrt(total / (y.size() - 1));
		}

		

		T median() const 
		{
		
			std::pair<std::vector<T>, std::vector<T>> xy = xy_collection();
			std::vector<T> y = std::get<1>(xy);
			std::sort(y.begin(), y.end());
			return y[y.size() / 2];
	
		}

	
		T slope() const 
		{
			
				size_t n = record.size();
				std::pair<T, T> sums_xy = sum_x_y();
				std::pair<std::vector<T>, std::vector<T>> v_xy = xy_collection();
				std::vector<T> x = std::get<0>(v_xy);
				T sum_x = std::get<0>(sums_xy);
				T sum_y = std::get<1>(sums_xy);

				T sum_prod_x_y = { 0 };
				std::for_each(record.begin(), record.end(), [&](auto& i) { sum_prod_x_y += i.first * i.second; });

				T sum_squared_x = { 0 };
				std::for_each(x.begin(), x.end(), [&](auto& i) { sum_squared_x += i * i; });

				T numerator = (n * sum_prod_x_y) - (sum_x * sum_y);
				T denominator = ((n * sum_squared_x) - (sum_x * sum_x));

				return numerator / denominator;
	    }

		

		T intercept() const 
		{
			size_t n = record.size();
			std::pair<T, T> sums_xy = sum_x_y();
			T sum_x = std::get<0>(sums_xy);
			T sum_y = std::get<1>(sums_xy);

			return (sum_y - (slope() * sum_x)) / n;
		}


	

	

		

		void displayData(std::ostream& os) 
		{
		
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;

			for (const auto& i : record)
			{
				os << std::fixed << std::setprecision(ND) << std::setw(FW) << std::right << std::get<0>(i) << std::setprecision(ND) << std::setw(FW) << std::get<1>(i) << std::endl;

			}
		}


		void displayStatistics(std::ostream& os) 
		{
		
			os << "\nStatistics" << std::endl;
			os << "----------" << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y mean    = " << std::setw(FW) << mean() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y sigma   = " << std::setw(FW) << sigma() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y median  = " << std::setw(FW) << median() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  slope     = " << std::setw(FW) << slope() << std::endl;
			os << std::fixed << std::setprecision(ND) << "  intercept = " << std::setw(FW) << intercept() << std::endl;
		
		}
	};
}
#endif // !SICT_DATA_TABLE_H
