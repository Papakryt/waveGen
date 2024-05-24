#include <math.h>
#include <QVector>
class waveClass{
private:
    int Size;
    float A; float F; float Fs; float Tb; float T0; float Phase;
public:
    float* Signal;
    waveClass(float A, float F, float Fs, float Tb, float T0, float Phase);
    int getSize();
    void subWave(float A, float F, float Fs, float Tb, float T0, float Phase);
    ~waveClass();
};
