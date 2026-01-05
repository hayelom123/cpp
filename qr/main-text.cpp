#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "qrcodegen.hpp"
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype> // for toupper

using namespace qrcodegen;

// Simple 5x8 bitmap font (row 0 = top of character)
std::unordered_map<char, std::vector<uint8_t>> font = {
    {' ', {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
    {'+', {0x00, 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00}},
    {'0', {0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00, 0x00, 0x00}},
    {'1', {0x00, 0x42, 0x7F, 0x40, 0x00, 0x00, 0x00, 0x00}},
    {'2', {0x42, 0x61, 0x51, 0x49, 0x46, 0x00, 0x00, 0x00}},
    {'3', {0x21, 0x41, 0x45, 0x4B, 0x31, 0x00, 0x00, 0x00}},
    {'4', {0x18, 0x14, 0x12, 0x7F, 0x10, 0x00, 0x00, 0x00}},
    {'5', {0x27, 0x45, 0x45, 0x45, 0x39, 0x00, 0x00, 0x00}},
    {'6', {0x3C, 0x4A, 0x49, 0x49, 0x30, 0x00, 0x00, 0x00}},
    {'7', {0x01, 0x71, 0x09, 0x05, 0x03, 0x00, 0x00, 0x00}},
    {'8', {0x36, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00, 0x00}},
    {'9', {0x06, 0x49, 0x49, 0x29, 0x1E, 0x00, 0x00, 0x00}},
    {'A', {0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00, 0x00, 0x00}},
    {'B', {0x7F, 0x49, 0x49, 0x49, 0x36, 0x00, 0x00, 0x00}},
    {'C', {0x3E, 0x41, 0x41, 0x41, 0x22, 0x00, 0x00, 0x00}},
    {'D', {0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00, 0x00, 0x00}},
    {'E', {0x7F, 0x49, 0x49, 0x49, 0x41, 0x00, 0x00, 0x00}},
    {'F', {0x7F, 0x09, 0x09, 0x09, 0x01, 0x00, 0x00, 0x00}},
    {'G', {0x3E, 0x41, 0x49, 0x49, 0x7A, 0x00, 0x00, 0x00}},
    {'H', {0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00, 0x00, 0x00}},
    {'I', {0x00, 0x41, 0x7F, 0x41, 0x00, 0x00, 0x00, 0x00}},
    {'J', {0x20, 0x40, 0x41, 0x3F, 0x01, 0x00, 0x00, 0x00}},
    {'K', {0x7F, 0x08, 0x14, 0x22, 0x41, 0x00, 0x00, 0x00}},
    {'L', {0x7F, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00}},
    {'M', {0x7F, 0x02, 0x0C, 0x02, 0x7F, 0x00, 0x00, 0x00}},
    {'N', {0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00, 0x00, 0x00}},
    {'O', {0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00}},
    {'P', {0x7F, 0x09, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00}},
    {'Q', {0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00, 0x00, 0x00}},
    {'R', {0x7F, 0x09, 0x19, 0x29, 0x46, 0x00, 0x00, 0x00}},
    {'S', {0x46, 0x49, 0x49, 0x49, 0x31, 0x00, 0x00, 0x00}},
    {'T', {0x01, 0x01, 0x7F, 0x01, 0x01, 0x00, 0x00, 0x00}},
    {'U', {0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00, 0x00, 0x00}},
    {'V', {0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00, 0x00, 0x00}},
    {'W', {0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00, 0x00, 0x00}},
    {'X', {0x63, 0x14, 0x08, 0x14, 0x63, 0x00, 0x00, 0x00}},
    {'Y', {0x07, 0x08, 0x70, 0x08, 0x07, 0x00, 0x00, 0x00}},
    {'Z', {0x61, 0x51, 0x49, 0x45, 0x43, 0x00, 0x00, 0x00}},
};

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
        "item1.URL:https://www.tiktok.com/@hikma_beauty\n"
        "item1.X-ABLabel:TikTok\n"
        "item2.URL:https://wa.me/251926962915\n"
        "item2.X-ABLabel:WhatsApp\n"
        "item3.URL:https://t.me/hikma_beauty\n"
        "item3.X-ABLabel:Telegram\n"
        "item4.URL:https://www.instagram.com/hikma_beauty_ig\n"
        "item4.X-ABLabel:Instagram\n"
        "PHOTO;VALUE=uri:https://p16-sign-va.tiktokcdn.com/tos-maliva-avt-0068/72684ce0c9270dc1abf12d6b5b3eb0d5~tplv-tiktokx-cropcenter:1080:1080.jpeg?dr=14579&refresh_token=f7dffeaf&x-expires=1767729600&x-signature=po%2BJyA25aEuM3nxsn9EEJ%2B86j4k%3D&t=4d5b0474&ps=13740610&shp=a5d48078&shcp=81f88b70&idc=my\n"
        "NOTE:Scan to save contact & follow on social media\n"
        "END:VCARD";

    QrCode qr = QrCode::encodeText(vcard.c_str(), QrCode::Ecc::MEDIUM);

    const int scale = 10;
    const int border = 8;
    const int qrPixelSize = (qr.getSize() + 2 * border) * scale;

    const int textHeight = 180;
    const int totalWidth = qrPixelSize;
    const int totalHeight = qrPixelSize + textHeight;

    std::vector<unsigned char> image(totalWidth * totalHeight * 3, 255); // White background

    // Draw QR code (black modules)
    for (int y = 0; y < qr.getSize(); ++y)
    {
        for (int x = 0; x < qr.getSize(); ++x)
        {
            if (qr.getModule(x, y))
            {
                for (int dy = 0; dy < scale; ++dy)
                {
                    for (int dx = 0; dx < scale; ++dx)
                    {
                        int px = (border + x) * scale + dx;
                        int py = (border + y) * scale + dy;
                        int idx = (py * totalWidth + px) * 3;
                        image[idx] = image[idx + 1] = image[idx + 2] = 0;
                    }
                }
            }
        }
    }

    // Fixed text drawing: reversed bit order for correct left-right orientation
    auto drawText = [&](const std::string &text, int startY, int charScale = 8)
    {
        int charWidth = 8 * charScale;
        int charHeight = 8 * charScale;
        int spacing = charScale * 2;
        int totalTextWidth = (static_cast<int>(text.length()) * (8 * charScale + spacing)) - spacing;
        int startX = (totalWidth - totalTextWidth) / 2;
        if (startX < 10)
            startX = 10; // Safety margin

        int posX = startX;
        for (char ch : text)
        {
            char key = (ch == ' ' || ch == '+') ? ch : std::toupper(ch);
            auto it = font.find(key);
            if (it == font.end())
            {
                posX += charWidth + spacing;
                continue;
            }
            const auto &bitmap = it->second;

            for (int row = 0; row < 8; ++row)
            {
                for (int bit = 0; bit < 8; ++bit)
                {
                    // REVERSED BIT ORDER: draws correct left-to-right
                    if (bitmap[row] & (1 << (7 - bit)))
                    {
                        for (int dy = 0; dy < charScale; ++dy)
                        {
                            for (int dx = 0; dx < charScale; ++dx)
                            {
                                int px = posX + bit * charScale + dx;
                                int py = startY + row * charScale + dy;
                                if (px >= 0 && px < totalWidth && py >= 0 && py < totalHeight)
                                {
                                    int idx = (py * totalWidth + px) * 3;
                                    image[idx] = image[idx + 1] = image[idx + 2] = 0; // Black text
                                }
                            }
                        }
                    }
                }
            }
            posX += charWidth + spacing;
        }
    };

    // Draw the text below the QR code
    drawText("HIKMA DAWUD", qrPixelSize + 30, 9);       // Large bold name
    drawText("+251 926 962 915", qrPixelSize + 110, 8); // Phone number

    stbi_write_png("contact_qr_with_name.png", totalWidth, totalHeight, 3, image.data(), totalWidth * 3);

    return 0;
}