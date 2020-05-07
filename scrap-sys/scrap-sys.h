
void error_free(char* err);

struct Display;

typedef struct {
    // These have to be freed individually
    struct Display** list;
    size_t len;
    char* err;
} DisplayListOrErr;

DisplayListOrErr display_list();

typedef struct {
    struct Display* display;
    char* err;
} DisplayOrErr;

DisplayOrErr display_primary();

DisplayOrErr get_display(int index);

void display_free(struct Display* display);

size_t display_width(struct Display* display);

size_t display_height(struct Display* display);

size_t display_left(struct Display* display);

size_t display_top(struct Display* display);

size_t display_id(struct Display* display);

struct Capturer;

typedef struct {
    struct Capturer* capturer;
    char* err;
} CapturerOrErr;

CapturerOrErr capturer_new(struct Display* display);

void capturer_free(struct Capturer* capturer);

size_t capturer_width(struct Capturer* capturer);

size_t capturer_height(struct Capturer* capturer);

typedef struct {
    unsigned char* data;
    size_t len;
    char would_block;
    char* err;
} FrameOrErr;

FrameOrErr capturer_frame(struct Capturer* capturer);
