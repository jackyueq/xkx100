// Room: /d/xiangyang/walls8.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ϳ�ͷ");
	set("long", @LONG
�������������ϳ�ͷ��һЩ�α����ڳ�ͷѲ�ߣ�һ������
�������������ܸ����سǲ��ϣ�һЩ���������鹭�������
�ų��µĶ�����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northeast" : __DIR__"walle7",
		"westdown"  : __DIR__"walls6",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -460);
	set("coor/y", -550);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}