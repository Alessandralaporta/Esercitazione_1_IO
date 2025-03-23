#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>

double map_value(double x, double old_min = 1, double old_max = 5, double new_min = -1, double new_max = 2) {
    return new_min + (x - old_min) * (new_max - new_min) / (old_max - old_min);
}

int main()
{
    std::string namefile="data.txt";
    std::fstream fstr(namefile);
    if(fstr.fail()){
        std::cerr << "file not found" << std::endl;
        return 1;
    }
    
    std::string outputfilename = "result.txt";
    std::ofstream ofst(outputfilename);
    
    if (ofst.fail()){
        std::cerr <<"file output error" << std::endl;
        return 2;
    }
    ofst << "# N Mean" << std::endl;
    double val;
    double sum=0;
    int N=0;
    while(fstr>>val){
        val=map_value(val);
        sum +=val;
        N++;
        double mean = sum/N;
        ofst<<N<<""<<std::scientific <<std::setprecision(16)<<mean<< std::endl;
    }
    
    fstr.close();
    ofst.close();
    return 0;
}
