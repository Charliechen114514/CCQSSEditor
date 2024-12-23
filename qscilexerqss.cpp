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

#include <QEventLoop>
#include <QRegularExpression>

#include "keywords_qss.h"
#include "Qsci/qsciapis.h"

#include "qscilexerqss.h"

QsciLexerQSS::QsciLexerQSS(QObject *parent)
    : QsciLexerCSS(parent)
{
    QsciAPIs *api = new QsciAPIs(this);

    static const QRegularExpression expression("\\s+");

    const QString stringKeywords = QString(keywords(KeyWordSet::Set1)) + keywords(KeyWordSet::Set2);

    QStringList listKeywords = stringKeywords.split(
        expression, Qt::SkipEmptyParts);

    for(const auto &keyword : KeyWordConstants::allKeywords)
    {
        listKeywords.append(keyword);
    }

    listKeywords.removeDuplicates();

    foreach(const QString &word, listKeywords)
    {
        api->add(word);
    }

    QEventLoop loop;

    connect(api, &QsciAPIs::apiPreparationFinished, &loop, &QEventLoop::quit);

    api->prepare();

    loop.exec();

    setAPIs(api);
}

const char *QsciLexerQSS::keywords(KeyWordSet set) const
{
    switch(set)
    {
        case Set1:
            return KeyWordConstants::KeywordSet1;
        case Set2:
            return KeyWordConstants::KeywordSet2;
    }
    return nullptr;
}

QFont QsciLexerQSS::defaultFont(int style) const
{
    QFont font = QsciLexerCSS::defaultFont(style);
    font.setBold(false);
    return font;
}
