#include "qrcodegen.hpp"
#include <algorithm>
#include <stdexcept>

using namespace qrcodegen;

QrCode::QrCode(int ver, Ecc ecl) :
    version(ver),
    errorCorrectionLevel(ecl),
    size(17 + 4 * version) {

    if (version < 1 || version > 40)
        throw std::invalid_argument("Version must be between 1 and 40");

    modules = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
}

int QrCode::getSize() const {
    return size;
}

bool QrCode::getModule(int x, int y) const {
    if (x < 0 || x >= size || y < 0 || y >= size)
        return false;
    return modules[y][x];
}

void QrCode::addFinderPattern(int x, int y) {
    for (int dy = -4; dy <= 4; dy++) {
        for (int dx = -4; dx <= 4; dx++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                modules[ny][nx] = (std::max(std::abs(dx), std::abs(dy)) <= 2);
            }
        }
    }
}

void QrCode::addAlignmentPattern(int x, int y) {
    for (int dy = -2; dy <= 2; dy++) {
        for (int dx = -2; dx <= 2; dx++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                modules[ny][nx] = (std::max(std::abs(dx), std::abs(dy)) <= 1);
            }
        }
    }
}

void QrCode::setupTimingPatterns() {
    for (int i = 8; i < size - 8; i++) {
        modules[6][i] = (i % 2 == 0);
        modules[i][6] = (i % 2 == 0);
    }
}

void QrCode::setupFormatInfo(Ecc ecl) {
    // Format info simplifié
    for (int i = 0; i < 8; i++) {
        modules[8][i] = (i < 4);
        modules[i][8] = (i < 4);
    }
    modules[8][8] = true;
}

QrCode QrCode::encodeText(const char *text, Ecc ecl) {
    QrCode qr(1, ecl);

    // Encodage simplifié du texte
    std::string data(text);
    size_t dataPos = 0;
    for (int y = 0; y < qr.size && dataPos < data.size() * 8; y++) {
        for (int x = 0; x < qr.size && dataPos < data.size() * 8; x++) {
            // Évite les zones réservées
            if ((x < 9 && y < 9) || (x < 9 && y > qr.size - 9) ||
                (x > qr.size - 9 && y < 9) || x == 6 || y == 6)
                continue;

            if (dataPos < data.size() * 8) {
                char c = data[dataPos / 8];
                qr.modules[y][x] = (c & (1 << (7 - (dataPos % 8)))) != 0;
                dataPos++;
            }
        }
    }

    // Ajoute les motifs fixes
    qr.addFinderPattern(0, 0);
    qr.addFinderPattern(0, qr.size - 7);
    qr.addFinderPattern(qr.size - 7, 0);
    qr.addAlignmentPattern(qr.size - 9, qr.size - 9);
    qr.setupTimingPatterns();
    qr.setupFormatInfo(ecl);

    return qr;
}
