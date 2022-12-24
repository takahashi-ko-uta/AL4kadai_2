#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"
#include "Object3d.h"
#include "Model.h"

#include "GameScene.h"


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

#pragma region 基盤システム初期化

    //WindowsAPIの初期化
    WinApp* winApp = nullptr;
    winApp = new WinApp();
    winApp->Initialize();

    MSG msg{};  // メッセージ

    //DirectX初期化
    DirectXCommon* dxCommon = nullptr;
    dxCommon = new DirectXCommon();
    dxCommon->Initialize(winApp);
    

    //inputの初期化
    Input* input = nullptr;
    input = new Input();
    input->Initialize(winApp);

    //スプライト共通部の初期化
    SpriteCommon* spriteCommon = nullptr;
    spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon);
    spriteCommon->LoadTexture(0, "stage1.png");
    spriteCommon->LoadTexture(1, "stage2.png");
    spriteCommon->LoadTexture(2, "stage3.png");
    //object3dの初期化
    Object3d::StaticInitialize(dxCommon->GetDevice(), WinApp::window_width, WinApp::window_height);
#pragma endregion 基盤システム初期化
      
#pragma region 最初のシーンの初期化

    Sprite* sprite = nullptr;
    sprite = new Sprite();
    sprite->SetTextureIndex(0);
    sprite->Initialize(spriteCommon,2);
    
    //ゲームシーン初期化
    GameScene* gameScene = nullptr;
    gameScene = new GameScene();

    gameScene->Initialize(input,spriteCommon);

#pragma endregion 最初のシーンの初期化
    
#pragma region ゲームループ
    while (true) {

#pragma region 基盤システムの更新
        //Windowsのメッセージ処理
        if (winApp->ProcessMessage()) {
            //ゲームループを抜ける
            break;
        }

        //入力の更新
        input->Update();
#pragma endregion 基盤システムの更新

#pragma region 最初のシーンの更新

        sprite->Update();
        gameScene->Update();

#pragma endregion 最初のシーンの更新
        
        //描画前処理
        dxCommon->PreDraw();
  
#pragma region 最初のシーンの描画

        spriteCommon->PreDraw();
        //sprite->Draw();
        gameScene->SpriteDraw();
        spriteCommon->PostDraw();

        Object3d::PreDraw(dxCommon->GetCommandList());

        gameScene->ObjDraw();

        Object3d::PostDraw();

#pragma endregion 最初のシーンの描画

        //描画後処理
        dxCommon->PostDraw();
    }
#pragma endregion ゲームループ

#pragma region 最初のシーンの終了
    delete sprite;
#pragma endregion 最初のシーンの終了

#pragma region 基盤システムの終了
    //入力解放
    delete input;
    //DirectX解放
    delete dxCommon;
    //WindowsAPIの終了処理
    winApp->Finalize();
    //WindowsAPI解放
    delete winApp;
    //スプライト共通部解放
    delete spriteCommon;
    //ゲームシーン解放
    delete gameScene;

#pragma endregion 基盤システムの終了

    return 0;
}
