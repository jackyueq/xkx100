// wizboard.c ��ʦ��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"�糾���Ѱ�"NOR, ({ "board", "ban" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", HIM"
          ������һ��һ�ž����괺�촴������"HIR"��ʦ����\n"HIC"
��"HIY"����������������������������������������������������������������"HIC"��"HIG"
ahda                along               constant            evil
fandog              jacki               java"HIB"(��ʼ��)"HIG"        kiler
osdine              rknn                sega                sherry"HIB"(��ʼ��)"HIG"
sir                 solomon"HIB"(��ʼ��)"HIG"     spe                 suncity
winder"HIB"(��ʼ��)"HIG"      wuzw"HIC"
��"HIY"����������������������������������������������������������������"HIC"��\n"NOR);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
}

