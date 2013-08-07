// Room: /d/chengdu/nanjie.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϴ�ֵ����϶ˣ���·����������֦��Ҷï����ͩ��·�汻
��ɨ�øɸɾ��������������Ķ���Щ���º͹�Ա��ż���߹�������ƽ��
���ա�������һ�����ӵ����ã�������ƣ��������ﲻ�����Ǿ��Ǵ���
����ͬ������������������и��������µ�ʯ���š�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"      : __DIR__"gongqiao",
		"west"      : __DIR__"wuhoucigate",
		"north"     : __DIR__"nanjie2",
		"south"     : __DIR__"southgate",
		"southwest" : __DIR__"cai",
	]));
	set("objects", ([
		__DIR__"npc/qigai" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

