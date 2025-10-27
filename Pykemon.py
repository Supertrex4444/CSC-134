import pygame
import random
import time
import math

# --- 1. CORE DATA CLASSES ---

class Ability:
    """Represents a Pokémon ability with a name and base power."""
    def __init__(self, name, base_power):
        self.name = name
        self.base_power = base_power

class Pokemon:
    """Represents a combatant with stats and abilities."""
    def __init__(self, name, hp, attack, defense, abilities, color=None, emoji="❓", is_player=False):
        self.name = name
        self.max_hp = hp
        self.current_hp = hp
        self.attack = attack
        self.defense = defense
        self.abilities = abilities
        self.is_player = is_player
        self.color = color if color else (100, 100, 100)
        # NEW: Store the emoji string
        self.emoji = emoji

    def is_alive(self):
        return self.current_hp > 0

    def calculate_damage(self, target, ability):
        modifier = random.uniform(0.85, 1.0)
        damage = math.floor(((ability.base_power * self.attack) / target.defense) / 5 + 2)
        final_damage = math.floor(damage * modifier)
        return max(1, final_damage)

    def take_damage(self, damage):
        self.current_hp -= damage
        if self.current_hp < 0:
            self.current_hp = 0

    def get_hp_percentage(self):
        return self.current_hp / self.max_hp

# --- 2. GAME SETUP (PRE-PYGAME USER INPUT & DATA) ---

# Define a color and emoji for each starter
PYRON_COLOR = (255, 100, 50)
HYDROC_COLOR = (50, 150, 255)
TERRA_COLOR = (100, 200, 50)

# Define the starter Pokémon data
STARTER_DATA = {
    "Pyron": {
        "stats": (100, 55, 40),
        "abilities": [Ability("Ember", 40), Ability("Fire Blast", 70)],
        "color": PYRON_COLOR,
        "emoji": "🔥"
    },
    "Hydroc": {
        "stats": (110, 45, 50),
        "abilities": [Ability("Bubble", 40), Ability("Hydro Pump", 70)],
        "color": HYDROC_COLOR,
        "emoji": "💧"
    },
    "Terra": {
        "stats": (95, 60, 35),
        "abilities": [Ability("Vine Whip", 40), Ability("Earthquake", 70)],
        "color": TERRA_COLOR,
        "emoji": "🌿"
    }
}

def generate_enemy_pokemon():
    """Randomly generates an enemy Pokémon."""
    
    enemy_names = ["Venoshock", "Gloomfang", "Hydrocoil", "Aerochime", "Sablelash"]
    enemy_abilities = [
        Ability("Scratch", random.randint(30, 40)),
        Ability("Tackle", random.randint(40, 50)),
        Ability("Roar", random.randint(45, 60)),
        Ability("Swipe", random.randint(50, 70))
    ]
    
    name = random.choice(enemy_names)
    hp = random.randint(90, 110) 
    attack = random.randint(45, 55)
    defense = random.randint(35, 45)
    
    abilities = random.sample(enemy_abilities, 2)
    enemy_color = (random.randint(150, 200), random.randint(150, 200), random.randint(150, 200))
    
    # Assign the enemy emoji
    return Pokemon(name, hp, attack, defense, abilities, color=enemy_color, emoji="😈")

# Global variables for Pokémon data
PLAYER_POKEMON = None 
ENEMY_POKEMON = None 

# --- 3. PYGAME INITIALIZATION ---

pygame.init()

# Define screen dimensions and colors
SCREEN_WIDTH = 1920
SCREEN_HEIGHT = 1080
SCREEN_SIZE = (SCREEN_WIDTH, SCREEN_HEIGHT)
SCREEN = pygame.display.set_mode(SCREEN_SIZE)
pygame.display.set_caption("Pokémon Battle Simulator")

# Colors (RGB)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (75, 175, 75)
BLUE = (50, 50, 150)
YELLOW = (255, 215, 0)
GRAY = (50, 50, 50)
LIGHT_GRAY = (200, 200, 200)

