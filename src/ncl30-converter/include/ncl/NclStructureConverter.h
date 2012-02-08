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

#ifndef NCLNCMSTRUCTURECOMPILER_H
#define NCLNCMSTRUCTURECOMPILER_H

#include "ncl/NclDocument.h"
#include "ncl/NclDocument.h"
using namespace ::br::pucrio::telemidia::ncl;

#include "ncl/transition/TransitionBase.h"
using namespace ::br::pucrio::telemidia::ncl::transition;

#include "ncl/metainformation/Meta.h"
#include "ncl/metainformation/Metadata.h"
using namespace ::br::pucrio::telemidia::ncl::metainformation;

#include "ncl/components/ContextNode.h"
using namespace ::br::pucrio::telemidia::ncl::components;

#include "../framework/DocumentParser.h"
#include "../framework/ModuleParser.h"
using namespace ::br::pucrio::telemidia::converter::framework;

#include "../framework/ncl/NclStructureParser.h"
using namespace ::br::pucrio::telemidia::converter::framework::ncl;

#include <string>
using namespace std;

#include "NclPresentationSpecConverter.h"
#include "NclComponentsConverter.h"
#include "NclLinkingConverter.h"
#include "NclLayoutConverter.h"
#include "NclInterfacesConverter.h"
#include "NclPresentationControlConverter.h"
#include "NclConnectorsConverter.h"

#include <xercesc/dom/DOM.hpp>
XERCES_CPP_NAMESPACE_USE

namespace br {
namespace pucrio {
namespace telemidia {
namespace converter {
namespace ncl {
  class NclStructureConverter : public NclStructureParser {
	public:
		NclStructureConverter(DocumentParser *documentParser);
		virtual void addBodyToNcl(void *parentObject, void *childObject);
		virtual void addPortToBody(void *parentObject, void *childObject);
		virtual void addPropertyToBody(void *parentObject, void *childObject);
		virtual void addContextToBody(void *parentObject, void *childObject);
		virtual void addSwitchToBody(void *parentObject, void *childObject);
		virtual void addDescriptorBaseToHead(
			    void *parentObject, void *childObject);

		virtual void addHeadToNcl(void *parentObject, void *childObject);
		virtual void addRegionBaseToHead(
			    void *parentObject, void *childObject);

		virtual void addTransitionBaseToHead(
			    void* parentObject, void* childObject);

		virtual void addLinkToBody(void *parentObject, void *childObject);
		virtual void addMediaToBody(void *parentObject, void *childObject);
		virtual void addRuleBaseToHead(void *parentObject, void *childObject);
		virtual void addConnectorBaseToHead(
			    void *parentObject, void *childObject);

		virtual void *createBody(
			    DOMElement *parentElement, void *objGrandParent);

	private:
		void solveNodeReferences(CompositeNode *composition);

	public:
		virtual void* posCompileBody(
			    DOMElement *parentElement, void *parentObject);

		virtual void* createHead(
			    DOMElement *parentElement, void *objGrandParent);

		virtual void* createNcl(
			    DOMElement *parentElement, void *objGrandParent);

		virtual void addImportedDocumentBaseToHead(
			    void *parentObject, void *childObject);

		void addMetaToHead(void* parentObject, void* childObject);
		void addMetadataToHead(void* parentObject, void* childObject);
  };
}
}
}
}
}

#endif //NCLNCMSTRUCTURECOMPILER_H
