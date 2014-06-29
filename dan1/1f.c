#include <stdio.h>

typedef enum
{
    NED, /* = 0 */
    PON, /* = 1 */
    UTO,
    SRI,
    CET,
    PET,
    SUB
}dan_t;

typedef enum
{
    BAD_REQ = 400,
    UNAUTHORIZED = 401,
    PAY_REQ = 402,
    FORBIDDEN = 403,
    NOT_FOUND /* = 404 */
}html_error_t;

int main()
{
    dan_t danas = PON;
    html_error_t err = NOT_FOUND;
    printf("%d, %d", danas, err);
}