# Fonts (Scaled up for 1080p)
FONT_LG = pygame.font.Font(None, 96) 
FONT_MD = pygame.font.Font(None, 64) 
FONT_SM = pygame.font.Font(None, 48) 
# NEW: Massive font for Emojis
FONT_EMOJI_XL = pygame.font.Font(None, 300) 
FONT_EMOJI_MD = pygame.font.Font(None, 120) 

# Game State Management
GAME_STATE = -1 
GAME_MESSAGE = "Choose your starter Pokémon!"
player_name_input = "" 

CLOCK = pygame.time.Clock()

# --- 4. UI COMPONENTS (BUTTON CLASS) ---

class Button:
    """A simple clickable button for attack options and menu selection."""
    def __init__(self, x, y, width, height, text, color=BLUE, hover_color=None):
        self.rect = pygame.Rect(x, y, width, height)
        self.text = text
        self.color = color
        self.hover_color = hover_color if hover_color else tuple(min(255, c + 30) for c in color)
        self.ability = None 

    def draw(self, screen):
        """Renders the button on the screen."""
        current_color = self.color
        if self.rect.collidepoint(pygame.mouse.get_pos()):
            current_color = self.hover_color

        pygame.draw.rect(screen, current_color, self.rect, border_radius=15) 
        
        text_surface = FONT_MD.render(self.text, True, WHITE)
        text_rect = text_surface.get_rect(center=self.rect.center)
        screen.blit(text_surface, text_rect)

    def is_clicked(self, event):
        """Checks if the button was clicked."""
        return self.rect.collidepoint(event.pos)

# Function to create battle buttons 
def create_ability_buttons(pokemon):
    button_width = 300
    button_height = 100
    button_spacing = 40
    
    button_y = SCREEN_HEIGHT - button_height - 60
    button_x1 = SCREEN_WIDTH - (button_width * 2 + button_spacing + 60)
    button_x2 = SCREEN_WIDTH - button_width - 60
    
    btn1 = Button(button_x1, button_y, button_width, button_height, 
                  pokemon.abilities[0].name, BLUE, (80, 80, 180))
    btn1.ability = pokemon.abilities[0]
    
    btn2 = Button(button_x2, button_y, button_width, button_height, 
                  pokemon.abilities[1].name, BLUE, (80, 80, 180))
    btn2.ability = pokemon.abilities[1]
    
    return [btn1, btn2]

