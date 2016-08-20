//
//		OpenGLでCOLLADAドキュメントを描画
//		Created by TAKAHASHI Masafumi
//			http://www.shader.jp
//

#include <windows.h>

#include <gl/gl.h>
#include <gl/glut.h>

#include "TGATexture.h"

#include <vector>
using namespace std;

// COLLADA DOM関連
#include <dae.h>
#include <dom/domCOLLADA.h>

// ビューポート
const unsigned int SCREENX = 640;
const unsigned int SCREENY = 480;

// グローバル
DAE*	g_dae = NULL;
int		g_iGeometryElementCount = 0;		// ジオメトリ数
int		g_iImageElementCount = 0;			// テクスチャ数

vector<CTGATextureHelper*>			g_Texture;
vector<GLuint>				g_TextureObject;	// テクスチャ

// オフセットの最大値を返す
unsigned int getMaxOffset( domInputLocalOffset_Array &input_array ) 
{
	unsigned int maxOffset = 0;
	for ( unsigned int i = 0; i < input_array.getCount(); i++ ) {
		if ( input_array[i]->getOffset() > maxOffset ) {
			maxOffset = (unsigned int)input_array[i]->getOffset();
		}
	}
	return maxOffset;
}

// Triangleの描画
void RenderTriangle(domMesh *thisMesh, domTriangles *thisTriangles)
{
	//
	int numberOfInputs = (int)getMaxOffset(thisTriangles->getInput_array()) +1;// オフセット数
	int numberOfTriangles = (int)(thisTriangles->getP()->getValue().getCount() / numberOfInputs);	// 要素数

	// インデックスのオフセット
	unsigned int offset = 0;
	int texoffset = -255, noroffset = -255;
	for(unsigned int i=0;i<thisTriangles->getInput_array().getCount();i++)
	{
		if(strcmpi(thisTriangles->getInput_array()[i]->getSemantic(), "VERTEX")==0)
			offset = thisTriangles->getInput_array()[i]->getOffset();
		if(strcmpi(thisTriangles->getInput_array()[i]->getSemantic(), "TEXCOORD")==0)
			texoffset = thisTriangles->getInput_array()[i]->getOffset();
		if(strcmpi(thisTriangles->getInput_array()[i]->getSemantic(), "NORMAL")==0)
			noroffset = thisTriangles->getInput_array()[i]->getOffset();
	}

	glBegin(GL_TRIANGLES);

	for(int i=0;i<numberOfTriangles;i++)
	{
		int index = thisTriangles->getP()->getValue().get(i*numberOfInputs+offset);

		// 法線
		if(noroffset==-255)
		{
			// 法線のインデックスが頂点座標と共通の場合
			glNormal3f(
					thisMesh->getSource_array()[1]->getFloat_array()->getValue().get(index*3),
					thisMesh->getSource_array()[1]->getFloat_array()->getValue().get(index*3+1),
					thisMesh->getSource_array()[1]->getFloat_array()->getValue().get(index*3+2)
			);
		}
		else
		{
			// <p></p>内に法線のインデックスが存在する場合
			int norindex = thisTriangles->getP()->getValue().get(i*numberOfInputs+noroffset);
			glNormal3f(
					thisMesh->getSource_array()[1]->getFloat_array()->getValue().get(norindex*3),
					thisMesh->getSource_array()[1]->getFloat_array()->getValue().get(norindex*3+1),
					thisMesh->getSource_array()[1]->getFloat_array()->getValue().get(norindex*3+2)
			);
		}

		// テクスチャ座標
		if(texoffset!=-255)
		{
			int texindex = thisTriangles->getP()->getValue().get(i*numberOfInputs+texoffset);
			glTexCoord2f(
				thisMesh->getSource_array()[2]->getFloat_array()->getValue().get(texindex*2),
				thisMesh->getSource_array()[2]->getFloat_array()->getValue().get(texindex*2+1)
				);
		}
		// 頂点座標
		glVertex3f(
			thisMesh->getSource_array()[0]->getFloat_array()->getValue().get(index*3),
			thisMesh->getSource_array()[0]->getFloat_array()->getValue().get(index*3+1),
			thisMesh->getSource_array()[0]->getFloat_array()->getValue().get(index*3+2)
			);
	}

	glEnd();
}

// COLLADA ドキュメントの描画
void RenderDAE()
{
	// g_iGeometryElementCount数回描画
	for(int currentGeometry=0;currentGeometry<g_iGeometryElementCount;currentGeometry++)
	{
		// 現在のジオメトリの取得
		domGeometry *thisGeometry;
		g_dae->getDatabase()->getElement((daeElement**)&thisGeometry,currentGeometry, NULL, "geometry");

		// メッシュの取得
		domMesh *thisMesh = thisGeometry->getMesh();

		// Triangleの場合
		int triangleElementCount = (int)(thisMesh->getTriangles_array().getCount());
		for(int currentTriangle=0;currentTriangle<triangleElementCount;currentTriangle++)
		{
			domTriangles* thisTriangles = thisMesh->getTriangles_array().get(0);
			RenderTriangle(thisMesh, thisTriangles);
		}
	}
}

