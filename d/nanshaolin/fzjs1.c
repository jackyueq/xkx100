// Room: /d/nanshaolin/fzjs1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƿ��ɴ��͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�����ǽ��
����һ��������ǽ��һ�������ż���������и�������������ˡ�����
��������׭�֣������������ڣ��ƺ��Ǹ�����²衣�����Ƿ����ҡ�
LONG );
	set("exits", ([
		"north" : __DIR__"fzjs2",
		"down"  : __DIR__"fzjs",
	]));
	set("objects",([
		__DIR__"npc/xiao-tong" : 1,
		CLASS_D("nanshaolin")+"/fangxiang" : 1,
	]));
	set("coor/x", 1780);
	set("coor/y", -6150);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	int skill;

	skill = me->query_skill("buddhism", 1);
	if (!wizardp(me) && skill < 30)
	{
		if (dir == "north" )
		{
			return notify_fail("���ʸ񲻹������ܽ��뷽���ҡ�\n");
		}
	}
	return ::valid_leave(me, dir);
}


