#include"../dom.h"
#include"../../exception/generic.h"
#include<string>

using namespace dty::model::doc;

TianyuDOMNode::TianyuDOMNode() : IDOMNode() { }
TianyuDOMNode::~TianyuDOMNode() { }

TianyuDOMNodeType TianyuDOMNode::GetDOMType() { return TianyuDOMNodeType::UNDEFINED; }

bool TianyuDOMNode::IsNull() { return true; }
bool TianyuDOMNode::IsArray() { return false; }

bool TianyuDOMNode::ToBool() { return false; }
int32 TianyuDOMNode::ToInt() { return 0; }
float TianyuDOMNode::ToFloat() { return 0; }
string TianyuDOMNode::ToString() { return new char[1]{ '\0' }; }

dty::SmartPointer<IDOMNode> TianyuDOMNode::NewNullNode()
{

}

