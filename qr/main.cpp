#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "qrcodegen.hpp"
#include <vector>
#include <string>
#include <iostream>

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
        "TEL;TYPE=CELL:+251926962915\n"
        "TEL;TYPE=WORK,VOICE:+251977058512\n"
        "EMAIL:hikmadawudyenus@gmail.com\n"
        "URL;TYPE=TikTok:https://www.tiktok.com/@hikma_beauty\n"
        "URL;TYPE=WhatsApp:https://wa.me/251926962915\n" // Opens chat directly (use your WhatsApp number)
        "URL;TYPE=Telegram:https://t.me/hikma_beauty\n"  // Opens profile/chat directly
        "URL;TYPE=Instagram:https://www.instagram.com/hikma_beauty_ig\n"
        "X-SOCIALPROFILE;TYPE=tiktok:https://www.tiktok.com/@hikma_beauty\n"
        "X-SOCIALPROFILE;TYPE=whatsapp:https://wa.me/251926962915\n"
        "X-SOCIALPROFILE;TYPE=telegram:https://t.me/hikma_beauty\n"
        "X-SOCIALPROFILE;TYPE=instagram:https://www.instagram.com/hikma_beauty_ig\n"
        "PHOTO;VALUE=uri:https://p16-sign-va.tiktokcdn.com/tos-maliva-avt-0068/72684ce0c9270dc1abf12d6b5b3eb0d5~tplv-tiktokx-cropcenter:1080:1080.jpeg?dr=14579&refresh_token=f7dffeaf&x-expires=1767729600&x-signature=po%2BJyA25aEuM3nxsn9EEJ%2B86j4k%3D&t=4d5b0474&ps=13740610&shp=a5d48078&shcp=81f88b70&idc=my\n"
        "NOTE:Tap links for TikTok, WhatsApp & Telegram\n"
        "END:VCARD";

    QrCode qr = QrCode::encodeText(vcard.c_str(), QrCode::Ecc::LOW);

    const int scale = 10;
    const int border = 12;
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
    std::cout << "Image generated sucessfully!\n";
    std::cout << "saved to ./contact_qr.png \n";

    return 0;
}
