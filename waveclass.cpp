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

void waveClass::subWave(float A, float F, float Fs, float Tb, float T0, float Phase){
    if (this->Size<(Tb+T0)*Fs){
        float* sSignal = new float[int((Tb+T0)*Fs)];
        for (int i=0;i<((Tb+T0)*Fs);i++){
            sSignal[i]=1000*A*(std::sin(F*(i-(Tb*Fs))+Phase));
        }

        for (int i=0;i<((Tb+T0)*Fs);i++){
            sSignal[i]=sSignal[i]+this->Sig(i);
        }
        this->Signal=sSignal;
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
