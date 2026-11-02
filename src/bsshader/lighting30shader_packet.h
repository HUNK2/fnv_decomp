struct Lighting30Packet4
{
    unsigned int x, y, z, w;
};
struct Lighting30PacketState
{
    char pad[8];
    bool dirty;
};
extern Lighting30Packet4 DAT_011a9bd0, DAT_01201b30;
extern Lighting30PacketState* DAT_012010c4;
extern bool DAT_01200bf4, DAT_01200bf5;
