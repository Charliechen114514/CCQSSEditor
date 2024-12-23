#ifndef KEYWORDS_QSS_H
#define KEYWORDS_QSS_H

struct KeyWordConstants {
public:
    static constexpr const char* allKeywords[] = {
        // widget 类
        "QAbstractScrollArea", "QCheckBox", "QColumnView", "QComboBox", "QDateEdit",
        "QDateTimeEdit", "QDialog", "QDialogButtonBox", "QDockWidget", "QDoubleSpinBox",
        "QFrame", "QGroupBox", "QHeaderView", "QLabel", "QLineEdit", "QListView",
        "QListWidget", "QMainWindow", "QMenu", "QMenuBar", "QMessageBox", "QProgressBar",
        "QPushButton", "QRadioButton", "QScrollBar", "QSizeGrip", "QSlider", "QSpinBox",
        "QSplitter", "QStatusBar", "QTabBar", "QTabWidget", "QTableView", "QTableWidget",
        "QTextEdit", "QTimeEdit", "QToolBar", "QToolButton", "QToolBox", "QToolTip",
        "QTreeView", "QTreeWidget", "QWidget",

        // 对齐方式
        "top", "bottom", "left", "right", "center",

        // 附加方式
        "scroll", "fixed",

        // 边框图像方式
        "none", "stretch", "repeat",

        // 边框样式
        "dashed", "dot-dash", "dot-dot-dash", "dotted", "double", "inset", "outset",
        "ridge", "solid", "none",

        // 字体样式
        "normal", "italic", "oblique", "bold",

        // 渐变类型
        "qlineargradient", "qradialgradient", "qconicalgradient",

        // 原点类型
        "margin", "border", "padding", "content",

        // 调色板角色
        "alternate-base", "base", "bright-text", "button", "button-text", "dark",
        "highlight", "highlighted-text", "light", "link", "link-visited", "mid",
        "midlight", "shadow", "text", "window", "window-text",

        // 重复方式
        "repeat", "repeat-x", "repeat-y", "no-repeat"
    };


    static constexpr const char* KeywordSet1 =
        " alternate-background-color"
        " background"
        " background-color"
        " background-image"
        " background-repeat"
        " background-position"
        " background-attachment"
        " background-clip"
        " background-origin"
        " border"
        " border-top"
        " border-right"
        " border-bottom"
        " border-left"
        " border-color"
        " border-top-color"
        " border-right-color"
        " border-bottom-color"
        " border-left-color"
        " border-image"
        " border-radius"
        " border-top-left-radius"
        " border-top-right-radius"
        " border-bottom-right-radius"
        " border-bottom-left-radius"
        " border-style"
        " border-top-style"
        " border-right-style"
        " border-bottom-style"
        " border-left-style"
        " border-width"
        " border-top-width"
        " border-right-width"
        " border-bottom-width"
        " border-left-width"
        " bottom"
        " button-layout"
        " color"
        " dialogbuttonbox-buttons-have-icons"
        " font"
        " font-family"
        " font-size"
        " font-style"
        " font-weight"
        " gridline-color"
        " height"
        " icon-size"
        " image"
        " image-position"
        " left"
        " lineedit-password-character"
        " margin"
        " margin-top"
        " margin-right"
        " margin-bottom"
        " margin-left"
        " max-height"
        " max-width"
        " messagebox-text-interaction-flags"
        " min-height"
        " min-width"
        " opacity"
        " outline" // not documented
        " padding"
        " padding-top"
        " padding-right"
        " padding-bottom"
        " padding-left"
        " paint-alternating-row-colors-for-empty-area"
        " position"
        " right"
        " selection-background-color"
        " selection-color"
        " show-decoration-selected"
        " spacing"
        " subcontrol-origin"
        " subcontrol-position"
        " text-align"
        " text-decoration"
        " top"
        " width"

        " backward-icon"
        " cd-icon"
        " computer-icon"
        " desktop-icon"
        " dialog-apply-icon"
        " dialog-cancel-icon"
        " dialog-close-icon"
        " dialog-discard-icon"
        " dialog-help-icon"
        " dialog-no-icon"
        " dialog-ok-icon"
        " dialog-open-icon"
        " dialog-reset-icon"
        " dialog-save-icon"
        " dialog-yes-icon"
        " directory-closed-icon"
        " directory-icon"
        " directory-link-icon"
        " directory-open-icon"
        " dockwidget-close-icon"
        " downarrow-icon"
        " dvd-icon"
        " file-icon"
        " file-link-icon"
        " filedialog-contentsview-icon"
        " filedialog-detailedview-icon"
        " filedialog-end-icon"
        " filedialog-infoview-icon"
        " filedialog-listview-icon"
        " filedialog-new-directory-icon"
        " filedialog-parent-directory-icon"
        " filedialog-start-icon"
        " floppy-icon"
        " forward-icon"
        " harddisk-icon"
        " home-icon"
        " leftarrow-icon"
        " messagebox-critical-icon"
        " messagebox-information-icon"
        " messagebox-question-icon"
        " messagebox-warning-icon"
        " network-icon"
        " rightarrow-icon"
        " titlebar-contexthelp-icon"
        " titlebar-maximize-icon"
        " titlebar-menu-icon"
        " titlebar-minimize-icon"
        " titlebar-normal-icon"
        " titlebar-shade-icon"
        " titlebar-unshade-icon"
        " trash-icon"
        " uparrow-icon";

    static constexpr const char* KeywordSet2 =
        " active"
        " adjoins-item"
        " alternate"
        " bottom"
        " checked"
        " closable"
        " closed"
        " default"
        " disabled"
        " editable"
        " edit-focus"
        " enabled"
        " exclusive"
        " first"
        " flat"
        " floatable"
        " focus"
        " has-children"
        " has-siblings"
        " horizontal"
        " hover"
        " indeterminate"
        " last"
        " left"
        " maximized"
        " middle"
        " minimized"
        " movable"
        " no-frame"
        " non-exclusive"
        " off"
        " on"
        " only-one"
        " open"
        " next-selected"
        " pressed"
        " previous-selected"
        " read-only"
        " right"
        " selected"
        " top"
        " unchecked"
        " vertical"
        " window"

        " add-line"
        " add-page"
        " branch"
        " chunk"
        " close-button"
        " corner"
        " down-arrow"
        " down-button"
        " drop-down"
        " float-button"
        " groove"
        " indicator"
        " handle"
        " icon"
        " item"
        " left-arrow"
        " left-corner"
        " menu-arrow"
        " menu-button"
        " menu-indicator"
        " right-arrow"
        " pane"
        " right-corner"
        " scroller"
        " section"
        " separator"
        " sub-line"
        " sub-page"
        " tab"
        " tab-bar"
        " tear"
        " tearoff"
        " text"
        " title"
        " up-arrow"
        " up-button";
};

#endif  // KEYWORDS_QSS_H
