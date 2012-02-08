/******************************************************************************
Este arquivo eh parte da implementacao do ambiente declarativo do middleware
Ginga (Ginga-NCL).

Direitos Autorais Reservados (c) 1989-2007 PUC-Rio/Laboratorio TeleMidia

Este programa eh software livre; voce pode redistribui-lo e/ou modificah-lo sob
os termos da Licenca Publica Geral GNU versao 2 conforme publicada pela Free
Software Foundation.

Este programa eh distribuido na expectativa de que seja util, porem, SEM
NENHUMA GARANTIA; nem mesmo a garantia implicita de COMERCIABILIDADE OU
ADEQUACAO A UMA FINALIDADE ESPECIFICA. Consulte a Licenca Publica Geral do
GNU versao 2 para mais detalhes.

Voce deve ter recebido uma copia da Licenca Publica Geral do GNU versao 2 junto
com este programa; se nao, escreva para a Free Software Foundation, Inc., no
endereco 59 Temple Street, Suite 330, Boston, MA 02111-1307 USA.

Para maiores informacoes:
ncl @ telemidia.puc-rio.br
http://www.ncl.org.br
http://www.ginga.org.br
http://www.telemidia.puc-rio.br
******************************************************************************
This file is part of the declarative environment of middleware Ginga (Ginga-NCL)

Copyright: 1989-2007 PUC-RIO/LABORATORIO TELEMIDIA, All Rights Reserved.
  Copyright 2010 LIFIA - Facultad de Informatica - Univ. Nacional de La Plata


This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License version 2 as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License version 2 for more
details.

You should have received a copy of the GNU General Public License version 2
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA

For further information contact:
ncl @ telemidia.puc-rio.br
http://www.ncl.org.br
http://www.ginga.org.br
http://www.telemidia.puc-rio.br
*******************************************************************************/

#ifndef TEXTPLAYER_H_
#define TEXTPLAYER_H_

#include "system/io/interface/output/IWindow.h"
#include "system/io/interface/content/text/IFontProvider.h"
#include "system/io/ILocalDeviceManager.h"
using namespace ::br::pucrio::telemidia::ginga::core::system;

#include "system/util/functions.h"

#include "system/thread/Thread.h"

#include "AVPlayer.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

namespace br {
namespace pucrio {
namespace telemidia {
namespace ginga {
namespace core {
namespace player {
	class TextPlayer : public Player {
		protected:
			int fontHeight;
			int currentLine;
			int currentColumn;
			int tabSize;
			IColor* bgColor;
			int fontSize;
			bool isBold;
			string style;
			bool smallCaps;
			IColor* fontColor;
			string fontUri;
			string fontFamily;
			io::IFontProvider* font;

		public:
			TextPlayer();
			virtual ~TextPlayer();
			void initializePlayer();

			static int write(
					ISurface* s,
					string text,
					string fontUri = "",
					int fontSize = 12, IColor* fontColor = NULL);

			bool setFont(string someUri);
			void setFontSize(int size);
			void setFontFamily(std::string aFont);
			int getFontSize();
			bool getBold();
			void setBold(bool bold);
			string getStyle();
			void setStyle(string newStyle);
			int getFontHeight();
			void setBgColor(int red, int green, int blue, int alpha=255);
			void setColor(int red, int green, int blue, int alpha=255);
			void setTabSize(int size);
			int getTabSize();
			void drawText(string text, short align=(0x00000004 | 0x00000000));
			void drawTextLn(string text, short align=(0x00000004 | 0x00000000));
			void tab();
			void breakLine();
			int getCurrentColumn();
			int getCurrentLine();
			std::string getFontProperties();

			virtual void setPropertyValue(
					string name,
					string value, double duration=-1, double by=-1);
	};
}
}
}
}
}
}

#endif /*TEXTPLAYER_H_*/
