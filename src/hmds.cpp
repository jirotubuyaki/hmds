// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
using namespace Rcpp;
//' Calcurate approximate points in high dimensional coordinate space.
//' @param data is a numeric symmetric matrix of input data. It describe similarities or distances between two objects.
//' @param dim int: dim describes dimensions of coordinate space.
//' @param approx double: approximate rate between the sum of input distances and the sum of output distances. If the rate between input and output are less than approximate rate, iterations are halt.
//' @param itera int: teration numbers to move points in coordinate space.
//' @return Numeric Matrix of points in a distance space. row is items. col is dimentions.
//' @examples output <- hmds(matrix(1:9, nrow=3, ncol=3),dim=20,approx=1.2,itera=10000);
//' @export
//'
// [[Rcpp::export]]
NumericMatrix hmds(const NumericMatrix data,const int dim=50,const double approx=1.01,const int itera=1000){
	if(data.nrow() != data.ncol()){
		Rprintf("Error: row length and col length are not same. \n");
		stop("Unexpected condition occurred");
	}
	if(dim <= 0){
		Rprintf("Error : dimention is less than 0. \n");
		stop("Unexpected condition occurred");
	}
	if(approx < 1){
		Rprintf("Error : approximation rate is less than 1.0. \n");
		stop("Unexpected condition occurred");
	}
	if(itera <= 0){
		Rprintf("Error : iteration number is less than 0. \n");
		stop("Unexpected condition occurred");
	}
	int number = data.nrow();
	int dimention = dim;
	double approximation = approx;
	int count = itera;
	NumericMatrix point(data.nrow(),dimention);
	NumericMatrix basket = data;
	int flag = 0;
	int basket_count = 0;
	double distance;
	double distance_all_before = 0;
	double distance_all = 0;

	for(int i = 0;i < number;i++){
		for(int j = 0;j < dimention;j++){
			point(i,j) = R::runif(0.0,10.0);
			Rprintf("%d : %d : %f \n",i,j,point(i,j));
		}
	}
	while(flag == 0){
		for(int i = 0;i < number;i++){
			for(int j = 0;j < number;j++){
				if(i < j){
					distance = 0;
					for(int k = 0;k < dimention;k++){
						distance += (point(j,k) - point(i,k)) * (point(j,k) - point(i,k));
					}
					distance = sqrt(distance);
					if(approximation * basket(i,j) < distance){
						for(int k = 0;k < dimention;k++){
							for(int l = 0;l < dimention;l++){
								if(k < l){
									double pi = atan2(point(j,k) - point(i,k),point(j,l) - point(i,l));
									point(j,l) = point(j,l) + (-0.01) * (basket(i,j) / dimention) * cos(pi);
									point(j,k) = point(j,k) + (-0.01) * (basket(i,j) / dimention) * sin(pi);
								}
							}
						}
						basket_count++;
					}
					else if(basket(i,j) / approximation > distance){
						for(int k = 0;k < dimention;k++){
							for(int l = 0;l < dimention;l++){
								if(k < l){
									double pi = atan2(point(j,k) - point(i,k),point(j,l) - point(i,l));
									point(j,l) = point(j,l) + 0.01 * (basket(i,j) / dimention) * cos(pi);
									point(j,k) = point(j,k) + 0.01 * (basket(i,j) / dimention) * sin(pi);
								}
							}
						}
						basket_count++;
					}
				}
			}
		}
		if(basket_count == 0){
			flag = 1;
		}
		if(count == 0){
			flag = 1;
		}
		basket_count = 0;

		Rprintf("count : %d \n",count);
		count--;
	}
	count = 0;
	Rprintf("%10s : %10s : %10s : %10s\n","item","item","input distance","output distance");
	for(int i = 0;i < number;i++){
		for(int j = 0;j < number;j++){
			if(i < j){
				count++;
				distance = 0;
				for(int k = 0;k < dimention;k++){
					distance += (point(j,k) - point(i,k)) * (point(j,k) - point(i,k));
				}
				distance = sqrt(distance);
				distance_all += distance;
				distance_all_before += basket(i,j);
				Rprintf("%10d : %10d : %14.4f : %14.4f\n",i,j,basket(i,j),distance);
			}
		}
	}
	Rprintf("input data distance : %f\n",distance_all_before);
	Rprintf("output data distance : %f\n",distance_all);
	Rprintf("count:%d\n",count);
	return point;
}
