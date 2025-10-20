import pygame
import sys
import random
import math # Need the math module for square roots (distance formula) and geometry (trig)

# Initialize Pygame
pygame.init()

# --- Configuration ---

width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Colliding Bouncing Balls")

# Colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
BLUE = (150, 150, 255)

# Fonts
font_large = pygame.font.Font(None, 48)
font_medium = pygame.font.Font(None, 36)

# Ball properties
initial_radius = 20
MIN_SPEED = 2
MAX_SPEED = 7

# Function to generate a random color
def get_random_color():
    return (random.randint(100, 255), random.randint(100, 255), random.randint(100, 255))

# Function to generate a random speed component
def get_random_speed():
    return random.randint(MIN_SPEED, MAX_SPEED)

# Clock for controlling the frame rate
clock = pygame.time.Clock()
FPS = 60

# --- Helper Function for Physics ---

def resolve_collision(ball1, ball2):
    """
    Handles the physics response for an elastic collision between two balls.
    Uses vector projection to simulate a bounce along the collision angle.
    Assumes equal mass for simplicity.
    """
    x1, y1, dx1, dy1, r1, c1 = ball1
    x2, y2, dx2, dy2, r2, c2 = ball2

    # 1. Calculate the vector from ball1 to ball2
    dx = x2 - x1
    dy = y2 - y1

    # 2. Calculate the distance between centers (already known to be < r1 + r2)
    distance = math.sqrt(dx**2 + dy**2)
    
    # Check if a collision actually happened (should always be true when called)
    if distance == 0: return # Avoid division by zero
    
    # 3. Calculate the unit normal and tangent vectors
    nx = dx / distance
    ny = dy / distance
    tx = -ny
    ty = nx

    # 4. Project the velocity vectors onto the normal and tangent axes
    # Velocity 1 components
    v1n = dx1 * nx + dy1 * ny # Velocity 1 along normal (collision) axis
    v1t = dx1 * tx + dy1 * ty # Velocity 1 along tangent (no change) axis
    # Velocity 2 components
    v2n = dx2 * nx + dy2 * ny
    v2t = dx2 * tx + dy2 * ty

    # 5. The actual collision: Swap normal velocities (elastic collision, equal mass)
    v1n_prime = v2n
    v2n_prime = v1n

    # 6. Convert the new normal/tangent velocities back to Cartesian coordinates (dx, dy)
    new_dx1 = v1n_prime * nx + v1t * tx
    new_dy1 = v1n_prime * ny + v1t * ty
    new_dx2 = v2n_prime * nx + v2t * tx
    new_dy2 = v2n_prime * ny + v2t * ty

    # 7. Update ball velocities
    ball1[2], ball1[3] = new_dx1, new_dy1
    ball2[2], ball2[3] = new_dx2, new_dy2

    # 8. Separate the balls slightly to prevent sticking (push them apart along the normal vector)
    overlap = (r1 + r2) - distance
    # Move both balls away from each other by half the overlap
    ball1[0] -= overlap * nx / 2
    ball1[1] -= overlap * ny / 2
    ball2[0] += overlap * nx / 2
    ball2[1] += overlap * ny / 2


# --- 1. Input Phase (Same as before) ---

input_active = True
user_input = ""
MAX_INPUT_LENGTH = 3

