/**
    gTox a GTK-based tox-client - https://github.com/KoKuToru/gTox.git

    Copyright (C) 2014  Luca Béla Palkovics
    Copyright (C) 2014  Maurice Mohlek

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
 **/

#include "AccountWidget.h"
#include <glibmm/i18n.h>

#include <stdio.h>

AccountWidget::AccountWidget()
    : importText(_("ACCOUNT_WIDGET_NEW_IMPORT_MSG")),
      rbNew(_("CREATE_NEW_ACCOUNT")),
      rbImport(_("IMPORT_ACCOUNT")) {
    add(gridLayout);
    gridLayout.add(importText);

    rbImport.join_group(rbNew);

    radioBtnBox.pack_start(rbNew);
    radioBtnBox.pack_start(rbImport);

    gridLayout.attach(radioBtnBox, 0, 1, 1, 1);
}

AccountWidget::~AccountWidget() {
}
