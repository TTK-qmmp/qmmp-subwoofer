#include "effectsubwooferfactory.h"
#include "subwooferplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

const EffectProperties EffectSubwooferFactory::properties() const
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

void EffectSubwooferFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}

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