// 描画関数
void display(void)
{
	//
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(60.0, (double)SCREENX / (double)SCREENY, 0.1, 3000.0);
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

	// テクスチャ
	if(g_TextureObject.size() >= 1)
		glBindTexture(GL_TEXTURE_2D, g_TextureObject[0]);
	else
		glDisable(GL_TEXTURE_2D);

	// COLLADAドキュメントの描画
	RenderDAE();

	glFlush();
}

// 三角形化(Polylist)
void ConvertPolylistToTriangles(domMesh *thisMesh, domPolylist *thisPolylist)
{
	// 4角形を3角形化
	domTriangles *thisTriangles = (domTriangles *)thisMesh->createAndPlace("triangles");
	unsigned int triangles = 0;
	thisTriangles->setMaterial(thisPolylist->getMaterial());
	domP* p_triangles = (domP*)thisTriangles->createAndPlace("p");

	for(int i=0; i<(int)(thisPolylist->getInput_array().getCount()); i++)
	{
		thisTriangles->placeElement( thisPolylist->getInput_array()[i]->clone() );
	}

	// Get the number of inputs and primitives for the polygons array
	int numberOfInputs = (int)getMaxOffset(thisPolylist->getInput_array()) + 1;
	int numberOfPrimitives = (int)(thisPolylist->getVcount()->getValue().getCount());

	unsigned int offset = 0;

	for(int j = 0; j < numberOfPrimitives; j++)
	{	
		int triangleCount = thisPolylist->getVcount()->getValue()[j] -2;
		// Write out the primitives as triangles, just fan using the first element as the base
		int idx = numberOfInputs;
		for(int k = 0; k < triangleCount; k++)
		{
			// First vertex
			for(int l = 0; l < numberOfInputs; l++)
			{
				int a = thisPolylist->getP()->getValue()[offset + l];
				float b;
				memcpy(&b, &a, sizeof(float));
				p_triangles->getValue().append(thisPolylist->getP()->getValue()[offset + l]);
			}
			// Second vertex
			for(int l = 0; l < numberOfInputs; l++)
			{
				p_triangles->getValue().append(thisPolylist->getP()->getValue()[offset + idx + l]);
			}
			// Third vertex
			idx += numberOfInputs;
			for(int l = 0; l < numberOfInputs; l++)
			{
				p_triangles->getValue().append(thisPolylist->getP()->getValue()[offset + idx + l]);
			}
			//thisTriangles->setCount(thisTriangles->getCount()+1);
			triangles++;
		}
		offset += thisPolylist->getVcount()->getValue()[j] * numberOfInputs;
	}

	thisTriangles->setCount( triangles );
}

// 三角形化(Polygons)
void ConvertPolygonsToTriangles(domMesh *thisMesh, domPolygons *thisPolygons)
{
	// 3角形化
	domTriangles *thisTriangles = (domTriangles *)thisMesh->createAndPlace("triangles");
	thisTriangles->setCount( 0 );
	thisTriangles->setMaterial(thisPolygons->getMaterial());
	domP* p_triangles = (domP*)thisTriangles->createAndPlace("p");

	// Give the new <triangles> the same <input> and <parameters> as the old <polygons>
	for(int i=0; i<(int)(thisPolygons->getInput_array().getCount()); i++)
	{
		thisTriangles->placeElement( thisPolygons->getInput_array()[i]->clone() );
	}
	// Get the number of inputs and primitives for the polygons array
	int numberOfInputs = (int)getMaxOffset(thisPolygons->getInput_array()) +1;
	int numberOfPrimitives = (int)(thisPolygons->getP_array().getCount());

	// Triangulate all the primitives, this generates all the triangles in a single <p> element
	for(int j = 0; j < numberOfPrimitives; j++)
	{
		// Check the polygons for consistancy (some exported files have had the wrong number of indices)
		domP * thisPrimitive = thisPolygons->getP_array()[j];
		int elementCount = (int)(thisPrimitive->getValue().getCount());
		if((elementCount%numberOfInputs) != 0)
		{
//			cerr<<"Primitive "<<j<<" has an element count "<<elementCount<<" not divisible by the number of inputs "<<numberOfInputs<<"\n";
			continue;
		}
		else
		{
			int triangleCount = (elementCount/numberOfInputs)-2;
			// Write out the primitives as triangles, just fan using the first element as the base
			int idx = numberOfInputs;
			for(int k = 0; k < triangleCount; k++)
			{
				// First vertex
				for(int l = 0; l < numberOfInputs; l++)
				{
					p_triangles->getValue().append(thisPrimitive->getValue()[l]);
				}
				// Second vertex
				for(int l = 0; l < numberOfInputs; l++)
				{
					p_triangles->getValue().append(thisPrimitive->getValue()[idx + l]);
				}
				// Third vertex
				idx += numberOfInputs;
				for(int l = 0; l < numberOfInputs; l++)
				{
					p_triangles->getValue().append(thisPrimitive->getValue()[idx + l]);
				}
				thisTriangles->setCount(thisTriangles->getCount()+1);
			}
		}
	}
}

