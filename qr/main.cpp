#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "qrcodegen.hpp"
#include <vector>
#include <string>

using namespace qrcodegen;

int main()
{

    std::string vcard =
        "BEGIN:VCARD\n"
        "VERSION:3.0\n"
        "N:Dawud;Hikma;;;\n"
        "FN:Hikma Dawud\n"
        "ORG:Hikma Beauty salon\n"
        "TITLE:Nail stylist\n"
        "TEL;TYPE=CELL:+251926962911\n"
        "TEL;TYPE=WORK,VOICE:+251926962915\n"
        "EMAIL:hikma@example.com\n"
        "URL;TYPE=TikTok:https://www.tiktok.com/@hikma_beauty\n"
        "URL;TYPE=WhatsApp:https://wa.me/251926962915\n" // Opens chat directly (use your WhatsApp number)
        "URL;TYPE=Telegram:https://t.me/hikma_beauty\n"  // Opens profile/chat directly
        "X-SOCIALPROFILE;TYPE=tiktok:https://www.tiktok.com/@hikma_beauty\n"
        "X-SOCIALPROFILE;TYPE=whatsapp:https://wa.me/251926962915\n"
        "X-SOCIALPROFILE;TYPE=telegram:https://t.me/hikma_beauty\n"
        "PHOTO;VALUE=uri:https://example.com/profile.jpg\n"
        "NOTE:Tap links for TikTok, WhatsApp & Telegram\n"
        "END:VCARD";

    // std::string vcard =
    //     "BEGIN:VCARD\n"
    //     "VERSION:3.0\n"
    //     "N:Dawud;Hikma;;;\n"
    //     "FN:Hikma Dawud\n"
    //     "ORG:Hikma Beauty salon\n"
    //     "TITLE:Nail stylist\n"
    //     "TEL;TYPE=CELL:+251926962911\n"
    //     "TEL;TYPE=WORK,VOICE:+251926962915\n"
    //     "EMAIL:hikma@example.com\n"
    //     "URL:https://www.tiktok.com/@hikma_beauty\n"
    //     "X-SOCIALPROFILE;TYPE=whatsapp:+251926962915\n"
    //     "X-SOCIALPROFILE;TYPE=telegram:@hikma_beauty\n"
    //     "PHOTO;VALUE=uri:https://example.com/profile.jpg\n"
    //     "NOTE:TikTok Creator, WhatsApp & Telegram included\n"
    //     "END:VCARD";

    // std::string vcard =
    //     "BEGIN:VCARD\n"
    //     "VERSION:3.0\n"
    //     "N:Dawud;Hikma;;;\n"
    //     "FN:Hikma Dawud\n"
    //     "TEL;TYPE=CELL:+251926962915\n"
    //     "EMAIL:hayelom@example.com\n"
    //     "URL:https://www.tiktok.com/@hikma_beauty\n"
    //     "END:VCARD";

    // std::string vcard =
    //     "BEGIN:VCARD\n"
    //     "VERSION:3.0\n"
    //     "N:Kiros;Hayelom;;;\n"
    //     "FN:Hayelom Kiros\n"
    //     "ORG:Software Engineer\n"
    //     "TEL;TYPE=CELL:+251926962915\n"
    //     "EMAIL:hayelom@example.com\n"
    //     "END:VCARD";

    QrCode qr = QrCode::encodeText(vcard.c_str(), QrCode::Ecc::LOW);

    const int scale = 10;
    const int border = 4;
    const int size = (qr.getSize() + border * 2) * scale;

    std::vector<unsigned char> image(size * size * 3, 255);

    for (int y = 0; y < qr.getSize(); y++)
    {
        for (int x = 0; x < qr.getSize(); x++)
        {
            if (qr.getModule(x, y))
            {
                for (int dy = 0; dy < scale; dy++)
                {
                    for (int dx = 0; dx < scale; dx++)
                    {
                        int px = (border + x) * scale + dx;
                        int py = (border + y) * scale + dy;
                        int idx = (py * size + px) * 3;
                        image[idx] = image[idx + 1] = image[idx + 2] = 0;
                    }
                }
            }
        }
    }

    stbi_write_png("contact_qr.png", size, size, 3, image.data(), size * 3);

    return 0;
}
