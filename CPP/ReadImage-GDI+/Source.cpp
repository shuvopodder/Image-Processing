#include <Windows.h>
#include <gdiplus.h>
#include <iostream>

#pragma comment (lib,"Gdiplus.lib")

using namespace Gdiplus;

int main()
{
	// Initialize GDI+
	GdiplusStartupInput gdiplusStartupInput;

	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	//Load image from file
	const WCHAR* fileName = L"Lena.png";
	BOOL useEmbeddedColorManagement = TRUE;

	Image* image = Image::FromFile(fileName, useEmbeddedColorManagement);

	if (image->GetLastStatus() == 0) {
		// Successfully loaded the image
		// Use the image object 
		
		//get the width and height
		UINT width = image -> GetWidth();
		UINT height = image -> GetHeight();

		std::cout << "Image dimensions: " << width << " x " << height << std::endl;

		// Obtain an HDC (for example, from a window)
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		Graphics graphics(hdc);

		//Image image(L"Lena.png");
		//graphics.DrawImage(&image, 60, 10);
		graphics.DrawImage(image, 60, 10);

		//clean 
		delete image;
	}
	else {
		//failed to load image
		std::cout << "Failed to load the image!" << std::endl;
	}

	//shutdown GDI+
	GdiplusShutdown(gdiplusToken);
	return 0;
}

/*
* References: 
* GDI+ :
*	https://learn.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-gdi-start
* Bitmaps :
*   https://learn.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-types-of-bitmaps-about
* 
* https://learn.microsoft.com/en-us/windows/win32/api/gdiplusheaders/nf-gdiplusheaders-image-fromfile
* https://learn.microsoft.com/en-us/windows/win32/api/gdiplusheaders/nf-gdiplusheaders-bitmap-frombitmapinfo
* 
* 
*/