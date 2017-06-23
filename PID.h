/*
    An adptation of the Simple PID Class of Ivan Seidel
    Link: https://gist.github.com/ivanseidel/b1693a3be7bb38ff3b63

    Free to use 
*/
#ifndef PID_H
#define PID_H

class PID
{
    public:
            PID(double,double,double);
    	    PID(double,double,double,double);
            void addNewSample (double);
            void setSetPoint(double);
	    void setMaxKI(double);
            void setKP(double);
            void setKI(double);
            void setKD(double);
	    double getKP();
	    double getKI();
	    double getKD();
	    double process();

    private:
            double error;
            double lastError;
            double sample;
	    double lastSample;
            double kP, kI, kD;
            double P, I, D;
            double pid;
            double setPoint;
	    double maxKI;
	    long lastProcess;
           

};
#endif
