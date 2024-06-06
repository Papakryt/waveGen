#include "waveclass.h"

waveClass::waveClass(float A, float F, float Fs, float Tb, float T0, float Phase) {
    Size = (Tb + T0) * Fs;
    Signal = new float[Size];
    this->A = A;
    this->F = F;
    this->Fs = Fs;
    this->Tb = Tb;
    this->T0 = T0;
    this->Phase = Phase;
    subWave(A, F, Fs, Tb, T0, Phase);
}


int waveClass::getSize() {
    return Size;
}

float waveClass::Sig(int i) {
    return A * (std::sin(F * (i - (Tb * Fs)) + Phase));
}

void waveClass::subWave(float A, float F, float Fs, float Tb, float T0, float Phase) {
    auto sampleCount = (Tb + T0) * Fs;
    if (this->Size < sampleCount) {
        float *sSignal = new float[int(sampleCount)];
        auto phaseInc = F / Fs;
        float phaseAccum = 0;
        for (int i = 0; i < sampleCount; i++) {
            sSignal[i] = A * (std::sin(phaseAccum + Phase));
            phaseAccum += phaseInc;
        }

        for (int i = 0; i < ((Tb + T0) * Fs); i++) {
            sSignal[i] = sSignal[i] + this->Sig(i);
        }
        this->Signal = sSignal;
    } else {

        float phase = Phase;
        for (size_t cntr = 0; cntr < sampleCount; ++cntr) {
            Signal[cntr] =A*std::sin(phase);
            phase += 2*M_PI*F/Fs;
            phase = fmodf(phase, 2.0f * M_PI);
        }
    }

}


waveClass::~waveClass() {
    delete[] Signal;
}
