#ifndef QRCODEGEN_HPP
#define QRCODEGEN_HPP

#include <vector>
#include <string>

namespace qrcodegen {

enum class Ecc {
    LOW = 0,
    MEDIUM,
    QUARTILE,
    HIGH
};

class QrCode {
public:
    static QrCode encodeText(const char *text, Ecc ecl);

    QrCode(int ver, Ecc ecl);
    int getSize() const;
    bool getModule(int x, int y) const;

private:
    int version;
    Ecc errorCorrectionLevel;
    int size;
    std::vector<std::vector<bool>> modules;

    // Ajoutez ces déclarations de méthodes privées
    void addFinderPattern(int x, int y);
    void addAlignmentPattern(int x, int y);
    void setupTimingPatterns();
    void setupFormatInfo(Ecc ecl);
};

} // namespace qrcodegen

#endif // QRCODEGEN_HPP
