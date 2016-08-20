#ifndef _TGATEXTURE_H_
#define _TGATEXTURE_H_

// TGAをテクスチャとして利用するためのヘルパークラス
class CTGATextureHelper
{
    int m_iNumChannel;			// 1ピクセルの色チャンネル数(RGB or RGBA)

	// 幅、高さ
	unsigned int m_iWidth;
    unsigned int m_iHeight;

	unsigned char *image;
	
public:
	CTGATextureHelper();
	~CTGATextureHelper();

	bool LoadTGA( char* filename );
	void Release();

	// 幅の取得
	unsigned int GetWidth(){ return m_iWidth; }
	// 高さの取得
	unsigned int GetHeight(){ return m_iHeight; }
	// イメージのビット列
	unsigned char* GetImage(){ return image; }

};

#endif