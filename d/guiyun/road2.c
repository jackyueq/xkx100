// Room: /d/guiyun/road2.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ��������С·�������濴Զ���ƺ�����һ��С�ӡ������濴��һ
����֪�ж೤��С·�����߿����Ǹ����ֵ���ͷ��������һ��С�ƹݡ�
LONG );
	set("no_clean_up", 0);
	set("outdoors", "guiyun");

	set("exits", ([
		"west" : __DIR__"matou",
		"east" : __DIR__"riverw",
		"north": __DIR__"road3",
		"south": __DIR__"jiuguan",
	]) );
	set("objects", ([
		"/d/village/npc/kid" : 1,
	]) );
	setup();
	quarter_pass();
}

void quarter_pass()
{
//	mixed *local;
	string time = NATURE_D->game_time();
/*
	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21)
*/
	if( strsrch(time, "��ʱ") >= 0 ||
		strsrch(time, "��ʱ") >= 0 ||
		strsrch(time, "��ʱ") >= 0 ||
		strsrch(time, "��ʱ") >= 0 ||
		strsrch(time, "��ʱ") >= 0)
	{
		set("long", @LONG
һ��������С·�������濴Զ���ƺ�����һ��С�ӡ������濴��һ
����֪����֪�ж೤��С·�����߿����Ǹ����ֵ���ͷ��������һ�Ҵ�
���˵�С�ƹݡ�
LONG
		);
		delete("exits/south");
	}
	else {
		set("long", @LONG
һ��������С·�������濴Զ���ƺ�����һ��С�ӡ������濴��һ
����֪����֪�ж೤��С·�����߿����Ǹ����ֵ���ͷ��������һ�ҿ�
�ŵ�С�ƹݡ�
LONG
		);
		set("exits/south", __DIR__"jiuguan");
	}
	call_out("quarter_pass", 30);
}
