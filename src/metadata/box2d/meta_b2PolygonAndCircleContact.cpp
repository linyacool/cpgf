#include "Box2D/Box2D.h"
#include "Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h"

#include "cpgf/metadata/box2d/meta_b2PolygonAndCircleContact.h"

#include "cpgf/gmetapolicy.h"
#include "cpgf/goutmain.h"

using namespace cpgf;

namespace {

G_AUTO_RUN_BEFORE_MAIN()
{
    {
    GDefineMetaClass<void> _ns = GDefineMetaClass<void>::define("box2d");
    GDefineMetaClass<b2PolygonAndCircleContact, b2Contact> _d = GDefineMetaClass<b2PolygonAndCircleContact, b2Contact>::Policy<MakePolicy<GMetaRuleDestructorAbsent, GMetaRuleDefaultConstructorAbsent> >::declare("b2PolygonAndCircleContact");
    _ns._class(_d);
    buildMetaClass_B2PolygonAndCircleContact(0, _d, NULL, GMetaPolicyCopyAllConstReference());
    }
    

}

} // unnamed namespace
