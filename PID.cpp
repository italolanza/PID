#include <PID.h>
#include <Arduino.h>

PID::PID (double _kP, double _kI, double _kD)
{
  this->setKP(_kP);
  this->setKI(_kI);
  this->setKD(_kD);
  P	=	0;
  I	=	0;
  D	=	0;
  lastError	=	0;
  lastSample	=	0;
  lastProcess	=	0;
  maxKI	=	0;
}
//construtor com a opção de adicionar o setPoint logo na criação do objeto
PID::PID (double _kP, double _kI, double _kD, double _setPoint)
{
  	this->setKP(_kP);
  	this->setKI(_kI);
  	this->setKD(_kD);
	this->setSetPoint(_setPoint);
	P	=	0;
	I	=	0;
	D	=	0;
	lastError	=	0;
	lastSample	=	0;
  	lastProcess	=	0;
	maxKI	=	0;
}

void PID::addNewSample (double _sample)
{
    sample = _sample;
}

void PID::setSetPoint( double _setPoint)
{
    setPoint = _setPoint;
}

void PID::setMaxKI(double _maxKI)
{
	maxKI = _maxKI;
}

void PID::setKP(double _kP)
{
    kP = _kP;
}

void PID::setKI(double _kI)
{
    kI = _kI;
}

void PID::setKD(double _kD)
{
    kD = _kD;
}

double PID::getKP()
{
    return kP;
}

double PID::getKI()
{
    return kI;
}

double PID::getKD()
{
    return kD;
}

double PID::process ()
{
    // Implementação PID
        
		error = setPoint - sample;    
		float deltaTime = (millis() - lastProcess) / 1000.0;		//deltaTime esta em segundos
		lastProcess = millis();
	
	
		//P - erro proporcional
		P = error * kP;
		
		//I - "somatório dos erros"
		I = I + ((error * deltaTime) * kI);
		if( maxKI =! 0 && I > maxKI)	I = maxKI; 				// se maxKI for diferente de zero e o valor de I > KI o I sera maxKI
		else if ( maxKI =! 0 && I < -maxKI)	I = -maxKI;		
		
		//D - "derivara do erro"
		D 		= ((sample - lastSample) / deltaTime) * kD;
		lastError 	= error;
		lastSample 	= sample;
		
		// Soma todas as contribuições
		pid = P + I - D;
		
    return pid;
}

