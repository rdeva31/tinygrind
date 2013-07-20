#ifndef __TINYGRIND_UTILS_H__
#define __TINYGRIND_UTILS_H__

enum tg_log_level {
	DBG,
	INFO,
	WARN,
	ERR,
};

static enum tg_log_level log_level = INFO;

#define dprintk(level, fmt, arg...) \
        do { \
                if (level >= log_level)  \
                        printf("tinygrind: %5s: " fmt, #level, ##arg);\
        } while (0)


#endif
