// Room: /d/quanzhou/shisun.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����Ȫ�������һ����ò��ۣ���ǧ���ʴ�γɵ�ʯ��ǧ��ٹ֣�
�ƽ����Ƶ�����׶����̬���졣�����ݺᣬ��֪���ա������ɽ������
һ�����֡�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"shangu",
		"north" : __DIR__"luanshigang",
	]));
	set("coor/x", 1820);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
