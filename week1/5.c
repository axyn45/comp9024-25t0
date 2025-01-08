typedef struct
{
    int id;
    char type[1];
    char time[4];
    char journey_start[31];
    char journey_end[31];
    int fare;     // multiplied by 100 and stored as int
    int discount; // multiplied by 100 and stored as int
    char discount_type[10];
    int journey_of_week;
} ride_record;