def draw_input_screen(screen, user_input):
    screen.fill(BLACK)
    title_surface = font_large.render("Set Ball Limit", True, WHITE)
    screen.blit(title_surface, (width // 2 - title_surface.get_width() // 2, 50))
    prompt_surface = font_medium.render("Enter a number (then press ENTER):", True, WHITE)
    screen.blit(prompt_surface, (width // 2 - prompt_surface.get_width() // 2, 150))
    input_box_rect = pygame.Rect(width // 2 - 100, 200, 200, 50)
    pygame.draw.rect(screen, BLUE, input_box_rect, 0)
    pygame.draw.rect(screen, WHITE, input_box_rect, 2)
    text_surface = font_large.render(user_input, True, BLACK)
    screen.blit(text_surface, (input_box_rect.x + 10, input_box_rect.y + 5))
    pygame.display.flip()

while input_active:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RETURN:
                if user_input.isdigit() and int(user_input) > 0:
                    MAX_BALLS = int(user_input)
                    input_active = False
                else:
                    user_input = ""
            elif event.key == pygame.K_BACKSPACE:
                user_input = user_input[:-1]
            elif event.unicode.isdigit() and len(user_input) < MAX_INPUT_LENGTH:
                user_input += event.unicode
    
    draw_input_screen(screen, user_input)
    clock.tick(FPS)

if 'MAX_BALLS' not in locals():
    MAX_BALLS = 10 

# --- 2. Game Phase Initialization ---

# Ball list structure: [x, y, dx, dy, radius, color]
# Start with one ball, applying the new random speed function
balls = [
    [
        width // 2, 
        height // 2, 
        get_random_speed() * random.choice([-1, 1]), 
        get_random_speed() * random.choice([-1, 1]), 
        initial_radius, 
        get_random_color()
    ]
]

# --- 3. Main Game Loop (The Bouncing and Colliding) ---

running = True
while running:
    clock.tick(FPS)

    # Event Handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # --- Inter-Ball Collision Logic (NEW) ---
    # Check every ball against every other ball
    for i in range(len(balls)):
        for j in range(i + 1, len(balls)):
            ball1 = balls[i]
            ball2 = balls[j]

            # Calculate distance squared to avoid using math.sqrt() if possible (faster)
            dist_sq = (ball1[0] - ball2[0])**2 + (ball1[1] - ball2[1])**2
            
            # Check if centers are closer than the sum of radii squared
            min_dist = ball1[4] + ball2[4] # Sum of radii
            
            if dist_sq < min_dist**2:
                # Collision detected! Resolve the physics
                resolve_collision(ball1, ball2)
    # ---------------------------------------------

    # --- Wall Collision and Movement Logic (Modified) ---
    for ball in balls:
        ball_x, ball_y, dx, dy, radius, color = ball

        # 1. Update Position
        ball[0] += dx
        ball[1] += dy

        spawn_new_ball = False

        # 2. Wall Collision Detection and Spawning (same as before)

        # Check X-axis collision
        if ball[0] + radius > width or ball[0] - radius < 0:
            ball[2] *= -1  # Reverse dx
            spawn_new_ball = True
            # Adjust position to prevent sticking
            if ball[0] + radius > width:
                ball[0] = width - radius
            else:
                ball[0] = radius
            
        # Check Y-axis collision
        if ball[1] + radius > height or ball[1] - radius < 0:
            ball[3] *= -1  # Reverse dy
            spawn_new_ball = True
            # Adjust position to prevent sticking
            if ball[1] + radius > height:
                ball[1] = height - radius
            else:
                ball[1] = radius

        # Check for spawning
        if spawn_new_ball and len(balls) < MAX_BALLS:
            new_ball = [
                ball[0], # Spawn at collision point
                ball[1],
                get_random_speed() * random.choice([-1, 1]),
                get_random_speed() * random.choice([-1, 1]),
                initial_radius,
                get_random_color()
            ]
            balls.append(new_ball)

    # --- 4. Drawing ---
    
    screen.fill(BLACK)

    # Draw all the balls
    for ball in balls:
        # Note: We use the list indices directly now as we didn't unpack for drawing
        pygame.draw.circle(screen, ball[5], (int(ball[0]), int(ball[1])), ball[4])

    # Display the current ball count
    ball_count_text = font_medium.render(f"Balls: {len(balls)} / {MAX_BALLS}", True, WHITE)
    screen.blit(ball_count_text, (10, 10))

    # Update the display
    pygame.display.flip()

# --- Cleanup ---
pygame.quit()
sys.exit()