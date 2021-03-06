#ifndef __TUNER_FC0013_H
#define __TUNER_FC0013_H

class baz_rtl_source_c;

/**
@file

@brief   FC0013 tuner module declaration

One can manipulate FC0013 tuner through FC0013 module.
FC0013 module is derived from tuner module.

// The following context is implemented for FC0013 source code.
**/

// Definitions
enum FC0013_TRUE_FALSE_STATUS
{
	FC0013_FALSE,
	FC0013_TRUE,
};

enum FC0013_I2C_STATUS
{
	FC0013_I2C_SUCCESS,
	FC0013_I2C_ERROR,
};

enum FC0013_FUNCTION_STATUS
{
	FC0013_FUNCTION_SUCCESS,
	FC0013_FUNCTION_ERROR,
};

// Functions
int FC0013_Read(baz_rtl_source_c* pTuner, unsigned char RegAddr, unsigned char *pByte);
int FC0013_Write(baz_rtl_source_c* pTuner, unsigned char RegAddr, unsigned char Byte);

int
fc0013_SetRegMaskBits(
	baz_rtl_source_c* pTuner,
	unsigned char RegAddr,
	unsigned char Msb,
	unsigned char Lsb,
	const unsigned char WritingValue
	);

int
fc0013_GetRegMaskBits(
	baz_rtl_source_c* pTuner,
	unsigned char RegAddr,
	unsigned char Msb,
	unsigned char Lsb,
	unsigned char *pReadingValue
	);

int FC0013_Open(baz_rtl_source_c* pTuner);
int FC0013_SetFrequency(baz_rtl_source_c* pTuner, unsigned long Frequency, unsigned short Bandwidth);

// Set VHF Track depends on input frequency
int FC0013_SetVhfTrack(baz_rtl_source_c* pTuner, unsigned long Frequency);


// The following context is FC0013 tuner API source code

// Definitions

// Bandwidth mode
enum FC0013_BANDWIDTH_MODE
{
	FC0013_BANDWIDTH_6000000HZ = 6,
	FC0013_BANDWIDTH_7000000HZ = 7,
	FC0013_BANDWIDTH_8000000HZ = 8,
};

// Default for initialing
#define FC0013_RF_FREQ_HZ_DEFAULT			50000000
#define FC0013_BANDWIDTH_MODE_DEFAULT		FC0013_BANDWIDTH_8000000HZ

// Tuner LNA
enum FC0013_LNA_GAIN_VALUE
{
	FC0013_LNA_GAIN_LOW     = 0x00,	// -6.3dB
	FC0013_LNA_GAIN_MIDDLE  = 0x08,	//  7.1dB
	FC0013_LNA_GAIN_HIGH_17 = 0x11,	// 19.1dB
	FC0013_LNA_GAIN_HIGH_19 = 0x10,	// 19.7dB
};

// Manipulaing functions
void
fc0013_GetTunerType(
	baz_rtl_source_c* pTuner,
	int *pTunerType
	);

void
fc0013_GetDeviceAddr(
	baz_rtl_source_c* pTuner,
	unsigned char *pDeviceAddr
	);

int
fc0013_Initialize(
	baz_rtl_source_c* pTuner
	);

int
fc0013_SetRfFreqHz(
	baz_rtl_source_c* pTuner,
	unsigned long RfFreqHz
	);

int
fc0013_GetRfFreqHz(
	baz_rtl_source_c* pTuner,
	unsigned long *pRfFreqHz
	);

// Extra manipulaing functions
int
fc0013_SetBandwidthMode(
	baz_rtl_source_c* pTuner,
	int BandwidthMode
	);

int
fc0013_GetBandwidthMode(
	baz_rtl_source_c* pTuner,
	int *pBandwidthMode
	);

int
fc0013_RcCalReset(
	baz_rtl_source_c* pTuner
	);

int
fc0013_RcCalAdd(
	baz_rtl_source_c* pTuner,
	int RcValue
	);

#endif
