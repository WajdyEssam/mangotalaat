#ifndef CONSTANTS_H
#define CONSTANTS_H


// order type constants
enum ORDER_TYPE {
    CASH=1, CUPON, DISCOUNT, FREE
};

// logging constant
enum LOGIN_TYPE {
    LOGIN=1 , LOGOUT
};

// sugar constant
enum SUGAR {
    NO=1, LOW, NORMAL, MORE
};


// conveter methods
static inline SUGAR getSugar(int sugar) {
    switch (  sugar ) {
        case 1: return NO;
        case 2: return LOW;
        case 3: return NORMAL;
        case 4: return MORE;
    }

    return NORMAL;
}

static inline ORDER_TYPE getOrderType(int orderType) {
    switch (  orderType ) {
        case 1: return CASH;
        case 2: return CUPON;
        case 3: return DISCOUNT;
        case 4: return FREE;
    }

    return CASH;
}

static inline LOGIN_TYPE getLoginType(int login) {
    switch (  login ) {
        case 1: return LOGIN;
        case 2: return LOGOUT;
    }

    return LOGIN;
}

#endif // CONSTANTS_H
