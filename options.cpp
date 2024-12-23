/*
 * This file is part of QssEditor.
 *
 * QssEditor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QssEditor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QssEditor. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QCoreApplication>
#include <QDir>

#include "settings.h"
#include "options.h"
#include "ui_options.h"

static inline QString base_path_gen(){
    return
    #ifdef Q_OS_UNIX
        QString("/usr/share/" TARGET_STRING).toLower()
    #else
        QCoreApplication::applicationDirPath()
    #endif
        + QDir::separator()
        + "translations"
        + QDir::separator();
}

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options),
    m_startTranslationIndex(-1)
{
    ui->setupUi(this);

    ui->checkOpenLast->setChecked(Settings::value<bool>(SETTING_OPEN_LAST_FILE));
    ui->spinPreviewDelay->setValue(Settings::value<int>(SETTING_PREVIEW_DELAY));

    ui->comboLang->addItem('<' + tr("System") + '>');

    // translations
    const QMap<QString, QString> tsmap = Settings::instance()->translations();
    QString ts = Settings::value<QString>(SETTING_TRANSLATION);
    QMap<QString, QString>::const_iterator itEnd = tsmap.end();

    const QString basePath = base_path_gen();

    for(QMap<QString, QString>::const_iterator it = tsmap.begin();it != itEnd;++it)
    {
        ui->comboLang->addItem(QIcon(basePath + it.key() + ".png"), it.value(), it.key());

        if(it.key() == ts)
        {
            m_startTranslationIndex = ui->comboLang->count() - 1;
            ui->comboLang->setCurrentIndex(m_startTranslationIndex);
        }
    }

    if(m_startTranslationIndex < 0)
        m_startTranslationIndex = 0;

    ui->labelRestart->hide();

    adjustSize();
    resize(width(), height()+10);
}

Options::~Options()
{
    delete ui;
}

void Options::slotSomethingImportantChanged()
{
    ui->labelRestart->setVisible(ui->comboLang->currentIndex() != m_startTranslationIndex);
}

void Options::saveSettings() const
{
    Settings::setValue<QString>(SETTING_TRANSLATION, ui->comboLang->itemData(ui->comboLang->currentIndex()).toString(), Settings::NoSync);
    Settings::setValue<bool>(SETTING_OPEN_LAST_FILE, ui->checkOpenLast->isChecked(), Settings::NoSync);
    Settings::setValue<int>(SETTING_PREVIEW_DELAY, ui->spinPreviewDelay->value());
}
