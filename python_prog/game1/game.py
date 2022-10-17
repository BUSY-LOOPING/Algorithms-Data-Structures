from turtle import back
import pygame
import random
import math

if __name__ == '__main__':
    pygame.init()

    # creating the screen
    screen = pygame.display.set_mode((800, 600))  # width x height

    #background
    background = pygame.image.load('bg_game.jpg')
    background = pygame.transform.scale(background, (800, 600))
    background.set_alpha(100)

    #title and icon
    pygame.display.set_caption("Pew Pew Game")
    icon = pygame.image.load('time.png')
    pygame.display.set_icon(icon)

    # player
    playerImg = pygame.image.load('space.png')
    playerX = 370
    playerY = 480
    player_change = 0

    # enemy
    enemyImg = []
    enemyX = []
    enemyY = []
    enemyX_change = []
    enemyY_change = []
    num_ememies = 6
    
    for i in range(num_ememies):
       
        enemyImg.append(pygame.image.load('alien.png'))
        enemyX.append(random.randint(0, 735))
        enemyY.append(random.randint(50, 150))  
        enemyX_change.append(2)
        enemyY_change.append(40)
    
    #bullet
    bulletImg = pygame.image.load('bullet.png')
    bulletX = 0
    bulletY = 480
    bulletX_change = 0
    bulletY_change = 10
    bullet_state = 'ready'
    #ready = we cant see the bullet on screen 
    #fire = we can see the bullet
    
    score_value = 0
    font = pygame.font.Font('KOMIKAX_.ttf', 32)
    
    game_over_font = pygame.font.Font('KOMIKAX_.ttf', 55)
    
    textX = 10
    textY = 10
    
    def show_score(x, y):
        score = font.render('Score : ' + str(score_value), True, (255, 255, 255))
        screen.blit(score, (x, y))  
        
    def game_over_text()  :
        over_txt = game_over_font.render('GAME OVER', True, (255, 255, 255))
        screen.blit(over_txt, (200, 250)) 
                
    def fire_bullet(x, y) :
        global bullet_state
        bullet_state = 'fire'
        screen.blit(bulletImg, (x + 16, y + 10))

    def player(x, y):
        screen.blit(playerImg, (x, y))

    def enemy(x, y, i):
        screen.blit(enemyImg[i], (x, y))
        
    def isCollision(enemyX, enemyY, bulletX, bulletY):
        distance = math.sqrt(math.pow(enemyX - bulletX, 2) + math.pow(enemyY - bulletY, 2))
        if distance < 27 : 
            return True
        return False

    # game loop
    running = True
    while running:
        screen.fill((0, 0, 0))
        #bg image
        screen.blit(background, (0, 0))
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            # check right or left keystroke
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    player_change = -5

                if event.key == pygame.K_RIGHT:
                    player_change = 5
                    
                if event.key == pygame.K_SPACE:
                    if bullet_state is 'ready' :
                        bulletX = playerX
                        fire_bullet(bulletX, bulletY)

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    player_change = 0

        playerX += player_change
        if playerX < 0:
            playerX = 0
        elif playerX > 736:
            playerX = 736
        
        for i in range(num_ememies) :
            #Game over
            if enemyY[i] > playerY :
                for j in range(num_ememies) :
                    enemyY[j] = 2000
                game_over_text()
                break
            
            
            enemyX[i] += enemyX_change[i]
            if enemyX[i] < 0:
                enemyX_change[i] = 2
                enemyY[i] += enemyY_change[i]
            elif enemyX[i] > 736:
                enemyX_change[i] = -2
                enemyY[i] += enemyY_change[i]
                
            #collision
            collision = isCollision(enemyX[i], enemyY[i], bulletX, bulletY)
            if collision:
                bulletY = 480    
                bullet_state = 'ready'
                score_value += 1
                enemyX[i] = random.randint(0, 735)
                enemyY[i] = random.randint(50, 150)
            
            enemy(enemyX[i], enemyY[i], i)
        

        
        #bullet movement
        if bulletY <= 0 :
            bulletY = 480
            bullet_state = 'ready'
        
        if bullet_state is 'fire' :
            fire_bullet(bulletX, bulletY)
            bulletY -= bulletY_change
            
            
        player(playerX, playerY)
        show_score(textX, textY)
        pygame.display.update()
