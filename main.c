#include <stdio.h>
#include "raylib.h"
#define MAX_FRAME_DELAY     30
#define MIN_FRAME_DELAY      1

int main()
{
	Texture2D sprite;
    Texture2D iniciar;
    Texture2D instrucoes;
    Texture2D creditos;
    Texture2D sair;
    Texture2D tela_creditos;
    Texture2D bginstrucoes_tela;
    Texture2D select;
    Texture2D jogador;
    Texture2D ani_minerador;
    Texture2D carta_atual;
    //Texture2D vaso_icon;

    int mouse_x;
    int my;
    //ure2D menu;
    //Tamanho da tela em pixels
	int screenWidth = 1920;
    int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Luzente");

    InitAudioDevice();
    //sons


    int inicializar = 0;
    int animFrames = 0;
    int animframasw = 0;
    int animframasj = 0;
    int animframasd = 0;
    int animframasm = 0;

	// imagens
	sprite = LoadTexture("imagens/menu.png");
    iniciar = LoadTexture("imagens/iniciar.png");
    instrucoes = LoadTexture("imagens/instrucoes.png");
    creditos = LoadTexture("imagens/creditos.png");
    sair = LoadTexture("imagens/sair.png");
    tela_creditos = LoadTexture("imagens/creditos_tela.png");
    bginstrucoes_tela = LoadTexture("imagens/instrucoes_tela.png");
    select = LoadTexture("imagens/select.png");
    //vaso_icon = LoadTexture("sprite.png");


    //dialogos
    Texture2D jornaleiro_fala = LoadTexture("dialogos/dialogo_jornaleiro.png");
    Texture2D daniel_fala = LoadTexture("dialogos/cena021.png");
    Texture2D quarto = LoadTexture("dialogos/cena022.png");
    Texture2D fala_depois_jornaleiro = LoadTexture("dialogos/cena011.png");
    Texture2D inicio_fase_2 = LoadTexture("dialogos/cena02.png");
    Texture2D sala = LoadTexture("dialogos/cena023.png");
    Texture2D mina = LoadTexture("dialogos/cena03.png");
    Texture2D daniel_mina = LoadTexture("dialogos/cena031.png");
    Texture2D caverna = LoadTexture("dialogos/cena032.png");


    Image imScene = LoadImageAnim("cutscene.gif", &inicializar);
    Texture2D texScene = LoadTextureFromImage(imScene);
    unsigned int nextFrameDataOffset = 0;
    unsigned int nextFrameDataOffsetj = 0;
    unsigned int nextFrameDataOffsetd = 0;
    unsigned int nextFrameDataOffsetm = 0;

    Image imScarfyAnim = LoadImageAnim("protagonista_idle.gif", &animFrames);
    Texture2D texScarfyAnim = LoadTextureFromImage(imScarfyAnim);

    Image imScarfyAnim1 = LoadImageAnim("protagonista_walk.gif", &animframasw);
    Texture2D textScarfyAnim1 = LoadTextureFromImage(imScarfyAnim1);

    Image jornaleiro = LoadImageAnim("jornaleiro_idle.gif", &animframasj);
    Texture2D texjornaleiro = LoadTextureFromImage(jornaleiro);

    Image daniel = LoadImageAnim("DanielIdle.gif", &animframasd);
    Texture2D texdaniel = LoadTextureFromImage(daniel);

    Image minerador_andando = LoadImageAnim("Correndo.gif", &animframasm);
    Texture2D texminerador = LoadTextureFromImage(minerador_andando);

    Texture2D minerador_gritando = LoadTexture("MineradorGritando_spritesheet.png");

    Texture2D background = LoadTexture("Fase04.png");
    Texture2D background1 = LoadTexture("Fase01.png");
    Texture2D background2 = LoadTexture("Fase02.png");
    Texture2D background3 = LoadTexture("fase03.png");
    Texture2D background4 = LoadTexture("fase05.png");
    Texture2D background5 = LoadTexture("1.png");
    Texture2D background5_1 = LoadTexture("2.png");
    Texture2D background5_2 = LoadTexture("3.png");

    //cartas

    Texture2D carta1 = LoadTexture("Cartas/carta1.png");
    Texture2D carta2 = LoadTexture("Cartas/carta2.png");
    Texture2D carta3 = LoadTexture("Cartas/carta3.png");
    Texture2D carta4 = LoadTexture("Cartas/carta4.png");
    Texture2D carta5 = LoadTexture("Cartas/carta5.png");
    Texture2D carta6 = LoadTexture("Cartas/carta6.png");
    Texture2D carta7 = LoadTexture("Cartas/carta7.png");
    Texture2D carta8 = LoadTexture("Cartas/carta8.png");
    Texture2D carta9 = LoadTexture("Cartas/Carta-Queimada.png");

    int currentAnimFrame = 0;
    int currentAnimFramej = 0;
    int currentAnimFramed = 0;
    int currentAnimFramem = 0;
    int frameDelay = 2;
    int frameDelay1 = 10;
    int frameDelayj = 2;
    int frameDelayd = 2;
    int frameDelaym = 2;
    int frameCounter = 0;
    int frameCounterj = 0;
    int frameCounterd = 0;
    int frameCounterm = 0;
    int tela_base = 0;
    int jornaleiro_x = 1830;
    int porta_x = 3223;
    int daniel_x = 870;
    int daniel_x1 = 3979;
    int andando = 0;
    int popup = 800;
    int time = 500;
    int fade = 0;
    int carta = 1;
    int delay_mineiro = 0;

    //menu = LoadTexture("menu.png")
	bool start = true;
    bool creditos_tela = false;
    bool instrucoes_tela = false;
    bool cutscene_tela = false;

    //fases
    bool fase1 = false;
    bool fase2 = false;
    bool fase3 = false;
    bool fase4 = false;
    bool fase5 = false;
    bool fase6 = false;


    bool parado = false;
    bool vaso = false;
    bool mala = false;
    bool dialogo_jornaleiro = false;
    bool jornaleiro_falando = false;
    bool daniel_falando = false;
    bool daniel_falando1 = false;
    bool liberado = false;
    bool fala = false;
    bool player_direita = true;
    bool player_esquerda = false;
    bool fadeout = false;
    bool fadein = false;
    bool fim = false;
    bool lendo_cartas = false;
    bool minerador = false;

    Rectangle caixa_de_dialogo = (Rectangle){0, 0,1920, 330};
    Rectangle mineiro_andando_rec = (Rectangle){0,0,1000,1000};
    Rectangle mineiro_gritando_rec = (Rectangle){0,0,239,552};
    int minerador_walk = 1920;

    //jogador
    int player_x = 15+(imScarfyAnim.width/2);

    SetTargetFPS(60);
	while(!WindowShouldClose())
	{
        if (start){
        
        int atual_xmouse = GetMouseX();
        int atual_ymouse = GetMouseY();
        if (IsKeyPressed(KEY_SPACE)){
            ToggleFullscreen();
        }

        // captura do click do mouse, utilizado para interações no menu
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mouse_x = atual_xmouse;
            my = atual_ymouse;
        }

        // iniciar interação
        if (mouse_x >= 280 && mouse_x <= (280+iniciar.width)){
            if (my >= 337 && my <= (377+iniciar.height)){
                start = false;
                cutscene_tela = true;
            }
        }
        // instrucoes interação
        if (mouse_x >= 250 && mouse_x <= (250+iniciar.width)){
            if (my >= 423 && my <= (423+iniciar.height)){
                start = false;
                instrucoes_tela = true;
            }
        }
        //sair interação
        if (mouse_x >= 300 && mouse_x <= (300+iniciar.width)){
            if (my >= 516 && my <= (516+iniciar.height)){
                CloseWindow();
            }
        }
        //creditos interação
        if (mouse_x >= 264 && mouse_x <= (264+iniciar.width)){
            if (my >= 615 && my <= (615+iniciar.height)){
                start = false;
                creditos_tela = true;
            }
        }

        // sprites em tela
		BeginDrawing();
		
			ClearBackground(RAYWHITE);
			

			DrawTexture(sprite, 0, 0, WHITE);
            DrawTexture(iniciar, 280, 337, WHITE);
            DrawTexture(instrucoes, 250, 423, WHITE);
            DrawTexture(creditos, 264, 615, WHITE);
            DrawTexture(sair, 300, 516, WHITE);
            // iniciar select
            if (atual_xmouse >= 280 && atual_xmouse <= (280+iniciar.width)){
                if (atual_ymouse >= 337 && atual_ymouse <= (377+iniciar.height)){
                    DrawTexture(select, 280-30, 337, WHITE);
                }
            }
            // instrucoes select
            if (atual_xmouse >= 250 && atual_xmouse <= (250+iniciar.width)){
                if (atual_ymouse >= 423 && atual_ymouse <= (423+iniciar.height)){
                    DrawTexture(select, 250-30, 423, WHITE);
                }
            }
            // creditos select
            if (atual_xmouse >= 264 && atual_xmouse <= (264+iniciar.width)){
                if (atual_ymouse >= 615 && atual_ymouse <= (615+iniciar.height)){
                    DrawTexture(select, 264-30, 615, WHITE);
                }
            }
            // sair select
            if (atual_xmouse >= 300 && atual_xmouse <= (300+iniciar.width)){
                if (atual_ymouse >= 516 && atual_ymouse <= (516+iniciar.height)){
                    DrawTexture(select, 300-30, 516, WHITE);
                }
            }
            

			
		EndDrawing();
        
        }

        if(creditos_tela){

            if (IsKeyPressed(KEY_SPACE)){
            ToggleFullscreen();
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                mouse_x = 0;
                my = 0;
                creditos_tela = false;
                start = true;
            }

            BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawTexture(tela_creditos, 0, 0, WHITE);

            EndDrawing();
        }

        if(instrucoes_tela){

            if (IsKeyPressed(KEY_SPACE)){
            ToggleFullscreen();
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                mouse_x = 0;
                my = 0;
                instrucoes_tela = false;
                start = true;
            }

            BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawTexture(bginstrucoes_tela, 0, 0, WHITE);

            EndDrawing();
        }

        if(cutscene_tela){
        if (IsKeyPressed(KEY_SPACE)){
        ToggleFullscreen();
        }
        // Update
        //----------------------------------------------------------------------------------
        frameCounter++;
        if (frameCounter >= frameDelay1)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= inicializar){
                currentAnimFrame = 0;
                cutscene_tela = false;
                lendo_cartas = true;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScene.width*imScene.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(texScene, ((unsigned char *)imScene.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay1 > MAX_FRAME_DELAY) frameDelay1 = MAX_FRAME_DELAY;
        else if (frameDelay1 < MIN_FRAME_DELAY) frameDelay1 = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            for (int i = 0; i < MAX_FRAME_DELAY; i++)
            {
                if (i < frameDelay1) DrawRectangle(190 + 21*i, 300, 20, 20, RED);
                DrawRectangleLines(190 + 21*i, 300, 20, 20, MAROON);
            }

            DrawTexture(texScene, 0, 0, WHITE);

        EndDrawing();

        }
        
        if(lendo_cartas){

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                mouse_x = GetMouseX();
                if(mouse_x < screenWidth/2){
                    carta -= 1;
                    if(carta == 0){
                        carta = 1;
                    }
                }
                else{
                    carta += 1;
                }
            }

            switch (carta)
            {
            case 1:
                carta_atual = carta1;
                break;
                
            case 2:
                carta_atual = carta2;
                break;
                
            case 3:
                carta_atual = carta3;
                break;
                
            case 4:
                carta_atual = carta4;
                break;
                
            case 5:
                carta_atual = carta5;
                break;
                
            case 6:
                carta_atual = carta6;
                break;
                
            case 7:
                carta_atual = carta7;
                break;
                
            case 8:
                carta_atual = carta8;
                break;
            case 9:
                mouse_x = 0;
                lendo_cartas = false;
                fase1 = true;
                parado = true;
            }


        BeginDrawing();
            DrawTexturePro(carta_atual, (Rectangle){0,0, 595,842}, (Rectangle){screenWidth/2,screenHeight/2,595,842}, (Vector2){carta_atual.width/2, carta_atual.height/2}, 0, WHITE);
        EndDrawing();
        }

        if(fase1){


        if (fadeout)
        {
            fade += 1;
        }
        if(fadein){
            fade -= 1;
        }

        if (fade == 255)
        {
            fade = 255;
            fadeout = false;
        }
        if (fade == 0)
        {
            fade = 0;
            fadein = false;
        }

        if (IsKeyPressed(KEY_SPACE)){
        ToggleFullscreen();
        }
        // Update
        //----------------------------------------------------------------------------------
        if(parado){
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames){
                currentAnimFrame = 0;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
        else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------


        jogador = texScarfyAnim;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouse_x = GetMouseX();
            my = GetMouseY();
            if(mouse_x > screenWidth/2){
                andando = mouse_x - screenWidth/2;
            }
            if(mouse_x < screenWidth/2){
                andando = screenWidth/2 - mouse_x;
            }
            if(my > 360){
            parado = false;
            frameCounter = 0;
            currentAnimFrame = 0;
            }
        }
        }

        else{
            frameCounter++;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                mouse_x = GetMouseX();
                my = GetMouseY();
                if(my > 360){
                if(mouse_x > screenWidth/2){
                    andando = mouse_x - screenWidth/2;
                }
                if(mouse_x < screenWidth/2){
                    andando = screenWidth/2 - mouse_x;
                }
                }
            }
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animframasw){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim1.width*imScarfyAnim1.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(textScarfyAnim1, ((unsigned char *)imScarfyAnim1.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------

            jogador = textScarfyAnim1;
            //----------------------------------------------------------------------------------
        


                if (andando > 0){
                    if (player_x <= screenWidth/2-3 || player_x >= screenWidth/2+3){
                        if(mouse_x > player_x){
                            player_direita = true;
                            player_esquerda = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x + 5;
                            if(player_x > mouse_x){
                                player_x = mouse_x;
                            }
                            if(player_x > screenWidth-75){
                                player_x = screenWidth-75;
                                mouse_x = screenWidth-75;
                            }

                            }
                        }
                        if(mouse_x < player_x){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x - 5;
                            if(player_x < mouse_x){
                                    player_x = mouse_x;
                                }
                            if(player_x < 75){
                                player_x = 75;
                                mouse_x = 75;
                            }
                            }
                        }

                        
                        }
                    else if(player_x >= screenWidth/2 && (tela_base >= -3883 && tela_base <= 0)){
                        

                        if(mouse_x >= screenWidth/2){
                        player_direita = true;
                        player_esquerda = false;
                        if (andando > 0){
                            andando -= 5;
                        tela_base = tela_base - 5;
                        jornaleiro_x -= 5;
                            if (tela_base < -3883)
                            {
                                tela_base = -3882;
                                jornaleiro_x = -3882+1830;
                            }
                        }
                        }
                        if(mouse_x <= screenWidth/2){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            tela_base = tela_base+5;
                            jornaleiro_x += 5;
                            if (tela_base > -1)
                            {
                                tela_base = 0;
                                jornaleiro_x = 1830;
                            }
                        }
                        }
                        
                        
                    }

                    
                }
                else{
                    parado = true;
                    frameCounter = 0;
                    currentAnimFrame = 0;
                }
            
        }
        
        frameCounterj++;
        if (frameCounterj >= frameDelayj)
        {
            currentAnimFramej++;
            if (currentAnimFramej >= animframasj-15){
                currentAnimFramej = 0;
            }
            nextFrameDataOffsetj = jornaleiro.width*jornaleiro.height*4*currentAnimFramej;

            UpdateTexture(texjornaleiro, ((unsigned char *)jornaleiro.data) + nextFrameDataOffsetj);

            frameCounterj = 0;
        }

        if (frameDelayj > MAX_FRAME_DELAY) frameDelayj = MAX_FRAME_DELAY;
        else if (frameDelayj < MIN_FRAME_DELAY) frameDelayj = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if (mouse_x >= jornaleiro_x && mouse_x <= (jornaleiro_x+425)){
                if (my >= screenHeight/2+155 && my <= ((screenHeight/2+155)+360)){
                    jornaleiro_falando = true;
                }
                }
        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(my < 360){
                caixa_de_dialogo.y += 330;
                if (caixa_de_dialogo.y > jornaleiro_fala.height-330)
                {
                    jornaleiro_falando = false;
                    dialogo_jornaleiro = true;
                    caixa_de_dialogo.y = 0;
                }
                
            }
            
        }


        if (dialogo_jornaleiro)
        {
            popup -= 1;
            if(popup == 600 || popup == 300){
                caixa_de_dialogo.y += 330;
                fala = true;
            }
            else if (popup == 10)
            {
                caixa_de_dialogo.y = 0;
                fala = false;
            }
            
        }
        

        if (tela_base <= -3850 && dialogo_jornaleiro)
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (mouse_x > screenWidth/2)
                {
                    fadeout = true;
                }
                
            }
            
        }
        
        if(fade == 255){
            
                    player_x = 0;
                    andando = 0;
                    mouse_x = 0;
                    tela_base = 0;
                    fala = true;
                    popup = 600;
                    caixa_de_dialogo.y = 0;
                    fadein = true;
                    fadeout = false;
                    fase1 = false;
                    fase2 = true;
        }
        
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(background1, tela_base, 0, WHITE);
            DrawTextureEx(texjornaleiro, (Vector2){jornaleiro_x, screenHeight/2+60},0, 0.42f, WHITE);

            if(!parado){
                if(mouse_x < player_x){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                }
                else{
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                }
            }
            else{
                if(player_direita){
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                    }
                else if(player_esquerda){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                }
            }

            //DrawTextureEx(jogador,(Vector2){player_x-(textScarfyAnim1.width/2),screenHeight/2+155}, 0, 0.65f, WHITE);
            if(fala){
                DrawTextureRec(fala_depois_jornaleiro, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            if(jornaleiro_falando){
                DrawTextureRec(jornaleiro_fala, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            
            if(fadein || fadeout){
                DrawRectangle(0,0,1920,1080, (Color){0,0,0, fade});
            }
        EndDrawing();

        }

        if(fase2){
        
        if (fadeout)
        {
            fade += 1;
        }
        if(fadein){
            fade -= 1;
        }

        if (fade == 255)
        {
            fade = 255;
            fadeout = false;
        }
        if (fade == 0)
        {
            fade = 0;
            fadein = false;
        }

        if (IsKeyPressed(KEY_SPACE)){
        ToggleFullscreen();
        }
        // Update
        //----------------------------------------------------------------------------------
        if(parado){
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames){
                currentAnimFrame = 0;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
        else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------


        jogador = texScarfyAnim;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouse_x = GetMouseX();
            my = GetMouseY();
            if(mouse_x > screenWidth/2){
                andando = mouse_x - screenWidth/2;
            }
            if(mouse_x < screenWidth/2){
                andando = screenWidth/2 - mouse_x;
            }
            if(my > 360){
            parado = false;
            frameCounter = 0;
            currentAnimFrame = 0;
            }
        }
        }

        else{
            frameCounter++;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                mouse_x = GetMouseX();
                my = GetMouseY();
                if(my > 360){
                if(mouse_x > screenWidth/2){
                    andando = mouse_x - screenWidth/2;
                }
                if(mouse_x < screenWidth/2){
                    andando = screenWidth/2 - mouse_x;
                }
                }
            }
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animframasw){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim1.width*imScarfyAnim1.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(textScarfyAnim1, ((unsigned char *)imScarfyAnim1.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------

            jogador = textScarfyAnim1;
            //----------------------------------------------------------------------------------
        


                if (andando > 0){
                    if (player_x <= screenWidth/2-3 || player_x >= screenWidth/2+3){
                        if(mouse_x > player_x){
                            player_direita = true;
                            player_esquerda = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x + 5;
                            if(player_x > mouse_x){
                                player_x = mouse_x;
                            }
                            if (player_x > screenWidth-75)
                            {
                                player_x = screenWidth-75;
                                mouse_x = screenWidth-75;
                            }
                            

                            }
                        }
                        if(mouse_x < player_x){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x - 5;
                            if(player_x < mouse_x){
                                    player_x = mouse_x;
                                }
                            }
                            if (player_x < 75)
                            {
                                player_x = 75;
                                mouse_x = 75;
                            }
                            
                        }

                        
                        }
                    else if(player_x >= screenWidth/2 && (tela_base >= -3471 && tela_base <= 0)){
                        

                        if(mouse_x >= screenWidth/2){
                        player_direita = true;
                        player_esquerda = false;
                        if (andando > 0){
                            andando -= 5;
                        tela_base = tela_base - 5;
                        porta_x -= 5;
                            if (tela_base < -3471)
                            {
                                tela_base = -3470;
                                porta_x = -3223+1830;
                            }
                        }
                        }
                        if(mouse_x <= screenWidth/2){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            tela_base = tela_base+5;
                            porta_x += 5;
                            if (tela_base > -1)
                            {
                                tela_base = 0;
                                porta_x = 3223;
                            }
                        }
                        }
                        
                        
                    }

                    
                }
                else{
                    parado = true;
                    frameCounter = 0;
                    currentAnimFrame = 0;
                }
            
        }
        
        frameCounterd++;
        if (frameCounterd >= frameDelayd)
        {
            currentAnimFramed++;
            if (currentAnimFramed >= animframasd){
                currentAnimFramed = 0;
            }
            nextFrameDataOffsetd = daniel.width*daniel.height*4*currentAnimFramed;

            UpdateTexture(texdaniel, ((unsigned char *)daniel.data) + nextFrameDataOffsetd);

            frameCounterd = 0;
        }

        if (frameDelayd > MAX_FRAME_DELAY) frameDelayd = MAX_FRAME_DELAY;
        else if (frameDelayd < MIN_FRAME_DELAY) frameDelayd = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if (mouse_x >= porta_x && mouse_x <= (porta_x+425)){
                if (my >= screenHeight/2+155 && my <= ((screenHeight/2+155)+360)){
                    daniel_falando = true;
                }
                }
        }
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(my < 360){
                caixa_de_dialogo.y += 330;
                if (caixa_de_dialogo.y > daniel_fala.height-330)
                {
                    daniel_falando = false;
                    fadeout = true;
                }
                
            }
            
        }
        
        if(fade == 255){
            daniel_falando = false;
            caixa_de_dialogo.y = 0;
            player_x = 1725;
            andando = 0;
            mouse_x = 0;
            player_esquerda = false;
            player_direita = true;
            fadeout = false;
            fadein = true;
            fase2 = false;
            fase3 = true;
        }

        if(fala){
            popup -= 1;
            if (popup == 300)
            {
                caixa_de_dialogo.y += 330;
            }
            else if (popup < 5 || daniel_falando)
            {
                caixa_de_dialogo.y = 0;
                fala = false;
                popup = 800;
            }
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangle(porta_x, 595, 230, 305, RAYWHITE);
            DrawTexture(background2, tela_base, 0, WHITE);
            //DrawTextureEx(texdaniel, (Vector2){porta_x, screenHeight/2+60},0, 0.65f, WHITE);
            if(player_x <= porta_x+212){
                DrawTexturePro(texdaniel, (Rectangle){0,0,-500,500}, (Rectangle){porta_x, screenHeight/2+60, 325,325}, (Vector2){50,0},0, WHITE);
            }
            else{
                DrawTexturePro(texdaniel, (Rectangle){0,0,500,500}, (Rectangle){porta_x, screenHeight/2+60, 325,325}, (Vector2){0,0},0, WHITE);
            }
            //DrawTextureEx(jogador,(Vector2){player_x-(textScarfyAnim1.width/2),screenHeight/2+155}, 0, 0.65f, WHITE);

            if(!parado){
                if(mouse_x < player_x){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                }
                else{
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                }
            }
            else{
                if(player_direita){
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                    }
                else if(player_esquerda){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+155, 325, 325}, (Vector2){162,0}, 0, WHITE);
                }
            }

            if(daniel_falando){
                DrawTextureRec(daniel_fala, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            if(fala){
                DrawTextureRec(inicio_fase_2, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            
            if(fadein || fadeout){
                DrawRectangle(0,0,1920,1080, (Color){0,0,0, fade});
            }
        EndDrawing();

        }

        if(fase3){

        if (fadeout)
        {
            fade += 1;
        }
        if(fadein){
            fade -= 1;
        }

        if (fade == 255)
        {
            fade = 255;
            fadeout = false;
        }
        if (fade == 0)
        {
            fade = 0;
            fadein = false;
        }

        if (IsKeyPressed(KEY_SPACE)){
        ToggleFullscreen();
        }
        // Update
        //----------------------------------------------------------------------------------
        if(parado){
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames){
                currentAnimFrame = 0;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
        else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------


        jogador = texScarfyAnim;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouse_x = GetMouseX();
            my = GetMouseY();
            if(my > 360){
                if(mouse_x != player_x){
                parado = false;
                frameCounter = 0;
                currentAnimFrame = 0;
                }
            }
        }
        }

        else{
            frameCounter++;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                mouse_x = GetMouseX();
                my = GetMouseX();
            }
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animframasw){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim1.width*imScarfyAnim1.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(textScarfyAnim1, ((unsigned char *)imScarfyAnim1.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------

            jogador = textScarfyAnim1;
            //----------------------------------------------------------------------------------
            

            if (frameDelayd > MAX_FRAME_DELAY) frameDelayd = MAX_FRAME_DELAY;
            else if (frameDelayd < MIN_FRAME_DELAY) frameDelayd = MIN_FRAME_DELAY;
            
            if (player_x != mouse_x){
                    if(mouse_x > player_x){
                    player_direita = true;
                    player_esquerda = false;
                    player_x = player_x + 5;
                        if(player_x > mouse_x){
                            player_x = mouse_x;
                        }
                    if(player_x > screenWidth-75){
                        player_x = screenWidth-75;
                        mouse_x = screenWidth-75;
                    }
                    }
                
                    if(mouse_x < player_x){
                    player_esquerda = true;
                    player_direita = false;
                    player_x = player_x - 5;
                        if(player_x < mouse_x){
                            player_x = mouse_x;
                        }
                    if(player_x < 75){
                        player_x = 75;
                        mouse_x = 75;
                    }
                    }
            
            }
            else{
                parado = true;
                frameCounter = 0;
                currentAnimFrame = 0;
            }
        }
        frameCounterd++;
        if (frameCounterd >= frameDelayd)
        {
            currentAnimFramed++;
            if (currentAnimFramed >= animframasd){
                currentAnimFramed = 0;
            }
            nextFrameDataOffsetd = daniel.width*daniel.height*4*currentAnimFramed;

            UpdateTexture(texdaniel, ((unsigned char *)daniel.data) + nextFrameDataOffsetd);

            frameCounterd = 0;
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            my = GetMouseY();
        }
        

        //pra mudar a cena é aqui!
        if(liberado){
            if (mouse_x > 1725)
            {
                fadeout = true;
            }
        }

        if(liberado && fade == 255){
            liberado = false;
            daniel_falando = false;
            fala = true;
            player_direita = false;
            player_esquerda = true;
            player_x = 1725;
            andando = 0;
            mouse_x = 1725;
            caixa_de_dialogo.y = 0;
            fadeout = false;
            fadein = true;
            fase3 = false;
            fase4 = true;
        }
        //dialogar com daniel
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if(!daniel_falando){
                if(mouse_x >= 1262 && mouse_x <= (1262+146)){
                    if(my >= 479 && my <= (479+450)){
                        mala = true;
                    }
                }
                else{
                    if(mala){
                        if(my < 360){
                            caixa_de_dialogo.y += 330;
                            if(caixa_de_dialogo.y > 660){
                                mala = false;
                                daniel_falando = true;
                            }
                        }
                    }
                }
            }
        }
        

        //dialogar com mala
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if(daniel_falando){
                if (mouse_x >= 441 && mouse_x <= (441+353)){
                    if (my >= 739 && my <= (739+127)){
                        mala = true;
                    }
                }
                else{
                    if (mala)
                    {
                        if (my < 360)
                        {
                            caixa_de_dialogo.y += 330;
                            if(caixa_de_dialogo.y > (330*13)){
                                mala = false;
                                daniel_falando = false;
                                liberado = true;
                                caixa_de_dialogo.y = 0;
                            }
                        }
                        
                    }
                    
                }
            }
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(background3, 0,0, WHITE);
            //DrawTextureEx(texdaniel, (Vector2){screenWidth/2+150, screenHeight/2-250},0, 1.40f, WHITE);
            if(player_x <= screenWidth/2+150+350){
                DrawTexturePro(texdaniel, (Rectangle){0,0,-500,500}, (Rectangle){screenWidth/2+150, screenHeight/2-250, 700,700}, (Vector2){250,0},0, WHITE);
            }
            else{
                DrawTexturePro(texdaniel, (Rectangle){0,0,500,500}, (Rectangle){screenWidth/2+150, screenHeight/2-250, 700,700}, (Vector2){0,0},0, WHITE);
            }


            if(!parado){
                if(mouse_x < player_x){
                    DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                }
                else{
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                }
            }
            else{
                if(player_direita){
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                    }
                else if(player_esquerda){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                }
            }

            if(mala){
                DrawTextureRec(quarto, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            

            if(fadein || fadeout){
                DrawRectangle(0,0,1920,1080, (Color){0,0,0, fade});
            }
        EndDrawing();
        }

        if (fase4){
        
        if (fadeout)
        {
            fade += 1;
        }
        if(fadein){
            fade -= 1;
        }

        if (fade == 255)
        {
            fade = 255;
            fadeout = false;
        }
        if (fade == 0)
        {
            fade = 0;
            fadein = false;
        }


        if (IsKeyPressed(KEY_SPACE)){
        ToggleFullscreen();
        }
        // Update
        //----------------------------------------------------------------------------------
        if(!fala){
        if(parado){
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames){
                currentAnimFrame = 0;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
        else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------


        jogador = texScarfyAnim;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mouse_x = GetMouseX();
            my = GetMouseY();
            if(my > 360){
            parado = false;
            frameCounter = 0;
            currentAnimFrame = 0;
            }
        }
        }

        else{
        frameCounter++;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            mouse_x = GetMouseX();
            my = GetMouseX();
        }
        if (frameCounter >= frameDelay)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= animframasw){
                currentAnimFrame = 0;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScarfyAnim1.width*imScarfyAnim1.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(textScarfyAnim1, ((unsigned char *)imScarfyAnim1.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
        else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------

        jogador = textScarfyAnim1;
        //----------------------------------------------------------------------------------
        
        if (player_x != mouse_x){
            if(mouse_x > player_x){
            player_direita = true;
            player_esquerda = false;
            player_x = player_x + 10;
                if(player_x > mouse_x){
                    player_x = mouse_x;
                }
            if(player_x > screenWidth-75){
                player_x = screenWidth-75;
                mouse_x = screenWidth-75;
            }
            }

            if(mouse_x < player_x){
            player_esquerda = true;
            player_direita = false;
            player_x = player_x - 10;
            if(player_x < mouse_x){
                player_x = mouse_x;
            }
            if(player_x < 75){
                player_x = 75;
                mouse_x = 75;
            }
            }
        }
        else{
            parado = true;
            frameCounter = 0;
            currentAnimFrame = 0;
        }
        }
        }
        else{
            frameCounter++;
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animFrames){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------


            jogador = texScarfyAnim;

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                caixa_de_dialogo.y += 330;
                if(caixa_de_dialogo.y > 330*3){
                    fala = false;
                }
            }
        }

        frameCounterd++;
        if (frameCounterd >= frameDelayd)
        {
            currentAnimFramed++;
            if (currentAnimFramed >= animframasd){
                currentAnimFramed = 0;
            }
            nextFrameDataOffsetd = daniel.width*daniel.height*4*currentAnimFramed;

            UpdateTexture(texdaniel, ((unsigned char *)daniel.data) + nextFrameDataOffsetd);

            frameCounterd = 0;
        }

        
        if (mouse_x >= 1189 && mouse_x <= (1189+78)){
            if (my >= 589 && my <= (589+161)){
                vaso = true;
            }
        }
        if(vaso){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                my = GetMouseY();
                if(my < 360){
                    caixa_de_dialogo.y += 330;
                    if(caixa_de_dialogo.y > 330*7){
                        caixa_de_dialogo.y = 330*4;
                        vaso = false;
                        liberado = true;
                    }
                }
            }
        }
        
        if(liberado){
            if(mouse_x < 640){
                fadeout = true;
            }
        }

        if(liberado && fade == 255){
            player_x = screenWidth/2-15;
            mouse_x = screenWidth/2-15;
            andando = 0;
            tela_base = 0;
            fala = true;
            caixa_de_dialogo.y = 0;
            liberado = false;
            player_esquerda = false;
            player_direita = true;
            fadeout = false;
            fadein = true;
            fase4 = false;
            fase5 = true;
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            //DrawTexture(texScarfyAnim, 0, 0, WHITE);
            DrawTextureEx(background, (Vector2){0,0}, 0, 0.5f, WHITE);


            if(player_x <= screenWidth/2-250+350){
                DrawTexturePro(texdaniel, (Rectangle){0,0,-500,500}, (Rectangle){screenWidth/2-250, screenHeight/2-180, 700,700}, (Vector2){250,0},0, WHITE);
            }
            else{
                DrawTexturePro(texdaniel, (Rectangle){0,0,500,500}, (Rectangle){screenWidth/2-250, screenHeight/2-180, 700,700}, (Vector2){0,0},0, WHITE);
            }

            //player draw
            if(!parado){
                if(mouse_x < player_x){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                }
                else{
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                }
            }
            else{
                if(player_direita){
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                    }
                else if(player_esquerda){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2-120, 675, 675}, (Vector2){337,0}, 0, WHITE);
                }
            }
        
            if(fala){
                DrawTextureRec(sala, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }

            if(vaso){
                DrawTextureRec(sala, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            

            if(fadein || fadeout){
                DrawRectangle(0,0,1920,1080, (Color){0,0,0, fade});
            }
        EndDrawing();
        }

        if(fase5){
        
        if (fadeout)
        {
            fade += 1;
        }
        if(fadein){
            fade -= 1;
        }

        if (fade == 255)
        {
            fade = 255;
            fadeout = false;
        }
        if (fade == 0)
        {
            fade = 0;
            fadein = false;
        }
        


        if (IsKeyPressed(KEY_SPACE)){
        ToggleFullscreen();
        }
        // Update
        //----------------------------------------------------------------------------------
        if(!fala){
        if(parado){
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames){
                currentAnimFrame = 0;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
        else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------


        jogador = texScarfyAnim;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouse_x = GetMouseX();
            my = GetMouseY();
            if(mouse_x > screenWidth/2){
                andando = mouse_x - screenWidth/2;
            }
            if(mouse_x < screenWidth/2){
                andando = screenWidth/2 - mouse_x;
            }
            if(my > 360){
            parado = false;
            frameCounter = 0;
            currentAnimFrame = 0;
            }
        }
        }

        else{
            frameCounter++;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                mouse_x = GetMouseX();
                my = GetMouseY();
                if(my > 360){
                if(mouse_x > screenWidth/2){
                    andando = mouse_x - screenWidth/2;
                }
                if(mouse_x < screenWidth/2){
                    andando = screenWidth/2 - mouse_x;
                }
                }
            }
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animframasw){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim1.width*imScarfyAnim1.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(textScarfyAnim1, ((unsigned char *)imScarfyAnim1.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------

            jogador = textScarfyAnim1;
            //----------------------------------------------------------------------------------
        


                if (andando > 0){
                    if (player_x <= screenWidth/2-3 || player_x >= screenWidth/2+3){
                        if(mouse_x > player_x){
                            player_direita = true;
                            player_esquerda = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x + 5;
                            if(player_x > mouse_x){
                                player_x = mouse_x;
                            }
                            if (player_x > screenWidth-75)
                            {
                                player_x = screenWidth-75;
                                mouse_x = screenWidth-75;
                            }
                            

                            }
                        }
                        if(mouse_x < player_x){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x - 5;
                            if(player_x < mouse_x){
                                    player_x = mouse_x;
                                }
                            }
                            if (player_x < 75)
                            {
                                player_x = 75;
                                mouse_x = 75;
                            }
                            
                        }

                        
                        }
                    else if(player_x >= screenWidth/2 && (tela_base >= -3471 && tela_base <= 0)){
                        if(mouse_x >= screenWidth/2){
                        player_direita = true;
                        player_esquerda = false;
                        if (andando > 0){
                            andando -= 5;
                        tela_base = tela_base - 5;
                        daniel_x -= 5;
                        daniel_x1 -= 5;
                            if (tela_base < -3471)
                            {
                                tela_base = -3470;
                                daniel_x = -3223+870;
                                daniel_x1 = -3223+3979;
                            }
                        }
                        }
                        if(mouse_x <= screenWidth/2){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            tela_base = tela_base+5;
                            daniel_x += 5;
                            daniel_x1 += 5;
                            if (tela_base > -1)
                            {
                                tela_base = 0;
                                daniel_x = 870;
                                daniel_x1 = 3979;
                            }
                        }
                        }
                        
                        
                    }

                    
                }
                else{
                    parado = true;
                    frameCounter = 0;
                    currentAnimFrame = 0;
                }
            
        }
        }
        else{
            frameCounter++;
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animFrames){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------


            jogador = texScarfyAnim;

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                caixa_de_dialogo.y += 330;
                if(caixa_de_dialogo.y > 330*3){
                    fala = false;
                }
            }
        }
        
        frameCounterd++;
        if (frameCounterd >= frameDelayd)
        {
            currentAnimFramed++;
            if (currentAnimFramed >= animframasd){
                currentAnimFramed = 0;
            }
            nextFrameDataOffsetd = daniel.width*daniel.height*4*currentAnimFramed;

            UpdateTexture(texdaniel, ((unsigned char *)daniel.data) + nextFrameDataOffsetd);

            frameCounterd = 0;
        }

        if (frameDelayd > MAX_FRAME_DELAY) frameDelayd = MAX_FRAME_DELAY;
        else if (frameDelayd < MIN_FRAME_DELAY) frameDelayd = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------
        
        frameCounterm++;
        if (frameCounterm >= frameDelaym)
        {
            currentAnimFramem++;
            if (currentAnimFramem >= animframasm){
                currentAnimFramem = 0;
            }
            nextFrameDataOffsetm = minerador_andando.width*minerador_andando.height*4*currentAnimFramem;

            UpdateTexture(texminerador, ((unsigned char *)minerador_andando.data) + nextFrameDataOffsetm);

            frameCounterm = 0;
        }

        if (frameDelaym > MAX_FRAME_DELAY) frameDelaym = MAX_FRAME_DELAY;
        else if (frameDelaym < MIN_FRAME_DELAY) frameDelaym = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if (mouse_x >= daniel_x && mouse_x <= (daniel_x+500)){
                if (my >= screenHeight/2+155 && my <= ((screenHeight/2+155)+500)){
                    daniel_falando = true;
                }
                }
        }

        if(daniel_falando){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(my < 360){
                    caixa_de_dialogo.y += 330;
                    daniel_falando = false;
                    caixa_de_dialogo.y = 0;
                }
            }
        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if (mouse_x >= daniel_x1 && mouse_x <= (daniel_x1+500)){
                if (my >= screenHeight/2+155 && my <= ((screenHeight/2+155)+500)){
                    daniel_falando1 = true;
                    caixa_de_dialogo.y = 330;
                }
                }
        }

        if(daniel_falando1){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(my < 360){
                    caixa_de_dialogo.y += 330;
                    if(caixa_de_dialogo.y >= 330*5){
                        daniel_falando1 = false;
                        caixa_de_dialogo.y = 0;
                        liberado = true;
                    }
                }
            }
        }

        if(liberado){
            if(mouse_x > 1285){
                fadeout = true;
            }
        }
        
        
        if(fala){
            popup -= 1;
            if (popup == 300)
            {
                caixa_de_dialogo.y += 330;
            }
            else if (popup < 5 || daniel_falando)
            {
                caixa_de_dialogo.y = 0;
                fala = false;
                popup = 800;
            }
        }
        
        if(caixa_de_dialogo.y == 330*5){
            minerador = true;
            
        }
        else if(caixa_de_dialogo.y == 330*6){
            minerador = false;
            ani_minerador = minerador_gritando;
            if(delay_mineiro == 0){
            mineiro_gritando_rec.x = mineiro_gritando_rec.x + 239;
            if(mineiro_gritando_rec.x > minerador_gritando.width){
                mineiro_gritando_rec.x = 0;
            }
            }
        }
        else if(caixa_de_dialogo.y >= 330*7){
            minerador = true;
        }
        else{
            minerador = false;
            minerador_walk = 1920;
        }

        if(minerador){
            delay_mineiro += 1;
            if (delay_mineiro == 3)
            {
                delay_mineiro = 0;
            }
            
        }

        if(minerador && caixa_de_dialogo.y != 330*6){
            minerador_walk -= 5;
            if (minerador_walk <= player_x/2+150)
            {
                minerador_walk = player_x/2+350;
            }
            
        }
        
        
        if(liberado && fade == 255){
            player_x = screenWidth/2-15;
            mouse_x = screenWidth/2-15;
            andando = 0;
            daniel_x1 = 7000;
            tela_base = 0;
            fala = true;
            caixa_de_dialogo.y = 0;
            daniel_falando = false;
            daniel_falando1 = false;
            liberado = false;
            player_esquerda = false;
            player_direita = true;
            fase5 = false;
            fase6 = true;
            fadein = true;
            fadeout = false;
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangle(daniel_x, 595, 230, 305, RAYWHITE);
            DrawTexture(background4, tela_base, 0, WHITE);
            //DrawTextureEx(texdaniel, (Vector2){porta_x, screenHeight/2+60},0, 0.65f, WHITE);
            if(player_x <= daniel_x+250){
                DrawTexturePro(texdaniel, (Rectangle){0,0,-500,500}, (Rectangle){daniel_x, 540, 500,500}, (Vector2){50,0},0, WHITE);
                DrawTexturePro(texdaniel, (Rectangle){0,0,-500,500}, (Rectangle){daniel_x1, 540, 500,500}, (Vector2){50,0},0, WHITE);
            }
            else{
                DrawTexturePro(texdaniel, (Rectangle){0,0,500,500}, (Rectangle){daniel_x, 540, 500,500}, (Vector2){0,0},0, WHITE);
                DrawTexturePro(texdaniel, (Rectangle){0,0,500,500}, (Rectangle){daniel_x1, 540, 500,500}, (Vector2){0,0},0, WHITE);
            }
            //DrawTextureEx(jogador,(Vector2){player_x-(textScarfyAnim1.width/2),screenHeight/2+155}, 0, 0.65f, WHITE);

            if(!parado){
                if(mouse_x < player_x){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                }
                else{
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                }
            }
            else{
                if(player_direita){
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                    }
                else if(player_esquerda){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                }
            }

            if(minerador && caixa_de_dialogo.y != 330*6){
                DrawTexturePro(texminerador, mineiro_andando_rec,(Rectangle){minerador_walk, screenHeight/2+100, 425,425}, (Vector2){0,0}, 0, WHITE);
            }
            else if(!minerador && caixa_de_dialogo.y == 330*6){
                DrawTexturePro(ani_minerador, mineiro_gritando_rec,(Rectangle){minerador_walk, screenHeight/2+100, 200,425}, (Vector2){0,0}, 0, WHITE);
            }

            if(daniel_falando || daniel_falando1){
                DrawTextureRec(daniel_mina, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            if(fala){
                DrawTextureRec(mina, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            
            if(fadein || fadeout){
                DrawRectangle(0,0,1920,1080, (Color){0,0,0, fade});
            }

        EndDrawing();

        }

        if(fase6){
        
        if(fim){
            time -= 2;
            fadeout = true;
        }
        
        if (fadeout)
        {
            fade += 1;
        }
        if(fadein){
            fade -= 1;
        }

        if (fade == 255)
        {
            fade = 255;
            fadeout = false;
        }
        if (fade == 0)
        {
            fade = 0;
            fadein = false;
        }
        
        
        if (IsKeyPressed(KEY_SPACE)){
        ToggleFullscreen();
        }
        // Update
        //----------------------------------------------------------------------------------
        if(!fala){
        if(parado){
        frameCounter++;
        if (frameCounter >= frameDelay)
        {
            // Move to next frame
            // NOTE: If final frame is reached we return to first frame
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames){
                currentAnimFrame = 0;
            }
            // Get memory offset position for next frame data in image.data
            nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

            // Update GPU texture data with next frame image data
            // WARNING: Data size (frame size) and pixel format must match already created texture
            UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
        else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------


        jogador = texScarfyAnim;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            mouse_x = GetMouseX();
            my = GetMouseY();
            if(mouse_x > screenWidth/2){
                andando = mouse_x - screenWidth/2;
            }
            if(mouse_x < screenWidth/2){
                andando = screenWidth/2 - mouse_x;
            }
            if(my > 360){
            parado = false;
            frameCounter = 0;
            currentAnimFrame = 0;
            }
        }
        }

        else{
            frameCounter++;
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                mouse_x = GetMouseX();
                my = GetMouseY();
                if(my > 360){
                if(mouse_x > screenWidth/2){
                    andando = mouse_x - screenWidth/2;
                }
                if(mouse_x < screenWidth/2){
                    andando = screenWidth/2 - mouse_x;
                }
                }
            }
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animframasw){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim1.width*imScarfyAnim1.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(textScarfyAnim1, ((unsigned char *)imScarfyAnim1.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------

            jogador = textScarfyAnim1;
            //----------------------------------------------------------------------------------
        


                if (andando > 0){
                    if (player_x <= screenWidth/2-3 || player_x >= screenWidth/2+3){
                        if(mouse_x > player_x){
                            player_direita = true;
                            player_esquerda = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x + 5;
                            if(player_x > mouse_x){
                                player_x = mouse_x;
                            }
                            if (player_x > screenWidth-75)
                            {
                                player_x = screenWidth-75;
                                mouse_x = screenWidth-75;
                            }
                            

                            }
                        }
                        if(mouse_x < player_x){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            player_x = player_x - 5;
                            if(player_x < mouse_x){
                                    player_x = mouse_x;
                                }
                            }
                            if (player_x < 75)
                            {
                                player_x = 75;
                                mouse_x = 75;
                            }
                            
                        }

                        
                        }
                    else if(player_x >= screenWidth/2 && (tela_base >= -15300 && tela_base <= 0)){
                        if(mouse_x >= screenWidth/2){
                        player_direita = true;
                        player_esquerda = false;
                        if (andando > 0){
                            andando -= 5;
                        tela_base = tela_base - 5;
                        daniel_x -= 5;
                        daniel_x1 -= 5;
                            if (tela_base < -15300)
                            {
                                tela_base = -15300;
                                daniel_x = -3223+870;
                                daniel_x1 = -3223+7000;
                            }
                        }
                        }
                        if(mouse_x <= screenWidth/2){
                            player_esquerda = true;
                            player_direita = false;
                            if(andando > 0){
                            andando -= 5;
                            tela_base = tela_base+5;
                            daniel_x += 5;
                            daniel_x1 += 5;
                            if (tela_base > -1)
                            {
                                tela_base = 0;
                                daniel_x = 870;
                                daniel_x1 = 7000;
                            }
                        }
                        }
                        
                        
                    }

                    
                }
                else{
                    parado = true;
                    frameCounter = 0;
                    currentAnimFrame = 0;
                }
            
        }
        }
        else{
            frameCounter++;
            if (frameCounter >= frameDelay)
            {
                // Move to next frame
                // NOTE: If final frame is reached we return to first frame
                currentAnimFrame++;
                if (currentAnimFrame >= animFrames){
                    currentAnimFrame = 0;
                }
                // Get memory offset position for next frame data in image.data
                nextFrameDataOffset = imScarfyAnim.width*imScarfyAnim.height*4*currentAnimFrame;

                // Update GPU texture data with next frame image data
                // WARNING: Data size (frame size) and pixel format must match already created texture
                UpdateTexture(texScarfyAnim, ((unsigned char *)imScarfyAnim.data) + nextFrameDataOffset);

                frameCounter = 0;
            }

            if (frameDelay > MAX_FRAME_DELAY) frameDelay = MAX_FRAME_DELAY;
            else if (frameDelay < MIN_FRAME_DELAY) frameDelay = MIN_FRAME_DELAY;
            //----------------------------------------------------------------------------------


            jogador = texScarfyAnim;

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                caixa_de_dialogo.y += 330;
                if(caixa_de_dialogo.y > 330*3){
                    fala = false;
                }
            }
        }
        
        frameCounterd++;
        if (frameCounterd >= frameDelayd)
        {
            currentAnimFramed++;
            if (currentAnimFramed >= animframasd){
                currentAnimFramed = 0;
            }
            nextFrameDataOffsetd = daniel.width*daniel.height*4*currentAnimFramed;

            UpdateTexture(texdaniel, ((unsigned char *)daniel.data) + nextFrameDataOffsetd);

            frameCounterd = 0;
        }

        if (frameDelayd > MAX_FRAME_DELAY) frameDelayd = MAX_FRAME_DELAY;
        else if (frameDelayd < MIN_FRAME_DELAY) frameDelayd = MIN_FRAME_DELAY;
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if (mouse_x >= daniel_x && mouse_x <= (daniel_x+500)){
                if (my >= screenHeight/2+155 && my <= ((screenHeight/2+155)+500)){
                    daniel_falando = true;
                }
                }
        }

        if(daniel_falando){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(my < 360){
                    caixa_de_dialogo.y += 330;
                    daniel_falando = false;
                    caixa_de_dialogo.y = 0;
                }
            }
        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            if (mouse_x >= daniel_x1 && mouse_x <= (daniel_x1+500)){
                if (my >= screenHeight/2+155 && my <= ((screenHeight/2+155)+500)){
                    daniel_falando1 = true;
                    caixa_de_dialogo.y = 330;
                }
                }
        }

        if(daniel_falando1){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(my < 360){
                    caixa_de_dialogo.y += 330;
                    if(caixa_de_dialogo.y > 6*330){
                        daniel_falando1 = false;
                        liberado = true;
                        caixa_de_dialogo.y = 0;
                    }
                }
            }
        }

        if(fala){
            popup -= 5;
            if (popup == 300)
            {
                caixa_de_dialogo.y += 330;
            }
            else if (popup < 5 || daniel_falando)
            {
                caixa_de_dialogo.y = 330;
                fala = false;
                popup = 800;
            }
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawRectangle(daniel_x, 595, 230, 305, RAYWHITE);
            DrawTexture(background5_2, 16000+tela_base,0, WHITE);
            DrawTexture(background5_1, 8000+tela_base,0,WHITE);
            DrawTexture(background5, tela_base, 0, WHITE);
            //DrawTextureEx(texdaniel, (Vector2){porta_x, screenHeight/2+60},0, 0.65f, WHITE);
            if(player_x <= daniel_x+250){
                DrawTexturePro(texdaniel, (Rectangle){0,0,-500,500}, (Rectangle){daniel_x, 540, 500,500}, (Vector2){50,0},0, WHITE);
                DrawTexturePro(texdaniel, (Rectangle){0,0,-500,500}, (Rectangle){daniel_x1, 540, 500,500}, (Vector2){50,0},0, WHITE);
            }
            else{
                DrawTexturePro(texdaniel, (Rectangle){0,0,500,500}, (Rectangle){daniel_x, 540, 500,500}, (Vector2){0,0},0, WHITE);
                DrawTexturePro(texdaniel, (Rectangle){0,0,500,500}, (Rectangle){daniel_x1, 540, 500,500}, (Vector2){0,0},0, WHITE);
            }
            //DrawTextureEx(jogador,(Vector2){player_x-(textScarfyAnim1.width/2),screenHeight/2+155}, 0, 0.65f, WHITE);

            if(!parado){
                if(mouse_x < player_x){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                }
                else{
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                }
            }
            else{
                if(player_direita){
                    DrawTexturePro(jogador, (Rectangle){0,0,500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                    }
                else if(player_esquerda){
                        DrawTexturePro(jogador, (Rectangle){0,0,-500, 500}, (Rectangle){player_x, screenHeight/2+120, 425, 425}, (Vector2){162,0}, 0, WHITE);
                }
            }

            if(liberado){
                if(tela_base <= -10000 && tela_base>= -11500){
                    caixa_de_dialogo.y = 330*7;
                    DrawTextureRec(caverna, caixa_de_dialogo, (Vector2){0,0}, WHITE);
                }
                else if(tela_base <= -11500 && tela_base >= -11750){
                    DrawTexturePro(carta9, (Rectangle){0,0, 595,842}, (Rectangle){screenWidth/2,screenHeight/2,595,842}, (Vector2){carta9.width/2, carta9.height/2}, 0, WHITE);
                }
                else if(tela_base <= -11750 && tela_base >= -13000){
                    caixa_de_dialogo.y = 330*8;
                    DrawTextureRec(caverna, caixa_de_dialogo, (Vector2){0,0}, WHITE);
                    }
                else if(tela_base <= -14750 && tela_base >= -17114){
                    caixa_de_dialogo.y = 330*9;
                    DrawTextureRec(caverna, caixa_de_dialogo, (Vector2){0,0}, WHITE);
                    fim = true;
                }
            }



            if(daniel_falando || daniel_falando1){
                DrawTextureRec(caverna, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            if(fala){
                DrawTextureRec(caverna, caixa_de_dialogo, (Vector2){0,0}, WHITE);
            }
            if(fadein || fadeout){
                DrawRectangle(0,0,1920,1080, (Color){0,0,0, fade});
            }

        EndDrawing();

        if(time < 0){
            currentAnimFrame = 0;
            currentAnimFramej = 0;
            currentAnimFramed = 0;
            frameDelay = 2;
            frameDelay1 = 10;
            frameDelayj = 2;
            frameDelayd = 2;
            frameCounter = 0;
            frameCounterj = 0;
            frameCounterd = 0;
            tela_base = 0;
            jornaleiro_x = 1830;
            porta_x = 3223;
            daniel_x = 870;
            daniel_x1 = 3979;
            andando = 0;
            popup = 800;
            time = 500;
            player_x = 15+(imScarfyAnim.width/2);
            caixa_de_dialogo.y = 330;
            fade = 255;

            //menu = LoadTexture("menu.png")
            start = false;
            creditos_tela = true;
            instrucoes_tela = false;
            cutscene_tela = false;

            //fases
            fase1 = false;
            fase2 = false;
            fase3 = false;
            fase4 = false;
            fase5 = false;
            fase6 = false;


            parado = false;
            vaso = false;
            mala = false;
            dialogo_jornaleiro = false;
            jornaleiro_falando = false;
            daniel_falando = false;
            daniel_falando1 = false;
            liberado = false;
            fala = false;
            player_direita = true;
            player_esquerda = false;
            fim = false;
            fadein = true;
            fadeout = false;

        }
        }

    }
	UnloadTexture(texScene);
    UnloadImage(imScene);
	UnloadTexture(texScarfyAnim);
    UnloadImage(imScarfyAnim);
    UnloadTexture(textScarfyAnim1);
    UnloadImage(imScarfyAnim1);
	UnloadTexture(texjornaleiro);
    UnloadImage(jornaleiro);

	CloseAudioDevice();
	
	CloseWindow();
	
	return 0;
}