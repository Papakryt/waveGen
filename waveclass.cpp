#include "waveClass.h"
waveClass::waveClass(float A, float F, float Fs, float Tb, float T0, float Phase)
{
    Size=(Tb+T0)*Fs;
    Signal=new float[Size];
    this->A=A; this->F=F; this->Fs=Fs; this->Tb=Tb; this->T0=T0; this->Phase=Phase;
    for (int i=0;i<Size;i++){
        Signal[i]=1000*A*(std::sin(F*(i-(Tb*Fs))+Phase));
    }
}


int waveClass::getSize(){
    return Size;
}

float waveClass::Sig(int i){
    return 1000*A*(std::sin(F*(i-(Tb*Fs))+Phase));
}

float waveClass::getISignal(int i){
    return Signal[i];
}
void waveClass::createSig(float A, float F, float Fs, float Tb, float T0, float Phase){
    this->A=A;this->F=F;this->Fs=Fs;this->Tb=Tb;this->T0=T0;this->Phase=Phase;
}

void waveClass::subWave(float A, float F, float Fs, float Tb, float T0, float Phase){
    if (this->Size<(Tb+T0)*Fs){
        for(int i=0;i<(Tb+T0)*Fs;i++){
            this->Signal[i]=1000*A*(std::sin(F*(i-(Tb*Fs))+Phase))+this->Sig(i);
        }
    }
    else{
        for(int i=0;i<Size;i++){
            this->Signal[i]=1000*A*(std::sin(F*(i-(Tb*Fs))+Phase))+this->Sig(i);
        }
    }

}


waveClass::~waveClass(){
    delete [] Signal;
}