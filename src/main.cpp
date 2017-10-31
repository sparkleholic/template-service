/*
 *   Copyright (C) 2017 Pelagicore AB
 *
 *   This Source Code Form is subject to the terms of the Mozilla Public
 *   License, v. 2.0. If a copy of the MPL was not distributed with this
 *   file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *   SPDX-License-Identifier: MPL-2.0
 *
 */

#ifdef TEMPLATE_LIBRARY
#include <template-library/templatepublicclass.h>

void testTemplateLibrary() {
    std::shared_ptr<TemplatePublicClass> templatePublicInstance(new TemplatePublicClass());
    templatePublicInstance->templateFunction();
}
#endif

#include <iostream>
#include <memory>


int main(int argc, char const **argv)
{
    std::cout << "Hello from Template Service!\n";
#ifdef TEMPLATE_LIBRARY
    testTemplateLibrary();
#endif
    return 0;
}
