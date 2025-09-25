#include <cstdint>
enum state_e : std::uint8_t{
    START,
    OUT_OF_ORDER, 
    LOCKED,
    UNLOCKED,
    STOP,
};

enum input_e : std::uint8_t{
    PUSH,
    COIN,
    END,
    OFF,
    ON,
    NONE,
};

class Catraca{
    state_e m_state{START};
    input_e m_input{NONE};
    size_t coins{};
    public:
    [[nodiscard]] bool out_of_order() const {return m_state == OUT_OF_ORDER};
    [[nodiscard]] bool ended();
    void process_evets();
    void update();
    void render();
};

void Catraca::process_events