// Room: /d/nanshaolin/qdian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
void create()
{
	set("short", "ǰ��");
	set("long", @LONG
������������ǰ��һ��ǰ���ģ��С���������޺ܶ���衣ֻ��
����Сɳ���ڽӴ�����������͡�͸�������Ĵ��ţ����Կ���ǰ���ģ
��ΰ�������
LONG );
	set("exits", ([
		"south" : __DIR__"gchang-1",
                "north" : __DIR__"twdian",
	]));
	set("objects",([
                CLASS_D("nanshaolin") + "/yuanshang" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

