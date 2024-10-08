#include "effectsubwooferfactory.h"
#include "subwooferplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
const EffectProperties EffectSubwooferFactory::properties() const
#else
EffectProperties EffectSubwooferFactory::properties() const
#endif
{
    EffectProperties properties;
    properties.name = tr("Subwoofer Plugin");
    properties.shortName = "subwoofer";
    properties.hasSettings = true;
    properties.hasAbout = true;
    return properties;
}

Effect *EffectSubwooferFactory::create()
{
    return new SubwooferPlugin();
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void EffectSubwooferFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}
#else
QDialog *EffectSubwooferFactory::createSettings(QWidget *parent)
{
    return new SettingsDialog(parent);
}
#endif

void EffectSubwooferFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About Subwoofer Effect Plugin"),
                       tr("Qmmp Subwoofer Effect Plugin") + "\n"+
                       tr("Written by: Ilya Kotov <forkotov02@ya.ru>"));
}

QString EffectSubwooferFactory::translation() const
{
    return QString();
}
