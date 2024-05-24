#include "waveClass.h"
waveClass::waveClass(float A, float F, float Fs, float Tb, float T0, float Phase)
{
    Size=(Tb+T0)*Fs;
    Signal=new float[Size];
    this->A=A; this->F=F; this->Fs=Fs; this->Tb=Tb; this->T0=T0; this->Phase=Phase;
    auto phaseInc = F/Fs;
    float phaseAccum = 0;
    for (int i=0;i<Size;i++){
        Signal[i]=A*(std::sin(phaseAccum+Phase));
        phaseAccum+=phaseInc;
    }
}


int waveClass::getSize(){
    return Size;
}

void waveClass::subWave(float A, float F, float Fs, float Tb, float T0, float Phase){
    auto sampleCount = (Tb+T0)*Fs;
    if (this->Size<sampleCount){
        float* sSignal = new float[int(sampleCount)];
        auto phaseInc = F/Fs;
        float phaseAccum = 0;
        for (int i=0;i<sampleCount;i++){
            sSignal[i]=(this->A*(std::sin(phaseAccum+Phase)))+(A*(std::sin(phaseAccum+Phase)));
            phaseAccum+=phaseInc;
        }
        float *dSignal=this->Signal;
        this->Signal=sSignal;
        delete [] dSignal;
    }
    else{
        auto phaseInc = F/Fs;
        float phaseAccum = 0;
        for (int i=0;i<sampleCount;i++){
            this->Signal[i]+=1000*A*(std::sin(phaseAccum+Phase));
            phaseAccum+=phaseInc;
        }

    }

}


waveClass::~waveClass(){
    delete [] Signal;
}
