// Room: /d/lingxiao/lianwu2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����������ǵ����䳡��ֻ�����⽣Ӱ��Ŀ��Ͼ�ӣ�һȺ��������
���ô����죬�˴˴���ѽ��ѷ֡�����������ϵ���ͣ��˴˼�������
�������µ���Ҳֻ��Ŭ���������Է����⡣
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"fudian2",
	]));
	set("objects", ([ 
		"/d/shaolin/npc/mu-ren" : 4,
	]));
	set("outdoors", "lingxiao" );
	set("coor/x", -30980);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

