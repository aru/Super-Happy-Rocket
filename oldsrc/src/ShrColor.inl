//----------------------------------------------------------------------------
inline unsigned int Color::MakeR8G8B8 (unsigned char red, unsigned char green,
    unsigned char blue)
{
#ifdef SHR_BIG_ENDIAN
    return (255 | (blue << 8) | (green << 16) | (red << 24));
#else
    return (red | (green << 8) | (blue << 16) | (255 << 24));
#endif
}
//----------------------------------------------------------------------------
inline unsigned int Color::MakeR8G8B8A8 (unsigned char red,
    unsigned char green, unsigned char blue, unsigned char alpha)
{
#ifdef SHR_BIG_ENDIAN
    return (alpha | (blue << 8) | (green << 16) | (red << 24));
#else
    return (red | (green << 8) | (blue << 16) | (alpha << 24));
#endif
}
//----------------------------------------------------------------------------
inline void Color::ExtractR8G8B8 (unsigned int color, unsigned char& red,
    unsigned char& green, unsigned char& blue)
{
#ifdef SHR_BIG_ENDIAN
    red =   (unsigned char)((color & 0xFF000000) >> 24);
    green = (unsigned char)((color & 0x00FF0000) >> 16);
    blue =  (unsigned char)((color & 0x0000FF00) >>  8);
#else
    red =   (unsigned char)((color & 0x000000FF));
    green = (unsigned char)((color & 0x0000FF00) >>  8);
    blue =  (unsigned char)((color & 0x00FF0000) >> 16);
#endif
}
//----------------------------------------------------------------------------
inline void Color::ExtractR8G8B8A8 (unsigned int color, unsigned char& red,
    unsigned char& green, unsigned char& blue, unsigned char& alpha)
{
#ifdef SHR_BIG_ENDIAN
    red =   (unsigned char)((color & 0xFF000000) >> 24);
    green = (unsigned char)((color & 0x00FF0000) >> 16);
    blue =  (unsigned char)((color & 0x0000FF00) >>  8);
    alpha = (unsigned char)((color & 0x000000FF));
#else
    red =   (unsigned char)((color & 0x000000FF));
    green = (unsigned char)((color & 0x0000FF00) >>  8);
    blue =  (unsigned char)((color & 0x00FF0000) >> 16);
    alpha = (unsigned char)((color & 0xFF000000) >> 24);
#endif
}
//----------------------------------------------------------------------------
