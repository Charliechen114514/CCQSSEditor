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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QStringList>
#include <QDataStream>
#include <QByteArray>
#include <QDateTime>
#include <QSettings>
#include <QVariant>
#include <QString>
#include <QPoint>
#include <QList>
#include <QHash>
#include <QMap>

static constexpr const char* SETTING_TRANSLATION[[maybe_unused]]
    = "translation";
static constexpr const char* SETTING_OPEN_LAST_FILE[[maybe_unused]]
    = "open-last-file";
static constexpr const char* SETTING_PREVIEW_DELAY[[maybe_unused]]
    = "preview-delay";
static constexpr const char* SETTING_LAST_FILE[[maybe_unused]]
    = "last-file";
static constexpr const char* SETTING_LAST_FILES[[maybe_unused]]
    = "last-files";
static constexpr const char* SETTING_FIND_REPLACE_FIND_TEXT[[maybe_unused]]
    = "fr-find-text";
static constexpr const char* SETTING_FIND_REPLACE_REPLACE[[maybe_unused]]
    = "fr-replace";
static constexpr const char* SETTING_FIND_REPLACE_REPLAC_TEXT[[maybe_unused]]
    = "fr-replace-text";
static constexpr const char* SETTING_FIND_REPLACE_FORWARD[[maybe_unused]]
    = "fr-forward";
static constexpr const char* SETTING_FIND_REPLACE_CASE_SENSITIVE[[maybe_unused]]
    = "fr-case-sensitive";
static constexpr const char* SETTING_FIND_REPLACE_WHOLE_WORDS[[maybe_unused]]
    = "fr-whole-words";
static constexpr const char* SETTING_FIND_REPLACE_REGEXP[[maybe_unused]]
    = "fr-regexp";

class SettingsPrivate;

/*
 *  Class to query the application settings. You can use
 *  the macroses above to query the appropriate values
 *  like that:
 *
 *      qDebug() << SETTINGS_GET_STRING(SETTING_TRANSLATION);
 */
class Settings
{
public:
    static Settings* instance();

    ~Settings();

    enum SyncType { NoSync, Sync };
    /*
     *  Add your default values for your settings
     */
    void addDefaultValues(const QHash<QString, QVariant> &defaultValues);

    /*
     *  Returns the default value of the setting 'key'. Returns
     *  an invalid QVariant if the settings is not found in the
     *  default values
     */
    QVariant defaultValue(const QString &key) const;

    /*
     *  Returns 'true' if the setting 'key' exists. If 'key' starts with '/'
     *  the setting is returned from "settings" group (almost all settings are stored there).
     *
     *  For example:
     *
     *  contains("list")  - will look for the "list" key in the global section
     *  contains("/list") - will look for the "list" key in the "settings" section
     */
    bool contains(const QString &key) const;

    /*
     *  Remove the specified key from the section "settings"
     */
    void remove(const QString &key, SyncType sync = Sync);

    /*
     *  Sync with the storage
     */
    void sync();

    /*
     *  Available translations, hardcoded
     */
    QMap<QString, QString> translations();


    /*
        Original Codes are lack of recognizing using
        templates, codes shell be replaced for bettercase
    */
    template<typename Value>
    static Value value(const QString &key){
        return Settings::instance()->__value<Value>(key);
    }

    template<typename Value>
    static Value value(const QString &key, const Value& def){
        return Settings::instance()->__value<Value>(key, def);
    }

    template<typename Value>
    static void setValue(const QString &key, const Value &value, SyncType sync = Sync){
        Settings::instance()->__setValue(key, value, sync);
    }


private:
    Settings();

    /*
     *  Get the key value. If the value is not found, then
     *  the appropriate value from the known default values
     *  is returned. If the default value for the key is unknown,
     *  the C++ default value is returned ('0' for 'int', 'false' for 'bool' etc.)
     */
    template <typename T>
    T __value(const QString &key);

    /*
     *  Get the key value. Return 'def' if the key is not found
     */
    template <typename T>
    T __value(const QString &key, const T &def);

    /*
     *  Set the value of the key. If 'sync' is 'Sync', then call sync()
     */
    template <typename T>
    void __setValue(const QString &key, const T &value, SyncType sync = Sync);


    void fillTranslations();

    QHash<QString, QVariant> &defaultValues();

    QSettings *settings();

private:
    SettingsPrivate *d;
};

/**********************************/

template <typename T>
T Settings::__value(const QString &key)
{
    T def = T();
    QHash<QString, QVariant>::iterator it = defaultValues().find(key);

    if(it != defaultValues().end())
        def = it.value().value<T>();

    return __value<T>(key, def);
}

template <typename T>
T Settings::__value(const QString &key, const T &def)
{
    QSettings *s = settings();

    s->beginGroup("settings");
    QVariant value = s->value(key, QVariant::fromValue(def));
    s->endGroup();

    return value.value<T>();
}

template <typename T>
void Settings::__setValue(const QString &key, const T &value, Settings::SyncType sync)
{
    QSettings *s = settings();

    s->beginGroup("settings");
    s->setValue(key, QVariant::fromValue(value));
    s->endGroup();

    if(sync == Sync)
        s->sync();
}

#endif // SETTINGS_H
