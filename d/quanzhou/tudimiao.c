// Room: /d/quanzhou/tudimiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʮ���ƾɵ�������Ҳ��֪�ķ��˶�ã����ϵ��²�����
�ҳ����������������ǽ���и����ڣ������������������ļ��ˡ�
LONG );
	set("exits", ([
		"west"   : __DIR__"luoyangqiao",
	]));
	set("objects", ([
		"/d/village/npc/dipi" : 1,
	]));
	set("coor/x", 1900);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