# --- STARTER MENU BUTTONS ---
starter_names = list(STARTER_DATA.keys())
menu_buttons = []
btn_w, btn_h = 250, 120 
start_x = SCREEN_WIDTH // 2 - (btn_w * 3 + 100) // 2 
for i, name in enumerate(starter_names):
    x = start_x + (btn_w + 50) * i
    btn = Button(x, SCREEN_HEIGHT // 2, btn_w, btn_h, name, STARTER_DATA[name]["color"], None)
    menu_buttons.append(btn)
    
ABILITY_BUTTONS = [] 

# --- 5. BATTLE RENDERING FUNCTIONS ---

def draw_hp_bar(screen, x, y, hp_percent, name, current_hp, max_hp, is_player):
    """Draws the Pokémon's name and its health bar."""
    
    BAR_WIDTH = 400 
    BAR_HEIGHT = 40 
    BORDER_RADIUS = 10 

    hp_color = (255 * (1 - hp_percent), 255 * hp_percent, 0) 

    pygame.draw.rect(screen, GRAY, (x, y + 40, BAR_WIDTH, BAR_HEIGHT), border_radius=BORDER_RADIUS) 
    
    fill_width = BAR_WIDTH * hp_percent
    pygame.draw.rect(screen, hp_color, (x, y + 40, fill_width, BAR_HEIGHT), border_radius=BORDER_RADIUS)

    name_text = FONT_LG.render(name, True, BLACK)
    screen.blit(name_text, (x, y))

    if is_player:
        hp_text = FONT_MD.render(f"HP: {current_hp}/{max_hp}", True, BLACK)
        screen.blit(hp_text, (x + BAR_WIDTH + 20, y + 40)) 

# NEW FUNCTION: Draws the scaled emoji
def draw_pokemon_emoji(screen, pokemon, center_x, center_y, font):
    """Draws the Pokémon's emoji using a large font."""
    # Note: Emojis are treated as text by Pygame's font renderer. Their color is usually defined by the OS/Font,
    # so we render them in white (or black) to allow the OS/Font to render the color emoji if possible,
    # or just use the font color if not. Using WHITE tends to work best for colored emojis.
    emoji_surface = font.render(pokemon.emoji, True, WHITE)
    emoji_rect = emoji_surface.get_rect(center=(center_x, center_y))
    screen.blit(emoji_surface, emoji_rect)


def draw_battle_interface(screen):
    """Draws the entire battle scene with emojis."""
    global GAME_STATE, GAME_MESSAGE, PLAYER_POKEMON, ENEMY_POKEMON
    
    # 1. Background and Arena
    screen.fill(WHITE)
    pygame.draw.rect(screen, (220, 220, 255), (0, 0, SCREEN_WIDTH, int(SCREEN_HEIGHT * 0.6))) 
    pygame.draw.rect(screen, (150, 255, 150), (0, int(SCREEN_HEIGHT * 0.6), SCREEN_WIDTH, int(SCREEN_HEIGHT * 0.4))) 
    
    if PLAYER_POKEMON and ENEMY_POKEMON:
        
        # --- Draw Pokémon Emojis (XL size) ---
        
        # Enemy Pokémon (Top Right)
        enemy_x, enemy_y = SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.25
        draw_pokemon_emoji(screen, ENEMY_POKEMON, int(enemy_x), int(enemy_y), FONT_EMOJI_XL)
        
        # Player Pokémon (Bottom Left)
        player_x, player_y = SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.55
        draw_pokemon_emoji(screen, PLAYER_POKEMON, int(player_x), int(player_y), FONT_EMOJI_XL)
        
        # 2. HP Bars
        draw_hp_bar(screen, SCREEN_WIDTH - 500, 80, ENEMY_POKEMON.get_hp_percentage(), 
                    ENEMY_POKEMON.name, ENEMY_POKEMON.current_hp, ENEMY_POKEMON.max_hp, False)
        draw_hp_bar(screen, 100, SCREEN_HEIGHT - 300, PLAYER_POKEMON.get_hp_percentage(), 
                    PLAYER_POKEMON.name, PLAYER_POKEMON.current_hp, PLAYER_POKEMON.max_hp, True)

    # 3. Message/Action Box 
    box_height = 100 
    box_width = SCREEN_WIDTH // 2 - 50 
    box_x = 50
    box_y = SCREEN_HEIGHT - box_height - 60
    
    box_rect = pygame.Rect(box_x, box_y, box_width, box_height)
    #pygame.draw.rect(screen, YELLOW, box_rect, border_radius=20)
    #pygame.draw.rect(screen, BLACK, box_rect, 5, border_radius=20) 
    
    message_surface = FONT_MD.render(GAME_MESSAGE, True, BLACK)
    screen.blit(message_surface, (box_x + 20, box_y + 20))

    # 4. Action Buttons 
    if GAME_STATE == 0:
        for button in ABILITY_BUTTONS:
            button.draw(screen)
    
    # 5. Game Over Screen Overlay
    if GAME_STATE == 2:
        overlay = pygame.Surface(SCREEN_SIZE, pygame.SRCALPHA)
        overlay.fill((0, 0, 0, 180)) 
        screen.blit(overlay, (0, 0))
        
        if PLAYER_POKEMON.is_alive():
            outcome_text = f"VICTORY! You defeated {ENEMY_POKEMON.name}!"
            color = GREEN
        else:
            outcome_text = f"DEFEAT! {PLAYER_POKEMON.name} fainted."
            color = (200, 50, 50)
            
        final_message = FONT_LG.render(outcome_text, True, color)
        message_rect = final_message.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2))
        screen.blit(final_message, message_rect)
        
        quit_text = FONT_MD.render("Press ESC to Quit", True, WHITE) 
        quit_rect = quit_text.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 + 100))
        screen.blit(quit_text, quit_rect)

