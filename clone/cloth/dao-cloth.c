// dao-cloth.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

string* clothname = ({
	HIB"��ɫ����"NOR,
	HIC"��ɫ����"NOR,
	HIW"��ɫ����"NOR,
	HIY"��ɫ����"NOR,
});
string* clothid = ({
	"dao pao",
	"dao pao",
	"dao pao",
	"dao pao",
});
string* clothlong = ({
	"����һ������ͨͨ���಼���ۡ�\n",
	"����һ��������ߡ�Ļ�ɫ�����ۡ�\n",
	"����һ��ϴ�úܸɾ��İײ����ۡ�\n",
	"����һ��ϴ�ú���ɫ�ĻƲ����ۡ�\n",
});

void create()
{
	int i = random(sizeof(clothname));
	set_name(clothname[i], ({ clothid[i], "cloth" }));
	set_weight(3000);
	set("long", clothlong[i]);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
//		set("long", clothlong[i]);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
