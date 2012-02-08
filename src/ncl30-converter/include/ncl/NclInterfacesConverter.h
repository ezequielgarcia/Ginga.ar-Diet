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

#ifndef NclInterfacesConverter_H
#define NclInterfacesConverter_H

#include "ncl/switches/SwitchNode.h"
using namespace ::br::pucrio::telemidia::ncl::switches;

#include "ncl/interfaces/Anchor.h"
#include "ncl/interfaces/PropertyAnchor.h"
#include "ncl/interfaces/IntervalAnchor.h"
#include "ncl/interfaces/LabeledAnchor.h"
#include "ncl/interfaces/RectangleSpatialAnchor.h"
#include "ncl/interfaces/RelativeTimeIntervalAnchor.h"
#include "ncl/interfaces/SampleIntervalAnchor.h"
#include "ncl/interfaces/SpatialAnchor.h"
#include "ncl/interfaces/TextAnchor.h"
#include "ncl/interfaces/SwitchPort.h"
#include "ncl/interfaces/Port.h"
using namespace ::br::pucrio::telemidia::ncl::interfaces;

#include "ncl/components/CompositeNode.h"
#include "ncl/components/NodeEntity.h"
using namespace ::br::pucrio::telemidia::ncl::components;

#include "../framework/DocumentParser.h"
using namespace ::br::pucrio::telemidia::converter::framework;

#include "../framework/ncl/NclInterfacesParser.h"
using namespace ::br::pucrio::telemidia::converter::framework::ncl;

#include "system/util/functions.h"
using namespace ::util;

#include <string>
using namespace std;

#include <xercesc/dom/DOM.hpp>
XERCES_CPP_NAMESPACE_USE

namespace br {
namespace pucrio {
namespace telemidia {
namespace converter {
namespace ncl {
  class NclInterfacesConverter : public NclInterfacesParser {
	public:
		NclInterfacesConverter(DocumentParser *documentParser);
		void *createPort(DOMElement *parentElement, void *objGrandParent);

	private:
		SpatialAnchor *createSpatialAnchor(DOMElement *areaElement);
		IntervalAnchor *createTemporalAnchor(DOMElement *areaElement);

	public:
		void *createProperty(DOMElement *parentElement, void *objGrandParent);
		void *createArea(DOMElement *parentElement, void *objGrandParent);
		void *createMapping(DOMElement *parentElement, void *objGrandParent);
		void *createSwitchPort(DOMElement *parentElement, void *objGrandParent);
		void addMappingToSwitchPort(void *parentObject, void *childObject);
  };
}
}
}
}
}

#endif
