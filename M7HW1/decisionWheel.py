import pygame
import random
import math

# --- 1. Pygame Initialization and Constants ---
pygame.init()

# Screen dimensions
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Dynamic Spin the Wheel")

# Colors
WHITE = (0, 0, 0)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
ORANGE = (255, 165, 0)
PURPLE = (128, 0, 128)
CYAN = (0, 255, 255)

ACTIVE_COLOR = (150, 200, 255) 
INACTIVE_COLOR = (200, 200, 200) 
BUTTON_COLOR = GREEN
BUTTON_HOVER_COLOR = (0, 200, 0)
DARKEN_COLOR = (0, 0, 0, 150) 
CONFETTI_COLORS = [RED, GREEN, BLUE, ORANGE, PURPLE, CYAN, (255, 255, 0), (255, 192, 203)]

# Game clock
clock = pygame.time.Clock()

# Wheel Parameters
WHEEL_CENTER = (SCREEN_WIDTH // 2 - 120, SCREEN_HEIGHT // 2)
WHEEL_RADIUS = 250
SPIN_DURATION_FRAMES = 180 

# Spin state variables
is_spinning = False
current_angle = 0.0  
target_angle_offset = 0.0  
spin_timer = 0
wheel_items = ["Pizza", "Tacos", "Burger", "Salad", "Steak", "Pasta"]
NUM_ITEMS = len(wheel_items)
SEGMENT_ANGLE = 360 / NUM_ITEMS

# Menu Parameters
MENU_START_X = 550
INPUT_BOX_WIDTH = 200
INPUT_BOX_HEIGHT = 30
INPUT_SPACING = 40
MAX_ITEMS = 10 

# Game States
MENU_STATE = 0
SPIN_STATE = 1
WINNER_STATE = 2

# Game state variable and winner screen items
game_state = MENU_STATE
winner_text = ""
winner_font = pygame.font.Font(None, 80)
confetti_pieces = []


# --- 2. Utility Classes for UI ---

class InputBox:
    def __init__(self, x, y, w, h, text=''):
        self.rect = pygame.Rect(x, y, w, h)
        self.color = INACTIVE_COLOR
        self.text = text
        self.font = pygame.font.Font(None, 24)
        self.txt_surface = self.font.render(text, True, BLACK)
        self.active = False
        self.max_width = w - 10 

    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            if self.rect.collidepoint(event.pos):
                self.active = not self.active
            else:
                self.active = False
            self.color = ACTIVE_COLOR if self.active else INACTIVE_COLOR
            
        if event.type == pygame.KEYDOWN:
            if self.active:
                if event.key == pygame.K_RETURN:
                    self.active = False
                    self.color = INACTIVE_COLOR
                elif event.key == pygame.K_BACKSPACE:
                    self.text = self.text[:-1]
                else:
                    temp_surface = self.font.render(self.text + event.unicode, True, BLACK)
                    if temp_surface.get_width() < self.max_width:
                        self.text += event.unicode
                        
                self.txt_surface = self.font.render(self.text, True, BLACK)

    def draw(self, screen):
        pygame.draw.rect(screen, self.color, self.rect, 0)
        pygame.draw.rect(screen, BLACK, self.rect, 2) 

        screen.blit(self.txt_surface, (self.rect.x + 5, self.rect.y + 5))

class Button:
    def __init__(self, x, y, w, h, text, action):
        self.rect = pygame.Rect(x, y, w, h)
        self.text = text
        self.action = action
        self.font = pygame.font.Font(None, 36)
        self.txt_surface = self.font.render(text, True, BLACK)

    def draw(self, screen, mouse_pos):
        color = BUTTON_COLOR
        if self.rect.collidepoint(mouse_pos):
            color = BUTTON_HOVER_COLOR
            
        pygame.draw.rect(screen, color, self.rect, 0, 5) 
        pygame.draw.rect(screen, BLACK, self.rect, 2, 5) 
        
        text_rect = self.txt_surface.get_rect(center=self.rect.center)
        screen.blit(self.txt_surface, text_rect)
        
    def handle_event(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN:
            if self.rect.collidepoint(event.pos):
                self.action()

# --- 3. Wheel and Game Logic Functions ---

def update_wheel_parameters():
    global NUM_ITEMS, SEGMENT_ANGLE
    NUM_ITEMS = len(wheel_items)
    SEGMENT_ANGLE = 360 / NUM_ITEMS if NUM_ITEMS > 0 else 0

def draw_wheel(screen, center, radius, items, current_rotation):
    """Draws the spinning wheel."""
    if not items:
        pygame.draw.circle(screen, INACTIVE_COLOR, center, radius)
        font = pygame.font.Font(None, 36)
        text_surface = font.render("NO ITEMS", True, BLACK)
        text_rect = text_surface.get_rect(center=center)
        screen.blit(text_surface, text_rect)
        return

    num_items = len(items)
    segment_angle = 360 / num_items
    
    colors = [RED, GREEN, BLUE, ORANGE, PURPLE, CYAN]
    font = pygame.font.Font(None, 24)

    for i in range(num_items):
        start_angle_deg = (i * segment_angle + current_rotation)
        end_angle_deg = ((i + 1) * segment_angle + current_rotation)
        
        start_angle_rad = math.radians(start_angle_deg)
        end_angle_rad = math.radians(end_angle_deg)
        
        color = colors[i % len(colors)]
        
        points = [center]
        num_arc_points = 30 
        for j in range(num_arc_points + 1):
            angle = start_angle_rad + (end_angle_rad - start_angle_rad) * j / num_arc_points
            x = center[0] + radius * math.cos(angle)
            y = center[1] - radius * math.sin(angle) 
            points.append((int(x), int(y)))
            
        pygame.draw.polygon(screen, color, points)
        #pygame.draw.circle(screen, BLACK, center, radius, 2) 

        # Draw Text
        text_angle_deg = start_angle_deg + segment_angle / 2
        text_angle_rad = math.radians(text_angle_deg)
        
        text_x = center[0] + (radius * 0.75) * math.cos(text_angle_rad)
        text_y = center[1] - (radius * 0.75) * math.sin(text_angle_rad) 
        
        text_surface = font.render(items[i], True, BLACK)
        
        text_surface = pygame.transform.rotate(text_surface, text_angle_deg)
        text_rect = text_surface.get_rect(center=(text_x, text_y))
        
        screen.blit(text_surface, text_rect)

def draw_pointer(screen, center, radius):
    """
    FIXED: Draws a pointer/marker fixed near the top of the wheel, 
    with the tip pointing inwards towards the wheel's center.
    """
    # Position the pointer base just outside the wheel, centered horizontally
    pointer_base_y = center[1] - radius - 5
    
    # Tip of the pointer, pointing down towards the wheel (inwards)
    tip = (center[0], pointer_base_y + 20) 
    
    # Base corners of the triangle, resting near the wheel edge
    base_left = (center[0] - 15, pointer_base_y) 
    base_right = (center[0] + 15, pointer_base_y) 
    
    # Draw the triangle 
    pygame.draw.polygon(screen, BLACK, [
        tip, 
        base_left, 
        base_right
    ])
    
    
def start_spin():
    global is_spinning, spin_timer, target_angle_offset, game_state, winner_text
    
    if is_spinning or NUM_ITEMS == 0 or game_state != MENU_STATE:
        return
        
    is_spinning = True
    spin_timer = 0
    winner_text = "Spinning..."
    game_state = SPIN_STATE
    
    target_index = random.randint(0, NUM_ITEMS - 1)
    
    winning_center_angle = (target_index * SEGMENT_ANGLE) + (SEGMENT_ANGLE / 2)
    
    full_rotations = random.randint(5, 10) * 360 
    
    target_angle_offset = 90 - winning_center_angle + full_rotations + (current_angle % 360)

def generate_confetti(count):
    """Creates a burst of confetti pieces."""
    global confetti_pieces
    confetti_pieces = []
    for _ in range(count):
        x = random.randint(0, SCREEN_WIDTH)
        y = random.randint(-200, 0)
        vx = random.uniform(-2, 2)
        vy = random.uniform(2, 6)
        size = random.randint(5, 10)
        color = random.choice(CONFETTI_COLORS)
        
        confetti_pieces.append({
            'rect': pygame.Rect(x, y, size, size),
            'velocity': (vx, vy),
            'color': color,
            'rotation': random.uniform(-0.1, 0.1) 
        })

def update_confetti():
    """Updates the position of all confetti pieces."""
    global confetti_pieces
    
    new_confetti = []
    for c in confetti_pieces:
        c['rect'].x += c['velocity'][0]
        c['rect'].y += c['velocity'][1]
        c['velocity'] = (c['velocity'][0] * 0.99, c['velocity'][1] + 0.1) 
        
        if c['rect'].top < SCREEN_HEIGHT:
            new_confetti.append(c)
            
    confetti_pieces = new_confetti

def draw_confetti(screen):
    """Draws the confetti pieces."""
    for c in confetti_pieces:
        pygame.draw.rect(screen, c['color'], c['rect'])
    
def return_to_menu():
    """Resets the game state from the winner screen."""
    global game_state, winner_text
    game_state = MENU_STATE
    winner_text = ""


# --- 4. Menu Actions and UI Setup ---

# Initialize Input Boxes
input_boxes = []
for i, item in enumerate(wheel_items):
    box_y = 50 + i * INPUT_SPACING
    box = InputBox(MENU_START_X, box_y, INPUT_BOX_WIDTH, INPUT_BOX_HEIGHT, text=item)
    input_boxes.append(box)

def add_section():
    global wheel_items, input_boxes
    if len(input_boxes) < MAX_ITEMS:
        new_item_text = f"Item {len(input_boxes) + 1}"
        wheel_items.append(new_item_text)
        
        box_y = 50 + len(input_boxes) * INPUT_SPACING
        new_box = InputBox(MENU_START_X, box_y, INPUT_BOX_WIDTH, INPUT_BOX_HEIGHT, text=new_item_text)
        input_boxes.append(new_box)
        update_wheel_parameters()

# UI Buttons
add_button = Button(
    MENU_START_X, 
    50 + MAX_ITEMS * INPUT_SPACING, 
    INPUT_BOX_WIDTH, 
    INPUT_BOX_HEIGHT, 
    "+ Add Section", 
    add_section
)

spin_button = Button(
    SCREEN_WIDTH // 2 - 75, 
    SCREEN_HEIGHT - 50, 
    150, 
    40, 
    "SPIN WHEEL", 
    start_spin 
)

return_button = Button(
    SCREEN_WIDTH // 2 - 100, 
    SCREEN_HEIGHT // 2 + 150, 
    250, 
    50, 
    "RETURN TO MENU", 
    return_to_menu
)


# --- 5. Main Game Loop ---
running = True

while running:
    mouse_pos = pygame.mouse.get_pos()
    
    # --- Event Handling ---
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        
        if game_state == MENU_STATE:
            for box in input_boxes:
                box.handle_event(event)
            add_button.handle_event(event)
            spin_button.handle_event(event)

        elif game_state == WINNER_STATE:
            return_button.handle_event(event)

    # --- Update Logic ---
    
    if game_state == MENU_STATE or game_state == SPIN_STATE:
        new_items = [box.text for box in input_boxes if box.text.strip() != ""]
        if new_items != wheel_items:
            wheel_items = new_items
            update_wheel_parameters()

    if is_spinning:
        spin_timer += 1
        
        progress = min(1.0, spin_timer / SPIN_DURATION_FRAMES)
        
        eased_progress = 1 - (1 - progress)**2 
        
        new_angle = eased_progress * target_angle_offset
        
        current_angle = new_angle 

        if progress >= 1.0:
            is_spinning = False
            game_state = WINNER_STATE 
            
            if NUM_ITEMS > 0:
                normalized_angle = (current_angle % 360 + 360) % 360
                angle_at_pointer = (90 - normalized_angle + 360) % 360
                winning_index = int(angle_at_pointer // SEGMENT_ANGLE)
                winner_text = wheel_items[winning_index]
                generate_confetti(100) 
            else:
                 winner_text = "No Items!"

    if game_state == WINNER_STATE:
        update_confetti()
        
    # --- Drawing ---
    screen.fill(WHITE)
    
    # Draw Wheel and Pointer (always visible)
    draw_wheel(screen, WHEEL_CENTER, WHEEL_RADIUS, wheel_items, current_angle)
    # The pointer is now correctly facing the wheel
    draw_pointer(screen, WHEEL_CENTER, WHEEL_RADIUS)

    # Draw UI elements based on state
    if game_state == MENU_STATE or game_state == SPIN_STATE:
        font_menu = pygame.font.Font(None, 24)
        menu_label = font_menu.render("Edit Wheel Sections:", True, BLACK)
        screen.blit(menu_label, (MENU_START_X, 20))
        
        for box in input_boxes:
            box.draw(screen)
            
        add_button.draw(screen, mouse_pos)
        spin_button.draw(screen, mouse_pos)
        
        font_status = pygame.font.Font(None, 40)
        status_text_surface = font_status.render(winner_text, True, BLACK)
        screen.blit(status_text_surface, (WHEEL_CENTER[0] - status_text_surface.get_width() // 2, WHEEL_CENTER[1] + WHEEL_RADIUS + 50))


    # Draw Winner Screen overlay
    if game_state == WINNER_STATE:
        # Create semi-transparent surface
        darken_surface = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
        darken_surface.fill(DARKEN_COLOR)
        screen.blit(darken_surface, (0, 0))

        # Draw Confetti (FIXED: The function call is now defined before this point)
        draw_confetti(screen)

        # Draw the large winner banner
        banner_surface = winner_font.render(f"WINNER: {winner_text}", True, WHITE)
        banner_rect = banner_surface.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2))
        
        pygame.draw.rect(screen, RED, banner_rect.inflate(40, 20), 0, 10)
        pygame.draw.rect(screen, WHITE, banner_rect.inflate(40, 20), 5, 10) 
        screen.blit(banner_surface, banner_rect)
        
        # Draw the Return to Menu button
        return_button.draw(screen, mouse_pos)


    pygame.display.flip()
    clock.tick(60)

# --- 6. Pygame Quit ---
pygame.quit()
