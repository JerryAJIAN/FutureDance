#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "QD3DRenderWidget.h"

#include "MikuEngine.h"
#include "Prerequisites.h"
#include "D3D11HLSLProgram.h"
#include "D3D11Prerequisites.h"
#include "FrameListener.h"
#include "Mesh.h"
#include "SubMesh.h"

using namespace Miku;

#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "dxgi.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "MikuEngine.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	
	QD3DRenderWidget renderWidget;
	w.setCentralWidget(&renderWidget);
	HWND hwnd = (HWND)renderWidget.winId();
	if (!renderWidget.app.setup("Example", renderWidget.width(), renderWidget.height(), false, hwnd))
		MessageBoxA(NULL, "App set up failed!", "error", MB_OK | MB_ICONERROR | MB_TASKMODAL);

	w.show();
	return a.exec();
}
