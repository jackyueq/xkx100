// Room: /d/chengdu/lingmu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "��Ĺ");
	set("long", @LONG
������һ���ܴ����Ĺ�����ߵ�����о��ֵֹģ���֪����ʲô
�ط����ԣ�Ҳ�������������ʹ����Щѹ�ְɣ��и�ɨĹ�������ﲻͣ
�ذ���̾����
LONG	);
	set("exits", ([
		"east" : __DIR__"wuhouci",
	]));
	set("objects",([
		 __DIR__"npc/saomuren" : 1,
	]));
	set("outdoors", "chengdu");
	set("coor/x", -8080);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

