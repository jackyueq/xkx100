// Room: /binghuo/inhole2.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�ڶ�");
	set("long", @LONG
�ڶ����ⶴ��С������ʯ�ڱߴ���һ��ľ�������ﲻ����⣬��
�����������ӣ�һ��ů�����ڡ�
LONG );
	set("no_beg", 1); 
	set("exits", ([
		"out"   : __DIR__"inhole1",
	]));
	set("objects", ([
		CLASS_D("mingjiao")+"/xiexun" : 1,
	]));
	setup();
}
void init()
{
	object weapon, ob, me = this_player();
        mapping weapon_prop;
        string *apply, type;

	if(objectp(ob = present("xie xun", environment(me))) && living(ob))
	{
		weapon = new(WEAPON_DIR"treasure/dragonblade");
		if ( weapon->violate_unique() )
		{
			destruct( weapon );
		}
		else
		{
			if(!present("dragon blade", ob))
			{
				weapon->move(ob);
				weapon_prop=weapon->query("weapon_prop");
				apply = keys(weapon_prop);
				for(int i = 0; i<sizeof(apply); i++)
					ob->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);
				ob->set_temp("weapon", weapon);
				ob->reset_action();
				weapon->set("equipped", "wielded");
			}
		}
	}
}
