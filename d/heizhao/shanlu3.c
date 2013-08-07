// Room: /heizhao/shanlu3.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "���ְ���");
	set("long", @LONG
��ɭɭ�������ﶼ����ľ���޷�ֱ�У�����С·������������
�����ѱ淽��æԾ����ȥ���������������Ǳ��������Ҳ�����·��
��������������Ծ��ȥ���ڰ���ȴ����������֮����
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);

	set("exits", ([
		"east"       : __FILE__,
		"west"       : __FILE__,
		"north"      : "/d/npc/m_weapon/lianfushi",
		"south"      : __FILE__,
		"northwest"  : __FILE__,
		"southwest"  : __DIR__"shanlu2",
		"northeast"  : __FILE__,
		"southeast"  : __FILE__,
	]));
	set("coor/x", -4000);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
}

int valid_leave (object who, string dir)
{
	if(dir != "west")
	{
		who->add_temp("heizhao2",-1);
		return ::valid_leave(who, dir);
	}
	else
	{
		if (who->query_temp("heizhao2") < 16)
		{
			who->add_temp("heizhao2",1);
			return ::valid_leave(who, dir);
		}
		else
		{
			who->move(__DIR__"shanlu4");
			return notify_fail(HIR"������Ŷ�������߹�һ���ˣ�\n"NOR);
		}
        }
}