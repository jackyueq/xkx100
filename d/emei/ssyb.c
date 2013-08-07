//Room: ssyb.c �����±�
//Date: Oct. 21 1997 by That
#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short","�����±�");
	set("long",@LONG
�������ε��±ڡ�̧ͷ������΢����⡣���泱ʪ���ѷ���΢��ˮ��
�������������ǵĳ�ˮ�����ܵľ��ﶼ�����塣�򶫾�������ʱ��ˮ̶��
LONG);
	set("outdoors","emei");
	set("objects", ([
		__DIR__"npc/frog" : 1,
	]) );
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"st8", 
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	set("sword_count",1);
	set("coor/x", -6220);
	set("coor/y", -1170);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_dig","dig");
	add_action("do_climb","climb");
}
int do_climb()
{
	object me = this_player();
	message("vision", me->name()+"ʹ������ȥ�����˾�ţ����֮����\n", environment(me), ({me}) );
	me->move(__DIR__"gudelin1");
	message("vision", me->name()+"���˾�ţ����֮������������ط���ȴ��֪�������\n", environment(me), ({me}) );
	return 1;
}
int do_dig()
{
	object ob, me = this_player();

	if (query("sword_count") <1)
	{
		message_vision("����ʲôҲû���ˣ�$N����̾�˿�����\n",me);
		return 1;
	}

	if (me->query("marks/skysword") )
	{
		if ( uptime() > 1800 && (random(10))==3 )
		{
			add("sword_count", -1);
			me->delete("marks/skysword");
			ob = new(WEAPON_DIR"treasure/skysword");
			if ( ob->violate_unique() )
			{
				destruct( ob );
				message_vision("����ʲôҲû���ˣ�$N����̾�˿�����\n",me);
				return 1;
			}
			message_vision("$N��Ȼ�ڵ���Ӳ�Ķ�����������Ĩ�������������˵Ĵ�Ц������\n", me);
			write("������������콣����\n");
			ob->move(me);
			message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ����콣����\n"NOR, users());
		}
		else
		{
			me->receive_damage("qi", 20);
			message_vision("$Nʹ����ʯ�����ڣ��ֶ��ڳ�Ѫ�ˡ����ǰ�æ�ˡ�\n", me);
		}
		return 1;
	} 
	else
	{
		message_vision("$Nʹ����ʯ�����ڣ��ֶ��ڳ�Ѫ�ˡ���ɶ�أ�\n",me);
		return 1;
	}
}
