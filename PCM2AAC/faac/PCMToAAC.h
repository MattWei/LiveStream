//////////////////////////////////////////////////////////////////////////
/// \file       PCMToAAC.h
/// \brief      PCMתAAC������
/// \author     
/// \version    
///             [V1.0] 2019/11/24, draft
/// \copyright  
///             
//////////////////////////////////////////////////////////////////////////

#pragma once
#include <faac.h>
#include <string>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class PCM_TO_AAC
{
public:
    //////////////////////////////////////////////////////////////////////////
    /// \brief  ���캯��
    /// \remark 
    /// \param[in]  samplerate  ������
    /// \param[in]  chanel      ͨ����
    /// \param[in]  sample_bit   ����λ��
    //////////////////////////////////////////////////////////////////////////
    PCM_TO_AAC(int samplerate, int chanel, int sample_bit);

    ~PCM_TO_AAC();

    //////////////////////////////////////////////////////////////////////////
    /// \brief  PCM��AAC��ת��
    /// \remark 
    /// \param[in]  pcmbuf       ��ת����PCM���ݣ������ݴ�С�������InputSample * ����λ�� / 8������ת����ʧ��
    /// \param[in]  PcmSize      ��ת��pcm���ݴ�С,�����ݴ�С�������InputSample * ����λ�� / 8
    /// \param[in]  aacBuf       aac���ݻ���buf
    /// \return  �ɹ�--����aac���ݴ�С��С�ڵ���0ʱ��Ϊʧ��
    //////////////////////////////////////////////////////////////////////////
    int ConvertProcess(char* pcmbuf, int PcmSize, unsigned char* aacBuf);

private:
    faacEncHandle   m_hEncoder ;
    unsigned long   m_InputSample ;
    unsigned long   m_MaxOutputBytes;
    int             m_PCMbitSize;
    int             m_SampleRate;
    int             m_Channel;

    int m_PCMBufSize;
    char* m_PtrPCMBuf;
    char* m_PtrAACBuf;

    faacEncConfigurationPtr m_pConfiguration;
};
