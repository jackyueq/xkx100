// medicine7.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
string* skills = ({
	"poison",
	"five-poison",
	"xidu-poison"
});
void create()
{
       // int i = random(sizeof(skills));
	set_name(HIC"���ѹö���"NOR, ({ "wangnangu dujing", "dujing", "jing"}));
	set_weight(10);
        set("skill",([
              "name":         skills[random(sizeof(skills))]
               ]) ); 
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","���ǵ��ȶ������ѹ�һ����Ѫ�㼯�ɵ�ʹ�����顣\n");
		set("value", 1500);
		set("material", "paper");
		set("skill", ([
          //		"name":         skills[random(sizeof(skills))],
			"exp_required": 100 ,
			"jing_cost":    30+random(10),
			"difficulty":   20,
			"min_skill":    10,
			"max_skill":    100
		]) );
	}
}
