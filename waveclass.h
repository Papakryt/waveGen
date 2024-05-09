#include <math.h>
#include <QVector>
class waveClass{
private:
    int Size;
    float A; float F; float Fs; float Tb; float T0; float Phase;
    float Sig(int i);
public:
    float* Signal;
    waveClass(float A, float F, float Fs, float Tb, float T0, float Phase);
    void createSig(float A, float F, float Fs, float Tb, float T0, float Phase);
    int getSize();
    float getISignal(int i);
    void subWave(float A, float F, float Fs, float Tb, float T0, float Phase);
    ~waveClass();
};
