// male-cloth.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;

inherit CLOTH;

string* clothname = ({
	"�ֲ���",
	HIB"����"NOR,
	BBLK"��ɫ��װ"NOR,
	HIC"�̴�װ"NOR,
	HIM"������"NOR,
	BLU"�����"NOR,
	HIY"���ƽ���"NOR,
	HIB"��������"NOR,
});
string* clothid = ({
	"rough cloth",
	"blue cloth",
	"black cloth",
	"bunt cloth",
	"purple cloth",
	"blue cloth",
	"yellow cloth",
	"celeste cloth",
});
string* clothlong = ({
	"����һ������ͨ�Ĵֲ��¡�\n",
	"����һ������ͨ�Ĵֲ�������\n",
	"����һ���ܱ�ͦ�ĺ�ɫ��װ��\n",
	"����һ���������Ķ̴�װ��\n",
	"����һ�����ص������ۡ�\n",
	"����һ�����ص�����ӡ�\n",
	"����һ�����ƽ��ۡ�\n",
	"����һ���������ۡ�\n",
});

void create()
{
	int i = random(sizeof(clothname));

	set_name(clothname[i], ({ clothid[i], "cloth" }));
	set_weight(1000);
        set("long", clothlong[i]);  
	if( clonep() )
		set_default_object(__FILE__);
	else {
       // 	set("long", clothlong[i]);
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
	}
	setup();
}