# --- STARTER MENU LOGIC AND RENDERING ---

def draw_starter_menu(screen, input_active):
    """Draws the starter selection and naming interface with emojis."""
    global GAME_MESSAGE, player_name_input
    
    screen.fill(LIGHT_GRAY)
    
    # Title 
    title_text = FONT_LG.render("Choose Your Starter Pokémon!", True, BLACK)
    screen.blit(title_text, (SCREEN_WIDTH // 2 - title_text.get_width() // 2, 80)) 

    # Instructions/Message 
    message_text = FONT_MD.render(GAME_MESSAGE, True, BLACK)
    screen.blit(message_text, (SCREEN_WIDTH // 2 - message_text.get_width() // 2, 200)) 
    
    # Buttons
    if GAME_MESSAGE == "Choose your starter Pokémon!":
        for button in menu_buttons:
            button.draw(screen)
            
            # Draw medium emoji above the button
            starter_data = STARTER_DATA[button.text]
            draw_pokemon_emoji(screen, 
                               Pokemon(button.text, 0, 0, 0, [], emoji=starter_data["emoji"]),
                               button.rect.centerx,
                               button.rect.y - 80, # Adjusted position to be higher
                               FONT_EMOJI_MD)
            
            # Display stats below buttons 
            stats_text = FONT_SM.render(
                f"HP:{starter_data['stats'][0]} ATK:{starter_data['stats'][1]} DEF:{starter_data['stats'][2]}", 
                True, BLACK
            )
            stats_rect = stats_text.get_rect(center=(button.rect.centerx, button.rect.y + button.rect.height + 40))
            screen.blit(stats_text, stats_rect)
            
    # Name Input Box
    elif "Enter a name" in GAME_MESSAGE:
        input_box_width = 800 
        input_box_height = 80 
        input_box_rect = pygame.Rect(
            SCREEN_WIDTH // 2 - input_box_width // 2, 
            SCREEN_HEIGHT // 2 - input_box_height // 2, 
            input_box_width, 
            input_box_height
        )
        
        # Draw the box
        box_color = YELLOW if input_active else WHITE
        pygame.draw.rect(screen, box_color, input_box_rect, border_radius=10)
        pygame.draw.rect(screen, BLACK, input_box_rect, 5, border_radius=10)
        
        # Render the input text 
        name_surface = FONT_MD.render(player_name_input + ("|" if input_active else ""), True, BLACK)
        screen.blit(name_surface, (input_box_rect.x + 20, input_box_rect.y + 10))
        
        # Confirm Button 
        confirm_btn = Button(SCREEN_WIDTH // 2 - 120, SCREEN_HEIGHT // 2 + 150, 240, 80, "Confirm", BLUE, (80, 80, 180))
        confirm_btn.draw(screen)
        
        return confirm_btn
    
    return None 

# --- 6. GAME LOGIC & 7. MAIN GAME LOOP (No functional changes) ---

def handle_player_turn(clicked_ability):
    global GAME_STATE, GAME_MESSAGE
    ability = clicked_ability 
    damage = PLAYER_POKEMON.calculate_damage(ENEMY_POKEMON, ability)
    ENEMY_POKEMON.take_damage(damage)
    GAME_MESSAGE = f"{PLAYER_POKEMON.name} used {ability.name}, dealing {damage} damage!"
    if not ENEMY_POKEMON.is_alive():
        GAME_STATE = 2 
    else:
        GAME_STATE = 1 
        
def handle_enemy_turn():
    global GAME_STATE, GAME_MESSAGE
    pygame.time.wait(1000) 
    ability = random.choice(ENEMY_POKEMON.abilities)
    damage = ENEMY_POKEMON.calculate_damage(PLAYER_POKEMON, ability)
    PLAYER_POKEMON.take_damage(damage)
    GAME_MESSAGE = f"{ENEMY_POKEMON.name} used {ability.name}, dealing {damage} damage!"
    if not PLAYER_POKEMON.is_alive():
        GAME_STATE = 2 
    else:
        pygame.time.wait(1500) 
        GAME_STATE = 0 
        GAME_MESSAGE = f"What will {PLAYER_POKEMON.name} do?"

def main_game_loop():
    global GAME_STATE, GAME_MESSAGE, PLAYER_POKEMON, ENEMY_POKEMON, player_name_input, ABILITY_BUTTONS
    
    running = True
    selected_starter_data = None 
    input_active = False 
    
    while running:
        # --- Event Handling ---
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE and GAME_STATE == 2:
                running = False

            if GAME_STATE == -1:
                # 1. Selection Phase
                if selected_starter_data is None and event.type == pygame.MOUSEBUTTONDOWN:
                    for button in menu_buttons:
                        if button.is_clicked(event):
                            selected_starter_data = STARTER_DATA[button.text]
                            GAME_MESSAGE = f"You chose {button.text}! Enter a name for your new friend:"
                            input_active = True
                            
                # 2. Naming Phase
                elif selected_starter_data is not None:
                    confirm_btn_check = Button(SCREEN_WIDTH // 2 - 120, SCREEN_HEIGHT // 2 + 150, 240, 80, "Confirm")
                    
                    if event.type == pygame.MOUSEBUTTONDOWN:
                        if confirm_btn_check.is_clicked(event) and player_name_input:
                            stats = selected_starter_data["stats"]
                            abilities = selected_starter_data["abilities"]
                            color = selected_starter_data["color"]
                            emoji = selected_starter_data["emoji"]
                            PLAYER_POKEMON = Pokemon(
                                player_name_input, stats[0], stats[1], stats[2], abilities, color=color, emoji=emoji, is_player=True
                            )
                            ENEMY_POKEMON = generate_enemy_pokemon()
                            ABILITY_BUTTONS = create_ability_buttons(PLAYER_POKEMON)
                            
                            print(f"Starting battle: {PLAYER_POKEMON.name} vs {ENEMY_POKEMON.name}!")
                            GAME_MESSAGE = f"Your opponent is {ENEMY_POKEMON.name}! What will {PLAYER_POKEMON.name} do?"
                            GAME_STATE = 0 
                        
                    elif event.type == pygame.KEYDOWN and input_active:
                        if event.key == pygame.K_RETURN:
                            if player_name_input:
                                stats = selected_starter_data["stats"]
                                abilities = selected_starter_data["abilities"]
                                color = selected_starter_data["color"]
                                emoji = selected_starter_data["emoji"]
                                PLAYER_POKEMON = Pokemon(
                                    player_name_input, stats[0], stats[1], stats[2], abilities, color=color, emoji=emoji, is_player=True
                                )
                                ENEMY_POKEMON = generate_enemy_pokemon()
                                ABILITY_BUTTONS = create_ability_buttons(PLAYER_POKEMON)
                                
                                print(f"Starting battle: {PLAYER_POKEMON.name} vs {ENEMY_POKEMON.name}!")
                                GAME_MESSAGE = f"Your opponent is {ENEMY_POKEMON.name}! What will {PLAYER_POKEMON.name} do?"
                                GAME_STATE = 0 
                                
                        elif event.key == pygame.K_BACKSPACE:
                            player_name_input = player_name_input[:-1]
                        elif len(player_name_input) < 12 and (event.unicode.isalnum() or event.unicode.isspace()):
                            player_name_input += event.unicode

            if GAME_STATE == 0 and event.type == pygame.MOUSEBUTTONDOWN:
                for button in ABILITY_BUTTONS:
                    if button.is_clicked(event):
                        handle_player_turn(button.ability)
                        
        # --- Game Logic Update ---
        if GAME_STATE == 1:
            handle_enemy_turn()

        # --- Drawing ---
        if GAME_STATE == -1:
            draw_starter_menu(SCREEN, input_active)
        else:
            draw_battle_interface(SCREEN)

        pygame.display.flip()
        CLOCK.tick(60)

    pygame.quit()

# Start the game
if __name__ == "__main__":
    main_game_loop()
