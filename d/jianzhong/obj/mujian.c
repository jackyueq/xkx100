#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
       set_name("ľ��", ({ "mu jian", "jian", "sword" }) );
       set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	       set("unit", "��");
       	set("long",HIC@LONG
��ѽ���ƮƮ�Ļ��������ľͷ���ɵģ�����������Щ�����ˡ�
LONG
NOR
);
       	set("value", 0);
       	set("material", "wood");
		}
       init_sword(10);
      	setup();
}
