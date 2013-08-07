// Room: /binghuo/shulin3.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������滨��ܣ�������Ҷ����ɽ��Ұ�����⼫��֮����
��Ȼ�д���ľ�������ǰݻ�ɽ֮���ˡ�ż������һЩ�в�����Ŀ�Ĵ�
��С�ޣ�Ҳ�����ˡ�
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"southwest" : __DIR__"shulin2",
		"south"     : __DIR__"pingyuan1",
		"northeast" : __DIR__"yuanye1",
		"northwest" : __DIR__"shanlu1",
	]));
	set("objects", ([
		"/d/guanwai/npc/buck": 1,
		"/d/guanwai/npc/doe": 1,
	]));
	setup();
}

int valid_leave (object who, string dir)
{
	if(dir != "northwest")
	{
		return ::valid_leave(who, dir);
	}
	else
	{
		if (who->query_temp("binghuo") > 10)
		{
			return 1;
		}
		else
		{
			who->add_temp("binghuo",1);
			who->start_busy(2);
			return notify_fail("��������������ȥ�����Ǻ����򲻶ԣ����˰��죬�ֻص���ԭ�ء�\n");
		}
        }
}

void fall_down (object who, object where)
{
	who->move(where);
	this_player()->unconcious();
}
void fall_down1 (object who, object where)
{
	this_player()->unconcious();
}

