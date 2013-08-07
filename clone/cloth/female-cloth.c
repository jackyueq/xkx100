// female-cloth.c
// Last Modified by winder on May. 25 2001

#include <armor.h>;
#include <ansi.h>;
inherit CLOTH;

string* clothname = ({
	HIM"�ۺ����"NOR,
	HIW"�׳���"NOR,
	HIG"���̳�ȹ"NOR,
	HIY"��Ƽа�"NOR,
	HIB"����С��"NOR,
	HIC"����С��"NOR,
	HIR"ɢ����"NOR,
	MAG"��ɴС����"NOR,
});
string* clothid = ({
	"pink cloth",
	"white cloth",
	"green skirt",
	"yellow coat",
	"blue shan",
	"qing mei",
	"flower cloth",
	"purple jiashan",
});
string* clothlong = ({
	"����ۺ�ɫ�ĳ����������ż�ֻ��ȵ������������һ�ɵ��㡣\n",
	"����һ����ӯƮ���İ׳�������\n",
	"����һ�����¿��˵ĺ��̳�ȹ��\n",
	"����һ��Ů��ϲ���Ķ�Ƽа���\n",
	"����һ��С�����������С�䡣\n",
	"����һ���ý������ż���÷��������С�ǡ�\n",
	"�����ɫ��ɢ��������ˬˬ������Ʈ�ݡ�\n",
	"����һ����ɴС������\n",
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
	      //  set("long", clothlong[i]);
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

