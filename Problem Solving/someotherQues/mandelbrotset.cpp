#include <windows.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <iostream>

using namespace DirectX;

// Define the size of the window
const UINT WIDTH = 800;
const UINT HEIGHT = 800;

// Function to calculate the Mandelbrot set
int mandelbrot(float x, float y, int maxIterations) {
    float cx = x;
    float cy = y;
    float zx = 0.0f;
    float zy = 0.0f;
    int iterations = 0;

    while (zx * zx + zy * zy < 4.0f && iterations < maxIterations) {
        float temp = zx * zx - zy * zy + cx;
        zy = 2.0f * zx * zy + cy;
        zx = temp;
        iterations++;
    }

    return iterations;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Create the window
    HWND hWnd;
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, DefWindowProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("Mandelbrot Set"), NULL };
    RegisterClassEx(&wc);
    hWnd = CreateWindow(wc.lpszClassName, _T("Mandelbrot Set"), WS_OVERLAPPEDWINDOW, 100, 100, WIDTH, HEIGHT, NULL, NULL, wc.hInstance, NULL);

    // Initialize DirectX
    DXGI_SWAP_CHAIN_DESC scd;
    ZeroMemory(&scd, sizeof(scd));
    scd.BufferCount = 1;
    scd.BufferDesc.Width = WIDTH;
    scd.BufferDesc.Height = HEIGHT;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = hWnd;
    scd.SampleDesc.Count = 1;
    scd.SampleDesc.Quality = 0;
    scd.Windowed = TRUE;

    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0 };
    D3D_FEATURE_LEVEL featureLevel;
    ID3D11Device* device;
    ID3D11DeviceContext* context;
    IDXGISwapChain* swapChain;
    ID3D11RenderTargetView* renderTargetView;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, featureLevels, ARRAYSIZE(featureLevels),
        D3D11_SDK_VERSION, &scd, &swapChain, &device, &featureLevel, &context);

    // Create render target view
    ID3D11Texture2D* backBuffer;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
    device->CreateRenderTargetView(backBuffer, NULL, &renderTargetView);
    backBuffer->Release();
    context->OMSetRenderTargets(1, &renderTargetView, NULL);

    // Set up the viewport
    D3D11_VIEWPORT viewport;
    ZeroMemory(&viewport, sizeof(viewport));
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = static_cast<FLOAT>(WIDTH);
    viewport.Height = static_cast<FLOAT>(HEIGHT);
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    context->RSSetViewports(1, &viewport);

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    bool running = true;
    while (running) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                running = false;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            // Draw the Mandelbrot set
            context->ClearRenderTargetView(renderTargetView, Colors::Black);

            for (UINT y = 0; y < HEIGHT; ++y) {
                for (UINT x = 0; x < WIDTH; ++x) {
                    float real = -2.5f + 4.0f * x / WIDTH;
                    float imag = -2.0f + 4.0f * y / HEIGHT;
                    int iterations = mandelbrot(real, imag, 1000);

                    // Coloring based on the number of iterations
                    float brightness = iterations < 1000 ? 1.0f - static_cast<float>(iterations) / 1000.0f : 0.0f;
                    XMFLOAT4 color(brightness, brightness, brightness, 1.0f);

                    D3D11_BOX box = { x, y, 0, x + 1, y + 1, 1 };
                    context->UpdateSubresource(backBuffer, 0, &box, &color, sizeof(color), 0);
                }
            }

            swapChain->Present(1, 0);
        }
    }

    // Cleanup
    renderTargetView->Release();
    swapChain->Release();
    context->Release();
    device->Release();
    UnregisterClass(wc.lpszClassName, wc.hInstance);
    return 0;
}
