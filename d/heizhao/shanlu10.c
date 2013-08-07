// Room: /heizhao/shanlu10.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "ɽ��ƽ��");
	set("long", @LONG
�����и��������Ȫ���ߴ�������࣬��ѩ����һ���޴��
ˮ����ʯ����ֱ�������������գ�����Ȫ������Ϫˮ���ٲ���Դ
ͷ������ɽ�ڶ�����ɽ��������ǣ�����һ�Է�ľ��䡣ɽ��һ
���ֱ۴�ϸ�ĳ���(teng)���ط���ϡ���ͷ��������ɽ����ϰ��
��������֮�У���֪�嶥���ж�ߡ�
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("resource/water", 1);
	set("objects", ([
		CLASS_D("dali")+"/yideng/qiao" : 1,
	]));
	set("exits", ([
		"down"   : __DIR__"pububian",
	]));
	set("coor/x", -5020);
	set("coor/y", -1260);
	set("coor/z", 30);
	setup();
}

int valid_leave (object who, string dir)
{
	if(dir == "down")
	{
		message_vision(HIY"$N˳ˮ�����۶��¡�\n"NOR, who);
	}
	return ::valid_leave(who, dir);
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player();
	int n;
	n = me->query_str();
	if ( !arg || arg != "teng")
	{
		write("��Ҫ��ʲôѽ? \n");
		return 1;
	}
	message_vision("$N������һ�������������ų��ٵ���������\n", me);
	if(n > 35)
	{
		message_vision("$N���˰��죬��������������$N���Ǹ��ˡ�\n", me);
		this_player()->move(__DIR__"shanding");
	}
	else
	{
		message_vision("$N����һ�ᣬ̫���ˣ���С�Ļ���������\n", me);
		me->receive_damage("qi",15);
		me->receive_wound("qi",10);
	}
	return 1;
}