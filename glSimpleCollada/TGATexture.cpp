#include "TGATexture.h"
#include <stdio.h>
#include<string.h>

// コンストラクタ
CTGATextureHelper::CTGATextureHelper()
{
	image = NULL;

	m_iWidth = 0;
	m_iHeight = 0;

	m_iNumChannel = 0;
}

// デストラクタ
CTGATextureHelper::~CTGATextureHelper()
{
	Release();
}

// 解放処理
void CTGATextureHelper::Release()
{
	if(image)
	{
		delete[] image;
		image = NULL;
	}
}

// 読み込み
bool CTGATextureHelper::LoadTGA(char *filename)
{
	if(!filename)
		return false;

	FILE*	fp;
	unsigned char tgaHeader[12];	// TGAのヘッダー
	// 非圧縮のTGAのヘッダー
	unsigned char unCompressHeader[12] = {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	unsigned char header[6];
	unsigned char bitCount;			// ピクセルあたりのビット幅
	int colorChannel;				// 1チャンネルのビット幅
	long tgaSize;					// 画像サイズ（全ピクセルの）

	fp = fopen( filename, "rb");
	if(!fp)
	{
		printf("%s open failed\n", filename);
		return false;
	}
	// TGAのヘッダーの読み込み
	fread(tgaHeader, 1, sizeof(tgaHeader), fp);

	// 非圧縮のTGAしか扱わないので非圧縮のTGAのヘッダーと比較
	if(memcmp(unCompressHeader, tgaHeader, sizeof(unCompressHeader)) != 0)
	{
		// 圧縮フォーマットなら失敗
		fclose(fp);
		return false;
	}

	// イメージの情報の読み込み
	fread(header, 1, sizeof(header), fp);

	m_iWidth = header[1] * 256 + header[0];
	m_iHeight = header[3] * 256 + header[2];

	bitCount = header[4];

	colorChannel = bitCount / 8;
	tgaSize = m_iWidth * m_iHeight * colorChannel;

	//
	image = new unsigned char[sizeof(unsigned char) * tgaSize];
	fread(image, sizeof(unsigned char), tgaSize, fp);

	// BGRで並んでいる物をRGBに並び替える
	for(long i=0;i<tgaSize;i++)
	{
		unsigned char buf = image[i];
		image[i] = image[i + 2];
		image[i + 2] = buf;
	}

	fclose(fp);
 
	if(colorChannel == 3) m_iNumChannel = 3;
	else m_iNumChannel = 4;

	return true;
}