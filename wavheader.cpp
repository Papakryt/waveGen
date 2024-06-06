#include "wavheader.h"

wavHeader::wavHeader(){}

void wavHeader::createWavFile(const char* filePath, const float* Amplitude, int VectorSize){
    int16_t Data;
    wavHeader wavHead;
    wavHead.RIFF[0] = 'R'; wavHead.RIFF[1] = 'I'; wavHead.RIFF[2] = 'F'; wavHead.RIFF[3] = 'F';
    wavHead.WAVE[0] = 'W'; wavHead.WAVE[1] = 'A'; wavHead.WAVE[2] = 'V'; wavHead.WAVE[3] = 'E';
    wavHead.fmt[0] = 'f';  wavHead.fmt[1] = 'm';  wavHead.fmt[2] = 't';  wavHead.fmt[3] = ' ';
    wavHead.Subchunk2ID[0] = 'd'; wavHead.Subchunk2ID[1] = 'a'; wavHead.Subchunk2ID[2] = 't'; wavHead.Subchunk2ID[3] = 'a';
    wavHead.Subchunk1Size = 16;
    wavHead.AudioFormat = 1;
    wavHead.NumOfChan = 1;
    wavHead.SamplesPerSec = 48000;
    wavHead.bitsPerSample = sizeof (Data)*8;
    wavHead.bytesPerSec = wavHead.SamplesPerSec*wavHead.bitsPerSample/8;
    wavHead.blockAlign = wavHead.bitsPerSample/8;
    wavHead.Subchunk2Size = VectorSize * wavHead.blockAlign;
    wavHead.ChunkSize =  wavHead.Subchunk2Size + 36;
    size_t headerSize = sizeof(wavHeader);

    FILE* wavFile = fopen(filePath, "wb");
    fwrite(&wavHead, headerSize, 1, wavFile);

    for(int i = 0; i < VectorSize; i++)
    {
        Data = static_cast<decltype(Data)>(std::round(Amplitude[i]));
        fwrite(&Data, sizeof (Data), 1, wavFile);

    }
    fclose(wavFile);
}
