// Room: /d/quanzhou/chouduan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������ׯ");
	set("long", @LONG
���������������˿���������ģ���ɫ����ĵ��棬���ϹҸ�Ʈ��
һ���ʵ��Ϻõĳ��棬���ź�ɫ�ġ������С��ĸ����֡���ԭ������
��˿���ڴ˼ӹ���ԴԴ���ϵ��������������ׯ�ڸ�ʽ��ɫ���ʵصĳ�
��Ӧ�о��У�������Ŀ��
LONG );
	set("exits", ([
		"west"   : __DIR__"road1",
	]));
	set("objects", ([
		__DIR__"npc/xu" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