// COLLADA関連の初期化
bool InitCOLLADA()
{
	int iRet = 0;
	// COLLADA ドキュメントのロード
	g_dae = new DAE();
	//file:/mushroom_durer.dae
	iRet = g_dae->load("mushroom_durer.dae");
	if(iRet!=DAE_OK)
		return false;

	// ジオメトリ数の取得
	g_iGeometryElementCount =  g_dae->getDatabase()->getElementCount(NULL, "geometry", NULL);

	// Triangles以外だったらTriangles化
	for(int currentGeometry=0;currentGeometry<g_iGeometryElementCount;currentGeometry++)
	{
		// 現在のジオメトリの取得
		domGeometry *thisGeometry;
		g_dae->getDatabase()->getElement((daeElement**)&thisGeometry,currentGeometry, NULL, "geometry");

		// メッシュの取得
		domMesh *thisMesh = thisGeometry->getMesh();

		// Polylistの場合
		int polylistElemntCount = (int)(thisMesh->getPolylist_array().getCount());
		for(int currentPolylist=0;currentPolylist<polylistElemntCount;currentPolylist++)
		{
			domPolylist* thisPolylist = thisMesh->getPolylist_array().get(0);
			ConvertPolylistToTriangles( thisMesh, thisPolylist );
		}

		// Polygonsの場合
		int polygonsElementCount = (int)(thisMesh->getPolygons_array().getCount());
		for(int currentPolygons=0;currentPolygons<polygonsElementCount;currentPolygons++)
		{
			domPolygons* thisPolygons = thisMesh->getPolygons_array().get(0);
			ConvertPolygonsToTriangles( thisMesh, thisPolygons );
		}
	}

	// テクスチャ数の取得
	g_iImageElementCount = g_dae->getDatabase()->getElementCount(NULL, "image", NULL);
	for(int i=0;i<g_iImageElementCount;i++)
	{
		g_Texture.resize( g_Texture.size()+1);
		g_Texture[i] = new CTGATextureHelper;
		// Imageの取得
		domImage* thisImage;
		g_dae->getDatabase()->getElement((daeElement**)&thisImage, i, NULL, "image");

		// ファイル名の取得
		//daeString name =  thisImage->getInit_from()->getValue().getFile();
#if 0
		daeString name =  thisImage->getInit_from()->getValue().getPath();
		char *name2 = (char*)name;
#ifdef __MINGW32__
		if (*name2 == '/')
		{
			name2++;
		}
#endif
#else
		std::string name =  thisImage->getInit_from()->getValue().pathFile();
		char *name2 = (char*)(name.c_str());
#endif
		printf("path : %s\n", name2);
		g_Texture[i]->LoadTGA( name2 );
	}
	
	// テクスチャ生成
	for(unsigned int i=0;i<g_Texture.size();i++)
	{
		GLuint tex;
		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		g_TextureObject.push_back( tex );

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_CLAMP);
	
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, g_Texture[i]->GetWidth(), g_Texture[i]->GetHeight(),
			0, GL_RGB, GL_UNSIGNED_BYTE, g_Texture[i]->GetImage() );
	}

	return true;
}

// COLLADA関連の終了処理
void cleanupCOLLADA()
{
	// 解放処理
	for(unsigned int i=0;i<g_TextureObject.size();i++)
	{
		glDeleteTextures(1, &g_TextureObject[i]);
	}
	g_TextureObject.clear();

	for(unsigned int i=0;i<g_Texture.size();i++)
	{
		g_Texture[i]->Release();
		delete g_Texture[i];
	}
	g_Texture.clear();

	if(g_dae)
	{
		g_dae->cleanup();
	}

	// 終了時に呼ぶ
	DAE::cleanup();
}

// 
int main(int argc, char *argv[])
{
	// GLUT 関連
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	
	glutInitWindowSize(SCREENX, SCREENY);
	glutCreateWindow( "Simple COLLADA Sample" );
	
	glutDisplayFunc( display );

	glEnable(GL_TEXTURE_2D);
	glEnable( GL_DEPTH );
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	
	// COLLADA関連の初期化
	if(!InitCOLLADA())
		return 0;
	
	glutMainLoop();

	// 終了処理
	cleanupCOLLADA();

	return 0;
}